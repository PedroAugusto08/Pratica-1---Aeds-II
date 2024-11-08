#include "ArvoreBinaria.hpp"
#include "ArvoreAVL.hpp"
#include <iostream>
#include <vector>
#include <string>

void menuArvoreBinaria();
void menuAutocompletar();

int main() {
    int escolha;

    while (true) {
        cout << "Escolha uma opção:\n";
        cout << "1. Manipulação da Árvore Binária\n";
        cout << "2. Sistema de Autocompletar\n";
        cout << "0. Sair\n";
        cout << "Opção: ";
        cin >> escolha;
        cin.ignore();

        if (escolha == 1) {
            menuArvoreBinaria();
        } else if (escolha == 2) {
            menuAutocompletar();
        } else if (escolha == 0) {
            cout << "Encerrando o programa.\n";
            break;
        } else {
            cout << "Opção inválida! Tente novamente.\n";
        }
    }

    return 0;
}

void menuArvoreBinaria() {
    ArvoreBinaria arvore;
    int valor;
    int escolha;

    cout << "Escolha uma operação para a Árvore Binária:\n";
    cout << "1. Inserir valor\n";
    cout << "2. Remover valor\n";
    cout << "3. Exibir caminho mais longo\n";
    cout << "4. Sugerir rotações\n";
    cout << "0. Voltar ao menu principal\n";

    while (true) {
        cout << "Opção: ";
        cin >> escolha;

        if (escolha == 1) {
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            arvore.inserir(valor);
        } else if (escolha == 2) {
            cout << "Digite o valor a ser removido: ";
            cin >> valor;
            arvore.remover(valor);
        } else if (escolha == 3) {
            vector<int> caminho_mais_longo = arvore.encontrarCaminhoMaisLongo();
            cout << "Caminho mais longo: ";
            for (int val : caminho_mais_longo) cout << val << " ";
            cout << endl;
        } else if (escolha == 4) {
            arvore.sugerirRotacoes();
        } else if (escolha == 0) {
            break;
        } else {
            cout << "Opção inválida! Tente novamente.\n";
        }
    }
}

void menuAutocompletar() {
    ArvoreAVL dicionario;
    string prefixo;

    // Inserir algumas palavras para o exemplo de autocompletar
    dicionario.inserir("maçã");
    dicionario.inserir("apetite");
    dicionario.inserir("aplicativo");
    dicionario.inserir("banana");
    dicionario.inserir("banda");
    dicionario.inserir("largura_de_banda");
    dicionario.inserir("morcego");
    dicionario.inserir("batman");
    dicionario.inserir("batalha");

    cout << "Digite um prefixo para buscar sugestões (ou 'sair' para voltar ao menu principal):" << endl;

    while (true) {
        cout << "Prefixo: ";
        getline(cin, prefixo);

        if (prefixo == "sair") {
            break;
        }

        vector<string> sugestoes = dicionario.autocompletar(prefixo);

        cout << "Sugestões para \"" << prefixo << "\":" << endl;
        if (sugestoes.empty()) {
            cout << "Nenhuma sugestão encontrada." << endl;
        } else {
            for (const string& palavra : sugestoes) {
                cout << "- " << palavra << endl;
            }
        }
    }
}
