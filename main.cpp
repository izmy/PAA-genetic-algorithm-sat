#include <iostream>
#include <fstream>
#include <sstream>
#include "CKlauzule.h"
#include "CGenerace.h"

#define SOUBOR "v10_c25_1.cnf"

using namespace std;

int main() {
    ifstream inputFile;
    string fileInst;
    string line;
    CKlauzule * klauzule;
    int * vahy;

    bool maVahu = 0;
    string del;
    int pocetPromennych = 0;
    int pocetKlauzuli = 0;

    int velikostPopulace = 6;
    int pocetGeneraci = 7;
    double pravdepodobnostKrizeni = 0.6;
    double pravdepodobnostMutace = 0.9;

    double timeSum = 0;
    int count = 0;

    fileInst = (string)"inst/" + SOUBOR;

    inputFile.open( fileInst.c_str() );


    while ( getline(inputFile, line) )
    {
        if ( inputFile.eof() && line.empty() ) break;
        istringstream ss(line);
        // komentar
        if ( line[0] == 'c' ) {
            //cout << line << endl;
        }
        // informace o instanci
        if ( line[0] == 'p' ) {
            ss >> del >> del >> pocetPromennych >> pocetKlauzuli;
            klauzule = new CKlauzule[pocetKlauzuli];
        }
        // vahy
        if ( line[0] == 'w' ) {
            maVahu = 1;
            vahy = new int [pocetPromennych];
            ss >> del;
            for (int i = 0; i < pocetPromennych; ++i) {
                ss >> vahy[i];
            }
        }

        if ( line[0] != 'c' && line[0] != 'p' && line[0] != 'w' ) {
            ss >> klauzule[count].var1 >> klauzule[count].var2 >> klauzule[count].var3 >> del;
            count++;
        }
    }

//    if ( maVahu ) {
//        for (int i = 0; i < pocetPromennych; ++i) {
//            cout << vahy[i] << " ";
//        }
//        cout << endl;
//    }
//
//    for (int i = 0; i < pocetKlauzuli; ++i) {
//        cout << klauzule[i].var1 << " " <<  klauzule[i].var2  << " " << klauzule[i].var3  << endl;
//    }

    clock_t timeStart = clock();


    CGenerace * generace = new CGenerace(pocetPromennych, velikostPopulace, pocetKlauzuli, klauzule, vahy);
    for (int i = 0; i < pocetGeneraci; ++i) {
        generace->evoluce(pravdepodobnostKrizeni, pravdepodobnostMutace);
        cout << i << ". " << generace->splneneKlauzule() << "/" << pocetKlauzuli << endl;
    }

    cout << "X = {";
    generace->vypsatNejlepsiReseni();
    cout << "}" << endl;
    cout << "S = " << generace->nejlepsiVaha() << endl;

    double duration = ( clock() - timeStart ) / (double) CLOCKS_PER_SEC;

    delete generace;
    delete klauzule;

    cout << "Čas zpracování instance: " << duration << endl;

    inputFile.close();

    return 0;
}