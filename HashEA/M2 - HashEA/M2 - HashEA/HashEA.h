#include <string>
#include <iostream>
#include <limits>

using namespace std;


const int MAXCHAVE = 32000;

template <typename T>
struct Data {
	T dado;
}; 

template <typename T, int max>
struct HashEA{
	Data<T> dado[max];
	int quantidade;
};

template <typename T, int max>
bool hashIniciar(HashEA<T, max> &hash, int indice = 0) {
	if (indice == max) {
		hash.quantidade = 0;
		return true;
	}
	
	hash.dado[indice].dado = NULL;
	return hashIniciar(hash, ++indice);
}

int hashGeracaoChave(int max) {
	int chave = 0;

	chave = rand() % MAXCHAVE + 1;
	chave = chave % max - 1;

	if (chave > 999)
		hashGeracaoChave(max);
	return chave;
}

template <typename T, int max>
void hashInsercao(HashEA<T, max> &hash, T dado, int &numeroDeInstrucoes, int chave = 0) {
	if(chave == 0)
		chave = hashGeracaoChave(max);

	if (hash.dado[chave].dado == NULL)
		hash.dado[chave].dado = dado;
	else if (chave == 999)
		return;
	else
		hashInsercao(hash, dado, ++numeroDeInstrucoes, ++chave);
}

template <typename T, int max>
T hashBusca(HashEA<T, max> &hash, int &numeroDeInstrucoes, int chave = 0) {
	if (chave == 0)
		chave = hashGeracaoChave(max);

	if (hash.dado[chave].dado != NULL)
		return hash.dado[chave].dado;
	else 
		hashBusca(hash, ++numeroDeInstrucoes, ++chave);
}