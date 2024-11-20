#include <iostream>
#include "include/no.h"
#include "include/lista.h"
#include "include/polinomio.h"
using namespace std;


int main (){
    No no1(2,4);
    No *n1 = &no1;
    No no2(2,3);
    No *n2 = &no2;
    No no3(3,3);
    No *n3 = &no3;
    No no4(3,2);
    No *n4 = &no4;

    Polinomio p1;
    Polinomio p2;


    p1.inserir_comeco(n1);
    p1.inserir_fim(n2);

    p2.inserir_comeco(n3);
    p2.inserir_fim(n4);


    p1.exibir();
    cout << "\n";
    p2.exibir();

    // Polinomio p3;
    // Polinomio *pi3 = &p3;
    // pi3= p1.adicao(p2);
    // p3.mostrar_lista();

    return 0;
}
