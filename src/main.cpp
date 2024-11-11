#include "ArvoreBinaria.hpp"
#include "ArvoreAVL.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Função para carregar o dicionário do arquivo para a árvore AVL
void carregarDicionarioDeArquivo(ArvoreAVL& arvore, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string palavra;

    if (arquivo.is_open()) {
        while (getline(arquivo, palavra)) {
            arvore.inserir(palavra);  // Insere cada palavra na árvore AVL
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo de dicionário: " << nomeArquivo << endl;
    }
}

int main() {
    int escolha;
    cout << "Escolha o programa que deseja executar:" << endl;
    cout << "1 - Programa de árvore binária com funcionalidades de balanceamento" << endl;
    cout << "2 - Programa de autocompletar usando árvore AVL" << endl;
    cin >> escolha;

    if (escolha == 1) {
        ArvoreBinaria arvore;
        int valor;
        int opcao;

        cout << "Escolha uma operação para a Árvore Binária:\n";
        cout << "1. Inserir valor\n";
        cout << "2. Remover valor\n";
        cout << "3. Exibir caminho mais longo\n";
        cout << "4. Sugerir rotações\n";
        cout << "0. Voltar ao menu principal\n";

        while (true) {
            cout << "Opção: ";
            cin >> opcao;

            if (opcao == 1) {
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                arvore.inserir(valor);
            } else if (opcao == 2) {
                cout << "Digite o valor a ser removido: ";
                cin >> valor;
                arvore.remover(valor);
            } else if (opcao == 3) {
                vector<int> caminho_mais_longo = arvore.encontrarCaminhoMaisLongo();
                cout << "Caminho mais longo: ";
                for (int val : caminho_mais_longo) cout << val << " ";
                cout << endl;
            } else if (opcao == 4) {
                arvore.sugerirRotacoes();
            } else if (opcao == 0) {
                break;
            } else {
                cout << "Opção inválida! Tente novamente.\n";
            }
        }
    } else if (escolha == 2) {
        ArvoreAVL arvoreAVL;
        string nomeArquivo = "datasets/dicionario.txt";

        // Carrega o dicionário do arquivo para a árvore AVL
        carregarDicionarioDeArquivo(arvoreAVL, nomeArquivo);

        string prefixo;
        cout << "Digite o prefixo para sugestões: ";
        while (true) {
            cin >> prefixo;
            if (prefixo == "sair") {
                break; // Encerra o programa se o usuário digitar "sair"
            }

            vector<string> sugestoes = arvoreAVL.autocompletar(prefixo);
            
            if (sugestoes.empty()) {
                cout << "Nenhuma palavra encontrada para o prefixo '" << prefixo << "'." << endl;
            } else {
                cout << "Sugestões para '" << prefixo << "':" << endl;
                for (const string& sugestao : sugestoes) {
                    cout << sugestao << endl;
                }
            }

            cout << "\nDigite o prefixo para sugestões (ou 'sair' para sair): ";
        }
    }

    return 0;
}
