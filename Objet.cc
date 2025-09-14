#include "Objet.h"

using namespace std;

//---------DESTRUCTEUR--------------------------------------------------
Objet:: ~Objet() = default;

ostream& operator<< (ostream& sortie, const Objet& obj){return obj.affiche(sortie);}  //cet operateur surchargé appelle simplement la méthode polymorphique affiche() redefinie dans chaque Objet


//======================================================================

//---------DESTRUCTEUR--------------------------------------------------
ObjetSimple:: ~ObjetSimple() = default;


//======================================================================


//---------DESTRUCTEUR--------------------------------------------------
ObjetCompose:: ~ObjetCompose() = default;


//----------MÉTHODES_PLYMORPHIQUES--------------------------------------
std::ostream& ObjetCompose:: affiche(std::ostream& sortie) const{						//Pour afficher un ObjetCompose, on appelle simplement la méthode affiche de chacune de ses composantes.
	if (not composants.empty()) {
		for (auto const& obj : composants) {
		obj->affiche(sortie);
		}
	}
return sortie;
}

void ObjetCompose:: agir_sur(ObjetMobile& objet){										//Pour faire agir un ObjetCompose sur un ObjetMobile, on appelle simplement la méthode agir_sur de chacune de ses composantes.
	if (not composants.empty()) {														
		for (auto const& element : composants) {
		element->agir_sur(objet);
		}
	}
}

void ObjetCompose:: ajoute_a (Systeme& systeme) const{									//Pour ajouter un ObjetCompose à un système, on ajoute simplement chacune de ses composantes au système.
	if (not composants.empty()) {
		for (auto const& obj : composants) {
		obj->ajoute_a(systeme);
		}
	}
}

double ObjetCompose:: distance(const ObjetMobile& obj) const{
	if (not composants.empty()) {
	double plus_petite_d (composants[0]->distance(obj));								//on initialise la plus petite distance à la distance entre le premier composant et l'objet
	for (auto const& element: composants) {
		if (element->distance(obj) <= plus_petite_d){									//si un composant de l'ObjetCompose est à une plus petite distance de l'objet,
		plus_petite_d = element->distance(obj); 										//alors cette distance devient la plus petite distance (plus_petite_d).
		}
	}
	return plus_petite_d;
	}else {
	cerr << "on ne peut pas calculer de distance si l'objet est vide ! (0 par defaut)";
	return 0;
	}
}

void ObjetCompose:: dessine_sur(SupportADessin& support){								//Pour dessiner un ObjetCompose, on dessine simplement chacune de ses composantes.
	
	if (not composants.empty()) {
		for (auto const& element : composants) {
			element->dessine_sur(support);
		}
	}
}
