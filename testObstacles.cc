#include "Brique.h"
#include "Plan.h"
#include "Balle.h"
#include "Objet.h"
#include "PortionPlan.h"

using namespace std;

int main(){
	Brique mur_brique ({0, 0, 0.5},{0, -0.6, 0}, {0.8, 0, 0}, 0.5);
	Portionplan portion ({0, 0, 0},{0, 0, 1}, 500,500,{1, 0, 0});
	Plan mur ({0, 0, 0},{0, 0, 1});
	Balle balle(0.0, 3,0.2, {0, 0, -0.591725259488945}, {1.2, -0.4, 0.3}, {0, 0, 0});


cout << "Nous avons :" << endl << endl << mur << endl<< mur_brique << endl<< balle << endl;

//FACE 5 DE NOTRE BRIQUE===========================================================================================================================================================================
cout << "tests :" << endl;
cout << mur.point_plus_proche(balle) << " # point plus proche plan" << endl;
cout << mur.distance(balle) << " # distance plan" << endl;
cout << mur_brique.point_plus_proche(balle) << " # point plus proche brique" << endl;
cout << mur_brique.distance(balle) << " # distance brique" << endl<< endl;

//FACE 1 DE NOTRE BRIQUE===========================================================================================================================================================================
cout << "je déplace la balle en : 1.2 -0.4 1.3" << endl;
balle.setPosition ({1.2, -0.4, 1.3});
cout << balle<< endl;

cout << "tests :" << endl;
cout << mur.point_plus_proche(balle) << " # point plus proche plan" << endl;
cout << mur.distance(balle) << " # distance plan" << endl;
cout << mur_brique.point_plus_proche(balle) << " # point plus proche brique" << endl;
cout << mur_brique.distance(balle) << " # distance brique" << endl << endl;

//FACE 1 DE NOTRE BRIQUE (encore une fois)==========================================================================================================================================================
cout << "je déplace la balle en : 0.2 -0.4 1.3" << endl;
balle.setPosition ({0.2, -0.4, 1.3});
cout << balle<< endl;

cout << "tests :" << endl;
cout << mur.point_plus_proche(balle) << " # point plus proche plan" << endl;
cout << mur.distance(balle) << " # distance plan" << endl;
cout << mur_brique.point_plus_proche(balle) << " # point plus proche brique" << endl;
cout << mur_brique.distance(balle) << " # distance brique" << endl << endl;

//FACE 4 DE NOTRE BRIQUE===========================================================================================================================================================================
cout << "je déplace la balle en : 0.4 -1.3 0.4" << endl;
balle.setPosition ({0.4, -1.3, 0.4});
cout << balle<< endl;

cout << "tests :" << endl;
cout << mur.point_plus_proche(balle) << " # point plus proche plan" << endl;
cout << mur.distance(balle) << " # distance plan" << endl;
cout << mur_brique.point_plus_proche(balle) << " # point plus proche brique" << endl;
cout << mur_brique.distance(balle) << " # distance brique" << endl << endl;

//FACE 2 DE NOTRE BRIQUE===========================================================================================================================================================================
cout << "je déplace la balle en : 0.2 -0.4 -1.3" << endl;
balle.setPosition ({-0.2, -0.4, -1.3});
cout << balle<< endl;

cout << "tests :" << endl;
cout << mur.point_plus_proche(balle) << " # point plus proche plan" << endl;
cout << mur.distance(balle) << " # distance plan" << endl;
cout << mur_brique.point_plus_proche(balle) << " # point plus proche brique" << endl;
cout << mur_brique.distance(balle) << " # distance brique" << endl << endl;

//FACE 6 DE NOTRE BRIQUE===========================================================================================================================================================================
cout << "je déplace la balle en : 0.4 -0.3 -0.3" << endl;
balle.setPosition (Vecteur({0.4, -0.3, -0.3}));
cout << balle << endl;

cout << "tests :" << endl;
cout << mur.point_plus_proche(balle) << " # point plus proche plan" << endl;
cout << mur.distance(balle) << " # distance plan" << endl;
cout << mur_brique.point_plus_proche(balle) << " # point plus proche brique" << endl;
cout << mur_brique.distance(balle) << " # distance brique" << endl << endl;

//FACE 3 DE NOTRE BRIQUE===========================================================================================================================================================================
cout << "je déplace la balle en : 0.4 1.3 0.4" << endl;
balle.setPosition (Vecteur({0.4, 1.3, 0.4}));
cout << balle << endl;

cout << "tests :" << endl;
cout << mur.point_plus_proche(balle) << " # point plus proche plan" << endl;
cout << mur.distance(balle) << " # distance plan" << endl;
cout << mur_brique.point_plus_proche(balle) << " # point plus proche brique" << endl;
cout << mur_brique.distance(balle) << " # distance brique" << endl << endl;

return 0;
}
