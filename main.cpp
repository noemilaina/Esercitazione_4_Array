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
	size_t n;
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
	
	string output_str = final_result(S, n, w, r, R, V);
	cout << output_str << endl;
	
	delete [] w;
	delete [] r;
	
	string outputFile("result.txt");
	if (!esporta_data(outputFile, output_str)){
		cerr << "Impossibile aprire il file di output" << endl;
		return 2;
	}
    return 0;
}
