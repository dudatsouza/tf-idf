#include "ranking.hpp"

void Ranking::readFile(const std::string& filename, std::list<std::string>& words) {
    std::ifstream arquivo(filename);
    std::string palavra;
    
    if (arquivo.is_open()) {
        while (arquivo >> palavra) {
            words.push_back(normalize(palavra));         }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
    }
}

std::string Ranking::normalize(const std::string &word) {
    std::string normalized = word;
    
    std::transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);
    normalized.erase(std::remove_if(normalized.begin(), normalized.end(), [](char c) { return !std::isalnum(c) || ::ispunct(c); }), normalized.end());

    return normalized;
}

int Ranking::calculateTF(const std::string &word, const std::list<std::string> &words) {
    int count = 0;
    
    for (const auto &w : words) {
        if (w == word) {
            count++;
        }
    }
    
    return count;
}

double Ranking::calculateIDF(const std::string& term) {
    int numDocsWithTerm = 0;
    for (const auto& doc : documents) {
        if (std::find(doc.begin(), doc.end(), term) != doc.end()) {
            numDocsWithTerm++;
        }
    }
    return log(static_cast<double>(documents.size()) / (1 + numDocsWithTerm));
}