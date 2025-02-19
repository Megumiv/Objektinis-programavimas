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

using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::cin; 
using std::fixed;
using std::setprecision; 
using std::left;
using std::setw; 

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
	double gal = 0.0; 
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
