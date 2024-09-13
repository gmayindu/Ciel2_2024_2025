#include "compteepargne.h"
#include <math.h>

using namespace std;

CompteEpargne::CompteEpargne(const float _tauxInterets, const float _solde):
    CompteBancaire(_solde),
    tauxInterets(_tauxInterets)
{
    cout << "Compte créé avec un taux d'interets de " << tauxInterets << " % " << endl;
}

/**
 * @brief CompteEpargne::CalculerInterets
 * Méthode pour calculer les intérets
 */
void CompteEpargne::CalculerInterets()
{
    solde += (solde * tauxInterets) / 100.0;

    cout << "Vous avez votre taux d'interets de : " << solde << " € " << endl;
}

void CompteEpargne::ModifierTaux(double nouveauTaux)
{
    tauxInterets = nouveauTaux;
}
