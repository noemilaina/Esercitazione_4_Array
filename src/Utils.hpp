#pragma once
#include <iostream>


using namespace std;

bool import_data(const char* filename, double& S, int& n, double* w, double* r);
void PortfolioFinale(double* w, double* r, int n, double S, double& PortfolioReturn, double& V);
void stampaConsole(double S, int n, const double* w, const double* r, double PortfolioReturn, double V);
void scriviFile(const char* filename, double S, int n, const double* w, const double* r, double PortfolioReturn, double V);
