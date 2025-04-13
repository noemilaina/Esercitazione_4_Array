#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	double S;
	int n;
	
	ifstream inputFile("data.txt");
	if (!inputFile){
		cerr << "Impossibile aprire il file di input" << endl;
		return 1;
	}
	string line;
	
	getline(inputFile, line);
	stringstream ss1(line);
	string temp;
	getline(ss1, temp, ';');
	ss1 >> S;
	
	getline(inputFile, line);
	stringstream ss2(line);
	getline(ss1, temp, ';');
	ss2 >> n;
	
	
	vector<double> w(n);
	vector<double> r(n);
	
	getline(inputFile,line);
	
	for(int i = 0; i < n; ++i){
		getline(inputFile, line);
		stringstream ss(line);
		string w_str, r_str;
		getline(ss, w_str, ';');
		getline(ss, r_str, ';');
		w[i] = stod(w_str);
		r[i] = stod(r_str);
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
	outputFile << "Il rendimento del portafoglio vale:" << R << "%" << endl;
	outputFile << "Il valore finale del portfolio è di:" << V << endl;
	
	inputFile.close();
	outputFile.close();

    return 0;
}
