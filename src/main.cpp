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
        "A Quincas Borba",
        "Senhor Jesus Cristo",
        "Reino de Valença",
        "hoje o dia está nublado",
        "Rubião fitava a enseada,--eram oito horas da manhã",
        "O terremoto no Reino de Valença foi uma tragédia que marcou a história, deixando um rastro de destruição e desespero.",
        "grinaldas alcovas Nero autópsias",
    };

    // limpando terminal
    system("clear");

    std::cout << "--------------------------" << std::endl;
    std::cout << "RANQUEAMENTO DE DOCUMENTOS" << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    if(OPTIMIZE)
        std::cout << "Por padrão o programa está configurado para uma forma otimizada de busca, onde a frequência de palavras é armazenada em um unordered_map. Para mudar para a forma não otimizada, altere a variável OPTIMIZE para 0 no arquivo 'src/document.hpp' e recompile o programa." << std::endl << std::endl;
    else
        std::cout << "Por padrão o programa está configurado para uma forma não otimizada de busca, onde a frequência de palavras é armazenada em uma lista. Para mudar para a forma otimizada, altere a variável OPTIMIZE para 1 no arquivo 'src/document.hpp' e recompile o programa." << std::endl << std::endl;

    std::cout << "--------------------------" << std::endl;

    std::cout << "Rankeando..." << std::endl << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    int i = 1;
    for (const auto phrase : phrases) {
        std::cout << "Busca " << i << ": " << phrase << std::endl;

        Ranking ranking(phrase);

        ranking.calculateRelevanceDoc();

        ranking.quickSort(ranking.documents, 0, ranking.documents.size() - 1);

        for (const auto &doc : ranking.documents) {
            if (doc.relevance == 0) 
                continue;

            std::cout << "Doc: " << doc.filename << " - Relevância: " << doc.relevance << std::endl;
        }

        // std::cout << "Documento: " << ranking.documents.front().filename << " - Relevância: " << ranking.documents.front().relevance << std::endl;

        std::cout << std::endl;
        
        i++;
    }

    std::cout << "--------------------------" << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tempo de execução: " << duration.count() / 60000 << " minutos, " << (duration.count() % 60000) / 1000 << " segundos e " << (duration.count() % 60000) % 1000 << " milissegundos" << std::endl << std::endl;

    return 0;
}