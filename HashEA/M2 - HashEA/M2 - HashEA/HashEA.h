#include <string>
#include <iostream>
#include <limits>
#include <time.h>

using namespace std;

template <typename T>
struct Data {
	T dado;
};

template <typename T, int max>
struct Hash {
	Data<T> dado[max];
	int quantidade;
};

template <typename T, int max>
void iniciarHash(Hash<T, max> &hash) {
	for (int indice = 0; indice < max; indice++)
		hash.dado[indice].dado = NULL;

	hash.quantidade = 0;
}

template <typename T, int max>
void operacaoParaInsercao(Hash<T, max> hash, T dado) {
	float chave = 0.4;
}