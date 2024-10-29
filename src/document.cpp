#include "document.hpp"

// Construtor da classe Document
Document::Document(const std::string &filename, std::unordered_set<std::string> stopWords) {
    this->filename = filename;
    this->stopWords = stopWords;
    readFile();
}

// Função que lê um arquivo e armazena as palavras em uma lista
void Document::readFile() {
    std::ifstream arquivo(this->filename);
    std::string palavra;
    totalWords = 0;

    if (arquivo.is_open()) {
        while (arquivo >> palavra) {
            std::string normalized;

            normalized = normalize(palavra);
            if (stopWords.find(normalized) != stopWords.end()) {
                continue;
            }

            size_t pos;
            while ((pos = normalized.find_first_of(".,;:!?()[]{}«»<>-_\\/\"'ªº°§&*@#$+")) != std::string::npos) {
                normalized.replace(pos, 1, " ");
            }

            std::istringstream iss(normalized);
            while (iss >> normalized) {
                addWord(normalized);
            }
        }
        // imprimindoPalavras();

        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo: " << this->filename << std::endl;
    }
}

void Document::addWord(const std::string &word) {
    std::string normalized = word;
    totalWords++;
    if (OPTIMIZE) {
        if (wordsFreq.find(normalized) == wordsFreq.end()) {
            wordsFreq[normalized] = 1;
        } else {
            wordsFreq[normalized]++;
        }
    } else {
        auto it = std::find_if(docWords.begin(), docWords.end(), [&normalized](const WordFreq &word) { return word.word == normalized; });
        if (it != docWords.end()) {
            it->freq++;
        } else {
            WordFreq wordFreq;
            wordFreq.word = normalized;
            wordFreq.freq = 1;
            docWords.push_back(wordFreq);
        }
    }
}

// Função que normaliza uma palavra, removendo caracteres especiais e transformando em minúsculas
std::string normalize(const std::string &word) {
    std::string normalized = word;

    std::transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    wchar_t withAccent[] = L"ÁÀÃÂÉÈẼÊÍÌĨÎÓÒÔÕÚÜÇáàãâéèẽêíìĩîóòôõúüç";
    wchar_t withoutAccent[] = L"AAAAEEEEIIIIOOOOUUCaaaaeeeeiiiioooouuc";

    std::wstring wordNormalized = converter.from_bytes(normalized);

    for (size_t i = 0; i < wcslen(withAccent); i++) {
        std::replace(wordNormalized.begin(), wordNormalized.end(), withAccent[i], withoutAccent[i]);
    }

    normalized = converter.to_bytes(wordNormalized);

    return normalized;
}

void Document::imprimindoPalavras() {
    if (OPTIMIZE) {
        for (const auto &word : wordsFreq) {
            std::cout << word.first << " " << word.second << std::endl;
        }
    } else {
        for (const auto &word : docWords) {
            std::cout << word.word << " " << word.freq << std::endl;
        }
    }
}