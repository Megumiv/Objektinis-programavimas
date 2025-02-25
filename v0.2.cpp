#include "header2.h"


int main()
{
	while (true) {

		meniu(); // isvedami meniu pasirinkimai

		if (choice == "1") //ivedama ranka
		{
			cout << "Iveskite studentu kieki: ";
			cin >> m;

			/* norint generuoti atsitiktinai :
			  m = diss(gen);
			  cout << "Studentu kiekis (atsitiktinis, 1-10): " << m << endl; 
			*/

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

				// galutinis balas
				if (pasirinkimas == 1) {
					laik.galvid = (0.4 * vidurkis(laik.paz) + 0.6 * laik.egz);
					laik.galmed = -1;
				}
				else if (pasirinkimas == 2) {
					laik.galmed = (0.4 * mediana(laik.paz) + 0.6 * laik.egz);
					laik.galvid = -1;
				}

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
				if (pasirinkimas == 1) {
					laik.galvid = (0.4 * vidurkis(laik.paz) + 0.6 * laik.egz);
					laik.galmed = -1;
				}
				else if (pasirinkimas == 2) {
					laik.galmed = (0.4 * mediana(laik.paz) + 0.6 * laik.egz);
					laik.galvid = -1;
				}

				grupe.push_back(laik);
			}
		}

		else if (choice == "3") // sugeneruojami pazymiai ir vardai
		{
			m = diss(gen); // random studentu kiekis 1-10
			cout << "\nStudentu kiekis (atsitiktinis, 1-10): " << m << endl;

			while (true) { // pasirenkamas vidurkis arba mediana
				cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
				cin >> pasirinkimas;
				if (pasirinkimas == 1 || pasirinkimas == 2) break;
				else cout << "Netinkama verte. Iveskite skaiciu 1 arba 2.\n";
			}

			std::uniform_int_distribution<> nameDist(0, firstNames.size() - 1);
			std::uniform_int_distribution<> surnameDist(0, lastNames.size() - 1);

			for (int i = 0; i < m; i++) {
				stud laik;

				// random priskiriami vardai ir pavardes
				laik.var = firstNames[nameDist(gen)];
				laik.pav = lastNames[surnameDist(gen)];

				cout << endl;
				cout << laik.var << " " << laik.pav << " --- ";

				// random egzamino pazymys 0-10
				laik.egz = dis(gen);
				cout << "Egzaminas: " << laik.egz <<", ";

				cout << "Namu darbai: ";
				// random namu darbu vertinimai
				int num_homework = diss(gen) % 5 + 1; // nuo 1 iki 5 rezultatu
				for (int j = 0; j < num_homework; j++) {
					laik.paz.push_back(dis(gen));
					cout << dis(gen) << " "; 
				}

				// galutinis balas
				if (pasirinkimas == 1) {
					laik.galvid = (0.4 * vidurkis(laik.paz) + 0.6 * laik.egz);
					laik.galmed = -1;
				}
				else if (pasirinkimas == 2) {
					laik.galmed = (0.4 * mediana(laik.paz) + 0.6 * laik.egz);
					laik.galvid = -1;
				}

				grupe.push_back(laik);
			}
		}

		else if (choice == "4") { // duomenys nuskaitomi is failo

			// pasirenkamas vidurkis arba mediana
			while (true) { 
				cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
				cin >> pasirinkimas;
				if (pasirinkimas == 1 || pasirinkimas == 2) break;
				else cout << "Netinkama verte. Iveskite skaiciu 1 arba 2.\n";
			}

			for (int i = 0; i < testnr; i++)
			{
				// Paleisti testavima
				auto start = std::chrono::high_resolution_clock::now(); 

				string filename = "kursiokai.txt"; // <--- skirtingiems failams istestuoti PAKEICIAMAS pavadinimas / atkometuojama
				//string filename = "studentai10000.txt";
				//string filename = "studentai100000.txt";
				//string filename = "studentai1000000.txt";

				ifstream file(filename);

				if (!file) {
					cout << "Klaida: Nepavyko atidaryti failo " << filename << ". Patikrinkite, ar failas egzistuoja.\n";
					continue;
				}

				// praleidziama pirma nuskaitomo failo eilute
				string line;
				std::getline(file, line);

				// nuskaitymas
				while (std::getline(file, line)) {
					std::istringstream ss(line);
					stud laik;
					ss >> laik.var >> laik.pav; // nuskaitomas vardas ir pavarde

					laik.paz.clear();

					vector<int> paz_temp;
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

					// galutinis balas
					if (pasirinkimas == 1) {
						laik.galvid = (0.4 * vidurkis(laik.paz) + 0.6 * laik.egz);
						laik.galmed = -1;
					}
					else if (pasirinkimas == 2) {
						laik.galmed = (0.4 * mediana(laik.paz) + 0.6 * laik.egz);
						laik.galvid = -1;
					}

					grupe.push_back(laik);
				}
				file.close();

				auto end = std::chrono::high_resolution_clock::now(); // stabdyti testavima
				diff = end - start; // skirtumas sekundemis 
				testai.push_back(diff.count());
			}
			if (testnr > 1) { cout << "\nVidutinis nuskaitymo vykdymo laikas 1 000 000 studentu per " << testai.size() << " testus: " << tvid(testai) << " s\n"; } // testavimo rezultatas 
			
		}

		else if (choice == "5") { // baigiamas darbas - isvestis ir rusiavimas

			while (true) {
				cout << "\nPasirinkite pagal ka norite surusiuoti: \n  a) Pavarde \n  b) Varda \n  c) Galutinis pagal vidurki \n  d) Galutinis pagal mediana. \nIveskite tik pasirinkimo raide: ";
				cin >> sortChoice;

				// tikrinama ar ivestis atitinka galimus paasirinkimus
				if (sortChoice == "a" || sortChoice == "b" || sortChoice == "c" || sortChoice == "d") {
					break;}
				else {
					cout << "\nNeteisingas pasirinkimas. Bandykite dar karta.\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruoja neteisinga ivesti
				}
			}
			Sort(sortChoice);  // rusiavimo funkcija
			break;
		}

		else { // meniu neteisingo ivedimo isvestis
			cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n"; 
			continue;
		}
	}

	// Rezultatai
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
	return 0;
}
