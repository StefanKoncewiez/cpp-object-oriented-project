#include "ChampForce.h"
#include "Balle.h"
#include "constantes.h"
#include "Objet.h"
#include "integrateur.h"
#include <iostream>
using namespace std;

int main() {

ChampForces gravite (g);
Balle balle(0.0, 3, 0.2, {0,0,0}, {0,0, 0}, {0, 0.1, 0.2});							//3 #masse volumique
IntegrateurEulerCromer integr;
gravite.agir_sur(balle);
cout << "Nous avons :" << endl << gravite;
cout << balle << endl;

const double nbr_iter(4);															//nombre d'itérations, modifiable
const double T_i(0.01);																//"pas de temps" d'intégration, modifiable

for (int i (1); i<=nbr_iter; ++i){
integr.integre(balle, T_i);
cout << "l'intégration "<< i << " donne :"<< endl<< balle << endl<< endl;
}
return 0;
}
