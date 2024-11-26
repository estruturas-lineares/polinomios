#include <iostream>
#include "include/no.h"
#include "include/lista.h"
#include "include/polinomio.h"
#include <fstream>
#include <sstream>
using namespace std;

Polinomio linha_para_polinomio(string linha_polinomio){
    Polinomio resultado;
    //istringstream gera uma instancia da variavel linha_polinomio
    //que permite tratar essa string como uma entrada de dados
    istringstream str(linha_polinomio);
    int base, expoente;
    while(str >> base >> expoente){
        resultado.inserir_fim(base, expoente);
    };

    return resultado;
};

int main (){
    ifstream file("src/file.txt");
    string linha;
    string linha_polinomio;

    if (!file.is_open()) {
        return 1;
    }


    while (getline(file, linha)) {
        if (linha == "+") {

            getline(file, linha_polinomio);
            Polinomio p1 = linha_para_polinomio(linha_polinomio);
            getline(file, linha_polinomio);
            Polinomio p2 = linha_para_polinomio(linha_polinomio);

            cout << p1 << endl << p2 << endl;

            Polinomio resultado = p1 + p2;
            cout << "Resultado da soma: " << resultado << endl;

        }else if (linha == "-") {

            getline(file, linha_polinomio);
            Polinomio p1 = linha_para_polinomio(linha_polinomio);
            getline(file, linha_polinomio);
            Polinomio p2 = linha_para_polinomio(linha_polinomio);

            cout << p1 << endl << p2 << endl;

            Polinomio resultado = p1 - p2;
            cout << "Resultado da subtração: " << resultado << endl;

        }else if (linha == "*") {

            getline(file, linha_polinomio);
            Polinomio p1 = linha_para_polinomio(linha_polinomio);
            getline(file, linha_polinomio);
            Polinomio p2 = linha_para_polinomio(linha_polinomio);

            cout << p1 << endl << p2 << endl;

            Polinomio resultado = p1 * p2;
            cout << "Resultado da multiplicação: " << resultado << endl;

        }else if (linha == "g" || linha == "G") {

            getline(file, linha_polinomio);
            Polinomio p1 = linha_para_polinomio(linha_polinomio);

            cout << "Grau: " << p1.grau_polinomio();

        }else if (linha == "a" || linha == "A") {
            int x = 0;
            cout << "Informe um valor para X:" <<endl;
            cin >> x;

            getline(file, linha_polinomio);
            Polinomio p1 = linha_para_polinomio(linha_polinomio);

            cout << "Avaliação: " << p1.avaliar(x);

        }else if (linha == "t" || linha == "T") {
            getline(file, linha_polinomio);
            Polinomio p1 = linha_para_polinomio(linha_polinomio);

            cout << "Tamanho: " << p1.tamanho();

        }else if (linha == "p" || linha == "P") {
            getline(file, linha_polinomio);
            Polinomio p1 = linha_para_polinomio(linha_polinomio);

            cout << p1 << endl;
        }else {
            cout << "Operador invalido!" << endl;
        }

    }















    //testes
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
