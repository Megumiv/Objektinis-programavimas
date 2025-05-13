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
#include <stdexcept> //

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
using std::accumulate; // suma / .size -> vidurkis
using std::ofstream;

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
int pasirinkimas = 0; // skaiciuoti pagal vidurki ar mediana
int isv = 0;

vector<stud> grupe;
string choice;
vector<int> paz_temp;
string sortChoice;
stud laik;

// vardu ir pavardziu sarasas
const vector<string> firstNames = { "Augustas", "Birute", "Daiva", "Ema", "Fiodoras", "Gabrielius", "Haroldas", "Ieva", "Tomas", "Nija" };
const vector<string> lastNames = { "Baravykas", "Kiskis", "Lydeka", "Burokas", "Neris", "Jankauskas", "Kazlauskas", "Urbonas", "Boruta", "Zemaite" };

