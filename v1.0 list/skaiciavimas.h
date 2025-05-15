#pragma once
#include "Header.h"

double vidurkis(const list<int>& nam) // namu darbu vidurkis
{
	if (nam.empty()) return 0.0;
	return accumulate(nam.begin(), nam.end(), 0.0) / nam.size();
}

double mediana(list<int> nd) {
	if (nd.empty()) return 0.0;
	nd.sort(); // list
	size_t size = nd.size();
	auto it = nd.begin();
	std::advance(it, size / 2);
	if (size % 2 == 0) {
		auto it2 = it;
		std::advance(it2, -1);
		return (*it + *it2) / 2.0;
	}
	else {
		return *it;
	}
}

// Meniu
void meniu()
{
	cout << "\n\nMeniu: \n";
	cout << "1 - Rankiniu budu ivesti pazymius\n";
	cout << "2 - Generuoti pazymius\n";
	cout << "3 - Generuoti pazymius ir studentu vardus bei pavardes\n";
	cout << "4 - Duomenis nuskaityti is failo\n";
	cout << "5 - Baigti darba ir isvesti rezultatus\n";
	cout << "6 - Sugeneruoti testavimo failus\n";

	cout << "Pasirinkite (1, 2, 3, 4, 5, 6 ): ";
	cin >> choice;
}


void galutinis(stud& laik) {
	if (pasirinkimas == 1) {
		laik.galvid = (0.4 * vidurkis(laik.paz) + 0.6 * laik.egz);
		laik.galmed = -1;
	}
	else if (pasirinkimas == 2) {
		laik.galmed = (0.4 * mediana(laik.paz) + 0.6 * laik.egz);
		laik.galvid = -1;
	}
	else {
		cout << "Neteisingas pasirinkimas.\n";
	}
}


void vidarmed() {
	while (true) {
		cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
		cin >> pasirinkimas;
		if (pasirinkimas == 1 || pasirinkimas == 2) break;
		else cout << "Netinkama verte. Iveskite skaiciu 1 arba 2.\n";
	}
}


void pazymiai(stud& laik) {
	// random egzamino pazymys
	laik.egz = dis(gen);
	cout << "Egzamino rezultatas (atsitiktinis, 0-10): " << laik.egz << endl;

	// random namu darbu rezultatai
	int num_homework = dis(gen) % 5 + 1;
	cout << "Namu darbu rezultatai (atsitiktiniai, 0-10): ";
	for (int j = 0; j < num_homework; j++) {
		int random_homework = dis(gen);
		laik.paz.push_back(random_homework);
		cout << random_homework << " ";
	}
	cout << endl;
}
