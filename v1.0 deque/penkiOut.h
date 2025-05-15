#pragma once
#include "Header.h"

void Skirstymas(const std::deque<stud>& visiStudentai) {
    deque<stud> kietiakiai;
    deque<stud> vargsiukai;

    for (const auto& s : visiStudentai) {
        if (s.galvid >= 5.0 || s.galmed>=5.0)
            kietiakiai.push_back(s);
        else
            vargsiukai.push_back(s);
    }

    std::ofstream outKiet("kietiakiai.txt");
    std::ofstream outVargs("vargsiukai.txt");

    if (!outKiet || !outVargs) {
        std::cerr << "Nepavyko atidaryti isvesties failu.\n";
        return;
    }


    outKiet << left << setw(15) << "\nPavarde" << setw(15) << "Vardas";
    outKiet << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    outKiet << "------------------------------------------------------------------\n";
    for (auto& s : kietiakiai) {
        outKiet << left << setw(15) << s.pav << setw(15) << s.var;

        // galutinis pasirinktas pagal vidurki, o prie medianos - x
        if (s.galvid == -1) outKiet << setw(20) << "x.xx";
        else outKiet << fixed << setprecision(2) << setw(20) << s.galvid;

        // galutinis pasirinktas pagal mediana, o prie vidurkio - x
        if (s.galmed == -1) outKiet << setw(20) << "x.xx" << endl;
        else outKiet << fixed << setprecision(2) << setw(20) << s.galmed << endl;
    }

    outVargs << left << setw(15) << "\nPavarde" << setw(15) << "Vardas";
    outVargs << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    outVargs << "------------------------------------------------------------------\n";

    for ( auto& s : vargsiukai) {
        outVargs << left << setw(15) << s.pav << setw(15) << s.var;

        // galutinis pasirinktas pagal vidurki, o prie medianos - x
        if (s.galvid == -1) outVargs << setw(20) << "x.xx";
        else outVargs << fixed << setprecision(2) << setw(20) << s.galvid;

        // galutinis pasirinktas pagal mediana, o prie vidurkio - x
        if (s.galmed == -1) outVargs << setw(20) << "x.xx" << endl;
        else outVargs << fixed << setprecision(2) << setw(20) << s.galmed << endl;
    }
//failas.close();

    cout << "\nPapildomai surusiuota ir isvesta i failus: \"kietiakiai.txt\" (balas >= 5) ir \"vargsiukai.txt\" (balas < 5).\n";
}

