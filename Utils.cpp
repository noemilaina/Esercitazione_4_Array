#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool import_data(const string& file_path, double& S, size_t& n, double*& w, double*& r)
{
	ifstream ifile(file_path);
	if(ifile.fail())
		return false;
	
	string line;
	// Leggo riga con S
	if (getline(ifile, line)){
		stringstream ss(line);
		string key;
		string value_str;
		getline(ss, key, ';');
		getline(ss, value_str, ';');
		if (key == "S"){
			try {
				S = stod(value_str);
			} catch (const std::invalid_argument& e){
				cerr << "Errore nella lettura di S:" << e.what() << endl;
				ifile.close();
				return false;
			} catch (const std::out_of_range& e){
				cerr << "Valore di S fuori range" << e.what() << endl;
				ifile.close();
				return false;
			}
		}else{
			cerr << "Formato file non valido" << endl;
			ifile.close();
				return false;
		}
	}else {
			cerr << "Errore nella lettura del file" << endl;
			ifile.close();
			return false;
		}
	}
	// Leggo riga con n	
	if (getline(ifile,line)){
		stringstream ss(line);
		string key;
		string value_str;
		getline(ss, key, ';');
		getline(ss, value_str, ';');
		if (key == "n"){
			try{
				n = stoul(value_str);
			}catch (const std::invalid_argument& e){
				cerr << "Errore nella lettura di n:" << e.what() << endl;
				ifile.close();
				return false;
			}catch (const std::out_of_range& e){
				cerr << "Valore fuori range" << e.what() << endl;
				ifile.close();
				return false;	
			}
		}else{
			cerr << "Formato file non valido" << endl;
			ifile.close();
			return false;
		}
	} else{
		cerr << "Errore nella lettura del file" << endl;
		ifile.close();
		return false;
	}
	//Leggi e ignora l'intestazione
	getline(ifile, line);
	
	w = new double[n];
	r = new double[n];

	for(size_t i=0; i<n; ++i){
		if (getline(ifile, line)){
			stringstream ss(line);
			string w_str, r_str;
			if(getline(ss, w_str, ';') && getline(ss, r_str, ';')){
				try{
					w[i] = stod(w_str);
					r[i] = stod(r_str);
				} catch (const std::invalid_argument& e){
					cerr << "Errore nella conversione a double nella riga" << i + 4 << ":" << e.what() << endl;
					delete[] w;
					delete[] r;
					ifile.close();
					return false;
				}catch(const std::out_of_range& e){
					cerr << "Valore fuori range nella riga" << i+4 << ":" << e.what() << endl;
					delete[] w;
					delete[] r;
					ifile.close();
					return false;
				}
			}else{
				cerr << "Formato errato nella riga" << i+4 << ":attesi due valori separati da ';'" << endl;
				delete[] w;
				delete[] r;
				ifile.close();
				return false;
			}
		}else{
			cerr << "Errore nella lettura dei dati w e r: file troppo corto" << endl;
			delete[] w;
			delete[] r;
			ifile.close();
			return false;
		}
	}
	ifile.close();
	return true;
}

double tasso_tot(const double& S, const double& V){
	double R=(V/S)-1;
	return R;
}

double valore_finale(const double& S, const size_t n, const double* const& w, const double* const& r){
	double V = S;
	for(size_t i=0; i<n; i++){
		V += (1 + r[i])*(S*w[i]);
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
	ss_output << "Rate of return of the portfolio:" << fixed<< setprecision(4) << R << endl;
	ss_output << "V:" << ss_V.str() << endl;
	return ss_output.str();
}

bool esporta_data(const string& ofile_path, const string& out_str){
	ofstream out(ofile_path);
	if(out.fail())
		return false;
	out << out_str;
	out.flush();
	return true;
}
