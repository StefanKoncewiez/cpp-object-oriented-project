#include "ChampForce.h"
#include "constantes.h"
#include <cmath>

using namespace std;

//---------CONSTRUCTEURS/DESTRUCTEUR------------------------------------
ChampForces:: ChampForces (double x, double y, double z)
	: champ_forces(x,y,z)
{}

ChampForces:: ChampForces (Vecteur const& vect)
	: champ_forces(vect.getvecteur())
{}

ChampForces:: ~ChampForces() = default;


//----------MÉTHODES POLYMORPHIQUES-------------------------------------
void ChampForces:: agir_sur(ObjetMobile& objet) {						//a tester
	objet.applique_champ(*this);
		/*double m( objet.getmasse());
		double r( objet.getrayon() );
		Vecteur F (champ_forces* (m - (4 * M_PI * Rho_air * (r*r*r)/3)));
		objet.ajoute_force(F);*/
}

double ChampForces:: distance(const ObjetMobile&) const {							//car définition le champ est défini en tout points de l'espace, donc le point le plus proche dans le champ c'est la position de l'objet mobile
return 0;}																			//comme le point d'application du champ est supposé la position de l'objet mobile (i.e. on ne s'occupe pas du rayon), alors la distance est 0 tout le temps.

unique_ptr<ChampForces> ChampForces:: copie() const{
	return unique_ptr<ChampForces>(new ChampForces(*this)); 
}

void ChampForces:: dessine_sur(SupportADessin& support)
  { support.dessine(*this); }
  
ostream& ChampForces:: affiche(ostream& sortie) const{								//affichage d'un ChampForce
champ_forces.affiche(sortie);
sortie << "# intensité"<< endl;
return sortie;}


void ChampForces:: ajoute_a(Systeme & systeme) const{
	systeme.ajoute_champ(*this);
}


//----------MÉTHODES PROPRES_À_CHAMPFORCE-------------------------------
Vecteur ChampForces:: getchamp() const{
return champ_forces;
}
