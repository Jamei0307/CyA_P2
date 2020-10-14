
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
// $ g++ -std=c++14 -g -Wall -o erathostenes erathostenes_v0.5.cc
 
#include <iostream>
#include <vector>
#include <string>

void mostrar(std::vector<int> vect_p, int Range) {
  std::cout << "Lista de numeros primos 1-" << Range << ": " << std::endl;
  for(int i = 0; i < vect_p.size(); i++) {
    std::cout << "[" << vect_p[i] << "] ";
  }
}

void test(std::vector<int> vect, std::vector<bool> vect_bool) {
  for(int i=0; i < vect.size(); i++) {
    std::cout << vect[i] << " | ";
    if(vect_bool[i] == true) {
      std::cout << "PRIMO" << std::endl;  
    }
    else {
      std::cout << "NO PRIMO" << std::endl;
    }
  }
}

void Delete(std::vector<int> &vect, std::vector <bool> &vect_bool) {
  for(int i = 0; i < vect.size(); i++) {
    if(vect_bool[i] == false) {
      vect.erase(vect.begin() + i);
      vect_bool.erase(vect_bool.begin() + i);
      i--; 
    }
  }
}

void Remove(int num, std::vector<int> &vect, std::vector<bool> &vect_bool) {
  int i = 0;
  while (i != vect.size()) {
    if(vect[i] % num == 0 && vect[i] != num) {
      vect_bool[i] = false;
    }
    i++;
  }
}

void Sieve(std::vector<int> &vect, std::vector<bool> &vect_bool) {
  int i = 0; 
  while(i != vect.size()) {
    if(vect_bool[i] == true) {
      //std::cout << "Numero a evaluar: " << vect[i] << std::endl;
      Remove(vect[i], vect, vect_bool);
      //Delete(vect, vect_bool);
    }
    i++;          
  }
}

int main(int argc, char *argv[]) {
  int N = atoi(argv[1]);
  std::vector <int> vect_p(N-1);
  std::vector <bool> vect_bool_p(N-1);
  for(int i = 0; i < N-1; i++) {
    vect_p[i] = i+2;
    vect_bool_p[i] = true;
  }

  Sieve(vect_p, vect_bool_p);
  Delete(vect_p, vect_bool_p);
  mostrar(vect_p, N);
  //test(vect_p, vect_bool_p);
  return 0;
}