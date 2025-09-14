#include "Pendule.h"
#include <cmath>
#include <vector>
#include "constantes.h"

using namespace std;


Pendule:: Pendule (double M, double MV, double R, double L, const Vecteur& P_, double fr, const Vecteur& P_prime, const Vecteur& F, const Vecteur& O, const Vecteur& dir)
: ObjetMobile(M,MV,R,F,P_,P_prime), frottement(fr), longueur(L), origine(O), direction(dir)
{}

Vecteur Pendule:: evolution(Vecteur Dt1, Vecteur Dt2) const{								//méthode qui retourne l'équation d'évolution du pendule, implémenter à l'aide du complément mathématiques
	Vecteur T (P + Dt1);
	Vecteur T_p (P_derive + Dt2);
	double valeur(0);
	double theta (T.getvecteur()[0]);
	double theta_point (T_p.getvecteur()[0]);
	double L (longueur);
	if ((direction*g) != 0) {cerr << "le pendule va avoir du mal à osciller dans ce plan" << endl;}
	double b (frottement);
	double m ( masse_ );
	valeur = (cos(theta)* force_ *direction - sin(theta)*(force_* (~g)) - b/L*(theta_point))/(m*L) ;
	return Vecteur ({valeur});
}


Vecteur Pendule:: getforce_totale() const{													//Retourne de la force totale s'exerçant au bout du pendule (y compris la force centripète/de tension)
		double m ( masse_ );																//implémenté à l'aide complément mathématique
		double L (longueur);
		double theta (P.getvecteur()[0]);
		double theta_point (P_derive.getvecteur()[0]);
		return (evolution().getvecteur()[0]*(direction*cos(theta)- sin(theta)*(~g)) - theta_point*theta_point*(direction*sin(theta) +cos(theta)*(~g))  )*m*L ;
}


Vecteur Pendule:: getPosition() const {														//retourne la position du pendule en fonction de l'angle du pendule
double theta (P.getvecteur()[0]);															//implémenté à l'aide complément mathématique
return (origine + (~g)* longueur*cos(theta) + direction * longueur*sin(theta));												
}

Vecteur Pendule:: getVitesse() const {														//retourne la vitesse du pendule en fonction de la vitesse angulaire du pendule
double theta (P.getvecteur()[0]);															//implémenté à l'aide complément mathématique
double thetaP (P_derive.getvecteur()[0]);
return thetaP*longueur * ( direction*cos(theta) - (~g)*sin(theta));
}																

void Pendule:: setVitesse(Vecteur const& vect) {											//modifie la vitesse angulaire du pendule en fonction de la vitesse que l'on veut lui donner
	if ( vect.getvecteur().size() == getVitesse().getvecteur().size()){
		double valeur (( vect * get_tang()*get_tang()).norme() * (1/longueur));
		setP_derive( {valeur*(1/longueur)} );
	} else { cout << "les vecteurs ne sont pas de meme taille";}
}

std::unique_ptr<ObjetMobile> Pendule:: copie() const{										//héritée d'ObjetMobile, permet la copie polymorphique profonde
	return std::unique_ptr<ObjetMobile>(new Pendule(*this)); 
}

void Pendule:: dessine_sur(SupportADessin& support){
support.dessine(*this); }

Vecteur Pendule:: calc_force() const {														//pour les chocs, permet de projeter les forces sur la tangente pour
	Vecteur b(get_tang());																	//forcer les forces à être tengentes au mouvement comme demandé
	return (force_*b)*b;
}


ostream& Pendule:: affiche(ostream& sortie) const{											//affichage d'un pendule
	string nom("pendule");
	sortie << "un " << nom << " :" <<endl;
	sortie << origine << " # origine/point d'attache " << nom << endl << direction << " # direction "<< nom <<endl << longueur << " # longueur "<< nom << endl;
	sortie << frottement << " # frottement " << nom << endl;
	ObjetMobile:: affiche(sortie);
	sortie << P.getvecteur()[0] << " # angle " << nom << endl;
	sortie << P_derive.getvecteur()[0] << " # vitesse angulaire " << nom << endl << evolution() << " # f() " << nom << endl;
	return sortie;

}

void Pendule:: applique_champ(ChampForces & champ) {
	ajoute_force(champ.getchamp() * (masse_  /*- (4 * M_PI * Rho_air * (rayon_*rayon_*rayon_)/3)*/));			//Par convention, nous avons décidé de ne pas appliquer 
																												//la poussée d'Archimède pour les pendules, mais si vous
}																												//si vous voulez l'ajouter il faut décommenter le texte en rouge

string Pendule::get_nom() const{
	return "bout pendule";
}


//----------MÉTHODES_PROPRES_A_PENDULE----------------------------------
Vecteur Pendule:: get_tang() const{															//retourne la tangente au mouvement
	Vecteur a(direction^(~g));
	return Vecteur (a^ (Vecteur (getPosition()-origine) ) );
}
