#pragma once
#include "Header.h"


// testavimui
int testnr = 1; // <--- PAKEISTI NORINT TESTUOTI
std::chrono::duration<double> diff; // skirtumas sekundemis
list<double> testai;
double tvid(const list<double>& times) {
	if (times.empty()) return 0.0;
	return accumulate(times.begin(), times.end(), 0.0) / times.size();
}

/* testavimo rezultatai VECTOR:
	Vidutinis nuskaitymo vykdymo laikas 10 000 studentu per 5 testus: 8.64434 s
	Vidutinis nuskaitymo vykdymo laikas 100 000 studentu per 5 testus: 110.531 s
	Vidutinis nuskaitymo vykdymo laikas 1 000 000 studentu per 5 testus: 442.675 s
*/

/* Nauju generuojamu duomenu failu testavimo rezultatai:
	1 000 studentu:  0.0172659 s
	10 000 studentu:  0.145388 s
	100 000 studentu:  1.495 s
	1 000 000 studentu:  15.8693 s
	10 000 000 studentu:   165.408 s
*/