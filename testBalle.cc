#include "Balle.h"
#include "ChampForce.h"
#include "constantes.h"
#include "Objet.h"
#include <iostream>
using namespace std;

//Dans ce fichier test, on teste les constructeurs de balle ainsi que leur affichage. On teste aussi leurs "getteurs" et leur "setteurs".
//La méthode affiche() qui permet la surcharge de l'opérateur << utilise aussi des méthodes de Balle qui sont donc aussi testées dans le test d'affichage.

int main() {
ChampForces gravite (g);

Balle balle0;
Balle balle1 (0, 3, 0.2, {0.0, 0.0, 0.0}, {1.0, 2.0, 3.0}, {0.0, 0.1, 0.2});				//test du constructeur
Balle balle2 (0, 1.1, 0.1, {0.0, 0.0, 0.0}, {-1, 1.2, 1.3}, {0.0, 0.1, 0.0});

cout << "Avant action de la gravité :"<< endl;
cout<< "balle 1" <<endl << balle1 << endl << "balle 2" << endl << balle2<< endl;					//test affichage

gravite.agir_sur(balle1);																	//test de la bonne action de la gravite
gravite.agir_sur(balle2);

cout << "Après action de la gravité :"<< endl;
Balle balle3 (balle2);																		//test constructeur de copie
cout<< "balle 1" <<endl << balle1 << endl << "balle 2" << endl << balle3; 


//===============================================================================================================================================
//test des "setteurs"
balle1.setPosition({0.1, 2.3, 4.5});
cout << "la position de la balle est " << balle1.getPosition() << " et doit être 0.1 2.3 4.5 ";

balle1.setVitesse({5.4, 3.2, 1.0});
cout << "la vitesse de la balle est " << balle1.getVitesse() << " et doit être 5.4 3.2 1.0 ";

cout << endl;
//===============================================================================================================================================
//test d'erreurs :

cout << endl << "Tests d'erreurs : ";
cout <<endl << "la position ne doit pas pouvoir être afféctée !" << endl;
balle1.setPosition({0.1, 2.3});
cout << endl;
cout << "la vitesse ne doit pas pouvoir être afféctée !" << endl;
balle1.setVitesse({5.4, 3.2});
cout << endl;

return 0;
}
