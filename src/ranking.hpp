#ifndef RANKING_HPP
#define RANKING_HPP

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <cctype> 

class Ranking {

private:
        std::vector<std::string> documents;
        std::unordered_map<std::string, double> tfidf;

public:
    void readFile(const std::string &filename, std::list<std::string> &words);
    std::string normalize(const std::string &word);
    int calculateTF(const std::string &word, const std::list<std::string> &words);
    double calculateIDF(const std::string &word);
    double calculateRelevance(const std::list<std::string>& searchWords, const std::list<std::string> &document);
    // void quickSort(std::vector<std::string> &documentos, int left, int right);


};

#endif
