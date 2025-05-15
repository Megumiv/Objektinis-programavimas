#pragma once
#include "Header.h"

void Isvedimas(const vector<stud>& grupe) {
	while (true) {
		cout << "\nIrasykite, i kur norite isvesti rezultatus (1 - ekrana, 2 - faila): ";
		cin >> isv;
		if (isv == 1 || isv == 2) break;
		else cout << "Netinkama verte. Iveskite skaiciu 1 arba 2.\n";
	}

	// isvestis i ekrana
	if (isv == 1) {

		cout << left << setw(15) << "\nPavarde" << setw(15) << "Vardas";
		cout << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
		cout << "------------------------------------------------------------------\n";

		for (auto& s : grupe) {
			cout << left << setw(15) << s.pav << setw(15) << s.var;

			// galutinis pasirinktas pagal vidurki, o prie medianos - x
			if (s.galvid == -1) cout << setw(20) << "x.xx";
			else cout << fixed << setprecision(2) << setw(20) << s.galvid;

			// galutinis pasirinktas pagal mediana, o prie vidurkio - x
			if (s.galmed == -1) cout << setw(20) << "x.xx" << endl;
			else cout << fixed << setprecision(2) << setw(20) << s.galmed << endl;
		}
	}

	// isvestis i faila
	if (isv == 2) {

		string file = "Rezultatai.txt";
		ofstream failas(file);

		if (!failas) {
			cout << "Klaida atidarant faila!\n";
			//return 1;
		}

		failas << left << setw(15) << "\nPavarde" << setw(15) << "Vardas";
		failas << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
		failas << "------------------------------------------------------------------\n";

		for (auto& s : grupe) {
			failas << left << setw(15) << s.pav << setw(15) << s.var;

			// galutinis pasirinktas pagal vidurki, o prie medianos - x
			if (s.galvid == -1) failas << setw(20) << "x.xx";
			else failas << fixed << setprecision(2) << setw(20) << s.galvid;

			// galutinis pasirinktas pagal mediana, o prie vidurkio - x
			if (s.galmed == -1) failas << setw(20) << "x.xx" << endl;
			else failas << fixed << setprecision(2) << setw(20) << s.galmed << endl;
		}
		failas.close();
		cout << "\nRezultatai issaugoti faile: " << file << endl;
	}
}

