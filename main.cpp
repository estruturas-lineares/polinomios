#include <iostream>
#include "include/no.h"
#include "include/lista.h"
#include "include/polinomio.h"
using namespace std;


int main (){
    Polinomio p1;
    Polinomio p2;


    p1.inserir_comeco(1,3);
    p1.inserir_fim(2,2);

    p2.inserir_comeco(4,3);
    p2.inserir_fim(1,4);


    p1.exibir();
    cout << "\n";
    p2.exibir();
    cout << "\n";

    Polinomio p3;
    p3 = p1+p2;
    p3.mostrar_lista();

    return 0;
}
