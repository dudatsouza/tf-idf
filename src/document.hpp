#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <bits/stdc++.h>

std::string normalize(const std::string &word);



class Document {
    public:
        Document(const std::string &filename, std::unordered_set<std::string> stopWords);
        std::unordered_set<std::string> stopWords;

        int relevance;

        std::string filename;

        std::unordered_map<std::string, int> wordsFreq;

        void imprimindoPalavras();
        
        void readFile();
        
        bool operator==(const Document &other) const {
            return filename == other.filename;
        }
};

// Função de hash para a classe Document
namespace std {
    template <>
    struct hash<Document> {
        size_t operator()(const Document& doc) const {
            return hash<std::string>()(doc.filename);
        }
    };
}




#endif