#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void gravar(string tableHash, string operacao, int ocupacao, int numeroDeInstrucoes) {

	if (operacao == "Inserir") {
		ofstream arquivo("Saida-InsereE2.csv", ofstream::app);
		arquivo << tableHash << ","
			<< operacao << ","
			<< ocupacao << ","
			<< numeroDeInstrucoes << "\n";
	}
	else {
		ofstream arquivo("Saida-BuscaE.csv", ofstream::app);
		arquivo << tableHash << ","
			<< operacao << ","
			<< ocupacao << ","
			<< numeroDeInstrucoes << "\n";
	}

	
}
