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
    
    if (arquivo.is_open()) {
        while (arquivo >> palavra) {
            if (stopWords.find(normalize(palavra)) != stopWords.end()) {
                continue;
            }

            wordsFreq[normalize(palavra)]++;
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo: " << this->filename << std::endl;
    }

    // imprimindoPalavras();
}

// Função que normaliza uma palavra, removendo caracteres especiais e transformando em minúsculas
std::string normalize(const std::string &word) {
    std::string normalized = word;
    
    std::transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);
    normalized.erase(std::remove_if(normalized.begin(), normalized.end(), [](char c) { return !std::isalnum(c) || ::ispunct(c); }), normalized.end());

    return normalized;
}

void Document::imprimindoPalavras() {
    for (const auto &word : wordsFreq) {
        std::cout << word.first << " " << word.second << std::endl;
    }
}