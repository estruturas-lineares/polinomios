#include <iostream>
#include "include/no.h"
#include "include/lista.h"
#include "include/polinomio.h"
#include <fstream>
#include <sstream>
using namespace std;

Polinomio linha_para_polinomio(string linha){
    Polinomio resultado;
    //istringstream gera uma instancia da variavel linha
    //que permite tratar essa string como uma entrada de dados
    istringstream str(linha);
    int base, expoente;
    while(str >> base >> expoente){
        resultado.inserir_fim(base, expoente);
    };

    return resultado;
};

int main (){
    ifstream file("src/teste.txt");
    string linha;

    cout << "oie";

    string op;
    if (file.is_open()){
        while(getline(file, linha)){
            if (linha == "+"){
                getline(file, op);
                Polinomio p1 = linha_para_polinomio(op);

                getline(file, op);
                Polinomio p2 = linha_para_polinomio(op);

                cout << p1 << endl << p2 << endl;
                cout << p1 + p2 << endl;                
            }
        }
        file.close();
    }

















    // Polinomio p1;
    // Polinomio p2;
    // p1.inserir_comeco(1,3);
    // p1.inserir_fim(2,2);
    // p2.inserir_comeco(4,3);
    // p2.inserir_fim(1,4);
    // p1.exibir();
    // cout << "\n";
    // p2.exibir();
    // cout << "\n";
    // Polinomio p3;
    // p3 = p1+p2;
    // cout << p3;
    // cout << "\n";
    // Polinomio p4;
    // p4 = p1 - p2;
    // cout << p4;

    // cout << "\n";
    // Polinomio p5;
    // p5 = p1 * p2;
    // p5.mostrar_lista();

    // cout << "\n";
    // int r = p1.avaliar(2);
    // cout << r;
    return 0;
}
