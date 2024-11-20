#include "../include/lista.h"
#include "../include/no.h"
#include <iostream>
using namespace std;

//construtor
Lista::Lista(): cabeca(nullptr){};
// Destruidor
// Lista::~Lista() {
//         while (cabeca != nullptr) {
//             No* temp = cabeca;
//             cabeca = cabeca->getProximo();
//             delete temp;
//         }
//     }


void Lista::inserir_comeco(No *no_a_inserir){
    no_a_inserir->setProximo(cabeca);
    cabeca = no_a_inserir;
};


void Lista::inserir_fim(No *no_a_inserir){
    No *ponteiro_atual = cabeca;
    if (cabeca == nullptr){
        no_a_inserir->setProximo(cabeca);
        cabeca = no_a_inserir;
    }else{
        while(ponteiro_atual->getProximo() != nullptr){
            ponteiro_atual = ponteiro_atual->getProximo();
        };
        ponteiro_atual->setProximo(no_a_inserir);

    };
};

int Lista::tamanho(){
    int contador = 0;
    No *ponteiro_atual = cabeca;
    while(ponteiro_atual != nullptr){
        contador++;
        ponteiro_atual = ponteiro_atual->getProximo();
    }
    return contador;
};

void Lista::mostrar_lista(){
    No *ponteiro_atual = cabeca;
    while (ponteiro_atual != nullptr){
        cout << ponteiro_atual->getBase() << "^" << ponteiro_atual->getExpoente() << " -> ";
        ponteiro_atual = ponteiro_atual->getProximo();
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
void Lista::excluir_comeco(No *no_a_excluir){
    if (!esta_vazia()){
        if (cabeca == no_a_excluir){
            No *primeiro = cabeca;
            cabeca = cabeca->getProximo();
            free(primeiro);
        }
    }
};

void Lista::excluir_fim(No *no_a_excluir){
    if (!esta_vazia()){
        No *ponteiro_atual = cabeca;
        while(ponteiro_atual !=nullptr){
            ponteiro_atual = ponteiro_atual->getProximo();
        }
        if (ponteiro_atual == no_a_excluir){
            free(ponteiro_atual);
        }

    }
};

void Lista::excluir_meio(No *no_a_excluir){
    if (!esta_vazia()){
        //ponteiro atual ja começa no segundo
        No *ponteiro_atual = cabeca->getProximo();
        //ponteiro anterior do atual
        No *ponteiro_anterior = cabeca;

        while(ponteiro_atual !=nullptr && ponteiro_atual != no_a_excluir){
            ponteiro_atual = ponteiro_atual->getProximo();
            ponteiro_anterior = ponteiro_anterior->getProximo();

        }
        //se o ponteiro atual é nulo, então ele é igual ao nó a ser excluído
        if (ponteiro_atual != nullptr){
            ponteiro_anterior->setProximo(ponteiro_atual->getProximo());
            free(ponteiro_atual);
        }
    };
}


bool Lista::existe(No *no_item){
    No *ponteiro_atual = cabeca;
    while(ponteiro_atual != nullptr && ponteiro_atual != no_item){
        ponteiro_atual = ponteiro_atual->getProximo();
    };

    if (ponteiro_atual == no_item){
            cout << "existe";
            return true;
    }else {
        cout << "nao existe";
        return false;
    }
}

No* Lista::buscar(No *no_a_buscar){
    No *ponteiro_atual = cabeca;
    while(ponteiro_atual != nullptr && ponteiro_atual != no_a_buscar){
        ponteiro_atual = ponteiro_atual->getProximo();
    };

    if (ponteiro_atual == no_a_buscar){
            cout << "existe";
            return ponteiro_atual;
    }else return nullptr;
};

void Lista::obter_valores(int &b, int &e, No *no_item){
    b = no_item->getBase();
    e = no_item->getExpoente();
};


void Lista::alterar_no(No *no_a_modificar, int nova_base, int novo_expoente){
    No *ponteiro_atual = cabeca;
    while(ponteiro_atual !=nullptr && ponteiro_atual != no_a_modificar){
        ponteiro_atual = ponteiro_atual->getProximo();
    }

    if (ponteiro_atual == no_a_modificar){
        ponteiro_atual->setBase(nova_base);
        ponteiro_atual->setExpoente(novo_expoente);
    }

};
