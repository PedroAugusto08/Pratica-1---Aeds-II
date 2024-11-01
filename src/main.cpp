#include "ArvoreBinaria.hpp"
#include <iostream>
#include <vector>

int main() {
    ArvoreBinaria arvore;

    // Conjunto 1: Inserções desbalanceadas
    vector<int> insercoes_desbalanceadas = {10, 5, 1, 7, 20, 30, 25, 40};
    cout << "Inserindo nós para criar uma árvore desbalanceada:" << endl;
    for (int valor : insercoes_desbalanceadas) {
        arvore.inserir(valor);
    }

    // Exibe o caminho mais longo
    vector<int> caminho_mais_longo = arvore.encontrarCaminhoMaisLongo();
    cout << "Caminho mais longo na árvore desbalanceada: ";
    for (int val : caminho_mais_longo) cout << val << " ";
    cout << endl;

    // Sugere rotações
    arvore.sugerirRotacoes();

    // Conjunto 2: Inserções mais equilibradas
    ArvoreBinaria arvore_balanceada;
    vector<int> insercoes_balanceadas = {15, 10, 20, 8, 12, 17, 25, 5, 9, 11, 13, 16, 18, 23, 27};
    cout << "\nInserindo nós para criar uma árvore mais balanceada:" << endl;
    for (int valor : insercoes_balanceadas) {
        arvore_balanceada.inserir(valor);
    }

    // Exibe o caminho mais longo
    caminho_mais_longo = arvore_balanceada.encontrarCaminhoMaisLongo();
    cout << "Caminho mais longo na árvore balanceada: ";
    for (int val : caminho_mais_longo) cout << val << " ";
    cout << endl;

    // Sugere rotações
    arvore_balanceada.sugerirRotacoes();

    return 0;
}
