//
// Created by Jaroslav Hrách on 26.12.16.
//


#include "CChromozom.h"

CChromozom::CChromozom(int delkaChromozomu) {
    this->delkaChromozomu = delkaChromozomu;
    geny = new bool[delkaChromozomu];
    fitnessHodnota = 0;
    maxVaha = 0;
    splneneKlauzule = 0;
};

CChromozom::~CChromozom() {
    delete geny;
};

void CChromozom::nahodnyChromozom() {
    for (int i = 0; i < delkaChromozomu; ++i) {
        int nahodnyStav = rand() % 2;
        geny[i] = nahodnyStav;
    }
}

void CChromozom::kopie(CChromozom *chromozom) {
    for (int i = 0; i < delkaChromozomu; ++i) {
        geny[i] = chromozom->getGen(i);
    }
}

bool CChromozom::getGen(int poradi) {
    return geny[poradi];
}

void CChromozom::setGen(int poradi, bool novaHodnota) {
    geny[poradi] = novaHodnota;
}

void CChromozom::fitness(int pocetKlauzuli, CKlauzule klauzule[], int vahy[]) {
    int tmpVaha = 0;

    int pocetSplnenychKlauzuli = 0;
    bool splnenaKlauzule = 0;
    fitnessHodnota = 0;


    for (int i = 0; i < pocetKlauzuli; ++i) {
        splnenaKlauzule = 0;
        // promenna 1
        if( geny[abs(klauzule[i].var1) - 1] == 1 && klauzule[i].var1 > 0) {
            splnenaKlauzule = 1;
        } else if (geny[abs(klauzule[i].var1) - 1] == 0 && klauzule[i].var1 < 0) {
            splnenaKlauzule = 1;
        }
        // promenna 2
        if( geny[abs(klauzule[i].var2) - 1] == 1 && klauzule[i].var2 > 0) {
            splnenaKlauzule = 1;
        } else if (geny[abs(klauzule[i].var2) - 1] == 0 && klauzule[i].var2 < 0) {
            splnenaKlauzule = 1;
        }

        // promenna 3
        if( geny[abs(klauzule[i].var3) - 1] == 1 && klauzule[i].var3 > 0) {
            splnenaKlauzule = 1;
        } else if (geny[abs(klauzule[i].var3) - 1] == 0 && klauzule[i].var3 < 0) {
            splnenaKlauzule = 1;
        }
        if( splnenaKlauzule ) pocetSplnenychKlauzuli++;
    }

    splneneKlauzule = pocetSplnenychKlauzuli;

    if (pocetSplnenychKlauzuli == pocetKlauzuli) {
        for (int i = 0; i < delkaChromozomu; ++i) {
            tmpVaha += geny[i] == 1 ? vahy[i] : 0;
        }
        fitnessHodnota += tmpVaha;
    }

    maxVaha = tmpVaha;
    fitnessHodnota += pocetSplnenychKlauzuli;
}

int CChromozom::getFitness() {
    return fitnessHodnota;
}

void CChromozom::vypsatGeny() {
    for (int i = 0; i < delkaChromozomu; ++i) {
        cout << geny[i];
        if ( i < delkaChromozomu - 1 ) cout << ", ";
    }
}

int CChromozom::getMaxVaha() {
    return maxVaha;
}

int CChromozom::getSplneneKlauzule() {
    return splneneKlauzule;
}
