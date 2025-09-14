#include "Vent.h"
#include "Balle.h"
#include "ChampForce.h"
#include "constantes.h"
#include "integrateur.h"
#include "Objet.h"
#include <iostream>


using namespace std;

int main(){
	Vent vent ({0.0, 0.0, 0.0}, {0.0, 3, 0}, {0, 0, 3.0}, 3, 2);
	Balle balle (0, 3, 0.2, {0.0, 0.0, 0.0}, {1, 1, 1}, {0.0, 0, 0});
	IntegrateurEulerCromer integr;
	ChampForces gravite ({g});
	
	int nbr_iteration1(10);
	double T_int1(0.01);
	
	cout<<balle<<endl;
	cout << "Voici la direction du vent : " <<vent.get_direction_vent()<< endl;		//verifier que la balle va dans le bon sens 
	
	for (int i (1); i<=nbr_iteration1; ++i){
	
	gravite.agir_sur(balle);
	vent.agir_sur(balle);
	
	integr.integre(balle,T_int1);
	
	cout << balle.getPosition() << balle.getVitesse()<<endl ;
	
	balle.reset_force();
	}
}
