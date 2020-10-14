
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
// $ g++ -std=c++14 -g -Wall -o erathostenes erathostenes_v0.6.cc
 
#include <iostream>
#include <vector>
#include <string>

void Mostrar(const std::vector<int> vect_p) {
  for(int i = 0; i < vect_p.size(); i++) {
    std::cout << "[" << vect_p[i] << "] ";
  }
}

void Test(const std::vector<int> vect, const std::vector<bool> vect_bool) {
  for(int i=0; i < vect.size(); i++) {
    std::cout << vect[i] << " | ";
    if (vect_bool[i] == true) {
      std::cout << "PRIMO" << std::endl;  
    } else {
      std::cout << "NO PRIMO" << std::endl;
    }
  }
}

// Once the function deletes data from both vectors all the data in the both
// vectors will move back one position to fill the gap, that is why i has to
// decrease so it doesnt skip data in the process of deleting.

void Delete(std::vector<int> &vect, std::vector <bool> &vect_bool) {
  for (int i = 0; i < vect.size(); i++) {
    if (vect_bool[i] == false) {
      vect.erase(vect.begin() + i);
      vect_bool.erase(vect_bool.begin() + i);
      i--;  // Index stays the same for next iteration.
    }
  }
}

// Searches for multiples of num using modulus and marks them as false, excluding num itself

void Remove(const int num, const std::vector<int> &vect, std::vector<bool> &vect_bool) {
  for (int i = 0; i < vect.size(); i++) {
    if (vect[i] % num == 0 && vect[i] != num) {
      vect_bool[i] = false;
    }
  }
}

void Sieve(std::vector<int> &vect, std::vector<bool> &vect_bool) {
  for (int i = 0; i < vect.size(); i++) {
    if (vect_bool[i] == true) {
      //std::cout << "Numero a evaluar: " << vect[i] << std::endl; 
      Remove(vect[i], vect, vect_bool);
      Delete(vect, vect_bool);
    }          
  }
}

int main(int argc, char *argv[]) {
  // Number up to which you have to search for prime numbers and initial size of data vector.
  int kN = atoi(argv[1]);

  std::vector <int> vect_prime(kN-1);
  std::vector <bool> vect_bool_prime(kN-1);

  // Adding 2 to the index to fill up data vector, making it start from 2, up to kN.
  for(int i = 0; i < kN-1; i++) {
    vect_prime[i] = i+2;
    vect_bool_prime[i] = true;
  }

  Sieve(vect_prime, vect_bool_prime);
  //Delete(vect_prime, vect_bool_prime);
  std::cout << "Lista de numeros primos 1-" << kN << ": " << std::endl;
  Mostrar(vect_prime);
  //Test(vect_prime, vect_bool_prime);
  return 0;
}