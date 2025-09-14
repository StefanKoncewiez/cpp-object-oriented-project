#include <cmath>
#include "obstacles.h"
#include "constantes.h"

using namespace std;

//---------CONSTRUCTEUR/DESTRUCTEURS------------------------------------
Obstacle:: Obstacle (Vecteur origine)
:position(origine)
{}

Obstacle:: ~Obstacle()= default;


//----------MÉTHODES POLYMORPHIQUES-------------------------------------
void Obstacle:: agir_sur(ObjetMobile& objet){												//effectue les chocs entre 2 ObjetMobile, modifie leur vitesse et leur forces
																							//Implémenté grâce aux complément mathématique

	Vecteur Prime (objet.getVitesse());
	Vecteur P (objet.getPosition());
	Vecteur n(~(P-point_plus_proche(objet)));												//vecteur unitaire normal au choc, dirigé dans le corps 1
	double alpha (alpha_);																	// coefficient de restitution (dans constantes.cc)
	if (alpha<0) {alpha=0;}
	double mu (mu_);																			// coefficient de frottement entre corps (dans constantes.cc)
	if (mu<0) {mu=0;}
	Vecteur deltaV(objet.getVitesse().getvecteur().size());									//  vecteur nul à la dimension de le vitesse de l'objet
	
	if ( distance(objet) <= 0 ) {															//si l'objet "traverse" l'obstacle
	double Fn1(objet.getforce() * n);
		if (Fn1<0){
		objet.setforce ( objet.getforce() - (n*Fn1) );
		objet.setforce(objet.calc_force());//
		}
	double V_ (- Prime * n);
	Vecteur Vc ( Prime + (n*V_) );
		if ( (7*mu*(1+alpha)*V_) >= 2*Vc.norme() ) {
		deltaV = n*((1+alpha)*V_) - Vc*(2/7);
		} else {
		deltaV = (n - (~Vc)*mu) * ((1+alpha)*V_);
		}
	objet.setVitesse( Prime + deltaV );


	//DEBUG
	cout << "vstar = " << V_<<endl;
	cout << "vc = " << Vc << endl;
	cout << "7*µ*(1+alpha)*vstar = " << 7*mu*(1+alpha)*V_<< endl;
	cout << "dv = " << deltaV << endl;
	cout << "vitesse : Prime + deltaV = " << Prime + deltaV<<endl;
	cout << "positon =" << objet.getPosition()<<endl;
	
	cout <<endl;
	}
}

void Obstacle:: ajoute_a (Systeme & systeme) const{													//permet l'ajout d'un obstacle au système, en l'ajoutant au tableau d'obstacles du système
	systeme.ajoute_obstacle(*this);
}

double Obstacle:: distance(const ObjetMobile& obj) const{											//calcule la distance entre un obstacle et l'objet mobile :
	return (obj.getPosition() - point_plus_proche(obj)).norme() - obj.getrayon();}					//distance entre le centre de l'objet et le point de l'obstacle
																									//qui en est le plus proche à laquelle on enleve le rayon afin
																									//d'obtenir la distance entre le bord de l'objet et l'obstacle
std::ostream& Obstacle:: affiche(std::ostream& sortie) const {
	sortie << position << "#origine" <<endl;
	return sortie;
}	

//----------MÉTHODES_PROPRES_À_OBSTACLE---------------------------------
Vecteur Obstacle:: getorigine() const{return position;}
