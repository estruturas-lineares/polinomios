#include "lista.h"
#ifndef POLINOMIO_H
#define POLINOMIO_H


class Polinomio : public Lista {

public:
    int grau_polinomio(No *no_item);
    Polinomio* subtracao(Polinomio *poli1, Polinomio *poli2);
    Polinomio* multiplicacao(Polinomio *poli1, Polinomio *poli2);
    Polinomio operator+(const Polinomio &poli2);
    void exibir();
    void combinar_termos();
};

#endif // POLINOMIO_H_INCLUDED
