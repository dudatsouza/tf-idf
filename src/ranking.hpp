#ifndef RANKING_HPP
#define RANKING_HPP

#include <bits/stdc++.h>

#include "document.hpp"

class Ranking {
    struct pairHash {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2> &p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

   private:
    std::vector<std::string> filenames = {
        "datasets/doc1.txt",
        "datasets/doc2.txt",
        "datasets/doc3.txt",
        "datasets/doc4.txt",
        "datasets/doc5.txt",
        "datasets/doc6.txt"};

   public:
    Ranking(std::string phrase);

    std::list<Document> documents;

    std::unordered_set<std::string> stopWords;

    std::unordered_map<std::string, int> wordsidf;
    // std::unordered_map<std::string, std::unordered_map<Document, int>> wordsdoctf;
    std::unordered_map<std::pair<std::string, Document>, int, pairHash> wordsdoctf;

    void readStopWords();
    void readPhrase(const std::string &phrase);

    int calculateIDF(const std::string &word);
    int calculateTFIDF(const std::string &term, Document doc);
    void calculateRelevanceDoc();
    void quickSort(std::list<Document> &documents, int left, int right);
    int partition(std::list<Document> &documents, int left, int right);
};

#endif
