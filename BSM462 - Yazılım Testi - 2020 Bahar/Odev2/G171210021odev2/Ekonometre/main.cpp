/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Main Program Source File
* </p>
*/
#include "Banka.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char** argv) {
    try {
        //::testing::InitGoogleTest(&argc, argv);
        //return RUN_ALL_TESTS();

        setlocale(LC_ALL, "Turkish");
        cout << std::fixed;
        cout << std::setprecision(2);
        Banka* b = new Banka();
        b->GuncelPortfoy();
        b->HisseFiyatGuncelle("hisseler.json");
        b->PortfoyGuncelle("portfoy.json");
        b->EmirGuncelle("emirler.json");
        b->PiyasaIslemi();
        //b->HisseEkle("123f", "AKSA", "AKSA", 123);
        //cout << b->HisseBul("AKSAM").getId(); //hata döndürür
    }
    catch (int msg) {
        cout << endl << "Hata: " << msg << endl;
    }

    return 0;
}