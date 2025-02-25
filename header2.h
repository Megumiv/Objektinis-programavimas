#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <random>
#include <cstdlib> 
#include <ctime>
//nuo v0.2
#include <fstream>
#include <limits>
#include <sstream>
#include <chrono> // testavimui


using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::left;
using std::setw;
using std::ifstream;
using std::accumulate; 

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 10);  // sugeneruoja random skaicius nuo 0 iki 10 - pazymiams
std::uniform_int_distribution<> diss(1, 10); // - studentu kiekiui


struct stud
{
	string var = "A";
	string pav = "A";
	vector <int> paz;
	int egz = 0;
	double galvid = 0.0;  // galutinis pagal vidurki
	double galmed = 0.0;  // galutinis pagal mediana
};

int m = 0; //studentu kiekis
int nd = 0; //namu darbu rezultatai
int pasirinkimas; // skaiciuoti pagal vidurki ar mediana
int pazymys; // reikalinga duomenu nuskaityme

vector<stud> grupe;
string choice; 
vector<int> paz_temp; 
string sortChoice;  

double vidurkis(const vector<int>& nam) //namu darbu vidurkis
{
	if (nam.empty()) return 0.0;
	return accumulate(nam.begin(), nam.end(), 0.0) / nam.size();
}

double mediana(vector<int> nd) {
	if (nd.empty()) return 0.0;
	std::sort(nd.begin(), nd.end());
	size_t size = nd.size();
	if (size % 2 == 0)
		return (nd[size / 2 - 1] + nd[size / 2]) / 2.0;
	else
		return nd[size / 2];
}

// vardu ir pavardziu sarasas
const vector<string> firstNames = { "Augustas", "Birute", "Daiva", "Ema", "Fiodoras", "Gabrielius", "Haroldas", "Ieva", "Tomas", "Nija" };
const vector<string> lastNames = { "Baravykas", "Kiskis", "Lydeka", "Burokas", "Neris", "Jankauskas", "Kazlauskas", "Urbonas", "Boruta", "Zemaite" };

// Meniu
void meniu()
{
	cout << "\n\nMeniu: \n";
	cout << "1 - Rankiniu budu ivesti pazymius\n";
	cout << "2 - Generuoti pazymius\n";
	cout << "3 - Generuoti pazymius ir studentu vardus bei pavardes\n";
	cout << "4 - Duomenis nuskaityti is failo\n";
	cout << "5 - Baigti darba ir isvesti rezultatus\n";

	cout << "Pasirinkite (1, 2, 3, 4, 5 ): ";
	cin >> choice;
}

	void Sort(const string & sortBy) {
		if (sortBy == "a") { //pavarde
			std::sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
				return a.pav < b.pav;
				});
		}
		else if (sortBy == "b") { //vardas
			std::sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
				return a.var < b.var;
				});
		}
		else if (sortBy == "c") { // vidurkio galutinis
			std::sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
				return a.galvid < b.galvid;
				});
		}
		else if (sortBy == "d") { // medianos galutinis
			std::sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
				return a.galmed < b.galmed;
				});
		}
	}

// testavimui
    int testnr = 1; // <--- PAKEISTI NORINT TESTUOTI
	std::chrono::duration<double> diff; // skirtumas sekundemis
	vector<double> testai;
	double tvid(const vector<double>& times) {
		if (times.empty()) return 0.0;
		return accumulate(times.begin(), times.end(), 0.0) / times.size();
	}

/* testavimo rezultatai:
	Vidutinis nuskaitymo vykdymo laikas 10 000 studentu per 6 testus: 0.604896 s
	Vidutinis nuskaitymo vykdymo laikas 100 000 studentu per 6 testus: 7.65952 s
	Vidutinis nuskaitymo vykdymo laikas 1 000 000 studentu per 6 testus: 40.6522 s
*/