//
// Created by Jaroslav Hrách on 26.12.16.
//

#ifndef GENETIKA_CCHROMOZOM_H
#define GENETIKA_CCHROMOZOM_H

#include <iostream>
#include "CKlauzule.h"

using namespace std;

class CChromozom {
private:
    bool * geny;
    int delkaChromozomu;
    int fitnessHodnota;
    int maxVaha;
    int splneneKlauzule;
public:
    CChromozom(int delkaChromozomu);
    ~CChromozom();
    void nahodnyChromozom();
    void kopie(CChromozom * chromozom);
    bool getGen(int poradi);
    void setGen(int poradi, bool novaHodnota);
    void fitness(int pocetKlauzuli, CKlauzule klauzule[], int vahy[]);
    int getFitness();
    int getMaxVaha();
    int getSplneneKlauzule();
    void vypsatGeny();
};


#endif //GENETIKA_CCHROMOZOM_H
