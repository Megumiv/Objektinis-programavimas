#include "header1m.h"

int main() {

	stud grupe[100];  // MASYVAS

	while (true) {
		cout << "\nMeniu: \n";
		cout << "1 - Rankiniu budu ivesti pazymius\n";
		cout << "2 - Generuoti pazymius\n";
		cout << "3 - Generuoti pazymius ir studentu vardus bei pavardes\n";
		cout << "4 - Baigti darba ir isvesti rezultatus\n";
		cout << "Pasirinkite (1, 2, 3, 4): ";
		cin >> choice;

		if (choice == "1") {
			if (studentCount >= 100) {
				cout << "Maksimalus studentu kiekis pasiektas (100).\n";
				continue;
			}

			cout << "Iveskite studento varda ir pavarde: ";
			cin >> grupe[studentCount].var >> grupe[studentCount].pav;

			while (true) {
				cout << "Iveskite egzamino rezultata (0-10): ";
				cin >> grupe[studentCount].egz;
				if (grupe[studentCount].egz >= 0 && grupe[studentCount].egz <= 10) break;
				else cout << "Netinkamas pazymys. Iveskite skaiciu nuo 0 iki 10.\n";
			}

			grupe[studentCount].pazKiekis = 0;
			cout << "Iveskite namu darbu rezultatus (0-10), o jei norite pabaigti: -1: ";
			while (grupe[studentCount].pazKiekis < 10) {
				int tempPaz;
				cin >> tempPaz;
				if (tempPaz == -1) break;
				if (tempPaz >= 0 && tempPaz <= 10) {
					grupe[studentCount].paz[grupe[studentCount].pazKiekis] = tempPaz;
					grupe[studentCount].pazKiekis++;
				}
				else {
					cout << "Netinkamas pazymys. Iveskite skaiciu nuo 0 iki 10.\n";
				}
			}

		}
		else if (choice == "2") {
			if (studentCount >= 100) {
				cout << "Maksimalus studentu kiekis pasiektas (100).\n";
				continue;
			}

			cout << "Iveskite studento varda ir pavarde: ";
			cin >> grupe[studentCount].var >> grupe[studentCount].pav;

			grupe[studentCount].egz = dis(gen);
			cout << "Egzamino rezultatas (atsitiktinis, 0-10): " << grupe[studentCount].egz << endl;

			grupe[studentCount].pazKiekis = dis(gen) % 5 + 1;
			cout << "Namu darbu rezultatai (atsitiktiniai, 0-10): ";
			for (int j = 0; j < grupe[studentCount].pazKiekis; j++) {
				grupe[studentCount].paz[j] = dis(gen);
				cout << grupe[studentCount].paz[j] << " ";
			}
			cout << endl;
		}
		else if (choice == "3") {
			if (studentCount >= 100) {
				cout << "Maksimalus studentu kiekis pasiektas (100).\n";
				continue;
			}

			grupe[studentCount].var = firstNames[nameDist(gen)];
			grupe[studentCount].pav = lastNames[surnameDist(gen)];

			grupe[studentCount].egz = dis(gen);
			grupe[studentCount].pazKiekis = dis(gen) % 5 + 1;

			for (int j = 0; j < grupe[studentCount].pazKiekis; j++) {
				grupe[studentCount].paz[j] = dis(gen);
			}
		}
		else if (choice == "4") {
			break;
		}
		else {
			cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
		}

		int pasirinkimas;
		while (true) {
			cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
			cin >> pasirinkimas;
			if (pasirinkimas == 1 || pasirinkimas == 2) break;
			else cout << "Netinkama verte. Iveskite skaiciu 1 arba 2.\n";
		}

		if (pasirinkimas == 1)
			grupe[studentCount].gal = 0.4 * vidurkis(grupe[studentCount].paz, grupe[studentCount].pazKiekis) + 0.6 * grupe[studentCount].egz;
		else if (pasirinkimas == 2)
			grupe[studentCount].gal = 0.4 * mediana(grupe[studentCount].paz, grupe[studentCount].pazKiekis) + 0.6 * grupe[studentCount].egz;

		studentCount++;
	}

	cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas";
	cout << setw(25) << "Galutinis (Vid.) / (Med.)" << endl;
	cout << "--------------------------------------------\n";
	for (int i = 0; i < studentCount; i++) {
		cout << left << setw(15) << grupe[i].pav << setw(15) << grupe[i].var
			<< fixed << setprecision(2) << setw(20) << grupe[i].gal << endl;
	}

	return 0;
}
