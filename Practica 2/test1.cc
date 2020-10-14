
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Computabilidad y Algoritmia
//
// author:  Jaime Pablo Pérez Moro
// email:   alu0101278919@ull.edu.es
// date:    10/10/2020
// version: 0.4
// brief:   Programa que imprime en pantalla una lista de números primos usando 
//          La críba de Eratóstenes, antiguo método para hallar números primos.
//
// Enlaces de interes:         
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// https://es.stackoverflow.com/
 
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

void Delete(vector<int> &vect, vector <bool> &vect_bool){
  for(int i = 0; i < vect.size(); i++){
    if(vect_bool[i] == false){
      vect.erase(vect.begin() + i);
      vect_bool.erase(vect_bool.begin() + i);
      i--; 
    }
  }
}

void Remove(int num, vector<int> &vect, vector<bool> &vect_bool){
  int i = 0;
  while (i != vect.size()){
    if(vect[i] % num == 0 && vect[i] != num){
      vect_bool[i] = false;
    }
    i++;
  }
}

void Sieve(vector<int> &vect, vector<bool> &vect_bool){
  int i = 0; 
  while(i != vect.size()){
    if(vect_bool[i] == true){
      //cout << "Numero a evaluar: " << vect[i] << endl;
      Remove(vect[i], vect, vect_bool);
      //Delete(vect, vect_bool);
    }
    i++;          
  }
}

int main(int argc, char *argv[]){
  int N = atoi(argv[1]);
  vector <int> vect_p(N-1);
  vector <bool> vect_bool_p(N-1);
  for(int i = 0; i < N-1; i++){
    vect_p[i] = i+2;
    vect_bool_p[i] = true;
  }

  Sieve(vect_p, vect_bool_p);
  Delete(vect_p, vect_bool_p);
  test(vect_p, vect_bool_p);
  return 0;
}