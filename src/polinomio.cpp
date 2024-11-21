#include "../include/polinomio.h"
#include "../include/no.h"
#include <iostream>
using namespace std;

int Polinomio::grau_polinomio(No *no_item){
    return no_item->getExpoente();
};

// void Polinomio::combinar_termos(){
//     if (!cabeca) return;


//     No* atual = cabeca;
//     No* prev = nullptr;

//     while(atual){
//         No* runner = atual;
//         while(runner->getProximo()){
//             if (runner->getProximo()->getExpoente() == atual->getExpoente()){
//                 atual->setBase(atual->getBase() + runner->getProximo()->getBase());
//                 No* temp = runner->getProximo();
//                 runner->setProximo(runner->getProximo()->getProximo());
//                 delete temp;
//             }
//             else
//                 runner = runner->getProximo();
//         }

//         if (atual->getBase() == 0){
//             No* temp = atual;

//             if (atual == cabeca) {
//                 cabeca = atual->getProximo();
//             } else {
//                 prev->setProximo(atual->getProximo());
//             }

//             atual = atual->getProximo();
//             delete temp;
//         }
//         else
//             prev = atual;
//             atual = atual->getProximo();
//     }
// }

void Polinomio::combinar_termos(){
    if (esta_vazia()) return;

    No *atual = cabeca;
    No *prev = nullptr;

    //percorrer a lista 
    while(atual != nullptr){
        //seguinte começa no primeiro Nó após o atual
        No *seguinte = atual->getProximo();
        //o segundo while irá percorrer os nós seguintes para comparar com o atual
        while (seguinte != nullptr){
            if (seguinte->getExpoente() == atual->getExpoente()){
                //o nó atual recebe o valor da soma dos nós com expoentes iguais
                atual->setBase(atual->getBase() + seguinte->getBase());
                No *temp = seguinte;
                excluir(temp);
                delete temp;
            } else {
                seguinte = seguinte->getProximo();
            }
        }

        
        if (atual->getBase() == 0){
            No* temp = atual;

            if (atual == cabeca) {
                cabeca = atual->getProximo();
            } else {
                prev->setProximo(atual->getProximo());
            }

            atual = atual->getProximo();
            delete temp;
        }
        else
            prev = atual;
            atual = atual->getProximo();
    
    }

}


Polinomio Polinomio::operator+(const Polinomio &poli2){
    No *atual_p1 = cabeca;
    No *atual_p2 = poli2.cabeca;

    //nova lista com resultado
    Polinomio resultado;
    while(atual_p1){
        resultado.inserir_fim(atual_p1->getBase(), atual_p1->getExpoente());
        atual_p1 = atual_p1->getProximo();
    }

    while(atual_p2){
        resultado.inserir_fim(atual_p2->getBase(), atual_p2->getExpoente());
        atual_p2 = atual_p2->getProximo();
    }

    resultado.combinar_termos();
    return resultado;

};

//retornar como string depois
void Polinomio::exibir(){
    No *atual = cabeca;
    while(atual != nullptr){
        cout << atual->getBase() << "x" << atual->getExpoente() << " -> ";
        atual = atual->getProximo();
    }

}
