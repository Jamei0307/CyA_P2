
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Computabilidad y Algoritmia
//
// author:  Jaime Pablo Pérez Moro
// email:   alu0101278919@ull.edu.es
// date:    13/10/2020
// version: 0.6
// brief:   Programa que imprime en pantalla una lista de números primos usando 
//          La críba de Eratóstenes, antiguo método para hallar números primos.
//
// Enlaces de interes:         
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// https://es.stackoverflow.com/
//
// Linea de compilación:
// $ g++ -std=c++14 -g -Wall -o erathostenes erathostenes_v0.1.cc
 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
  int N = stoi(argv[1]);
  vector <int> list(N);
  for(int i = 1; i <= N; i++){
    list[i] = i;
  }

  cout << "lista de numeros: " << endl;
  for(int i = 1; i <= N; i++){
    cout << list[i] << " ";
  }

  return 0;
}