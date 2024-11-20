#include "../include/polinomio.h"
#include "../include/no.h"
#include <iostream>
using namespace std;

int Polinomio::grau_polinomio(No *no_item){
    return no_item->getExpoente();
};

Polinomio* Polinomio::adicao( Polinomio poli2){
    No *ponteiro_atual_p1 = cabeca;
    No *ponteiro_atual_p2 = poli2.cabeca;

    //nova lista com resultado
    Polinomio *resultado;
    while (ponteiro_atual_p1 != nullptr && ponteiro_atual_p2 !=nullptr){
        if (ponteiro_atual_p1->getExpoente() == ponteiro_atual_p2->getExpoente()){
            int soma_bases = ponteiro_atual_p1->getBase() + ponteiro_atual_p2->getBase();
            No no1(soma_bases, ponteiro_atual_p1->getExpoente());
            No *no = &no1;
            resultado->inserir_fim(no);
            cout << "adicionado";
        }else{
            resultado->inserir_fim(ponteiro_atual_p1);
        }

        ponteiro_atual_p1 = ponteiro_atual_p1->getProximo();
        ponteiro_atual_p2 = ponteiro_atual_p2->getProximo();
    }

    return resultado;

};

//retornar como string depois
void Polinomio::exibir(){
    No *ponteiro_atual = cabeca;
    while(ponteiro_atual != nullptr){
        cout << ponteiro_atual->getBase() << "x" << ponteiro_atual->getExpoente() << " -> ";
        ponteiro_atual = ponteiro_atual->getProximo();
    }

}
