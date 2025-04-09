#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	double S;
	int n;
	
	ifstream inputFile("data.txt");
	if (!inputFile){
		cerr << "Impossibile aprire il file di input" << endl;
		return 1;
	}
	inputFile >> S >> n;
	
	vector<double> w(n);
	vector<double> r(n);
	
	for (int i = 0; i < n ; ++i){
		inputFile >> w[i] >> r[i];
		}
	double R = 0;
	for (int i = 0; i < n; ++i){
		R += w[i] * r[i];
	}
	double V = S * (1+ R);
	
	ofstream outputFile("result.txt");
	if (!outputFile){
		cerr << "Impossibile aprire il file di output" << endl;
		return 1;
	}
	outputFile << "Il rendimento del portafoglio vale:" << R << "&" << endl;
	outputFile << "Il valore finale del portfolio è di:" << V << endl;
	
	inputFile.close();
	outputFile.close();

    return 0;
}

