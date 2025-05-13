#pragma once
#include"Header.h"

void SortMeniu() {
	while (true) {
		cout << "\nPasirinkite pagal ka norite surusiuoti: \n  a) Pavarde \n  b) Varda \n  c) Galutinis pagal vidurki \n  d) Galutinis pagal mediana. \nIveskite tik pasirinkimo raide: ";
		cin >> sortChoice;

		// tikrinama ar ivestis atitinka galimus paasirinkimus
		if (sortChoice == "a" || sortChoice == "b" || sortChoice == "c" || sortChoice == "d") {
			break;
		}
		else {
			cout << "\nNeteisingas pasirinkimas. Bandykite dar karta.\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruoja neteisinga ivesti
		}
	}
}

void Sort(const string& sortBy) {
	if (sortBy == "a") { //pavarde
		std::sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
			return a.pav < b.pav;
			});
	}
	else if (sortBy == "b") { //vardas
		std::sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
			return a.var < b.var;
			});
	}
	else if (sortBy == "c") { // vidurkio galutinis
		std::sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
			return a.galvid < b.galvid;
			});
	}
	else if (sortBy == "d") { // medianos galutinis
		std::sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
			return a.galmed < b.galmed;
			});
	}
}