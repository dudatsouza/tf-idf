#include "document.hpp"
#include "ranking.hpp"

// Aquivos de texto que serão lidos
// doc1.txt = "A Mão e A Luva" - Machado de Assis
// doc2.txt = "A Bíblia Sagrada"
// doc3.txt = "Dom Casmurro" - Machado de Assis
// doc4.txt = "Quincas Borba" - Machado de Assis
// doc5.txt = "A semana" Texto-fonte: Obra Completa de Machado de Assis
// doc6.txt = "Relação do formidavel, e lastimoso terremoto succedido no Reino de Valença"

int main() {
    std::vector<std::string> phrases = {
        "A Quincas Borba.",
        "A fé pode mover montanhas.",
        "Valença.",
        "Deus e a Terra",
        "amor vida morte",
        "leite café pão",
        "grande alma pequeno corpo",
        "Reino de Valença",
        "hoje o dia está nublado",
        "Rubião fitava a enseada,--eram oito horas da manhã",
        "O amor pode ser a força que une, mas também a que destrói, levando à traição e ao sofrimento.",
        "A filosofia de Quincas Borba ensina que a vida é uma batalha constante entre o humanitismo e o egoísmo.",
        "A fé pode mover montanhas e realizar milagres, trazendo esperança àqueles que creem.",
        "O terremoto no Reino de Valença foi uma tragédia que marcou a história, deixando um rastro de destruição e desespero.",
        "pusillanime aborrecivel cypreste",
        "Senhor Jesus Cristo",
        "grinaldas alcovas Nero autópsias",
        "cadeirinha cahiu Humanitas sufficientemente",
        "asseio compostura respeitabilidade houverdes sertão",
        "lisboa madri espantosos Cameraria"};

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