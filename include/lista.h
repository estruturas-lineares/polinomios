#ifndef LISTA_H
#define LISTA_H
#include "no.h"
#include <iostream>
using namespace std;

class Lista{
    public:
    No *cabeca;

    public:
    Lista();

    void inserir_comeco(No *no_a_inserir);
    void inserir_fim(No *no_a_inserir);
    int tamanho();
    void mostrar_lista();
    No* obter_proximo(No *no_item);
    bool esta_vazia();
    void excluir_comeco(No *no_a_excluir);
    void excluir_fim(No *no_a_excluir);
    void excluir_meio(No *no_a_excluir);
    bool existe(No *no_item);
    No* buscar(No *no_a_buscar);
    void obter_valores(int &b, int &e, No *no_item);
    void alterar_no(No *no_a_modificar, int nova_base, int novo_expoente);

};
#endif
