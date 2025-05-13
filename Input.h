#pragma once
#include "Header.h"

void Nuskaitymas(stud& laik, const string& filename) {

	ifstream file(filename);

	if (!file) {
		cout << "Klaida: Nepavyko atidaryti failo " << filename << ". Patikrinkite, ar failas egzistuoja.\n";
		return;
	}

	// praleidziama pirma nuskaitomo failo eilute
	string line;
	std::getline(file, line);

	// nuskaitymas
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		stud laik;
		ss >> laik.var >> laik.pav; // nuskaitomas vardas ir pavarde

		laik.paz.clear();  //

		vector<int> paz_temp;
		int pazymys = 0;

		while (ss >> pazymys) { // nuskaito visus skaicius vienoje linijoje
			paz_temp.push_back(pazymys);
		}

		if (paz_temp.empty()) {
			cout << "Klaida: Studentas " << laik.var << " neturi jokiu pazymiu.\n";
			continue;
		}

		laik.egz = paz_temp.back(); // paskutini skaiciu priskiria egzaminui
		paz_temp.pop_back(); // istrina skaiciu is namu darbu vertinimu
		laik.paz = paz_temp; // priskiria likusius skaicius prie namu darbu

		galutinis(laik); // galutinis balas

		grupe.push_back(laik);
	}
	file.close();
}


void ivedimai(stud& laik) {

	cout << "Iveskite studento varda ir pavarde: ";
	cin >> laik.var >> laik.pav;

	// egzamino pazymio ivedimas 
	while (true) {
		cout << "Iveskite egzamino rezultata (0-10): ";
		cin >> laik.egz;
		if (laik.egz >= 0 && laik.egz <= 10) break;
		else cout << "Netinkamas pazymys. Iveskite skaiciu nuo 0 iki 10.\n";
	}

	// namu darbu rezultatu ivedimas ranka
	cout << "Iveskite namu darbu tarpinius rezultatus (0-10), o jei norite pabaigti: -1: ";
	while (true) {
		cin >> nd;
		if (nd == -1) break;
		if (nd >= 0 && nd <= 10)
			laik.paz.push_back(nd);
		else
			cout << "Netinkamas pazymys. Iveskite skaiciu nuo 0 iki 10.\n";
	}
}
