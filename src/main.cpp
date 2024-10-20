#include "ranking.hpp"
#include "document.hpp"

// Aquivos de texto que serão lidos
// doc1.txt = A Mao e A Luva - Machado de Assis
// doc2.txt = Biblia Sagrada
// doc3.txt = Dom Casmurro - Machado de Assis
// doc4.txt = Quincas Borba - Machado de Assis
// doc5.txt = A semana Texto-fonte: Obra Completa de Machado de Assis
// doc6.txt = Relação do formidavel, e lastimoso terremoto succedido no Reino de Valença
        
int main() {
    std::vector<std::string> phrases = {
            "A Quincas Borba.", 
            "A fé pode mover montanhas.", 
            "Valença."
    };

    for (const auto phrase : phrases) {
        std::cout << "Busca: " << phrase << std::endl;
        
        Ranking ranking(phrase);

        ranking.calculateRelevanceDoc();

        ranking.quickSort(ranking.documents, 0, ranking.documents.size() - 1);

        for (const auto &doc : ranking.documents) {
            std::cout << "Documento: " << doc.filename << " - Relevância: " << doc.relevance << std::endl;
        }

        std::cout << std::endl;
    } 

    return 0;
}