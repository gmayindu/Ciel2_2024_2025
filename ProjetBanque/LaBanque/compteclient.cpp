#include "compteclient.h"
#include "comptebancaire.h"
#include "compteepargne.h"
#include "menu.h"

using namespace std;

CompteClient::CompteClient(const string _nom, const int _numero):
    nom(_nom),
    numero(_numero)
{
    compteEpargne = nullptr;
    compteBancaire = new CompteBancaire(0);

}

CompteClient::~CompteClient()
{
    delete compteBancaire;
    if (compteEpargne)
        delete compteEpargne;
}

void CompteClient::OuvrirCompteEpargne()
{
    float soldeDepart;
    float tauxInteret;
    if(compteEpargne){
        cout << " Votre compte bancaire viens d'être creer, quelle somme voulez vous créditer" << endl;
        cin >> soldeDepart >> tauxInteret;
        compteEpargne = new CompteEpargne(tauxInteret,soldeDepart);
    }
    else
        cout << "vous avez deja un compte epargne" << endl;
}

void CompteClient::GererCompteBancaire()
{
    Menu leMenu("../LaBanque/comptebancaire.txt");
    float solde;
    int choix;
    float depot;
    float retrait;
    bool possibilite;
    bool sortie = 0;
    while (sortie == 0) {
        choix = leMenu.Afficher();
        switch (choix) {
        case 1:
            solde = compteEpargne->ConsulterSolde();
            cout << "Vous avez "<< solde<< "€ sur votre compte"<<endl;
            break;
        case 2:
            cout<< "Vous voulez déposez combien?" << endl;
            cin>> depot;
            compteEpargne->Deposer(depot);
            cout << "Vous avez déposé " << depot<<"€"<<endl;
            break;
        case 3:
            cout<< "Vous voulez retirer combien?" << endl;
            cin>> retrait;
            possibilite = compteEpargne->Retirer(retrait);
            if (possibilite == 1) {
                cout << "Vous avez retirer " << retrait << " €" << endl;
            }else{
                cout << "Vous n'avez pas pus retirer, solde insufisant " <<endl;
            }
            break;
        case 4:
            compteEpargne->CalculerInterets();
            solde = compteEpargne->ConsulterSolde();
            cout << "Vous avez " << solde << "€ sur votre compte avec les interets"<<endl;
            break;
        case 5:
            sortie = 1;
            break;
        }
        Menu::AttendreAppuiTouche();
    }
}

void CompteClient::GererCompteEpargne()
{
    int choix;
    float montant;
    float retrait;
    Menu leMenu("../LaBanque/compteepargne.txt");
    CompteEpargne compte(3.0);

    do{
        choix = leMenu.Afficher();
        switch (choix)
        {
        case 1:
            cout << "Votre solde est de : " << endl;
            cout << compte.ConsulterSolde() << endl;

            break;
        case 2:
            cout << "Effectuer un dépot, quelle est le montant ?" << endl;
            cin >> montant;
            compte.Deposer(montant);

            break;
        case 3:
            cout << "Effectuer un retrait, quelle est le montant ?" << endl;
            cin >> retrait;
            if(compte.Retirer(retrait) == true){

                compte.ConsulterSolde();
            }
            else{
                cout << "Solde insuffisant" << endl;
            }

            break;
        case 4:
            compte.CalculerInterets();
        }
    }
    while (choix != 5);
}
