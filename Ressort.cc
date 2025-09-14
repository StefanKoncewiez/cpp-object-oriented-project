#include "Ressort.h"
#include <iostream>

using namespace std;

//---------CONSTRUCTEUR-------------------------------------------------
Ressort::Ressort (double M, double MV, double R, double k,const Vecteur& P_, double fr, const Vecteur& P_prime, const Vecteur& F, const Vecteur& O, const Vecteur& dir)
: ObjetMobile(M,MV,R,F,P_,P_prime), k(k), frottement(fr), origine(O), direction(dir)
{}


//----------MÉTHODES POLYMORPHIQUES-------------------------------------
Vecteur Ressort:: evolution(Vecteur Dt1, Vecteur Dt2) const{							//méthode qui retourne l'équation d'évolution du pendule, implémenter à l'aide du complément mathématiques
	Vecteur T (P + Dt1);
	Vecteur T_p (P_derive + Dt2);
	double theta (T.getvecteur()[0]);
	double theta_point (T_p.getvecteur()[0]);
	double b (frottement);
	double m ( masse_ );
	return Vecteur ({(force_ * direction - k*theta - b*theta_point)/m});
}


Vecteur Ressort:: getPosition() const {													//retourne la position du ressort en fonction de l'angle du pendule
double theta (P.getvecteur()[0]);
return origine + direction*theta;
}

Vecteur Ressort:: getVitesse() const {													//retourne la vitesse du ressort en fonction de la vitesse angulaire du pendule
double thetaP (P_derive.getvecteur()[0]);
return direction * thetaP;
}

void Ressort:: setVitesse(Vecteur const& vect) {										//modifie le ressort en fonction de la vitesse que l'on veut lui donner
	if ( vect.getvecteur().size() == getVitesse().getvecteur().size()){
		//
	} else { cout << "les vecteurs ne sont pas de meme taille";}
}

//getforcetotale??																		//Retourne de la force totale s'exerçant au bout du pendule (y compris la force centripète/de tension)

std::unique_ptr<ObjetMobile> Ressort:: copie() const {
	return std::unique_ptr<ObjetMobile>(new Ressort(*this)); 
}
void Ressort:: applique_champ(ChampForces & champ) {
	ajoute_force(champ.getchamp()* (masse_/*- (4 * M_PI * Rho_air * (rayon_*rayon_*rayon_)/3)*/));				//Par convention, nous avons décidé de ne pas appliquer la poussée d'Archimède pour les pendules, mais si vous voulez l'ajouter il faut décommenter le texte en rouge
}


string Ressort:: get_nom() const {
	return "ressort";
}




void Ressort:: dessine_sur(SupportADessin& support) {
support.dessine(*this); }


ostream& Ressort:: affiche(ostream& sortie) const {
	string nom (get_nom());
	sortie << "un " << nom << " :" <<endl;
	sortie << masse_ << " # masse "<< nom << endl << k << " # raideur "<< nom << endl << frottement << " # frottement "<< endl;
	sortie << origine <<" # origine " << nom <<endl << direction << " # direction " << nom <<endl << P.getvecteur()[0] << " # x " << nom << endl;
	sortie << P_derive.getvecteur()[0] << " # x point " << nom  << endl << evolution() << " # f() "<< nom << endl;
	sortie << getPosition() << "position bout " << nom << endl;
	return sortie;
}

