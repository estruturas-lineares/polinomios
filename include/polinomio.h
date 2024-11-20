#include "lista.h"
#ifndef POLINOMIO_H
#define POLINOMIO_H


class Polinomio : public Lista {

public:
    int grau_polinomio(No *no_item);
    Polinomio* adicao(Polinomio poli2);
    Polinomio* subtracao(Polinomio *poli1, Polinomio *poli2);
    Polinomio* multiplicacao(Polinomio *poli1, Polinomio *poli2);
    void exibir();



};

#endif // POLINOMIO_H_INCLUDED
