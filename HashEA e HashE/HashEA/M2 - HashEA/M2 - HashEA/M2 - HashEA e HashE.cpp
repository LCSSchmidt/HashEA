// M2 - HashEA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HashEA.h"
#include "HashE.h"
#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include "Gravar.h"

using namespace std;

int main() {
	int dado;
	int numeroDeInstrucoes = 0;
	int chave;

	HashEA<int, 1000> hash;
	hashIniciar<int, 1000>(hash);
	mt19937 mt(42);

	for (int indice = 0; indice < 2000; indice++) {
		numeroDeInstrucoes++;
		uniform_int_distribution<int> linear_i(0, 1000);
		dado = linear_i(mt);
		hashInsercao<int, 1000>(hash, dado, numeroDeInstrucoes);

		if (indice == 90 || indice == 240 || indice == 740 || indice == 990 || indice == 1990) {
			int numeroDeInstrucoes = 0;
			for (int contador = 0; contador < 10; contador++) {
				int c;
				uniform_int_distribution<int> linear_i(0, 1000);
				c = linear_i(mt);
				numeroDeInstrucoes++;
				hashInsercao<int, 1000>(hash, c, numeroDeInstrucoes);
				gravar("HashEA", "Inserir", (indice + 10) / 10, numeroDeInstrucoes);
			}
			for (int contador = 0; contador < 10; contador++) {
				numeroDeInstrucoes++;
				hashBusca<int, 1000>(hash, numeroDeInstrucoes);
				gravar("HashEA", "Buscar", (indice + 10) / 10, numeroDeInstrucoes);
			}
		}
	}

	for (int indice = 0; indice < 2000; indice++) {
		cout << hashBusca<int, 1000>(hash) << "\n";
	}
	/*Thash<int> *hashE[1000];

	mt19937 mt(42);

	inicializa<int>(hashE);
	for (int indice = 0; indice < 2000; indice++) {
		numeroDeInstrucoes++;
		uniform_int_distribution<int> linear_i(0, 999);
		dado = linear_i(mt);
		chave = linear_i(mt);
		insere(hashE, chave, dado, numeroDeInstrucoes);
		
		if (indice == 90 || indice == 240 || indice == 740 || indice == 990 || indice == 1990) {
			int numeroDeInstrucoes = 0;
			for (int contador = 0; contador < 10; contador++) {
				int c;
				uniform_int_distribution<int> linear_i(0, 999);
				c = linear_i(mt);
				numeroDeInstrucoes++;
				insere(hashE, c, dado, numeroDeInstrucoes);
				gravar("HashE", "Inserir", (indice + 10) / 10, numeroDeInstrucoes);
			}
			for (int contador = 0; contador < 10; contador++) {
				numeroDeInstrucoes++;
				pesquisa(hashE, chave, numeroDeInstrucoes);
				gravar("HashE", "Buscar", (indice + 10) / 10, numeroDeInstrucoes);
			}
		}
	}*/
	
	
	
	system("pause");
	return 0;
}
	