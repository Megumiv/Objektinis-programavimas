#pragma once
#include <iostream>
//#include <vector>
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
#include <filesystem>
#include <list>

using std::cout;
using std::string;
//using std::vector;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::left;
using std::setw;
using std::ifstream;
using std::accumulate; // suma / .size -> vidurkis
using std::ofstream;
using std::list; 

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 10);  // sugeneruoja random skaicius nuo 0 iki 10 - pazymiams
std::uniform_int_distribution<> diss(1, 10); // - studentu kiekiui

struct stud
{
	string var = "A";
	string pav = "A";
	list <int> paz;
	int egz = 0;
	double galvid = 0.0;  // galutinis pagal vidurki
	double galmed = 0.0;  // galutinis pagal mediana
};


int m = 0; //studentu kiekis
int nd = 0; //namu darbu rezultatai
int pasirinkimas = 0; // skaiciuoti pagal vidurki ar mediana
int isv = 0;

list<stud> grupe;
string choice;
list<int> paz_temp;
string sortChoice;
stud laik;

// vardu ir pavardziu sarasas
const list<string> firstNames = { "Augustas", "Birute", "Daiva", "Ema", "Fiodoras", "Gabrielius", "Haroldas", "Ieva", "Tomas", "Nija" };
const list<string> lastNames = { "Baravykas", "Kiskis", "Lydeka", "Burokas", "Neris", "Jankauskas", "Kazlauskas", "Urbonas", "Boruta", "Zemaite" };

// vardu ir pavardziu generavimui
string getNthElement(const std::list<std::string>& lst, int n) {
	auto it = lst.begin();         // pradedame nuo pradzios
	std::advance(it, n);           // persokame n poziciju pirmyn
	return *it;                    // graziname reiksme
}
 