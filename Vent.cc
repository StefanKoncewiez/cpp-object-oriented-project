#include "Vent.h"
#include "PortionPlan.h"

using namespace std;

//---------CONSTRUCTEUR-------------------------------------------------
Vent:: Vent (const Vecteur& Ori, const Vecteur& l, const Vecteur& H, double prof, double V0)
:ChampForces(V0*(~(l^H))),origine (Ori), largeur(l), hauteur(H), profondeur((~(l^H) )*prof)
{}																					//La champ_force est initialisé à la vitesse du vent le long de la direction du vent (V0*(~(l^H))
																					//La profondeur est initialiser à la profondeur, dans la direction du vent.

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
void Vent:: agir_sur(ObjetMobile& objet){											//Si l'objet est dans le champ d'action du vent, on lui applique le vent (compément mathématique)
	if (est_dans_vent(objet)){
		Vecteur F( 3.77*get_vitesse_vent()*get_vitesse_vent()*objet.getrayon()*objet.getrayon()*(~profondeur) );
		objet.ajoute_force(F);
	}
}

void Vent:: dessine_sur(SupportADessin& support)
  { support.dessine(*this); }


std::unique_ptr<ChampForces> Vent:: copie() const {
	return std::unique_ptr<ChampForces>(new Vent(*this)); 
}

ostream& Vent:: affiche(ostream& sortie) const{										//Affichage d'un vent
sortie << "un vent :" << endl;
sortie << origine << "#origine vent" << endl;
sortie << largeur << "#largeur vent" << endl;
sortie << hauteur << "#hauteur vent" << endl;
sortie << profondeur.norme()  << " #profondeur vent" << endl;
sortie << get_vitesse_vent() << " #vitesse du vent" << endl;
return sortie;}

double Vent:: distance(const ObjetMobile& obj) const{
Portionplan p (origine, ~profondeur, hauteur.norme(), largeur.norme(), ~hauteur); 	// "plan du vent"
return (obj.getPosition() - p.point_plus_proche(obj)).norme() - obj.getrayon();
}

//----------MÉTHODES_PROPRES_AU_VENT------------------------------------
Vecteur Vent:: get_direction_vent() {return ~profondeur;}							//getteur de la direction du vent

double Vent:: get_vitesse_vent() const{return champ_forces*(~profondeur);}			//getteur de la vitesse du vent

bool Vent:: est_dans_vent (const ObjetMobile& objet){								//teste si l'objet mobile est dans l'action du vent, implémenté à l'aide du complément mathématique
	Vecteur pos_rel(objet.getPosition()-origine);
	Vecteur el (~largeur);
	Vecteur eL (~hauteur);
	Vecteur n (~profondeur);
	if (not (pos_rel * n > 0 and pos_rel * n < profondeur.norme()) ) return false;
	if (not (pos_rel * el > 0 and pos_rel * el < largeur.norme()) ) return false;
	if (not (pos_rel * eL > 0 and pos_rel * eL < hauteur.norme()) ) return false;

	return true;
}
