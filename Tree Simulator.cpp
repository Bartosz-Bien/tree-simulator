// projekt albo grywalna gra w trybie tekstowym
// kiedys savy oraz moze allegro


//sleep w pasekladowania ma miec 50

#include <iostream>
#include <windows.h>
#include "wtypes.h" // od fullscreena
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

void GetDesktopResolution(int& horizontal, int& vertical)   //fullscreen
{
   RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

void pasekLadowania () {
    for (int i=0; i<=100; i++){
        system("CLS");
        cout << endl << endl << endl << endl << endl << endl;
        cout <<"        ----------------------------------------------------------------------------------------------------" <<endl;
        cout <<"      |                                                                                                      |"<<endl;
        cout <<"      | ";
            for (int j=0; j<i; j++) {
                cout <<"x";
            }
            for (int k=100-i; k>0; k--) {
                cout <<" ";
            }
        cout <<" |" << endl;
        cout <<"      |                                                                                                      |"<<endl;
        cout <<"        ----------------------------------------------------------------------------------------------------" <<endl;
    Sleep(5);
    }

}

int wybor(char znak, int &miesiac, int &miesiaceGry, int &iloscPieniedzy, int &iloscNawozu, int &iloscDrzew) {

    if (znak == '0')
        miesiac = miesiaceGry;
    if (znak == '2') {
        iloscNawozu ++;
        iloscPieniedzy -= 50;
    }
    if (znak == '3') {
        iloscDrzew ++;
        iloscPieniedzy -= 3000;
    }
    if (znak == '4') {
       // zapisGry(miesiaceGry, iloscDrzew, iloscNawozu, iloscPieniedzy);
    }
}

void sklepKomunikat () {
    system("CLS");
    cout << "Wpisz 0 by wyjsc" << endl;
    cout << "Wpisz 1 by grac i nic nie kupowac" << endl;
    cout << "Wpisz 2 by kupic nawoz" << endl;
    cout << "Wpisz 3 by kupic drzewo" << endl;
    cout << "Wpisz 4 by zapisac gre i wyjsc [beta]" << endl;
}

void grafikaDrzewa () {
    cout << "                  oooooooooooooo               " << endl;
    cout << "                ooooooooooo x oooo                 " << endl;
    cout << "              oo x ooooooo x ooooo                " << endl;
    cout << "             oooo x ooooo x ooooooo               " << endl;
    cout << "              ooooo x o x oooooooo                   " << endl;
    cout << "                ooooo x x oooooo                    " << endl;
    cout << "                   ooo xx o x o                  " << endl;
    cout << "                     o xx x o                  " << endl;
    cout << "                       xx                       " << endl;
    cout << "                       xx                       " << endl;
    cout << "              -----------------------        " << endl;;

}

void grafikaNawozu () {
    cout << "               ------------------" << endl;
    for (int i=0; i<5; i++) {
        cout << "              |                  |"<< endl;
    }
    cout << "              |       nawoz      |"<< endl;
    for (int i=0; i<5; i++) {
        cout << "              |                  |"<< endl;
    }
    cout << "               ------------------" << endl;

}

void szkodniki (int &iloscDrzew, int &iloscNawozu) {
    system("CLS");
    int prawd;
    char wybor;
    prawd = rand() % 100;

    while (prawd <= 10) {
        cout << "Drzewo ma szkodniki. Uzyj nawozu." << endl;
        cout << "Nacisnij 1, aby uzyc nawozu (-1 nawoz)" << endl;
        cout << "Nacisnij 2, aby nic nie zrobic (-1 drzewo)" << endl;

        cin >> wybor;
        if (wybor == '1' && iloscNawozu != 0) {
            system("CLS");
            cout << "uzywasz nawozu i drzewko zdrowieje" << endl;
            prawd = 101;
            iloscNawozu --;
            Sleep(2000);
        }
        if (wybor == '1' && iloscNawozu == 0) {
            system("CLS");
            cout << "Niestety nie masz tyle nawozu, chyba musisz poswiecic drzewo..." << endl;
            Sleep(2000);
        }
        if (wybor == '2') {
            system("CLS");
            cout << "Postanawiasz poswiecic drzewo..." << endl;
            iloscDrzew --;
            prawd = 101;
            Sleep(2000);
        }
        if (wybor != '1' && wybor !='2') {
            system("CLS");
            cout << "Wpisz poprawnie." << endl;
            Sleep(2000);
        }
    }

}

void zapisGry (int &miesiaceGry, int &iloscDrzew, int &iloscNawozu, int &iloscPieniedzy) {
    ofstream zapis ("zapis.txt");
    zapis << miesiaceGry << endl;
    zapis << iloscDrzew << endl;
    zapis << iloscNawozu << endl;
    zapis << iloscPieniedzy << endl;
}


int main () {
srand(time(NULL));
    //poczatek fullscreena
    int horizontal = 0;
    int vertical = 0;
    GetDesktopResolution(horizontal, vertical);
    //koniec fullscreena

int miesiac=0, miesiaceGry, iloscDrzew=1, iloscNawozu=99, iloscPieniedzy=99999, cenaDrzewa, cenaNawozu;
char klawiszGracza;

//cout<<"Podaj lata gry: ";
//cin >> lataGry;
miesiaceGry=60;

// g³ówna petla gry
for (; miesiac<=miesiaceGry; miesiac++) {

        if (miesiac > 2) {
            szkodniki(iloscDrzew, iloscNawozu);
        }
    //ekran drzewa na poczatku miesiaca
        system("CLS");
        cout << "Miesiac: " << miesiac << endl;
        cout << "Ilosc miesiecy do konca gry: " << miesiaceGry - miesiac << endl;
        cout << "Ilosc pieniedzy: " << iloscPieniedzy << endl;
        cout << "Ilosc drzew: " << iloscDrzew << endl;
        cout << "Ilosc nawozu: " << iloscNawozu << endl;

        for (int i=0; i<iloscDrzew; i++) {
            grafikaDrzewa();
            cout << "                  Drzewo: " << i+1 << endl << endl << endl << endl;
        }


        cout << "Wcisnij dowolny znak, a potem enter, aby isc do kolejnego miesiaca" << endl;
        cin >> klawiszGracza;



    // ekran liczenia dni w miesiacu (pasek)
        pasekLadowania();
    // sklep
        sklepKomunikat();

        cenaNawozu = rand() % 20 + 40;
        cenaDrzewa = rand() % 2500 + 1000;

        grafikaDrzewa();
        cout << endl << "                  Cena drzewa: " << cenaDrzewa << endl << endl << endl;

        grafikaNawozu();
        cout << "                  Cena nawozu: " << cenaNawozu << endl;

        cout <<"Wpisz cyfre: ";
        cin >> klawiszGracza;
        wybor(klawiszGracza, miesiac, miesiaceGry, iloscPieniedzy, iloscNawozu, iloscDrzew);

}
}
