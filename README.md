<a name="readme-topo"></a>

<h1 align='center'>
  📊 Ranqueamento de Documentos - TF/IDF
</h1>

<div align='center'>

[![SO][Ubuntu-badge]][Ubuntu-url]
[![IDE][vscode-badge]][vscode-url]
[![Make][make-badge]][make-url]
[![Linguagem][cpp-badge]][cpp-url]

Algoritmos e Estruturas de Dados II <br>
Engenharia de Computação <br>
Prof. Michel Pires da Silva <br>
CEFET-MG Campus V <br>
2024/2
</div>

<details>
  <summary>
  <b style='font-size: 15px'>
    📑 Sumário
  </b>
  </summary>
  <ol>
    <li><a href="#-introdução">🔍 Introdução</a></li>
    <li>
      <a href="#-fundamentação-teórica">💡 Fundamentação Teórica</a>
    </li>
    <li>
      <a href="#-objetivos">🎯 Objetivos</a>
      <ul>
        <li><a href='#objetivo-geral'>Objetivo Geral</a></li>
        <li><a href='#objetivos-específicos'>Objetivos Específicos</a></li>
      </ul>
    </li>
    <li>
      <a href="#-modelagem-de-aplicação">🔬 Modelagem de Aplicação</a>
    </li>
    <li>
      <a href="#%EF%B8%8F-metodologia">🗳️ Metodologia</a>
      <ul>
        <li><a href='#-arquivos'>Arquivos</a></li>
        <li><a href='#-bibliotecas'>Bibliotecas</a></li>
        <li><a href='#definições-e-estruturas-usadas'>Definições e Estruturas Usadas</a></li>
        <li><a href='#-funções-implementadas'>Funções Implementadas</a></li>
      </ul>
    </li>
    <li>
      <a href="#-testes-e-análises-dos-resultados">📊 Testes e Análises dos Resultados</a>
    </li>
    <li><a href="#-conclusão">🏁 Conclusão</a></li>
    <li>
      <a href="#-começando">🔨 Começando</a>
      <ul>
        <li><a href="#pré-requisitos">Pré-requisitos</a></li>
        <li><a href="#instalando">Instalando</a></li>
      </ul>
    </li>
    <li><a href="#-ambiente-de-compilação-e-execução">🧪 Ambiente de Compilação e Execução</a></li>
    <li><a href="#-contato">📨 Contato</a></li>
    <li><a href="#referencias">📚 Referências</a></li>
  </ol>
</details>

<details> 
  <summary>
    <b style='font-size: 12px'> Abstract </b> 
  </summary>
  Este trabalho tem como objetivo a implementação de um algoritmo de ranqueamento de documentos, utilizando a técnica de ranqueamento TF-IDF. O algoritmo foi implementado em C++ e testado em diferentes cenários, com o intuito de avaliar a eficiência e a precisão do método de ranqueamento. Os resultados obtidos mostram que o algoritmo é capaz de ranquear documentos de forma eficiente porém com alguns problemas de precisão. 
  <br><br>
  🔑 <b>Keywords:</b> TF/IDF, Ranqueamento de Documentos, Implementação.
<br>
</details>

## 🔍 Introdução

<div align='justify'>

  Este [trabalho][trabalho-url] (Ranqueamento de Documentos) foi proposto na disciplina de Algoritmos e Estruturas de Dados II (AEDSII) pelo professor [Michel Pires da Silva][github-prof].

  O ranqueamento de documentos é uma técnica utilizada para ordenar documentos de acordo com sua relevância em relação a uma consulta. A técnica TF-IDF (Term Frequency-Inverse Document Frequency) é uma das mais utilizadas nesse contexto e, por sua simplicidade e eficiência, foi escolhida para ser testada neste trabalho.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 💡 Fundamentação Teórica

<div align='justify'>

 
</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🎯 Objetivos

<div align="justify">

  ### Objetivo Geral
  O objetivo deste trabalho é de, através da utilização das estruturas de dados já estudadas até o momento, implementar um algoritmo de ranqueamento de documentos que lança mão da técnica TF-IDF (Term Frequency-Inverse Document Frequency).

  ### Objetivos Específicos
  - Abordar e reforçar conceitos de análise de algoritmos e estruturas de dados já explorados no contexto da disciplina.
  - Refletir sobre como novas estruturas de dados, como as árvores binárias e os grafos, podem influenciar na resolução do problema proposto e quais ganhos de eficiência poderiam ser alcançados.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🔬 Modelagem de Aplicação 

