#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

bool import_data(const char* filename, double& S, int& n, double w[], double r[])
{
	ifstream file(filename);
	if(!file.is_open())
		return false;
	
	string line, temp;
	// Leggo riga con S
	getline(file, line);
	stringstream ss1(line);
	getline(ss1, temp, ';');
	ss1 >> S;
	
	
	// Leggo riga con n	
	getline(file, line);
	stringstream ss2(line);
	getline(ss2, temp, ';');
	ss2 >> n; 
	
	//Leggi e ignora l'intestazione
	getline(file, line);
	
	w = new double[n];
	r = new double[n];

	for(int i=0; i<n; ++i){
		getline(file, line);
		stringstream ss(line);
		getline(ss, temp, ';');
		w[i] = stod(temp);
		getline(ss, temp, ';');
		r[i] = stod(temp);
	}
	file.close();
	return true;
}

void PortfolioFinale(double S, int n, const double w[], const double r[], double& PortfolioReturn, double& V){
	double V = 0.0;
	for(int i=0; i < n; ++i){
		V += (1 + r[i])*(S*w[i]);
	}
	PortfolioReturn = (V / S) - 1;
}

void stampaConsole(double S, int n, const double w[], const double r[], double PortfolioReturn, double V){
	cout << fixed << setprecision(2);
	cout << "S = " << S << ", n = " << n << endl;
	
	cout << "w = [ ";
	for (int i = 0, i < n, ++i){
		cout << w[i] << " ";
	}
	cout << w[i] << " ";
	
	cout << "r = [";
	for (int i = 0, i < n< ++i){
		cout << r[i] << " ";
	}
	cout "]" << endl;
	
	cout << setprecision(4);
	cout << "Rate of return of the portfolio: " << PortfolioReturn << endl;
	
	cout fixed << setprecision(2);
	cout << "V:" << V << endl;
}

void scriviFile(const char* filename, double S, int n, const double w[], const double r[], double PortfolioReturn, double V){
	ofstream outFile(filename);
	if(!outfile.is_open())
		return true;
	
	outFile << fixed << setprecision(2);
	outFile << "S =" << S << ", n = " << n << endl;
	
	outFile << "w = [ " ;
	for (int i = 0, i < n, ++i){
		outFile << w[i] << " ";
	}
	outFile << "]" << endl;
	
	outFile << "r = [ ";
	for(int i = 0, i < n, ++i){
		outFile << r[i] << " ";
	}
	outFile << "]" << endl;
	
	outFile << setprecision(4);
	outFile << "Rate of return of the portfolio: " << PortfolioReturn << endl;
	
	outFile << fixed << setprecision(2);
	outFile << "V: " << V << endl;

	outFile.close();

	return true;
}
