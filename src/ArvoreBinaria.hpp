#ifndef ARVORE_BINARIA_HPP
#define ARVORE_BINARIA_HPP

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.hpp"

class ArvoreBinaria {
public:
    ArvoreBinaria() : raiz(nullptr) {}

    void inserir(int valor);
    void remover(int valor);
    int obterNivelMaximo() const;
    vector<int> encontrarCaminhoMaisLongo();
    void sugerirRotacoes();

private:
    Node* raiz;
    int nivel_maximo = 0;

    Node* inserirRecursivo(Node* node, int valor);
    Node* removerRecursivo(Node* node, int valor);
    Node* encontrarMinimo(Node* node);
    int calcularNivelMaximo(Node* node, int nivel = 0) const;
    void encontrarCaminhoMaisLongoRecursivo(Node* node, vector<int>& caminho_atual, vector<int>& caminho_mais_longo);
    void sugerirRotacoesRecursivo(Node* node);
};

#endif