<div aling='justify'>

</div>

## 🗳️ Metodologia

<div align="justify">

  As abordagens propostas para otimizar o algoritmo de ranqueamento foram implementadas em C++, utilizando a IDE Visual Studio Code para o desenvolvimento do código-fonte. O projeto foi organizado em um diretório principal, contendo subdiretórios para armazenar os arquivos de código-fonte e os `datasets` utilizados. A solução proposta com a aplicação da técnica TF-IDF para o ranqueamento foi dividida em classes, cada uma responsável por uma etapa do processo. A primeira, (`Ranking`)[ranking.hpp], recebe as frases a serem buscadas, armazena as `stopwords` e lê os documentos para criar objetos da classe `Document`, que armazenam os termos normalizados e suas frequências. Após isso, existe a etapa de cálculo da relevância dos termos, através de seus fatores TF/IDF em cada documento. E, por fim, a ordenação dos documentos em ordem decrescente de relevância.

  ### 📁 Arquivos 

  Para a implementação do algoritmo, o projeto foi organizado em um diretório principal, contendo subdiretórios para armazenar os arquivos de código-fonte e os datasets utilizados. A seguir, são apresentados os arquivos e diretórios utilizados no projeto:

  - [`datasets/`](datasets): diretório contendo os datasets utilizados.
    - [`doc1.txt`](datasets/doc1.txt): Primeiro documento a ser consultado, o livro "A Mão e A Luva", de Machado de Assis.
    - [`doc2.txt`](datasets/doc2.txt): Segundo documento a ser consultado, A Bíblia Sagrada.
    - [`doc3.txt`](datasets/doc3.txt): Terceiro documento a ser consultado, o livro "Dom Casmurro", de Machado de Assis.
    - [`doc4.txt`](datasets/doc4.txt): Quarto documento a ser consultado, o livro "Quincas Borba", de Machado de Assis.
    - [`doc5.txt`](datasets/doc5.txt): Quinto documento a ser consultado, o livro "A Semana", de Machado de Assis.
    - [`doc6.txt`](datasets/doc6.txt): Sexto documento a ser consultado, o relato histórico "Relação do formidavel, e lastimoso terremoto succedido no Reino de Valença".
    - [`stopwords.txt`](datasets/stopwords.txt): arquivo contendo as `stopwords` utilizadas da língua portuguesa. Isto é, as palavras que não possuem relevância para o ranqueamento dos documentos.

  - [`src/`](src): diretório contendo os arquivos de código-fonte do projeto.
    - [`document.cpp`](src/document.cpp): Arquivo de código-fonte que contém a implementação dos métodos da classe `Document`, responsável por ler e representar os documentos, além de normalizar os termos que os compõem.
    - [`document.hpp`](src/document.hpp): Arquivo de cabeçalho que contém a definição da classe `Document`, responsável por representar um documento a ser ranqueado.
    - [`main.cpp`](src/main.cpp): arquivo contendo a função principal do programa, responsável por fazer chamadas de funções que realizam  o ranqueamento dos documentos.
    - [`ranking.cpp`](src/ranking.cpp): Arquivo de código-fonte que contém a implementação dos métodos da classe `Ranking`, responsável por ler as frases a serem buscadas, armazenar as `stopwords` e calcular o fator TF/IDF de cada documento para cada termo e ranqueá-los em ordem decrescente.
    - [`ranking.hpp`](src/ranking.hpp): Arquivo de cabeçalho que contém a definição da classe `Ranking`, responsável por ranquear os documentos.

  - [`.gitignore`](.gitignore): arquivo contendo a lista de arquivos e diretórios a serem ignorados pelo Git.
  - [`make.sh`](make.sh): arquivo de script para compilar o código-fonte do projeto.
  - [`makefile`](makefile): arquivo contendo as regras para compilar o código-fonte do projeto.
  - [`README.md`](README.md): arquivo contendo a documentação do projeto.

  De uma forma compacta e organizada, os arquivos e diretórios estão dispostos da seguinte forma:

  ```.
  |
  ├── datasets
  │   │   └── doc1.txt
  │   │   └── doc2.txt
  │   │   └── doc3.txt
  │   │   └── doc4.txt
  │   │   └── doc5.txt
  │   │   └── doc6.txt
  │   │   └── stopwords.txt
  ├── src
  │   │   └── document.cpp
  │   │   └── document.hpp
  │   │   └── main.cpp
  │   │   └── ranking.cpp
  │   │   └── ranking.hpp
  ├── .gitignore
  ├── make.sh
  ├── makefile
  └── README.md
  ```
  
