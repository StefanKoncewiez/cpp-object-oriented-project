#include "Balle.h"
#include "Plan.h"
#include "Pendule.h"
#include "ChampForce.h"
#include "constantes.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Dans ce fichier test, nous testons différents chocs avec les ObjetMobiles.
//Dans le CHOC 1, nous testons le choc entre une Balle et un Plan
//Dans le CHOC 2, nous testons le choc entre 2 Balles
//Dans le CHOC 3, nous testons le choc entre une Balle est un Pendule


int main(){
ChampForces gravite (g);


//CHOC_1
cout << "//CHOC 1=========================================================================="<<endl<<endl;
Balle balle ( 0,3, 0.051111, {0,0,0}, {0, 0.624, 0.0465234}, {0, 0.8, -2.59108});
Plan z({0,0,0}, {0,0,1});
gravite.agir_sur(balle);
cout << "cas 1 :" << endl << endl;
cout << "avant rebond sol :" <<endl;
cout << "vitesse = " << balle.getVitesse()<< endl;
cout << "force = " << balle.getforce()<< endl << endl;

cout <<"calculs : ";
z.agir_sur(balle);
cout << endl;

cout << "après choc :" <<endl;
cout << "vitesse = " << balle.getVitesse()<< endl;
cout << "force = " << balle.getforce()<< endl << endl;
cout << endl;
cout << endl;


//CHOC_2
cout << "//CHOC 2=========================================================================="<<endl<<endl;

Balle balle1 ( 0, 3, 0.051111, {0,0,0}, {0, 1.36675, 0.283821}, {0, 0.715449, 0.0957368});
Balle balle2 (0.1,0, 0.05, {0,0,0}, {0, 1.46284, 0.260128}, {0, 0.419218, 0.13874});
gravite.agir_sur(balle1);
gravite.agir_sur(balle2);

cout << "cas 2 :" << endl << "avant choc:"<< endl<< endl;
cout <<"position balle1 = "<< balle1.getPosition()<< endl;
cout <<"position balle2 = "<< balle2.getPosition()<< endl;
cout <<"distance (entre centres) = "<< setprecision(17) << (balle1.getPosition() - balle2.getPosition()).norme() << endl;
cout <<"vitesse balle1 = "<< balle1.getVitesse()<< endl;
cout <<"vitesse balle2 = "<< balle2.getVitesse() << endl;
cout <<"force balle1 = "<< balle1.getforce()<< endl;
cout <<"force balle2 = "<< balle2.getforce()<< endl << endl;

cout <<"calculs : ";

balle1.agir_sur(balle2);
//qui doit etre egal à :														//test pour verifier que si la balle1.agir_sur(balle2) est euivalent à balle2.agir_sur(balle1)
//balle2.agir_sur(balle1);														//on obtient le même résultat
																				//si vous voulez tester les deux cas, ne le faites pas dans la même exécution sinon on aura pas les mêmes valeurs, on aura juste que le choc se fait 2 fois que suite
																				//faites une execution pour l'un et une execution pour l'autre.
cout << "après choc :" <<endl;
cout <<"vitesse balle1 = "<< setprecision(17) <<balle1.getVitesse()<< endl;
cout <<"vitesse balle2 = "<< balle2.getVitesse()<< endl;
cout <<"force balle1 = "<< setprecision(17) <<balle1.getforce()<< endl;
cout <<"force balle2 = "<< balle2.getforce()<< endl;

cout << endl;
cout << endl;



//CHOC_3:
cout << "//CHOC 3=========================================================================="<<endl<<endl;

//obligez les forces du pendule à être tangentes à son mouvement (c.-à-d. qu'une partie de la force est absorbée par l'axe fixe), alors vous auriez :
balle1 = Balle ( 0, 3, 0.051111, {0,0,0}, {0, 1.36675, 0.283821}, {0, 0.715449, 0.0957368});
Pendule pendule (0.1,0, 1, 1, {0.319603599172218}, 0, {0.441579572811062}, {0,0, 0},{0, 1.148649741794006, 1.209488037945800}, {0,1,0});
gravite.agir_sur(balle1);
gravite.agir_sur(pendule);

cout <<"position balle1 = "<< balle1.getPosition()<< endl;
cout <<"position pendule = "<< pendule.getPosition()<< endl;
cout <<"distance (entre centres) = "<< setprecision(17) << (balle1.getPosition() - pendule.getPosition()).norme() << endl;
cout <<"vitesse balle1 = "<< balle1.getVitesse()<< endl;
cout <<"vitesse pendule = "<< pendule.getVitesse() << endl;
cout <<"force balle1 = "<< balle1.calc_force()<< endl;
cout <<"force pendule = "<< pendule.calc_force()<< endl << endl;

cout <<"calculs : ";

//balle1.agir_sur(pendule);
// ce qui doit etre egal à														//test pour verifier que si la balle1.agir_sur(pendule) est equivalent à pendule.agir_sur(balle1)
pendule.agir_sur(balle1);														//on obtient le même résultat
																				//si vous voulez tester les deux cas, ne le faites pas dans la même exécution sinon on aura pas les mêmes valeurs, on aura juste que le choc se fait 2 fois que suite
																				//faites une execution pour l'un et une execution pour l'autre.

cout << "après choc :" <<endl;
cout <<"vitesse balle1 = "<< setprecision(17) <<balle1.getVitesse()<< endl;
cout <<"vitesse pendule = "<< pendule.getVitesse()<< endl;
cout <<"force balle1 = "<< setprecision(17) <<balle1.getforce()<< endl;
cout <<"force pendule = "<< pendule.getforce()<< endl;

return 0;
}

