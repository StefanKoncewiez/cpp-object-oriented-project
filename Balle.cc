#include "Balle.h"
#include <cmath>
#include "constantes.h"


using namespace std;

//---------CONSTRUCTEURS------------------------------------------------
Balle:: Balle (Balle const & autre)
: ObjetMobile (autre)
{}

Balle:: Balle (double M, double MV, double R, const Vecteur& F, const Vecteur& P_, const Vecteur& P_prime)
	: ObjetMobile (M,MV,R,F,P_,P_prime)													//appel au constructeur d'ObjetMobile
{}


//----------MÉTHODES POLYMORPHIQUES-------------------------------------
Vecteur Balle:: evolution (Vecteur Dt1, Vecteur Dt2) const {
	return (force_*(1/masse_));															//complément mathématique
}

std::unique_ptr<ObjetMobile> Balle:: copie() const{										//Voir class Systeme pour l'utilisation et l'explication de l'utilité de cette méthode
	return std::unique_ptr<ObjetMobile>(new Balle(*this)); 								//Retourne un unique_ptr sur un ObjetMobile, initialisé à l'instance courante de Balle
}

Vecteur Balle:: getPosition() const {return P;}											//Pour une balle, la position est le vecteur de paramètres.
Vecteur Balle:: getVitesse() const {return P_derive;}									//Pour une balle, la vitesse est le vecteur de paramètres dérivés.

void Balle:: setVitesse(Vecteur const& vect) {
	if ( vect.getvecteur().size() == P_derive.getvecteur().size()){						//test pour ne pas affecter un vecteur d'une dimension différente
	(*this).setP_derive(vect);															//Affecte "vect" au vecteur de paramètres dérivés de l'instance courante
	}else { cout << "les vecteurs ne sont pas de meme taille";}
}

void Balle:: dessine_sur(SupportADessin& support){										//Toute classe Dessinable doit redéfinir cette méthode à l'identique
	support.dessine(*this); //Cette méthode permet d'avoir du polymorphisme dans l'affichage de tous les ObjetMobile du Systeme (Voir TextViwer)
	}	

ostream& Balle:: affiche(ostream& sortie) const {
	string nom (get_nom());
	sortie << "une " << nom << " :"<<endl;
	ObjetMobile:: affiche(sortie);														//Permet d'éviter la duplication de code (regroupe l'affichage identique entre Balle et Pendule)
	sortie << evolution() << " # f() " << nom << endl;
	return sortie;
}

void Balle:: applique_champ(ChampForces & champ) {										//Pour un balle on deécide d'appliquer la force d'Archimède
	ajoute_force(champ.getchamp() * (masse_  - (4 * M_PI * Rho_air * (rayon_*rayon_*rayon_)/3)));
}


//----------MÉTHODES PROPRES_À_LA_BALLE---------------------------------
void Balle:: setPosition(Vecteur const& vect) {											
	if ( vect.getvecteur().size() == P.getvecteur().size()){							//test pour ne pas affecter un vecteur d'une dimension différente
	setParam(vect);																		//Affecte "vect" au vecteur de paramètres de l'instance courante
	}else {
	cout << "les vecteurs ne sont pas de meme taille";}
}


string Balle::get_nom() const{
	return "balle";
}


