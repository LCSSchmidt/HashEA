#include <iostream>
#define TAM 1000
using namespace std;

template <typename TIPO>
struct Thash {
	int chave;
	TIPO dado;
	Thash *prox;
};

template <typename TIPO>
void inicializa(Thash <TIPO> *tabela[]) {
	for (int i = 0; i < TAM; i++){
		Thash<TIPO> *aux = new Thash<TIPO>;
		tabela[i] = new Thash<TIPO>;
		tabela[i]->dado = NULL;
		tabela[i]->chave = NULL;
		tabela[i]->prox = aux;
		tabela[i]->prox->dado = NULL;
		tabela[i]->prox->chave = NULL;
	}
}

template <typename TIPO>
void insere(Thash<TIPO> *tabela[], int chave, TIPO dado, int &numeroinstrucoes) {
	int pos = chave % TAM;
	if (tabela[pos]->dado != NULL && tabela[pos]->prox->dado != NULL) {
		do {
			numeroinstrucoes++;
			pos++;
			if (pos >= 1000) {
				return;
			}
		} while (tabela[pos]->dado == NULL || tabela[pos]->prox->dado == NULL);
	}
	if (tabela[pos]->dado == NULL) {
		tabela[pos]->dado = dado;
		tabela[pos]->chave = chave;
	}
	else {
		Thash<TIPO> *aux = new Thash<TIPO>;
		aux->dado = dado;
		aux->chave = chave;
		tabela[pos]->prox = aux;
	}
	return;
}

template <typename TIPO>
bool excluir(Thash<TIPO> *tabela[], int chave) {
	int pos = chave % TAM;
	Thash<TIPO> *aux;
	if (tabela[pos] != NULL) {
		if (tabela[pos]->chave == chave) {
			aux = tabela[pos];
			tabela[pos] = tabela[pos]->prox;
			delete aux;
			return true;
		}
		else {
			aux = tabela[pos]->prox;
			Thash* ant = tabela[pos];

			while ((aux != NULL) && (aux->chave != chave)) {
				ant = aux;
				aux = aux->prox;
			}
			if (aux != NULL) {
				ant - prox = aux->prox;
				delete aux;
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
}

template <typename TIPO>
bool pesquisa(Thash<TIPO> *tabela[], int chave, int &numeroDeInstrucoes) {
	int pos = chave % TAM;
	Thash<TIPO> *nav = tabela[pos];
	if (nav->chave == chave) {
		tabela[pos] = nav->prox;
		numeroDeInstrucoes++;
		return true;
	}
	else {
		nav = nav->prox;
		Thash<TIPO> *nav2 = tabela[pos];
		while (nav->chave != chave) {
			numeroDeInstrucoes++;
			nav = nav->prox;
			nav2 = nav2->prox;
		}
		nav2->prox = nav->prox;
		return true;
	}

}
