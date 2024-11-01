#include "ArvoreBinaria.hpp"

void ArvoreBinaria::inserir(int valor) {
    raiz = inserirRecursivo(raiz, valor);
    nivel_maximo = calcularNivelMaximo(raiz);
    cout << "Nível máximo após inserção: " << nivel_maximo << endl;
}

void ArvoreBinaria::remover(int valor) {
    raiz = removerRecursivo(raiz, valor);
    nivel_maximo = calcularNivelMaximo(raiz);
    cout << "Nível máximo após remoção: " << nivel_maximo << endl;
}

int ArvoreBinaria::obterNivelMaximo() const {
    return calcularNivelMaximo(raiz);
}

vector<int> ArvoreBinaria::encontrarCaminhoMaisLongo() {
    vector<int> caminho;
    vector<int> caminho_mais_longo;
    encontrarCaminhoMaisLongoRecursivo(raiz, caminho, caminho_mais_longo);
    return caminho_mais_longo;
}

void ArvoreBinaria::sugerirRotacoes() {
    cout << "Sugestões de rotações para reduzir a profundidade:" << endl;
    sugerirRotacoesRecursivo(raiz);
}

Node* ArvoreBinaria::inserirRecursivo(Node* node, int valor) {
    if (!node) return new Node(valor);
    if (valor < node->valor)
        node->esquerda = inserirRecursivo(node->esquerda, valor);
    else
        node->direita = inserirRecursivo(node->direita, valor);
    return node;
}

Node* ArvoreBinaria::removerRecursivo(Node* node, int valor) {
    if (!node) return nullptr;
    if (valor < node->valor) {
        node->esquerda = removerRecursivo(node->esquerda, valor);
    } else if (valor > node->valor) {
        node->direita = removerRecursivo(node->direita, valor);
    } else {
        if (!node->esquerda) return node->direita;
        if (!node->direita) return node->esquerda;
        Node* menor_node_maior = encontrarMinimo(node->direita);
        node->valor = menor_node_maior->valor;
        node->direita = removerRecursivo(node->direita, menor_node_maior->valor);
    }
    return node;
}

Node* ArvoreBinaria::encontrarMinimo(Node* node) {
    while (node->esquerda) node = node->esquerda;
    return node;
}

int ArvoreBinaria::calcularNivelMaximo(Node* node, int nivel) const {
    if (!node) return nivel - 1;
    int nivel_esquerda = calcularNivelMaximo(node->esquerda, nivel + 1);
    int nivel_direita = calcularNivelMaximo(node->direita, nivel + 1);
    return max(nivel_esquerda, nivel_direita);
}

void ArvoreBinaria::encontrarCaminhoMaisLongoRecursivo(Node* node, vector<int>& caminho_atual, vector<int>& caminho_mais_longo) {
    if (!node) {
        if (caminho_atual.size() > caminho_mais_longo.size()) {
            caminho_mais_longo = caminho_atual;
        }
        return;
    }
    caminho_atual.push_back(node->valor);
    encontrarCaminhoMaisLongoRecursivo(node->esquerda, caminho_atual, caminho_mais_longo);
    encontrarCaminhoMaisLongoRecursivo(node->direita, caminho_atual, caminho_mais_longo);
    caminho_atual.pop_back();
}
