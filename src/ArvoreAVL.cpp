#include "ArvoreAVL.hpp"
#include <algorithm>

NoAVL::NoAVL(const string& p) : palavra(p), altura(1), esquerdo(nullptr), direito(nullptr) {}

ArvoreAVL::ArvoreAVL() : raiz(nullptr) {}

// Função de inserção na árvore AVL
void ArvoreAVL::inserir(const string& palavra) {
    raiz = inserir(raiz, palavra);
}

NoAVL* ArvoreAVL::inserir(NoAVL* no, const string& palavra) {
    if (no == nullptr) {
        return new NoAVL(palavra);
    }

    if (palavra < no->palavra) {
        no->esquerdo = inserir(no->esquerdo, palavra);
    } else if (palavra > no->palavra) {
        no->direito = inserir(no->direito, palavra);
    } else {
        return no; // Ignora duplicatas
    }

    no->altura = 1 + max(altura(no->esquerdo), altura(no->direito));
    int balanceamento = obterBalanceamento(no);

    // Rotacionar se estiver desbalanceado
    if (balanceamento > 1 && palavra < no->esquerdo->palavra)
        return rotacionarDireita(no);

    if (balanceamento < -1 && palavra > no->direito->palavra)
        return rotacionarEsquerda(no);

    if (balanceamento > 1 && palavra > no->esquerdo->palavra) {
        no->esquerdo = rotacionarEsquerda(no->esquerdo);
        return rotacionarDireita(no);
    }

    if (balanceamento < -1 && palavra < no->direito->palavra) {
        no->direito = rotacionarDireita(no->direito);
        return rotacionarEsquerda(no);
    }

    return no;
}

// Função para autocompletar
vector<string> ArvoreAVL::autocompletar(const string& prefixo) {
    vector<string> sugestoes;
    autocompletar(raiz, prefixo, sugestoes);
    return sugestoes;
}

void ArvoreAVL::autocompletar(NoAVL* no, const string& prefixo, vector<string>& sugestoes) {
    if (no == nullptr) return;

    if (no->palavra.find(prefixo) == 0) {
        sugestoes.push_back(no->palavra);
    }

    if (prefixo < no->palavra) {
        autocompletar(no->esquerdo, prefixo, sugestoes);
    } else {
        autocompletar(no->direito, prefixo, sugestoes);
    }
}

// Funções auxiliares de balanceamento e altura
int ArvoreAVL::altura(NoAVL* no) {
    return no == nullptr ? 0 : no->altura;
}

int ArvoreAVL::obterBalanceamento(NoAVL* no) {
    return no == nullptr ? 0 : altura(no->esquerdo) - altura(no->direito);
}

NoAVL* ArvoreAVL::rotacionarDireita(NoAVL* y) {
    NoAVL* x = y->esquerdo;
    NoAVL* T2 = x->direito;

    x->direito = y;
    y->esquerdo = T2;

    y->altura = max(altura(y->esquerdo), altura(y->direito)) + 1;
    x->altura = max(altura(x->esquerdo), altura(x->direito)) + 1;

    return x;
}

NoAVL* ArvoreAVL::rotacionarEsquerda(NoAVL* x) {
    NoAVL* y = x->direito;
    NoAVL* T2 = y->esquerdo;

    y->esquerdo = x;
    x->direito = T2;

    x->altura = max(altura(x->esquerdo), altura(x->direito)) + 1;
    y->altura = max(altura(y->esquerdo), altura(y->direito)) + 1;

    return y;
}