</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

### 📚 Bibliotecas

<div align="justify">

  As bibliotecas utilizadas na implementação do algoritmo LAC são as seguintes:

  - [`bits/stdc++.h`](https://www.geeksforgeeks.org/bitsstdc-h-c-include/): biblioteca que inclui todas as bibliotecas padrão da linguagem C++. Veja abaixo as bibliotecas que usamos da `bits/stdc++.h`:
    - [`iostream`](https://www.cplusplus.com/reference/iostream/): biblioteca padrão de entrada e saída de dados.
    - [`fstream`](https://www.cplusplus.com/reference/fstream/): biblioteca para manipulação de arquivos. 
    - [`string`](https://www.cplusplus.com/reference/string/): biblioteca para manipulação de strings.
    - [`cmath`](https://www.cplusplus.com/reference/cmath/): biblioteca para funções matemáticas.
    - [`vector`](https://www.cplusplus.com/reference/vector/): biblioteca para manipulação de vetores.
    - [`unordered_map`](https://www.cplusplus.com/reference/unordered_map/): biblioteca para manipulação de tabelas hash.
    - [`unordered_set`](https://www.cplusplus.com/reference/unordered_set/): biblioteca para manipulação de conjuntos hash.
    - [`list`](https://cplusplus.com/reference/list/list/): biblioteca para utilização de listas duplamente encadeadas.
  
</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

### Definições e Estruturas Usadas

<div align="justify">


</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🏁 Conclusão

<div  align="justify">

  
</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🔨 Começando

<div align="justify">

  Nesta seção estão exemplificados os meios através dos quais se tornam possíveis a compilação e execução do programa apresentado.

</div>

### Pré-requisitos

<div align="justify">

  Inicialmente, algumas considerações importantes sobre como se deve preparar o ambiente para compilar e executar o programa:

</div>

> [!NOTE]
> Recomenda-se usar uma distribuição de sistema operacional Linux ou o Windows Subsystem for Linux (WSL), pois os comandos no [`makefile`][makefile] foram selecionados para funcionar em um ambiente [_shell/bash_][bash-url].

<div align="justify">

  Considerando um ambiente _shell_, garanta que os seguintes comandos já foram executados:
  - Atualize os pacotes antes da instalação dos compiladores:
  ```console
  sudo apt update
  ```
  - Instale a coleção de compiladores ___GNU/g++___ e o ___make___:
  ```console
  sudo apt install build-essential
  ```
  - Se necessário, instale o ___make___ individualmente:
  ```console
  sudo apt install make
  ```

</div>

### Instalando

<div align="justify">
  Com o ambiente preparado, os seguintes passos são para a instalação, compilação e execução do programa localmente:

  1. Clone o repositório no diretório desejado:
  ```console
  git clone https://github.com/dudatsouza/tf-idf.git
  cd tf-idf
  ```
  2. Compile o programa com o ___make___, o que gera a pasta `build`, que contém arquivos de objeto e um arquivo executável:
  ```console
  make
  ```
  3. Execute o programa da pasta `build` após a compilação:
  ```console
  make run
  ```

  4. Se necessário, apague a última compilação da pasta `build`:
  ```console
  make clean
  ```

  O programa estará pronto para ser testado. Veja a tabela abaixo com alguns comandos do makefile:

</div>

<div align="center">

  | Comando      | **Descrição**                           |
  |--------------|-----------------------------------------|
  | `make`       | Compila o programa.                     |
  | `make run`   | Executa o programa com o arquivo de entrada fornecido. |
  | `make clean` | Remove os arquivos compilados.          |

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🧪 Ambiente de Compilação e Execução

<div align="justify">

  O trabalho foi desenvolvido e testado em várias configurações de hardware. Podemos destacar algumas configurações de Sistema Operacional e Compilador, pois as demais configurações não influenciam diretamente no desempenho do programa.

</div>

<div align='center'>

![Ubuntu][ubuntu-badge]
![GCC][gcc-badge]
![Make][make-badge] 

| **Hardware** | **Especificações** |
|:------------:|:-------------------:|
| **Laptop**   | Dell Inspiron 13 5330 |
| **Processador** | Intel Core i7-1360P |
| **Memória RAM** | 16 GB DDR5 |
| **Sistema Operacional** | Windows 11 |
| **IDE** | Visual Studio Code |
| **Placa de Vídeo** | Intel Iris Xe Graphics |

</div>

> [!IMPORTANT] 
> Para que os testes tenham validade, considere as especificações
> do ambiente de compilação e execução do programa.

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 📨 Contato

<div align="center">
  <br><br>
     <i>Guilherme Alvarenga de Azevedo - Graduando - 4º Período de Engenharia de Computação @ CEFET-MG</i>
  <br><br>
  
  [![Gmail][gmail-badge]][gmail-autor1]
  [![Linkedin][linkedin-badge]][linkedin-autor1]
  [![Telegram][telegram-badge]][telegram-autor1]
  
  
  <br><br>
     <i>Maria Eduarda Teixeira Souza - Graduando - 4º Período de Engenharia de Computação @ CEFET-MG</i>
  <br><br>
  
  [![Gmail][gmail-badge]][gmail-autor2]
  [![Linkedin][linkedin-badge]][linkedin-autor2]
  [![Telegram][telegram-badge]][telegram-autor2]
  
  <br><br>
     <i>Matheus Emanuel da Silva - Graduando - 4º Período de Engenharia de Computação @ CEFET-MG</i>
  <br><br>
  
  [![Gmail][gmail-badge]][gmail-autor3]
  [![Linkedin][linkedin-badge]][linkedin-autor3]
  [![Telegram][telegram-badge]][telegram-autor3]

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

<a name="referencias">📚 Referências</a>



[vscode-badge]: https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white
[vscode-url]: https://code.visualstudio.com/docs/?dv=linux64_deb
[make-badge]: https://img.shields.io/badge/_-MAKEFILE-427819.svg?style=for-the-badge
[make-url]: https://www.gnu.org/software/make/manual/make.html
[cpp-badge]: https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white
[cpp-url]: https://en.cppreference.com/w/cpp
[trabalho-url]: https://drive.google.com/file/d/1-IHbGaA1BIC6_CMBydOC-NbV2bCERc8r/view?usp=sharing
[github-prof]: https://github.com/mpiress
[main-ref]: src/main.cpp
[branchAMM-url]: https://github.com/alvarengazv/trabalhosAEDS1/tree/AlgoritmosMinMax
[makefile]: ./makefile
[bash-url]: https://www.hostgator.com.br/blog/o-que-e-bash/
[lenovo-badge]: https://img.shields.io/badge/lenovo%20laptop-E2231A?style=for-the-badge&logo=lenovo&logoColor=white
[ubuntu-badge]: https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white
[Ubuntu-url]: https://ubuntu.com/
[ryzen5500-badge]: https://img.shields.io/badge/AMD%20Ryzen_5_5500U-ED1C24?style=for-the-badge&logo=amd&logoColor=white
[ryzen3500-badge]: https://img.shields.io/badge/AMD%20Ryzen_5_3500X-ED1C24?style=for-the-badge&logo=amd&logoColor=white
[windows-badge]: https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white
[gcc-badge]: https://img.shields.io/badge/GCC-5C6EB8?style=for-the-badge&logo=gnu&logoColor=white


[linkedin-autor1]: https://www.linkedin.com/in/guilherme-alvarenga-de-azevedo-959474201/
[telegram-autor1]: https://t.me/alvarengazv
[gmail-autor1]: mailto:gui.alvarengas234@gmail.com

[linkedin-autor2]: https://www.linkedin.com/in/dudatsouza/
[telegram-autor2]: https://t.me/dudat_18
[gmail-autor2]: mailto:dudateixeirasouza@gmail.com

[linkedin-autor3]: https://www.linkedin.com/
[telegram-autor3]: https://t.me/
[gmail-autor3]: mailto:memanuel643@gmail.com

[linkedin-badge]: https://img.shields.io/badge/-LinkedIn-0077B5?style=for-the-badge&logo=Linkedin&logoColor=white
[telegram-badge]: https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white
[gmail-badge]: https://img.shields.io/badge/-Gmail-D14836?style=for-the-badge&logo=Gmail&logoColor=white
