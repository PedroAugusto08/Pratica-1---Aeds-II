<h1 align="center" font-size="200em"><b>Prática</b></h1>
<h1 align="center" font-size="100em"><b>Árvore Binária</b></h1>


<p align="center">

## Introdução
Este projeto é uma implementação de uma estrutura de árvore binária em C++ com funcionalidades avançadas, incluindo inserção e remoção de nós, cálculo do nível máximo da árvore, determinação do caminho mais longo e sugestões de rotações para balanceamento da árvore.
</p>

## Objetivos 🎯
Este projeto tem como objetivo explorar e aplicar conceitos de estruturas de dados, especialmente árvores binárias, em C++. Os objetivos principais incluem:

**Implementação de Estruturas de Dados Dinâmicas**: Desenvolver uma árvore binária em C++, aprofundando o entendimento sobre estruturas de dados dinâmicas e seus usos em organização e recuperação eficiente de dados.

**Prática de Algoritmos de Inserção, Remoção e Pesquisa**: Implementar e otimizar algoritmos fundamentais para a manipulação de árvores binárias, incluindo inserção de novos nós, remoção de nós existentes e busca de valores específicos.

**Exploração de Conceitos de Balanceamento de Árvore**: Analisar o comportamento de árvores desbalanceadas versus balanceadas, compreendendo como a estrutura afeta a eficiência de operações de busca. Adicionalmente, desenvolver uma abordagem para sugerir rotações de balanceamento, introduzindo o conceito de árvores balanceadas.

**Cálculo de Caminhos e Profundidade da Árvore**: Implementar métodos para calcular o caminho mais longo da árvore e a profundidade máxima, analisando como a estrutura da árvore influencia na altura e profundidade máxima.

**Preparação para Estruturas Mais Complexas**: Este projeto serve como base para o estudo de árvores balanceadas automaticamente, como as árvores AVL, onde o balanceamento é realizado por rotações automáticas após inserções e remoções.

Este projeto, além de fornecer uma base sólida para o entendimento de árvores binárias, também permite aprofundar-se em técnicas de manipulação de dados e otimização de estruturas, habilidades essenciais para programação de sistemas eficientes.
</p>

## Estrutura de Arquivos 📂 
O código é dividido em três arquivos principais:

`main.cpp`: Contém a lógica principal do programa e exemplos de uso da árvore binária.
`Node.hpp`: Define a estrutura básica do nó da árvore, com atributos para armazenar o valor do nó e ponteiros para os nós filhos.
`ArvoreBinaria.h` e `ArvoreBinaria.cpp`: Contêm a implementação da classe ArvoreBinaria, que possui métodos para inserção, remoção, balanceamento e outras operações na árvore.



├── `main.cpp`              -> Lógica principal do programa e exemplos de uso

├── `Node.hpp`                -> Estrutura básica do nó da árvore

├── `ArvoreBinaria.hpp`       -> Declaração da classe ArvoreBinaria e seus métodos

├── `ArvoreBinaria.cpp`     -> Implementação da classe ArvoreBinaria

└── `README.md`             -> Documentação do projeto


## Descrição do Código 📖

O projeto conta com diversas funções essenciais para a manipulação da árvore binária, que permitem realizar operações de inserção, remoção, cálculo de nível, e até sugestões de rotações. Vamos entender cada uma delas:

