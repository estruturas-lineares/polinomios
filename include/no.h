#ifndef NO_H
#define NO_H
#include <iostream>

class No{
    int base;
    int expoente;
    No *proximo;

    public:
    No(int b, int e);
    No* getProximo();
    void setProximo(No *proximoNo);
    int getBase();
    void setBase(int novaBase);
    int getExpoente();
    void setExpoente(int novoExpoente);
};

#endif

