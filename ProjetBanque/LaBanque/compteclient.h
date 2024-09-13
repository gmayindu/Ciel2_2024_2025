#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include "comptebancaire.h"
#include "compteepargne.h"

using namespace std;

class CompteClient
{

private:
    CompteBancaire *compteBancaire;
    CompteEpargne *compteEpargne;

    string nom;
    int numero;

public:
    CompteClient(const string _nom, const int _numero);
    ~CompteClient();
    void OuvrirCompteEpargne();
    void GererCompteEpargne();
    void GererCompteBancaire();
};

#endif // COMPTECLIENT_H
