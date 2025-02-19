#include "header1.h"

int main()
{
	vector<stud> grupe; 
	string choice; 

	while (true) {
		// Meniu
		cout << "\nMeniu: \n";
		cout << "1 - Rankiniu budu ivesti pazymius\n";
		cout << "2 - Generuoti pazymius\n";
		cout << "3 - Generuoti pazymius ir studentu vardus bei pavardes\n";
		cout << "4 - Baigti darba ir isvesti rezultatus\n";
		cout << "Pasirinkite (1, 2, 3, 4): ";
		cin >> choice;

		if (choice == "1") //ivedama ranka
		{

			cout << "Iveskite studentu kieki: ";
			cin >> m;

			// norint generuoti atsitiktinai:
			// m = diss(gen);
			// cout << "Studentu kiekis (atsitiktinis, 1-10): " << m << endl; 

			for (int i = 0; i < m; i++) {
				stud laik;
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

				// pasirenkamas vidurkis arba mediana
				while (true) { 
					cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
					cin >> pasirinkimas;
					if (pasirinkimas == 1 || pasirinkimas == 2) break;
					else cout << "Netinkama verte. Iveskite skaiciu 1 arba 2.\n";
				}

				if (pasirinkimas == 1)
					laik.gal = 0.4 * vidurkis(laik.paz) + 0.6 * laik.egz;
				else if (pasirinkimas == 2)
					laik.gal = 0.4 * mediana(laik.paz) + 0.6 * laik.egz;

				grupe.push_back(laik);
			}
		}

		else if (choice == "2") //sugeneruojami pazymiai
		{
			m = diss(gen); // random studentu kiekis 1-10
			cout << "Studentu kiekis (atsitiktinis, 1-10): " << m << endl;

			while (true) { // pasirenkamas vidurkis arba mediana
				cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
				cin >> pasirinkimas;
				if (pasirinkimas == 1 || pasirinkimas == 2) break;
				else cout << "Netinkama verte. Iveskite skaiciu 1 arba 2.\n";
			}

			for (int i = 0; i < m; i++) {
				stud laik;

				// ivedama ranka
				cout << "Iveskite studento varda ir pavarde: ";
				cin >> laik.var >> laik.pav;

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

				// galutinis balas
				if (pasirinkimas == 1)
					laik.gal = 0.4 * vidurkis(laik.paz) + 0.6 * laik.egz;
				else if (pasirinkimas == 2)
					laik.gal = 0.4 * mediana(laik.paz) + 0.6 * laik.egz;

				grupe.push_back(laik);
			}
		}



		else if (choice == "3") // sugeneruojami pazymiai ir vardai
		{
			m = diss(gen); // random studentu kiekis 1-10
			cout << "Studentu kiekis (atsitiktinis, 1-10): " << m << endl;

			while (true) { // pasirenkamas vidurkis arba mediana
				cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
				cin >> pasirinkimas;
				if (pasirinkimas == 1 || pasirinkimas == 2) break;
				else cout << "Netinkama verte. Iveskite skaiciu 1 arba 2.\n";
			}

			// vardu ir pavardziu sarasas
			const vector<string> firstNames = { "Augustas", "Birute", "Daiva", "Ema", "Fiodoras", "Gabrielius", "Haroldas", "Ieva", "Tomas", "Nija" };
			const vector<string> lastNames = { "Baravykas", "Kiskis", "Lydeka", "Burokas", "Neris", "Jankauskas", "Kazlauskas", "Urbonas", "Boruta", "Zemaite" };

			std::uniform_int_distribution<> nameDist(0, firstNames.size() - 1);
			std::uniform_int_distribution<> surnameDist(0, lastNames.size() - 1);

			for (int i = 0; i < m; i++) {
				stud laik;

				// random priskiriami vardai ir pavardes
				laik.var = firstNames[nameDist(gen)];
				laik.pav = lastNames[surnameDist(gen)];

				// random egzamino pazymys 0-10
				laik.egz = dis(gen);

				// random namu darbu vertinimai
				int num_homework = diss(gen) % 5 + 1; // Between 1-5 homework scores
				for (int j = 0; j < num_homework; j++) {
					laik.paz.push_back(dis(gen));
				}

				// galutinis balas
				if (pasirinkimas == 1)
					laik.gal = 0.4 * vidurkis(laik.paz) + 0.6 * laik.egz;
				else if (pasirinkimas == 2)
					laik.gal = 0.4 * mediana(laik.paz) + 0.6 * laik.egz;

				grupe.push_back(laik);
			}
		} 

		else if (choice == "4") { //baigiamas darbas - isvestis
			break;
        } 

		else {
			cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n"; //meniu neteisingo ivedimo isvestis
			continue;
		}
	}

		// Rezultatai
		cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas";
		cout << setw(25) << "Galutinis (Vid.) / (Med.)" << endl;
		cout << "--------------------------------------------\n";
		for (auto& s : grupe) {
			cout << left << setw(15) << s.pav << setw(15) << s.var
				<< fixed << setprecision(2) << setw(20) << s.gal << endl;
		}
	
	return 0;
}
