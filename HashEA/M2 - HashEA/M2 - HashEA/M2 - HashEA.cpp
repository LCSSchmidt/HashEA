// M2 - HashEA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HashEA.h"

int main() {
	int dado = 400;
	Hash<int, 1000> hash;

	iniciarHash<int, 1000>(hash);
	operacaoParaInsercao<int, 1000>(hash, dado);
	return 0;
}