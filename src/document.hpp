#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <bits/stdc++.h>

#define OPTIMIZE 1

std::string normalize(const std::string &word);

struct WordFreq {
    std::string word;
    int freq = 0;
};

class Document {
   public:
    Document(const std::string &filename, std::unordered_set<std::string> stopWords);
    std::unordered_set<std::string> stopWords;

    double relevance = 0;

    std::string filename;

    std::unordered_map<std::string, int> wordsFreq;
    std::list<WordFreq> docWords;
    int totalWords = 0;

    void imprimindoPalavras();

    void readFile();
    void addWord(const std::string &word);

    bool operator==(const Document &other) const {
        return filename == other.filename;
    }
};

// Função de hash para a classe Document
namespace std {
template <>
struct hash<Document> {
    size_t operator()(const Document &doc) const {
        return hash<std::string>()(doc.filename);
    }
};
}  // namespace std

#endif