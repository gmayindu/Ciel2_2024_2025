#include "emballage.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    //Emballage colis1 ("XS", 1, 270, 190);
    //Emballage *pColis;
    //pColis = new Emballage("XL", 7, 383, 250, 195);

    Emballage colis1("XS", 1, 217, 150, 50); // Instance créée automatiquement
    Emballage *pColi2;
    pColi2 = new Emballage ("XS à plat", 1, 270, 190); // Instance créée dymaniquement
    Emballage coli3("XL", 1, 270, 190); // Instance créée automatiquement
    Emballage *tabColis[5];

    string format;
    int resistance;
    int largeur;
    int longueur;
    int hauteur;

    for(int indice = 0 ; indice < 3 ; indice ++)
    {
        cout << "Nom du format : ";
        getline(cin,format);
        cout << "Resistance : ";
        cin >> resistance;
        cout << "Longueur : ";
        cin >> longueur;
        cout << "Largeur : ";
        cin >> largeur;
        cout << "Hauteur : ";
        cin >> hauteur;

        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        tabColis[indice] = new Emballage(format, resistance, longueur, largeur, hauteur);
    }

    coli3.Visualiser();
    pColi2->Visualiser();

    cout << endl;
    cout << setfill('-');
    cout <<"+" << setw(18) << "+";
    cout << setw(13) << "+";
    cout << setw(18) << "+";

    cout << endl;
    cout << setfill(' ');
    cout <<"|" << setw(17) << left << "Format";
    cout <<"|" << setw(17) << left << "Resistance";
    cout <<"|" << setw(17) << left << "Dimensions";

    cout << endl;
    cout << setfill('-');
    cout <<"+" << setw(18) << right << "+";
    cout << setw(13) << "+";
    cout << setw(18) << "+";

    cout << endl;
    cout << setfill(' ');

    for(int indice = 0 ; indice < 3 ; indice++) {
        tabColis[indice]->Visualiser();
    }

    cout << "+" << setw(18) << setfill('-') << "+";
    cout << setw(13) << "+";
    cout << setw(18) << "+" << endl << endl;

    if(*tabColis[0] < *tabColis[1])
        cout << "tabColis[0] est plus petit que tabColis[1]" << endl;
    else
        cout << "tabColis[1] est plus petit que tabColis[0]" << endl;

    if(*tabColis[0] == *tabColis[1])
        cout << "Les emballages tabColis[0] et tabColis[1] sont identiques" << endl;
    else
        cout << "Les emballages tabColis[0] et tabColis[1] sont differents" << endl;

    if(*tabColis[0] == *tabColis[2])
        cout << "Les emballages tabColis[0] et tabColis[2] sont identiques" << endl;
    else
        cout << "Les emballages tabColis[0] et tabColis[2] sont differents" << endl;

    if(*tabColis[0] == *tabColis[3])
        cout << "Les emballages tabColis[0] et tabColis[3] sont identiques" << endl;
    else
        cout << "Les emballages tabColis[0] et tabColis[3] sont differents" << endl;

    float volume = *tabColis[0];
    cout << "Le volume de tabColis[0] est de " << volume << " cm3" << endl;

    delete pColi2;



    //delete pColis;






    return 0;


}
