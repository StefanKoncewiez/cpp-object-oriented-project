#include "Systeme.h"
#include "Balle.h"
#include "TextViewer.h"
#include "Pendule.h"
#include "constantes.h"
#include "integrateur.h"
#include "Plan.h"
#include "ChampForce.h"
#include <iostream>
using namespace std;

int main () {

IntegrateurEulerCromer cromer;
Systeme systeme(cromer, 0.01);

//on ajoute nos Objets composant le systeme
ChampForces grav (g);														//g dans constantes.h
grav.ajoute_a(systeme) ;

Pendule pendule (0.1,0,0.05,0.2,{1.5},0.005,{-0.5},{0,0,0},{0,1.4,0.45},{0,1,0});
grav.agir_sur(pendule);
pendule.ajoute_a(systeme);

Balle balle(0,3,0.051111, {0, 0, 0}, {0, 0, 0.3} , {0, 0.8, 2});
grav.agir_sur(balle);
balle.ajoute_a(systeme);

Plan plan({0, 0, 0}, {0, 0, 1});
plan.ajoute_a(systeme);

cout << systeme << endl;
cout << "Le système évolue"<< endl;
cout << "## Dans l'ordre :"<<endl;
cout << "##    1) theta  pendule"<<endl;
cout << "##    2) thetaP pendule"<<endl;
cout << "##    3) f()    pendule (c.-à-d. fonction d'évolution)"<<endl;
cout << "##    4) y bout du pendule"<< endl;
cout << "##    5) z bout du pendule"<< endl;
cout << "##    6) y balle"<< endl;
cout << "##    7) z balle"<< endl;
cout << "##    8) Vy balle (vitesse)"<<endl;
cout << "##    8) Vz balle (vitesse)"<<endl;
cout << "##   10) distance bord balle - bord bout pendule"<<endl<<endl;

TextViewer ecran(cout);
pendule.dessine_sur(ecran);
balle.dessine_sur(ecran);
cout <<endl;

const double nbr_iter(200);															//nombre d'itérations, modifiable

	for (int i(1); i<=nbr_iter; ++i){
		systeme.evolue();													//On fait simplement évoluer le systeme,
		systeme.dessine_sur(ecran);											//puis on l'affiche de manière minimale (contrairement à l'operateur <<)
	}

return 0;
}
