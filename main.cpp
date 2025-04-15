#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main(){
	const char* inputFile = "data.txt";
	const char* outputFile = "result.txt";
	
	double S;
	int n;
	
	double* w = new double[n];
	double* r = new double[n];

	if(!import_data(inputFile, S, n, w, r)){
		cerr << "Impossibile aprire il file" << inputFile << endl;
		return 1;
	}
	
	double PortfolioReturn, V = 0.0;
	PortfolioFinale(w, r, n, S, PortfolioReturn, V);
	
	cout << "Il rendimento del portfolio vale:" << PortfolioReturn << endl;
	cout << "Il valore finale del portfolio è di:" << V << endl;
	
	scriviFile(outputFile, S, n, w, r, PortfolioReturn, V);
	
	delete [] w;
	delete [] r;
	
	
    return 0;
}
