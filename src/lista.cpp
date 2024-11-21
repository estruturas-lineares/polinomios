#include "../include/lista.h"
#include "../include/no.h"
#include <iostream>
using namespace std;

//construtor
Lista::Lista(): cabeca(nullptr), cauda(nullptr){};
// Destruidor
// Lista::~Lista() {
//         while (cabeca != nullptr) {
//             No* temp = cabeca;
//             cabeca = cabeca->getProximo();
//             delete temp;
//         }
//     }


void Lista::inserir_comeco(int base, int expoente){
    No *no_a_inserir = new No(base, expoente);
  
    no_a_inserir->setProximo(cabeca);
    cabeca = no_a_inserir;
};


void Lista::inserir_fim(int base, int expoente){
    No *no_a_inserir = new No(base, expoente);
    No *atual = cabeca;
    if (cabeca == nullptr){
        no_a_inserir->setProximo(cabeca);
        cabeca = no_a_inserir;
        cauda = no_a_inserir;
    }else{
        while(atual->getProximo() != nullptr){
            atual = atual->getProximo();
        };
        atual->setProximo(no_a_inserir);
        cauda = atual;
    };
};

int Lista::tamanho(){
    int contador = 0;
    No *atual = cabeca;
    while(atual != nullptr){
        contador++;
        atual = atual->getProximo();
    }
    return contador;
};

void Lista::mostrar_lista(){
    No *atual = cabeca;
    while (atual != nullptr){
        cout << atual->getBase() << "^" << atual->getExpoente() << " -> ";
        atual = atual->getProximo();
    }
    cout << "NULL";
};

No* Lista::obter_proximo(No *no_item){
    if (no_item->getProximo() == nullptr){
        cout << "Esse e ultimo da lista";
        return nullptr;
    }

    return no_item->getProximo();
};

bool Lista::esta_vazia(){
    if (cabeca == nullptr) return true;
    else return false;
}

void Lista::excluir(No *no_a_excluir){
    if (esta_vazia()) return;

    //elemento na cabeça da lista
    if (no_a_excluir == cabeca){
       No *atual = cabeca;

       //removendo o único nó
       if (cabeca == cauda){
            cauda = nullptr;
       }
       cabeca = cabeca->getProximo();
       free(atual);
    }else{
        //ponteiro atual ja começa no segundo
        No *atual = cabeca->getProximo();
        //ponteiro anterior do atual
        No *anterior = cabeca;

        while(atual !=nullptr && atual != no_a_excluir){
            atual = atual->getProximo();
            anterior = anterior->getProximo();

        }
        //se o ponteiro atual é nulo, então ele é igual ao nó a ser excluído
        if (atual != nullptr){
            anterior->setProximo(atual->getProximo());

            if (atual->getProximo() == nullptr){
                cauda = anterior;
            }
            free(atual);
        }
    }

    
};


bool Lista::existe(No *no_item){
    No *atual = cabeca;
    while(atual != nullptr && atual != no_item){
        atual = atual->getProximo();
    };

    if (atual == no_item){
            cout << "existe";
            return true;
    }else {
        cout << "nao existe";
        return false;
    }
}

No* Lista::buscar(No *no_a_buscar){
    No *atual = cabeca;
    while(atual != nullptr && atual != no_a_buscar){
        atual = atual->getProximo();
    };

    if (atual == no_a_buscar){
            cout << "existe";
            return atual;
    }else return nullptr;
};

void Lista::obter_valores(int &b, int &e, No *no_item){
    b = no_item->getBase();
    e = no_item->getExpoente();
};


void Lista::alterar_no(No *no_a_modificar, int nova_base, int novo_expoente){
    No *atual = cabeca;
    while(atual !=nullptr && atual != no_a_modificar){
        atual = atual->getProximo();
    }

    if (atual == no_a_modificar){
        atual->setBase(nova_base);
        atual->setExpoente(novo_expoente);
    }

};
