#include "integrateur.h"
#include "Vecteur.h"
#include "constantes.h"
#include <vector>
#include <cmath>

using namespace std;

//INTEGRATEUR===========================================================
//----------DESTRUCTEUR-------------------------------------------------
Integrateur:: ~Integrateur() = default;

//----------MÉTHODE_POLYMORPHIQUE---------------------------------------
ostream& Integrateur:: affiche(ostream& sortie) const{					//Cet affichage sera notamment utile dans la classe Systeme
	sortie << "Integrateur";											
	return sortie;}


std::ostream& operator<<(std::ostream& sortie, Integrateur const & integr){return integr.affiche(sortie);}


//INTEGRATEUR_EULER=====================================================

IntegrateurEuler:: ~IntegrateurEuler() = default;

Vecteur IntegrateurEuler:: integre_P_derivee(ObjetMobile& objet, double delta_T) {
	return(objet.getP_derive() + objet.evolution() * delta_T );
}
Vecteur IntegrateurEuler:: integre_Param(ObjetMobile& objet, double delta_T) {
	return( objet.getParam() + objet.getP_derive() * delta_T );
}

void IntegrateurEuler:: integre (ObjetMobile& objet, double delta_T) {
Vecteur x(integre_Param(objet, delta_T));
Vecteur y (integre_P_derivee(objet, delta_T));
objet.setParam(x);
objet.setP_derive(y);
}

ostream& IntegrateurEuler:: affiche(ostream& sortie) const{
	Integrateur:: affiche(sortie);
	sortie << " Euler"<<endl;
	return sortie;}

Integrateur* IntegrateurEuler:: copie() const {return new IntegrateurEuler(*this);}


//INTEGRATEUR_EULER_CROMER==============================================

void IntegrateurEulerCromer:: integre(ObjetMobile& objet, double delta_T) {
	if ( objet.getP_derive().getvecteur().empty() ) {					//Ceci est une équation différentielle du premier ordre
		   objet.setParam ( objet.getParam() + objet.evolution() * delta_T);
	}else {
		//cout << "P_derive = " << integre_P_derivee(objet, delta_T);
		objet.setP_derive(integre_P_derivee(objet, delta_T));
		Vecteur x (objet.getParam()+ objet.getP_derive() * delta_T);
		objet.setParam (x);
	}
}
Integrateur* IntegrateurEulerCromer:: copie() const {return new IntegrateurEulerCromer(*this);}


ostream& IntegrateurEulerCromer:: affiche(ostream& sortie) const{
	Integrateur:: affiche(sortie);
	sortie << "Euler-Cromer" << endl;
	return sortie;}


//INTEGRATEUR_NEWMARK===================================================

void IntegrateurNewark:: integre(ObjetMobile& objet, double delta_T) {	
	
	Vecteur oldP_derive (objet.getP_derive());
	Vecteur oldP (objet.getParam());
	Vecteur q (0.0);
	Vecteur r (0.0);
	//Initialisation :
	objet.setParam(oldP);
	objet.setP_derive(oldP_derive);
	Vecteur s (objet.evolution());
	//Boucle :
	do{
		q = objet.getParam();
		r = objet.evolution();
		objet.setP_derive(oldP_derive + (delta_T/2) * (r+s)  );
		objet.setParam ( oldP + delta_T * oldP_derive + (delta_T*delta_T/3) * (r*0.5 + s)  );
	}while((objet.getParam()-q).norme()>=epsilon);
}

Integrateur* IntegrateurNewark:: copie() const {return new IntegrateurNewark(*this);}

ostream& IntegrateurNewark:: affiche(ostream& sortie) const{
	Integrateur:: affiche(sortie);
	sortie << " Newmark" << endl;
	return sortie;
	}


//INTEGRATEUR_RUNGE-KUTTA===============================================

void IntegrateurRungeKutta:: integre(ObjetMobile& objet, double delta_T) { //Nous avons utilisé la lettre f comme moyen mnémotechnique (la méthode evolution est notée f dans le complément mathématique)
	Vecteur f1 (objet.evolution());
	Vecteur f2 (f1.getvecteur().size());
	Vecteur f3 (f2);
	Vecteur f4 (f2);
	if ( objet.getP_derive().getvecteur().empty() ) {					//eq. diff. premier ordre
		f2 = objet.evolution (f1*(delta_T/2));
		f3 = objet.evolution (f2*(delta_T/2));
		f4 = objet.evolution (f3*delta_T);
		objet.setParam (objet.getParam() + (f1+2*f2+2*f3+f4)*(delta_T/6));
	}else {
		Vecteur P1 (objet.getP_derive());								
		Vecteur P2 (P1 + f1*(delta_T/2));
		f2 = objet.evolution(P1*(delta_T/2), f1*(delta_T/2));			//Voir [Question P12.1] pour l'explication de cette méthode evolution revisitée
		Vecteur P3 (P1 + f2*(delta_T/2));
		f3 = objet.evolution(P2*(delta_T/2), f2*(delta_T/2));
		Vecteur P4 (P1 + f3*delta_T);
		f4 = objet.evolution(P3*delta_T, f3*delta_T);
		objet.setParam ( objet.getParam() + (P1+2*P2+2*P3+P4)*(delta_T/6));
		objet.setP_derive ( P1 + (f1+2*f2+2*f3+f4)*(delta_T/6));
	}

}

Integrateur* IntegrateurRungeKutta:: copie() const {return new IntegrateurRungeKutta(*this);}

ostream& IntegrateurRungeKutta:: affiche(ostream& sortie) const{
	Integrateur:: affiche(sortie);
	sortie << " Runge-Kutta"  << endl;
	return sortie;
	}
