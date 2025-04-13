#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main(){
	string input_file = "data.txt";
	double S;
	size_t n;
	double *ptr_w = nullptr;
	double *ptr_r = nullptr;
	
	if(!import_data(input_file, S, n, ptr_w, ptr_r)){
		cerr << "Impossibile aprire il file" << input_file << endl;
		return 1;
	}
	
	double V = valore_finale(S, n, ptr_w, ptr_r);
	double R = tasso_tot(S, V);
	
	string output_str = final_result(S, n, ptr_w, ptr_r, R, V);
	cout << output_str << endl;
	
	delete [] ptr_w;
	delete [] ptr_r;
	
	string outputFile("result.txt");
	if (!esporta_data(output_file, output_str)){
		cerr << "Impossibile aprire il file di output" << endl;
		return 2;
	}
    return 0;
}
