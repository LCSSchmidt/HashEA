#include <string>
#include <iostream>
#include <limits>

using namespace std;


const int MAXCHAVE = 32000;

template <typename T>
struct Data {
	T dado;
	Data *proximo;
};

template <typename T, int max>
struct HashEA {
	Data<T> dado[max];
	int quantidade;
};