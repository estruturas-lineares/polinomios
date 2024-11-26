#include "lista.h"
#ifndef POLINOMIO_H
#define POLINOMIO_H

class Polinomio : public Lista {

public:
    void exibir();
    int avaliar(int x);
    void simplificar();
    int grau_polinomio();

    Polinomio operator+(const Polinomio &poli2);
    Polinomio operator-(const Polinomio &poli2);

    //aqui o << é uma função amiga, significa que é externa a classe;
    friend Polinomio operator*(const Polinomio &poli1, const Polinomio &poli2);
    friend std::ostream& operator<<(std::ostream &os, const Polinomio &poli);

};

#endif // POLINOMIO_H_INCLUDED
