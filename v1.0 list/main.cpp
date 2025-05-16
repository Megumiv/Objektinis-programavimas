#include "skaiciavimas.h"
#include "test.h"
#include "sort.h"
#include "Input.h"
#include "Output.h"
#include "penkiOut.h"


int main()
{
	while (true) {

		meniu(); // isvedami meniu pasirinkimai

		if (choice == "1") //ivedama ranka
		{
			// studentu kiekio ivedimas
			while (true) {
				cout << "Iveskite studentu kieki: ";
				cin >> m;
				if (m > 0) break;
				else cout << "Netinkamas skaicius. Maziausias galimas 1.\n";
			}

			// vardu ivedimas
			for (int i = 0; i < m; i++) {
				ivedimai(laik);
			}

			vidarmed(); // pasirenkamas vidurkis arba mediana
			galutinis(laik);  // galutinis balas

			grupe.push_back(laik);
		}

		else if (choice == "2") //sugeneruojami pazymiai
		{
			vidarmed(); // pasirenkamas vidurkis arba mediana

			m = diss(gen); // random studentu kiekis 1-10
			cout << "Studentu kiekis (atsitiktinis, 1-10): " << m << endl;

			for (int i = 0; i < m; i++) {

				// ivedama ranka
				cout << "Iveskite studento varda ir pavarde: ";
				cin >> laik.var >> laik.pav;

				pazymiai(laik);  // sugeneruojami egzamino ir namu darbu pazymiai
				galutinis(laik); // galutinis balas

				grupe.push_back(laik);
			}
		}

		else if (choice == "3") // sugeneruojami pazymiai ir vardai
		{
			vidarmed(); // pasirenkamas vidurkis arba mediana

			m = diss(gen); // random studentu kiekis 1-10
			cout << "\nStudentu kiekis (atsitiktinis, 1-10): " << m << endl;

			std::uniform_int_distribution<> nameDist(0, firstNames.size() - 1);
			std::uniform_int_distribution<> surnameDist(0, lastNames.size() - 1);

			for (int i = 0; i < m; i++) {

				// random priskiriami vardai ir pavardes
				int nameIndex = nameDist(gen); 
				int surnameIndex = surnameDist(gen); 

				laik.var = getNthElement(firstNames, nameIndex); 
				laik.pav = getNthElement(lastNames, surnameIndex); 

				cout << endl;
				cout << laik.var << " " << laik.pav << " --- ";

				pazymiai(laik); // sugeneruojami egzamino ir namu darbu pazymiai
				galutinis(laik); // galutinis balas

				grupe.push_back(laik);
			}
		}

		else if (choice == "4") { // duomenys nuskaitomi is failo

			vidarmed(); // pasirenkamas vidurkis arba mediana

			//string filename = "kursiokai.txt"; // <--- skirtingiems failams istestuoti PAKEICIAMAS pavadinimas / atkometuojama
			string filename = "studentai10000.txt";
			//string filename = "studentai100000.txt";					
			//string filename = "studentai1000000.txt";

			// Paleisti testavima
			auto start = std::chrono::high_resolution_clock::now();

			for (int i = 0; i < testnr; i++)
			{
				Nuskaitymas(laik, filename);
			}

			auto end = std::chrono::high_resolution_clock::now(); // stabdyti testavima
			diff = end - start; // skirtumas sekundemis 
			testai.push_back(diff.count());
			//}

			if (testnr > 1) { cout << "\nVidutinis nuskaitymo vykdymo laikas 1 000 studentu per " << testnr << " testus: " << tvid(testai) << " s\n"; } // testavimo rezultatas 
		}

		else if (choice == "5") { // baigiamas darbas - isvestis ir rusiavimas

			SortMeniu(); // rusiavimo eigos pasirinkimas
			Sort(sortChoice);  // rusiavimo funkcija
			Isvedimas(grupe); // Rezultatai
			cout << "\nSuskirstymui pagal bala i kietiaciu ir vargsiuku failus:";
			SortMeniu(); // rusiavimo eigos pasirinkimas
			Sort(sortChoice);  // rusiavimo funkcija
			Skirstymas(grupe); // Kietiaciu ir vargsiuku failai

			break;
		}

		else if (choice == "6") { // generuojami duomenu failai
			GenFailai();
		}

		else { // meniu neteisingo ivedimo isvestis
			cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
			continue;
		}
	}
	return 0;
}