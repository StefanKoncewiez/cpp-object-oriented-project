#include <iostream>
#include "TextViewer.h"

using namespace std;


//---------CONSTRUCTEUR-------------------------------------------------
TextViewer:: TextViewer(ostream& f)
    : flot(f)
  {}


//----------MÉTHODES POLYMORPHIQUES-------------------------------------
	void TextViewer:: dessine(Systeme const & systeme) {				//La classe Systeme n'admet pas de "getter" retournant une copie du tableau d'ObjetMobiles.
		size_t max(systeme.getlongobj());								//En effet, cela n'a pas de sens avec des unique_ptr.
		for(size_t i(0); i<max; i+=2){									//On a donc décidé de surcharger l'operateur[] pour avoir accès aux élements de notre tableau d'ObjetMobiles
			systeme[i].dessine_sur(*this);								//Et pour pouvoir les "dessiner". En effet, dessine_sur() est une methode virtuelle et permet du polymorphisme.
			if (max>1){ 												
				systeme[i+1].dessine_sur(*this);
				flot << systeme[i].distance(systeme[i+1]) << endl;
			}else {flot << endl;}
		}
	}///Une manière alternative afin d'éviter l'operateur[] serait été de faire la boucle directement dans la classe Systeme. Mais, de cette manière, la methode :
	 /// dessine(Systeme const & systeme) aurait eu un corps vide. Or, conceptuellement, on doit clairement pouvoir dessiner un systeme.



//ObjetsMobiles à dessiner:
	void TextViewer:: dessine(Pendule const& pendule) {
	flot << pendule.getParam() << " " << pendule.getP_derive() << " " << pendule.evolution() << " " << pendule.getPosition();}
	void TextViewer:: dessine(Balle const& balle) {
	flot << balle.getPosition()<< " " << balle.getVitesse()<< " ";}
	void TextViewer:: dessine(Ressort const& ressort){
	flot << ressort.getParam() << " " << ressort.getP_derive() << ressort.getPosition()<< " " << ressort.getVitesse()<< " ";}

//Obstacles à dessiner:
	void TextViewer:: dessine(Plan const& plan) {}
	void TextViewer:: dessine(Portionplan const& por_plan) {}
	void TextViewer:: dessine(Brique const& brique) {}
	
//Champs de force à dessiner ??
	void TextViewer:: dessine(ChampForces const& ch_force) {}
	void TextViewer:: dessine(Vent const&) {}
