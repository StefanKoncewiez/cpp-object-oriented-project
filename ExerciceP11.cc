#include "Systeme.h"
#include "Balle.h"
#include "Objet.h"
#include <iostream>
#include "TextViewer.h"
#include "constantes.h"
#include "integrateur.h"
#include "Ventilateur.h"
#include "Brique.h"

//Dans ce programme, le but est de tester l'ajout d'un système d'objet composé, ainsi que la manière dont les objets composés agissent dans le système.

using namespace std;

int main () {
IntegrateurEulerCromer cromer;
Systeme sys(cromer, 0.01);
Balle balle (0.0,3, 0.2, {0, 0, 0}, {3, 3, 3} , {0, 0.0, 0.2});
Brique brique ({0, 0, 0}, {0.0, 0, 2.0}, {0, 2.0, 0.0}, 0.3);
Ventilateur VTLTR (brique, 4, 2);
ChampForces gravite (g);

//on ajoute nos composantes au système
balle.ajoute_a(sys);
gravite.ajoute_a(sys);
//test de l'ajout d'un objet compose au systeme
VTLTR.ajoute_a(sys);


cout << sys <<endl;														//Affichage complet du systeme avec l'operateur << surchargé
cout << "Le systeme evolue :"<< endl;
cout << "## Dans l'ordre : position vitessse" << endl;
TextViewer ecran(cout);

	for (int i(1); i<=200 ; ++i){
		sys.evolue();													//On fait simplement évoluer le systeme,
		sys.dessine_sur(ecran);											//puis on l'affiche de manière minimale (contrairement à l'operateur <<)
	}
}


