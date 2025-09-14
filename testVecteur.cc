#include "Vecteur.h"
#include <cmath>

using namespace std;

int main (){
	
Vecteur vect0 (3);
	// un vecteur en 3D :
Vecteur vect1(1.0, 2.0, -0.1);

// un autre vecteur en 3D
Vecteur vect2(2.6, 3.5,  4.1);
Vecteur vect3(vect1);  // copie de V1
Vecteur vect4(4);      // le vecteur nul en 4D
Vecteur vect5({1.0, 2.0, 3.0, 4.0, 5.0, 6.0}); // vecteur initialisé avec une liste de 'double'
Vecteur vectunit ({1.0, 1.0, 1.0, 1.0}); ~vectunit;
Vecteur vectnorm25 ({3.0, 4.0});

cout << "Vecteur 1 : " << vect1 << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;
cout << "Vecteur 4 : " << vect4 << endl;
cout << "Vecteur 5 : " << vect5 << endl;

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (not(vect1 == vect3)) {
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl;

Vecteur vect6(6);
vect6=vect5;  // test de l'affectation
cout << "Vecteur 5 : " << vect5 << endl;
cout << "Nouveau Vecteur 6 : " << vect6 << endl;

vect3.augmente(3.0);
vect5.set_coord(4, 69.0);
cout << "Nouveau Vecteur 3 : " << vect3 << endl;
cout << "Nouveau Vecteur 5 : " << vect5 << endl;

cout << "Le produit vectoriel entre le vecteur 1 et le vecteur 2 est" << (vect1^vect2)<<endl;

cout << "L'opposé du vecteur 3 = "<< vect3 << "est le vecteur = " << -vect3 << "qui doit aussi être égal à " << Vecteur(4) - vect3 << endl;
cout << "L'opération vect3 * 4 vaut 4 fois "<< vect3<<" c-a-d "<< vect3*4 << endl;
cout << "La norme du vecteur unitaire est " << vectunit.norme() << " et doit être " << sqrt(1+1+1+1)<<endl;
cout << "La norme au carré doit être 25 et elle est de " << vectnorm25.norme2() << endl;
cout << "L'addition des vecteurs 1 et 2 est "<< (vect1 + vect2) << "qui doit être égal à " << (vect2 + vect1)<<endl;
cout << "La soustraction des vecteurs 1 et 2 est "<< vect1 - vect2 << "qui doit être égal à" << (-vect2) + vect1<<endl;


vect2 + vect1;

cout <<"Le vecteur unitaire du vecteur 2 est : ";

cout << ~vect2 << "Et le vecteur unitaire du vecteur unitaire est : ";
cout << ~vectunit << endl;
// ici, avant de les mettre en "priavte", on avait testé les opérateurs *= , +=, -= ...
//for (int i(0); i<2; ++i) { cout << "Rajoutons le vecteur unitaire au vecteur 4, qui devient donc vect4 = " << (vect4 += vectunit) << endl;}

return 0; 
}

