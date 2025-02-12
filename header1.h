#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::cin; 
using std::fixed;
using std::setprecision; 
using std::left;

struct stud
{
	string var = "A";
	string pav = "A";
	vector <int> paz;
	int egz = 0;
	double gal;

};

int m = 0; //studentu kiekis
int nd = 0; //namu darbu rezultatai
int pasirinkimas; // skaiciuoti pagal vidurki ar mediana

double vidurkis (const vector<int>& nam) //namu darbu vidurkis
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