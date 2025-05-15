#pragma once
#include "Header.h"

// Nuskaitomi failai
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

// Duomenu ivedimai ranka
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


// Duomenu failu generavimas
void generateStudentFile(const std::string& filename, size_t recordCount) {
	std::ofstream out(filename);
	if (!out.is_open()) {
		std::cerr << "Nepavyko atidaryti failo: " << filename << "\n";
		return;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10);

	for (size_t i = 1; i <= recordCount; ++i) {
		out << "VardasNR" << i << " PavardeNR" << i << " "
			<< dis(gen) << " " << dis(gen) << " "
			<< dis(gen) << " " << dis(gen) << " "
			<< dis(gen) << "\n";
	}

	out.close();
	std::cout << "\nFailas sukurtas: " << filename << " (" << recordCount << " studentu)";
} 
void GenFailai() {
	std::vector<std::pair<std::string, size_t>> failai = {
		{"studentai_1k.txt", 1'000},
		{"studentai_10k.txt", 10'000},
		{"studentai_100k.txt", 100'000},
		{"studentai_1m.txt", 1'000'000},
		{"studentai_10m.txt", 10'000'000}
	};

	for (const auto& [filename, count] : failai) {
		auto start = std::chrono::high_resolution_clock::now();
		generateStudentFile(filename, count);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cout << "Sugeneruota per: " << elapsed.count() << " s\n\n";
	}
}
