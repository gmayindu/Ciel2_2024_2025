
#include <iostream>

#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H


class CompteBancaire
{
public:
    CompteBancaire(const float _solde=0);
    void Deposer(const float _montant);
    bool Retirer(const float _montant);
    float ConsulterSolde();

protected:
    float solde;

};

#endif // COMPTEBANCAIRE_H