1. Função `inserir(int valor)`
- Insere um novo valor na árvore.
- Chama a função recursiva inserirRecursivo para realizar a inserção correta na árvore binária.
- Após a inserção, a função calcula e atualiza o nível máximo da árvore.
- Exibe o nível máximo após a inserção para monitoramento.
2. Função `remover(int valor)`
- Remove um valor específico da árvore.
- Utiliza a função removerRecursivo para encontrar e remover o nó.
- Após a remoção, recalcula o nível máximo da árvore e exibe o valor atualizado.
3. Função `obterNivelMaximo()`
- Retorna o nível máximo atual da árvore.
- Chama a função calcularNivelMaximo, que calcula a profundidade máxima a partir da raiz.
4. Função `encontrarCaminhoMaisLongo()`
- Retorna um vetor contendo o caminho mais longo da raiz até a folha mais distante.
- Usa a função encontrarCaminhoMaisLongoRecursivo para percorrer a árvore e encontrar o caminho com o maior número de nós.
- Esse caminho pode ser útil para verificar o grau de balanceamento da árvore.
5. Função `sugerirRotacoes()`
- Exibe sugestões de rotações para melhorar o balanceamento da árvore.
- Utiliza a função sugerirRotacoesRecursivo para percorrer a árvore e verificar a diferença de profundidade entre subárvores de cada nó.
- Caso a diferença de profundidade entre os ramos esquerdo e direito de um nó seja maior que 1, o programa sugere uma rotação nesse nó.
6. Função `inserirRecursivo(Node* node, int valor)`
- Função auxiliar chamada pela inserir().
- Insere o valor recursivamente, seguindo a regra de árvores binárias: valores menores vão para a esquerda e valores maiores para a direita.
7. Função `removerRecursivo(Node* node, int valor)`
- Função auxiliar chamada pela remover().
- Procura o valor a ser removido na árvore e realiza a remoção adequada.
- Lida com os três casos de remoção: nó folha, nó com um único filho, e nó com dois filhos.
8. Função `encontrarMinimo(Node* node)`
- Retorna o nó com o menor valor na subárvore dada.
- Essa função é usada principalmente durante a remoção de um nó com dois filhos, pois substitui o valor do nó removido pelo valor mínimo da subárvore direita.
9. Função `calcularNivelMaximo(Node* node, int nivel = 0)`
- Calcula a profundidade máxima da árvore, usada para medir o nível máximo a partir da raiz.
- Executa uma busca recursiva, calculando o nível máximo em cada ramo e retornando o valor mais alto.
10. Função `encontrarCaminhoMaisLongoRecursivo(Node* node, vector<int>& caminho_atual, vector<int>& caminho_mais_longo)`
- Função auxiliar que percorre recursivamente a árvore, construindo o caminho mais longo.
- Armazena temporariamente o caminho atual e substitui o caminho_mais_longo quando encontra um novo caminho maior.
11. Função `sugerirRotacoesRecursivo(Node* node)`
- Função auxiliar para sugerir rotações de balanceamento.
- Calcula a profundidade dos ramos esquerdo e direito e, se houver um desbalanceamento (diferença de profundidade maior que 1), sugere uma rotação no nó atual.
- Essa função pode ajudar a identificar partes da árvore que estão desbalanceadas e precisam de ajustes.

## Observações e questionamentos 💭

1. `A prerrogativa de custo de 39% de depreciação ocorre em árvores não balanceadas em comparação com árvores balanceadas?`
</p>

O desempenho de busca em uma árvore binária de busca depende muito do quão bem balanceada ela está. Em uma árvore balanceada, operações como busca, inserção e remoção têm um custo médio proporcional a 𝑂(log 𝑛), onde 𝑛 é o número de nós. Já em uma árvore não balanceada, o custo sobe para 𝑂(𝑛).

Estudos e análises experimentais sugerem que, em média, árvores desbalanceadas podem sofrer uma redução de desempenho de aproximadamente 39% em operações de busca. Essa depreciação ocorre porque, em uma árvore desbalanceada, muitos nós podem ser acessados antes de encontrar o elemento desejado, aumentando significativamente o número de comparações.

Embora esse número varie dependendo do grau de desbalanceamento, o impacto no desempenho é sempre significativo quanto maior for a desorganização da árvore.

</p>


2. `Como o desbalanceamento afeta o comprimento do caminho em comparação com uma árvore idealmente balanceada?`
</p>

- **Árvore Balanceada**: Em uma árvore idealmente balanceada, a altura da árvore é minimizada e segue aproximadamente log2(n+1). Isso reduz a profundidade média dos nós, permitindo buscas e outras operações em tempo logarítmico.
</p>

- **Árvore desbalanceada**: Quando uma árvore está desbalanceada, sua altura pode se aproximar de 𝑛, especialmente se ela degenerar em uma lista. Isso aumenta o comprimento médio dos caminhos e, consequentemente, o número de comparações realizadas para encontrar um elemento. Operações como busca, inserção e remoção tornam-se mais custosas, pois a árvore perde sua eficiência logarítmica.

---

<h1 align="center" font-size="100em"><b>Dicionário Eletrônico</b></h1>

<p align="center">

## Introdução
Este projeto implementa uma árvore AVL em C++ que realiza operações de autocompletar com base em um dicionário de palavras. A árvore AVL é uma estrutura de dados balanceada que permite inserção, busca e sugestão de palavras de forma eficiente, ideal para aplicações onde o desempenho é essencial, como sistemas de autocompletar.
</p>

## Objetivos 🎯

