#include "PortionPlan.h"

using namespace std;


//---------CONSTRUCTEUR-------------------------------------------------
Portionplan:: Portionplan (const Vecteur& origine, const Vecteur& normal_, double L_, double l_, const Vecteur& vectLONGUEUR)
: Plan(origine, normal_), Longueur(L_*vectLONGUEUR), largeur(l_*(normal^(~Longueur)))
{}

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
Vecteur Portionplan:: point_plus_proche(const ObjetMobile& objet) const{			//Retourne le point le plus proche du plan, implémenté grâce aux compléments mathématiques
	Vecteur X2 (Plan:: point_plus_proche(objet));
	Vecteur EL (~Longueur);
	Vecteur El (~largeur);
	double L (Longueur.norme());
	double l (largeur.norme());
	double XkL( (X2-position)*EL);
	double Xkl( (X2-position)*El);
	if (XkL>L){
	X2 = X2 - ((XkL-L)*EL);
	} else if (XkL<0){
		X2 = X2 - EL*XkL;
		}

	if (Xkl>l){
	X2 = X2 - ((Xkl-l)*El);
	} else if (Xkl<0){
		X2 = X2 - El*Xkl;
		}
		
return X2;
}

unique_ptr<Obstacle> Portionplan:: copie() const {
	return unique_ptr<Obstacle>(new Portionplan(*this)); 
}

void Portionplan:: dessine_sur(SupportADessin& support){
	support.dessine(*this); }

ostream& Portionplan:: affiche(ostream& sortie) const {								//affichage de la portion de plan		
	sortie << "portion de ";
	Plan:: affiche(sortie);
	sortie << largeur << "# largueur"<< endl;
	sortie << Longueur << "#longueur"<< endl;
	return sortie;
}
