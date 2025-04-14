#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main(){
	const char* inputFile = "data.txt";
	const char* outputFile = "result.txt"
	
	double S;
	int n;
	double* w = new double[n];
	double* r = new double[n];

	if(!import_data(input_file, S, n, w, r)){
		cerr << "Impossibile aprire il file" << input_file << endl;
		return 1;
	}
	
	double V = valore_finale(S, n, w, r);
	double R = tasso_tot(S, V);
	
	cout << "Il rendimento del portfolio vale:" << R << endl;
	cout << "Il valore finale del portfolio è di:" << V << endl;
	
	printTo
	
	delete [] w;
	delete [] r;
	
	
    return 0;
}
