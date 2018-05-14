#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void gravar(string tableHash, string operacao, int ocupacao, int numeroDeInstrucoes) {
	ofstream arquivo("saida.csv", ofstream::app);
	arquivo << tableHash << ","
		<< operacao << ","
		<< ocupacao << ","
		<< numeroDeInstrucoes << "\n";
}
