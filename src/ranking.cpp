#include "ranking.hpp"

// Construtor da classe Ranking
Ranking::Ranking(std::string phrase) {
    readStopWords();
    for (const auto& filename : filenames) {
        Document doc(filename, stopWords);
        documents.push_back(doc);
    }
    readPhrase(phrase);
}

void Ranking::readStopWords() {
    std::ifstream arquivo("datasets/stopwords.txt");
    std::string palavra;

    if (arquivo.is_open()) {
        while (arquivo >> palavra) {
            stopWords.insert(normalize(palavra));
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de stopwords" << std::endl;
    }
}

// Função que calcula o IDF (Inverse Document Frequency) de uma palavra, ou seja, a quantidade de documentos que contêm a palavra
double Ranking::calculateIDF(const std::string& term) {
    int numDocsWithTerm = 0;
    for (const auto& doc : documents) {
        if (OPTIMIZE) {
            if (doc.wordsFreq.find(term) != doc.wordsFreq.end()) {
                numDocsWithTerm++;
            }
        } else {
            auto it = std::find_if(doc.docWords.begin(), doc.docWords.end(), [&term](const WordFreq& word) { return word.word == term; });
            if (it != doc.docWords.end()) {
                numDocsWithTerm++;
            }
        }
    }

    double ratio = (double)(documents.size() + 1) / (double)(numDocsWithTerm + 1);

    double idf = log2(ratio);

    return idf;
}

// Função que calcula o TF/IDF de uma palavra em um documento
double Ranking::calculateTFIDF(const std::string& term, Document doc) {
    double idf = calculateIDF(term);
    if (OPTIMIZE) {
        return ((double)doc.wordsFreq[term] / (double)doc.totalWords) * idf;
    } else {
        auto it = std::find_if(doc.docWords.begin(), doc.docWords.end(), [&term](const WordFreq& word) { return word.word == term; });
        double tf = 0;
        if (it != doc.docWords.end()) {
            tf = it->freq;
        }

        return ((double)tf / (double)doc.totalWords) * idf;
    }
}

// Função que pega uma lista de palavras de busca e passa para um unordered_map, onde a chave é a palavra e o valor é o idf da palavra
void Ranking::readPhrase(const std::string& phrase) {
    std::istringstream iss(phrase);
    std::string word;
    while (iss >> word) {
        word = normalize(word);

        size_t pos;
        while ((pos = word.find_first_of(".,;:!?()[]{}«»<>-_\\/\"'ªº°§&*@#$+")) != std::string::npos) {
            word.replace(pos, 1, " ");
        }

        std::istringstream issInside(word);
        while (issInside >> word) {
            if (stopWords.find(word) != stopWords.end()) {
                continue;
            }

            phraseWords.push_back(word);
        }
    }
}

// Função que calcula a relevância de um documento em relação a uma busca
void Ranking::calculateRelevanceDoc() {
    for (auto& doc : documents) {
        double relevance = 0;
        for (const auto& word : phraseWords) {
            relevance += calculateTFIDF(word, doc);
        }

        doc.relevance = relevance;
    }
}

// Função que ordena a lista de documentos de acordo com a relevância
void Ranking::quickSort(std::list<Document>& docs, int left, int right) {
    if (left < right) {
        int pivot = partition(docs, left, right);
        quickSort(docs, left, pivot - 1);
        quickSort(docs, pivot + 1, right);
    }
}

int Ranking::partition(std::list<Document>& docs, int left, int right) {
    auto pivot = std::next(docs.begin(), right);
    int i = left - 1;

    for (int j = left; j < right; j++) {
        auto doc = std::next(docs.begin(), j);
        if (doc->relevance > pivot->relevance) {
            i++;
            std::swap(*std::next(docs.begin(), i), *doc);
        }
    }

    std::swap(*std::next(docs.begin(), i + 1), *pivot);
    return i + 1;
}