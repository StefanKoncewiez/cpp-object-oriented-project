#include "ChampForce.h"
#include "constantes.h"
#include "Balle.h"
#include "Objet.h"
#include "integrateur.h"
#include <iostream>
#include <memory>
#include "TextViewer.h"
#include "Systeme.h"
#include "Pendule.h"

using namespace std;

int main() {
	ChampForces grav (g) ;
	cout << "gravité : " << grav<<endl;
	Balle balle1 (0.127, 0, 0, {0,0,0},{0,0.0, 1.0}, {0,1.0, 2.0});		//Une balle rayon de 0 arbitraire qui sera utilisée dans 1)
	Balle balle2 (balle1);												//Sera utilisée dans 2)
	IntegrateurNewark newmark;
	IntegrateurRungeKutta runge;

	Systeme systeme1(newmark, 0.01);									//Déclaration d'un systeme qui sera utilisé dans 1)
	Systeme systeme2(runge, 0.01);										//Sera utilisé dans 1)
	
	Pendule pendule1 (0.1,0,0.05,0.2,{1.5},0.005,{-0.5},{0,0,0},{0,1.4,0.45},{0,1,0});
	grav.agir_sur(pendule1);
	Pendule pendule2 (pendule1);
	systeme1.ajoute_objet(pendule1);
	systeme2.ajoute_objet(pendule2);									//En effet, on a décidé de ne pas pouvoir copié de systeme
	
	systeme1.ajoute_champ(g) ;
	systeme2.ajoute_champ(g) ;
	Balle balle3 (0,3,0.051111, {0, 0, 0}, {0, 0, 0.3} , {0, 0.8, 2});
	grav.agir_sur(balle3);
	Balle balle4 (balle3);
	systeme1.ajoute_objet(balle3);
	systeme2.ajoute_objet(balle3);

	Plan plan({0, 0, 0}, {0, 0, 1});
	systeme1.ajoute_obstacle(plan);
	systeme2.ajoute_obstacle(plan);

//==1)Integration de la balle avec newmark==============================
	cout <<newmark <<"Avec une balle :"<< endl ;
	grav.agir_sur(balle1);
	cout <<balle1.getPosition() << "#parametre"<<endl;


	for (int i (1); i<=68; ++i){
		newmark.integre(balle1, 0.01); //ou runge
		cout <<balle1.getPosition() << "#parametre"<<endl;
	}
//==1)Integration d'un systeme avec newmark=============================
	TextViewer ecran(cout);
	cout <<"Avec un systeme "<< endl ;
	pendule1.dessine_sur(ecran);
	balle3.dessine_sur(ecran);
	cout <<endl;
	for (int i(1); i<=9 ; ++i){
		systeme1.evolue();
		systeme1.dessine_sur(ecran);
	}
	
//==2)Integration de la balle avec runge================================
	cout << endl <<"En comparaison avec :" <<endl;
	cout << runge <<"Avec une balle "<< endl ;;
	grav.agir_sur(balle2);
	cout <<balle2.getPosition() << "#parametre"<<endl;


	for (int i (1); i<=68; ++i){
		runge.integre(balle2, 0.01);
		cout <<balle2.getPosition() << "#parametre"<<endl;
	}
//==2)Integration d'un systeme avec runge===============================
	cout <<"Avec un systeme :"<< endl ;
	pendule2.dessine_sur(ecran);
	balle4.dessine_sur(ecran);
	cout <<endl;
	for (int i(1); i<=9 ; ++i){
		systeme2.evolue();
		systeme2.dessine_sur(ecran);
	}

return 0;
}
