//#include "Vecteur.h"
//#include "ObjetsMobiles.h"
#include "ChampForce.h"
#include "Pendule.h"
#include "constantes.h"
#include "Objet.h"
#include "integrateur.h"
#include <iostream>
#include <cmath>

using namespace std;
int main() {
Pendule pendule (0.1, 0, 0.0 , 0.2, {0.4}, 0.005, {0}, {0,0,0}, {0,2,1}, {0,1,0});					// Le rayon du bout du pendule est mis à 0 pour supprimer l'action
																									// de la poussée d'Archimède et obtenir les mêmes résultats que ceux
																									// proposé par Mr. Chappelier
ChampForces gravite(g);
IntegrateurEulerCromer integrateur;

cout << " Nous avons :" << endl;
gravite.agir_sur(pendule);
cout << gravite << endl << pendule<< endl;
cout<< pendule.getforce();

const double nbr_iter(10);															//nombre d'itérations, modifiable
const double T_i(0.01);																//"pas de temps" d'intégration, modifiable

for (int i (1); i<=nbr_iter; ++i){
integrateur.integre(pendule, T_i);
cout << "l'intégration "<< i << " donne :"<< endl<< pendule << endl<< endl;
	}


return 0;
	
}