**Implementar Autocompletar Eficiente**: Usar a árvore AVL para sugerir palavras rapidamente com base em um prefixo fornecido pelo usuário.

**Manter Estrutura Balanceada**: Garantir que a árvore AVL esteja balanceada, melhorando a eficiência das buscas mesmo com grandes volumes de dados.

**Carregar Dados de um Dicionário**: Ler palavras de um arquivo .txt e organizá-las na árvore AVL de forma estruturada.

**Exibir Sugestões de Palavras**: Listar todas as palavras que começam com o prefixo digitado, ajudando o usuário a encontrar palavras mais rapidamente.

**Interface de Linha de Comando**: Oferecer uma interface simples para escolher funcionalidades como inserir e autocompletar.

**Ensinar Estruturas de Dados na Prática**: Demonstrar como árvores AVL podem resolver problemas reais, como o autocompletar, de maneira didática.
</p>

## Estrutura de Arquivos 📂 

├── main.cpp              -> Menu principal e exemplo de uso do dicionário e árvore de valores

├── ArvoreAVL.hpp         -> Declaração da classe ArvoreAVL para autocompletar

├── ArvoreAVL.cpp         -> Implementação da classe ArvoreAVL

## Descrição do Código 📖

**`Arquivo ArvoreAVL.hpp`**
</p>

Define a estrutura da árvore AVL e os métodos principais utilizados para inserir palavras e sugerir autocompletar. As principais seções são:

- *Estrutura NoAV*: Representa cada nó da árvore, contendo a palavra, altura do nó, e ponteiros para os filhos esquerdo e direito.
- *Classe ArvoreAVL*: Gerencia a árvore AVL e implementa métodos essenciais:
- `inserir(const string& palavra)`: Insere uma nova palavra na árvore e realiza balanceamento se necessário.
- `autocompletar(const string& prefixo)`: Recebe um prefixo e retorna uma lista de palavras que começam com esse prefixo.
</p>

**`Arquivo ArvoreAVL.cpp`**
</p>

Implementa a lógica das funções definidas em ArvoreAVL.hpp, incluindo as operações de balanceamento AVL e a função de autocompletar. As principais funções incluem:

Funções de Balanceamento:
- `altura(NoAVL* no)`: Retorna a altura de um nó.
- `obterBalanceamento(NoAVL* no)`: Calcula o fator de balanceamento para determinar se é necessário realizar rotações.
- `rotacionarDireita e rotacionarEsquerda`: Realizam rotações para balancear a árvore.
- `Função autocompletar`: Recebe um nó, um prefixo e uma referência para o vetor de sugestões. Percorre a árvore e armazena palavras que começam com o prefixo.

## Observações e Questionamentos 💭

1. `Discuta a eficiência do autocompletar utilizando a árvore binária e apresente uma análise comparativa em termos de tempo de busca para diferentes tamanhos de dicionário`

O autocompletar com uma árvore AVL é eficiente devido ao balanceamento, que garante um tempo de busca proporcional a 𝑂(log 𝑛), mesmo em dicionários grandes. Em árvores desbalanceadas, o tempo pode chegar a 𝑂(𝑛), tornando a busca mais lenta à medida que o dicionário cresce.

A AVL também organiza palavras de forma ordenada, permitindo localizar rapidamente palavras com o mesmo prefixo. Para dicionários maiores, essa estrutura se destaca por oferecer buscas muito mais rápidas e consistentes em comparação a árvores desbalanceadas.

## Compilação e Execução 💻

 Especificações da máquina em que o código foi rodado:
  * Processador Intel i5-11400H;
  * Sistema Operacional Ubuntu 22.04.01;
  * 16 GB de RAM.
* | Comando                | Função                                                                                            |       
  | -----------------------| ------------------------------------------------------------------------------------------------- |
  |  `make clean`          | Apaga a última compilação realizada contida na pasta build.                                       |
  |  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.          |
  |  `make run`            | Executa o programa da pasta build após a realização da compilação.                                |

---

## Autor

**Pedro Augusto Moura**  
[![Static Badge](https://img.shields.io/badge/%7C%20PedroAugusto08-black?style=flat-square&logo=github)](https://github.com/PedroAugusto08)
[![Static Badge](https://img.shields.io/badge/%7C%20pedroaugustomoura70927%40gmail.com-black?style=flat-square&logo=gmail)](mailto:pedroaugustomoura70927@gmail.com)

<!---
✉️ pedroaugustomoura70927@gmail.com (**Pedro Augusto Moura**)