#ifndef ARVOREAVL_HPP
#define ARVOREAVL_HPP

#include <string>
#include <vector>

using namespace std;

// Estrutura do nó AVL
struct NoAVL {
    string palavra;
    int altura;
    NoAVL* esquerdo;
    NoAVL* direito;

    NoAVL(const string& p);
};

// Classe da árvore AVL
class ArvoreAVL {
public:
    ArvoreAVL();
    void inserir(const string& palavra);
    vector<string> autocompletar(const string& prefixo);

private:
    NoAVL* raiz;
    NoAVL* inserir(NoAVL* no, const string& palavra);
    void autocompletar(NoAVL* no, const string& prefixo, vector<string>& sugestoes);
    int altura(NoAVL* no);
    int obterBalanceamento(NoAVL* no);
    NoAVL* rotacionarDireita(NoAVL* y);
    NoAVL* rotacionarEsquerda(NoAVL* x);
};

#endif // ARVOREAVL_H
