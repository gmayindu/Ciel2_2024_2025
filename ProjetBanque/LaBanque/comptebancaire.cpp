#include "comptebancaire.h"

using namespace std;

CompteBancaire::CompteBancaire(const float _solde):
    solde(_solde)
{
    cout << "Compte créé avec un solde de " << solde << " € " << endl;
}

void CompteBancaire::Deposer(const float _montant) {
    if (_montant > 0)
        solde += _montant;
    cout << "Vous avez déposé : " << _montant << " €" << endl;

}

bool CompteBancaire::Retirer(const float _montant) {
    if (_montant < 0)
        solde -= _montant;
    cout << "Vous avez retiré : " << _montant << " €" << endl;
}

float CompteBancaire::ConsulterSolde() {
    return solde;

    cout << "Vous avez consulté le solde de " << solde << " € " << endl;
}
