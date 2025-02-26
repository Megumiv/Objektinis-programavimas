#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <random>
#include <cstdlib> 
#include <ctime>

using std::cout;
using std::string;
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
std::uniform_int_distribution<> nameDist(0, 9);
std::uniform_int_distribution<> surnameDist(0, 9);

int studentCount = 0;
string choice;

const string firstNames[] = { "Augustas", "Birute", "Daiva", "Ema", "Fiodoras", "Gabrielius", "Haroldas", "Ieva", "Tomas", "Nija" };
const string lastNames[] = { "Baravykas", "Kiskis", "Lydeka", "Burokas", "Neris", "Jankauskas", "Kazlauskas", "Urbonas", "Boruta", "Zemaite" };


struct stud {
	string var = "A";
	string pav = "A";
	int paz[10];      // namu darbu MASYVAS
	int pazKiekis = 0; //pazymiu kiekis
	int egz = 0;
	double gal = 0.0;
};

double vidurkis(const int paz[], int pazKiekis) {
	if (pazKiekis == 0) return 0.0;
	int sum = 0;
	for (int i = 0; i < pazKiekis; i++) {
		sum += paz[i];
	}
	return static_cast<double>(sum) / pazKiekis;
}

double mediana(int paz[], int pazKiekis) {
	if (pazKiekis == 0) return 0.0;
	std::sort(paz, paz + pazKiekis);
	if (pazKiekis % 2 == 0)
		return (paz[pazKiekis / 2 - 1] + paz[pazKiekis / 2]) / 2.0;
	else
		return paz[pazKiekis / 2];
}
