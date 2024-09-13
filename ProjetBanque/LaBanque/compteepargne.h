#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H

#include <iostream>

#include "comptebancaire.h"

class CompteEpargne: public CompteBancaire
{
public:
    CompteEpargne(const float _tauxInterets, const float _solde = 0);
    void CalculerInterets();
    void ModifierTaux(double nouveauTaux);

private:
    float tauxInterets;
};

#endif // COMPTEEPARGNE_H
