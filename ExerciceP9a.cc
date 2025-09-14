#include "Systeme.h"
#include "Balle.h"
#include "Objet.h"
#include <iostream>
#include "TextViewer.h"
#include "constantes.h"
#include "integrateur.h"

using namespace std;

int main () {
IntegrateurEulerCromer cromer;
Systeme systeme(cromer, 0.01);

Balle balle(0.0,3, 0.2, {0, 0, 0}, {0, 0, 0} , {0, 0.1, 0.2});
ChampForces gravite (g);

//on ajoute nos composantes au système
balle.ajoute_a(systeme);
gravite.ajoute_a(systeme);


cout << systeme <<endl;													//Affichage complet du systeme avec l'operateur << surchargé
cout << "Le systeme evolue :"<< endl;
cout << "## Dans l'ordre : position vitessse" << endl;
TextViewer ecran(cout);

	for (int i(1); i<=5; ++i){
		systeme.evolue();												//On fait simplement évoluer le systeme,
		systeme.dessine_sur(ecran);										//puis on l'affiche de manière minimale (contrairement à l'operateur <<)
	}
}

