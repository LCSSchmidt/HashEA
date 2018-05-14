// M2 - HashEA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HashEA.h"
#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include "Gravar.h"

using namespace std;

int main() {



	HashEA<int, 1000> hash;
	int dado;
	int numeroDeInstrucoes = 0;
	

	hashIniciar<int, 1000>(hash);
	mt19937 mt(42);

	for (int indice = 0; indice < 2000; indice++) {
		numeroDeInstrucoes++;
		uniform_int_distribution<int> linear_i(0, 1000);
		dado = linear_i(mt);
		hashInsercao<int, 1000>(hash, dado);

		if (indice == 90 || indice == 240 || indice == 740 || indice == 990 || indice == 1990) {
			for (int contador = 0; contador < 10; contador++) {
				int c;
				uniform_int_distribution<int> linear_i(0, 1000);
				c = linear_i(mt);
				numeroDeInstrucoes = 1;
				hashInsercao<int, 1000>(hash, c, numeroDeInstrucoes);
				gravar("HashEA", "Inserir", (indice + 10) / 10, numeroDeInstrucoes);
			}
		}
	}
	
	for (int indice = 0; indice < 2000; indice++) {
		cout <<  hashBusca<int, 1000>(hash) << "\n";
	}
	system("pause");
	return 0;
}