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

// Função que calcula o IDF (Inverse Document Frequency) de uma palavra, ou seja, a quantidade de documentos que contém a palavra
int Ranking::calculateIDF(const std::string& term) {
    int numDocsWithTerm = 0;
    for (const auto& doc : documents) {
        if (doc.wordsFreq.find(term) != doc.wordsFreq.end()) {
            numDocsWithTerm++;
        }
    }

    return numDocsWithTerm;
}

// Função que calcula o TF/IDF de uma palavra em um documento
int Ranking::calculateTFIDF(const std::string& term, Document doc) {
    return doc.wordsFreq[term] * calculateIDF(term);
}

// Função que pega uma lista de palavras de busca e passa para um unordered_map, onde a chave é a palavra e o valor é o idf da palavra
void Ranking::readPhrase(const std::string& phrase) {
    std::istringstream iss(phrase);
    std::string word;
    while (iss >> word) {
        word = normalize(word);
        if (stopWords.find(word) != stopWords.end()) {
            continue;
        }

        int idf = calculateIDF(word);
        wordsidf[word] = idf;
    }

    for (const auto& doc : documents) {
        for (const auto& word : wordsidf) {
            int tf = 0;

            if (doc.wordsFreq.find(word.first) != doc.wordsFreq.end()) {
                tf = doc.wordsFreq.at(word.first);
            }

            std::pair<std::string, Document> wordsdoc = std::make_pair(word.first, doc);
            wordsdoctf[wordsdoc] = tf;
        }
    }
}

// Função que calcula a relevância de um documento em relação a uma busca
void Ranking::calculateRelevanceDoc() {
    for (auto& doc : documents) {
        double relevance = 0;
        for (const auto& word : wordsidf) {
            std::pair<std::string, Document> wordsdoc = std::make_pair(word.first, doc);
            relevance += wordsdoctf[wordsdoc] * word.second;
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