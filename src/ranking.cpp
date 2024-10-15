#include "ranking.hpp"

void Ranking::readFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }

    std::string line;

}
