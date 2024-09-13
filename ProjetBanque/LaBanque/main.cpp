#include <iostream>

#include "comptebancaire.h"
#include "compteepargne.h"
#include "menu.h"
#include "compteclient.h"

using namespace std;

enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2,
    OPTION_3,
    OPTION_4,
    OPTION_5,
    QUITTER
};

int main()
{

    // Compte Bancaire

    /*int choix;
    CompteBancaire compte(100.0);
    Menu leMenu("../LaBanque/comptebancaire.txt");


        do
    {

            cout << "Operations sur Compte de dépots" << endl;
            choix = leMenu.Afficher();
            switch (choix)
            {
            case OPTION_1:
                cout << "Votre solde est de : " << endl;
                cout << compte.ConsulterSolde() << " €" << endl;
                Menu::AttendreAppuiTouche();
                break;
            case OPTION_2:
                compte.Deposer(10.0);
                cout << "Vous avez effectué un dépot" << endl;
                Menu::AttendreAppuiTouche();
                break;
            case OPTION_3:
                compte.Retirer(20.0);
                cout << "Vous avez éffectué un retrait" << endl;
                Menu::AttendreAppuiTouche();
                break;
            case OPTION_4:
                cout << "Vous avez consulté le solde" << endl;
                Menu::AttendreAppuiTouche();
                break;
            }

        } while (choix != QUITTER);*/

    int choix;
    CompteEpargne compte(3.0);
    Menu leMenu("../LaBanque/client.txt");
    CompteClient LeCompte ("Albert",1);


    do
    {

        cout << "Operations sur Compte de dépots" << endl;
        choix = leMenu.Afficher();
        switch (choix)
        {
        case OPTION_1:
            LeCompte.OuvrirCompteEpargne();
            break;
        case OPTION_2:
            LeCompte.GererCompteBancaire();
            break;
        case OPTION_3:
            LeCompte.GererCompteEpargne();
            break;
        case OPTION_4:
            cout << "Vous pouvez quitter !";
            Menu::AttendreAppuiTouche();
            break;
        //case OPTION_5:

        }

        cout << "Votre choix : entre 1 et 4" << endl;

    } while (choix != QUITTER);

        return 0;
    }
