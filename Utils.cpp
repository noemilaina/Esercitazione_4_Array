#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool import_data(const string& file_path, double& S, size_t& n, double*& w, double*& r)
{
	ifstream ifile(file_path)
	if(ifile.fail())
		return false;
	
	char c;
	ifile>>c;
	ifile>>c;
	ifile>>S;
	
	ifile>>c;
	ifile>>c;
	ifile>>n;
	
	ifile>>c;
	
	string tmp;
	getline(ifile, tmp);
	
	w = new double[n];
	r = new double[n];
	
	string line;
	unsigned int i=0;
	for(; getline(ifile, line); ++i){
		stringstream ss_line(line);
		string data;
		double val;
		unsigned int j=0;
		for (; getline(ss_line, data, ';'); ++j){
			val = stod(data);
			if(j==0) 
				w[i]=val;
			else 
				r[i]=val;
		}
	}
	return true;
}

double tasso_tot(const double& S, const double& V){
	double R=(V/S)-1;
	return R;
}

double valore_finale(const double& S, const size_t n, const double* const& w, const double* const& r){
	double V = 0;
	for(unsigned int i=0; i<n; i++){
		V +=(1+r[i])*(S*w[i]);
	}
	return V;
}

string final_result(const double& S, const size_t& n, const double* const& w, const double* const& r, const double& R, const double& V){
	stringstream ss_output;
	stringstream ss_S, ss_V;
	ss_S<<fixed<<setprecision(2)<<S;
	ss_V<<fixed<<setprecision(2)<<V;
	
	ss_output << "S=" << ss_S.str()<< ","<< "n=" << n <<endl;
	
	ss_output << "w = [";
	for(unsigned int i=0; i<n; i++){
		ss_output<<w[i]<< ' ';
	}
	ss_output<<']'<<endl;
	
	ss_output << "r = [";
	for(unsigned int i=0; i<n; i++){
		ss_output << r[i] << ' ';
	}
	ss_output << ']'<<endl;
	ss_output << "Il tasso finale del portfolio vale:" << R << endl;
	ss_output << "V:" << ss_V.str() << endl;
	return ss_output.str();
}

bool esporta_data(const string& ofile_path, const string& out_str){
	ofstream out(ofile_path);
	if(out.fail())
		return false;
	return true;
}
