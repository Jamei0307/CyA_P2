
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
// $ g++ -std=c++14 -g -Wall -o erathostenes erathostenes_v0.2.cc
 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void test(vector<int> vect, vector<bool> vect_bool){
  for(int i=0; i < vect.size(); i++){
    cout << vect[i] << " | ";
    if(vect_bool[i] == true){
      cout << "PRIMO" << endl;  
    }
    else{
      cout << "NO PRIMO" << endl;
    }
  }
}

void Remove(int num, vector<bool> &vect_bool){
  for(int i = 1; i < vect_bool.size(); i++){
    if((i+1) % num == 0 && (i+1) != num){
      vect_bool[i] = false;
    }
  }
}

void Sieve(vector<int> &vect, vector<bool> &vect_bool){
  for(int i = 0; i < vect.size(); i++){
    if(vect_bool[i] == true){
      Remove(i+1, vect_bool);
    }
  }
}

/* void Delete(vector<int> &vect, vector <bool> &vect_bool){
  for(int i = 0; i < vect.size(); i++){
    if(vect_bool[i] == false){
      vect.erase(vect.begin() + i
    }
  }
} */

int main(int argc, char *argv[]){
  int N = atoi(argv[1]);
  vector <int> vect_p(N);
  vector <bool> vect_bool_p(N);
  for(int i = 0; i < N; i++){
    vect_p[i] = i+1;
    vect_bool_p[i] = true;
  }
  vect_bool_p[0] = false;

  Sieve(vect_p, vect_bool_p);
  test(vect_p, vect_bool_p);
  return 0;
}