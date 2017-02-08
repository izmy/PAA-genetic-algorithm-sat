//
// Created by Jaroslav Hrách on 26.12.16.
//

#ifndef GENETIKA_CGENERACE_H
#define GENETIKA_CGENERACE_H

#include <vector>
#include "CKlauzule.h"
#include "CChromozom.h"

using namespace std;

class CGenerace {
private:
    vector<CChromozom *> listChromozomu;
    int delkaChromozomu;
    int velikostPopulace;
    int pocetKlauzuli;
    CKlauzule * klauzule;
    int * vahy;
public:
    CGenerace(int delkaChromozomu, int velikostPopulace, int pocetKlauzuli, CKlauzule klauzule[], int vahy[]);
    ~CGenerace();
    void pridatChromozom(CChromozom * chromozom);
    void evoluce(double pravdepodobnostKrizeni, double pravdepodobnostMutace);
    void selekce();
    void krizeni(double pravdepodobnostKrizeni);
    void mutace(double pravdepodobnostMutace);
    void vypsatGeneraci();
    void vypsatNejlepsiReseni();
    int nejlepsiVaha();
    int splneneKlauzule();
};


#endif //GENETIKA_CGENERACE_H
