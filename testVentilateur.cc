#include "Ventilateur.h"
#include "Brique.h"
#include "Balle.h"
#include "ChampForce.h"
#include "constantes.h"
#include "integrateur.h"
#include "TextViewer.h"
#include "Objet.h"
#include <iostream>

using namespace std;


int main (){
	Brique brique ({0.0, 0.0, 0.0}, {0.0, 0, 3.0}, {0, 3.0, 0.0}, 0.3);
	Balle balle (0, 3, 0.2, {0.0, 0.0, 0.0}, {1, 1, 1}, {0.0, 0, 0});
	IntegrateurEulerCromer integr;
	ChampForces gravite ({g});
	Ventilateur v(brique, 4, 2);
	TextViewer ecran(cout);
	
	int nbr_iteration(10);
	double T_int(0.01);

	cout<<balle<<endl;
	cout << v <<endl;													//on teste l'affichage du ventilateur
	cout <<g << endl;
	cout << "distance ventilateur --> balle = " << v.distance(balle);
	
	for (int i (1); i<=nbr_iteration; ++i){								//on teste agir_sur du ventilateur
	v.agir_sur(balle);
	gravite.agir_sur(balle);
	integr.integre(balle,T_int);
	balle.dessine_sur(ecran);
	cout <<balle.getforce()<< endl;
	balle.reset_force();
	}
}
