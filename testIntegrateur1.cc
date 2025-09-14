#include "ChampForce.h"
#include "Balle.h"
#include "constantes.h"
#include "Objet.h"
#include "integrateur.h"
#include "Vecteur.h"
#include <iostream>
using namespace std;


int main() {
//Dans ce test, on se place dans un repère en 2D

ChampForces grav (Vecteur{0, -9.81}) ;										//Gravité projeté sur l'axe OYZ
cout << "gravité : " << grav <<endl;
Balle balle (0.127, 0, 0, {0,0},{0, 1.0}, {1.0, 2.0});						//rayon de 0 arbitraire
IntegrateurEulerCromer integr;
grav.agir_sur(balle);

cout <<balle.getPosition() << "#position"<<endl;
cout <<balle.getVitesse() << "#vitesse"<< endl << endl;
//cout << "force" << balle.getforce();										//ligne de DEBUG personnel

const double nbr_iter(68);													//nombre d'itérations, modifiable
const double T_i(0.01);														//"pas de temps" d'intégration, modifiable

for (int i (1); i<=nbr_iter; ++i){
integr.integre(balle, T_i);
cout <<balle.getPosition() << "#position"<<endl;
cout <<balle.getVitesse() << "#vitesse"<< endl << endl;
}
return 0;
}
