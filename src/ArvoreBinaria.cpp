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