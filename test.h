#pragma once
#include "Header.h"


// testavimui
int testnr = 1; // <--- PAKEISTI NORINT TESTUOTI
std::chrono::duration<double> diff; // skirtumas sekundemis
vector<double> testai;
double tvid(const vector<double>& times) {
	if (times.empty()) return 0.0;
	return accumulate(times.begin(), times.end(), 0.0) / times.size();
}

/* testavimo rezultatai:
	Vidutinis nuskaitymo vykdymo laikas 10 000 studentu per 6 testus: 0.604896 s
	Vidutinis nuskaitymo vykdymo laikas 100 000 studentu per 6 testus: 7.65952 s
	Vidutinis nuskaitymo vykdymo laikas 1 000 000 studentu per 6 testus: 40.6522 s
*/
