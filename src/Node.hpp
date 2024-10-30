#ifndef NODE_H
#define NODE_H

class Node {
public:
    int valor;
    Node* esquerda;
    Node* direita;

    Node(int val) : valor(val), esquerda(nullptr), direita(nullptr) {}
};

#endif