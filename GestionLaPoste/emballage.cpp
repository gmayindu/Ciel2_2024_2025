#include "emballage.h"

Emballage::Emballage(const string _format, const int _resistance, const int _largeur,
                     const int _longueur, const int _hauteur):
    format(_format),
    resistance(_resistance),
    largeur(_largeur),
    longueur(_longueur),
    hauteur(_hauteur),
    stock(0)
{
    cout << "Constructeur : Emballage / " << format << endl;
}

Emballage::~Emballage() {
    cout << "Destructeur : Emballage / " << format << endl;
}

void Emballage::Visualiser()
{
    cout << "| " << setw(15) << left << format
         << "| " << setw(2) << left << resistance << setw(12) << "Kg"
         << "| " << setw(1) << left << longueur << "X" << setw(1) << largeur;
    if (hauteur !=0) {
        cout << " X " << setw(10) << left << hauteur << " |" << endl;
    }
    else
        cout << right << setw(15) << " |" << endl;

}

bool Emballage::operator<(Emballage &autre)
{
    return CalculerVolume() < autre.CalculerVolume();
}

double Emballage::CalculerVolume()
{
    int volume = longueur * largeur;
    if(hauteur != 0)
        volume *= hauteur;

    double volumeCm3 = volume / 1000.0;

    return volumeCm3;
}

bool Emballage::operator==(Emballage &autre)
{
     return (longueur == autre.longueur && largeur == autre.largeur &&
             hauteur==autre.hauteur && resistance==autre.resistance);
}

Emballage::operator float()
{

}
