#include "Ressort.h"
#include <iostream>
#include "constantes.h"
#include "integrateur.h"
#include "ChampForce.h"
#include "Objet.h"
using namespace std;

int main() {


ChampForces grav (g) ;

Ressort ressort (0.1,0,0,1.38165,{0.4},0.01,{0},{0,0,0},{0, 0, 1},{0, 0.707106781186547, -0.707106781186547});
IntegrateurEulerCromer integr;
grav.agir_sur(ressort);

cout << "Nous avons :"<<endl<<"champ de force :" << endl << grav << endl << ressort<< endl;

const double nbr_iter(5);															//nombre d'itérations, modifiable
const double T_i(0.01);																//"pas de temps" d'intégration, modifiable


for (int i (1); i<=nbr_iter; ++i){
integr.integre(ressort, T_i);
cout << "l'intergration "<< i <<" donne:" << endl;
cout <<ressort <<endl;

}
return 0;
}

