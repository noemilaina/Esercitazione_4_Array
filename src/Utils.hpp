#pragma once
#include <iostream>

using namespace std;

bool import_data(const string& ifile_path, double& S, size_t& n, double*& w, double*& r);

double tasso_tot(const double& S, const double& V);

double valore_finale(const double& S, const size_t n, const double* const& w, const double* const& r);

string final_result(const double& S, const size_t& n, const double* const& w, const double* const& r, const double& R, const double& V);

bool esporta_data(const string& ofile_path, const string& out_str);
