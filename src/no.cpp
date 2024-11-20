#include "../include/no.h"

No::No(int b, int e){
    base = b;
    expoente = e;
    proximo = nullptr;
}

No* No::getProximo(){
    return proximo;
};
void No::setProximo(No *proximoNo){
    proximo = proximoNo;
}
int No::getBase(){
    return base;
}
void No::setBase(int novaBase){
    base = novaBase;
}

int No::getExpoente(){
    return expoente;
}
void No::setExpoente(int novoExpoente){
    expoente = novoExpoente;
}
