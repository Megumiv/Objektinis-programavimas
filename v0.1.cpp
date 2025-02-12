#include "header1.h"

int main()
{
	cout << "Iveskite studentu kieki: ";
	cin >> m;

	vector <stud> grupe;
	for (int i = 0; i < m; i++)
	{
		stud laik;
		cout << "Iveskite studento varda ir pavarde: ";
		cin >> laik.var >> laik.pav;
		cout << "Iveskite egzamino rezultata (0-10): ";

		while (true) {
			cin >> laik.egz; 
			if (laik.egz >= 0 && laik.egz <= 10) break;
			else cout << "Netinkamas pazymys. Iveskite skaiciu nuo 0 iki 10.\n" << endl;
		}

		cout << "Iveskite namu darbu tarpinius rezultatus (0-10),\no jei norite pabaigti: -1: ";
		while (true)
		{
			cin >> nd;
			if (nd == -1) break;  // nutraukiame cikla ivede -1
			if (nd >= 0 && nd <= 10)
				laik.paz.push_back(nd);
			else
				cout << "Netinkamas pazymys. Iveskite skaiciu nuo 0 iki 10.\n";
		}

		if (pasirinkimas == 1) laik.gal = 0.4 * vidurkis(laik.paz) + 0.6 * laik.egz;
		else laik.gal = 0.4 * mediana(laik.paz) + 0.6 * laik.egz;
		
		grupe.push_back(laik);
	}

	cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
	cin >> pasirinkimas;

	// Rezultatai
	cout << endl << left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas";
	if (pasirinkimas==1) cout << std::setw(20) << "Galutinis (Vid.)" << endl;
	else cout << std::setw(20) << "Galutinis (Med.)" << endl;
	cout << "--------------------------------------------\n";

	for (auto& s : grupe)
	{
		cout << left << std::setw(15) << s.pav << std::setw(15) << s.var
		<< fixed << setprecision(2) << std::setw(20) << s.gal << endl;
	}

	return 0;
}
