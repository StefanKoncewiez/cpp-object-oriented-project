#pragma once
#include "Vecteur.h"
#include "ObjetsMobiles.h"
#include "SupportADessin.h"
#include "ChampForce.h"
//#include "Systeme.h"
#include <iostream>

class Pendule : public ObjetMobile{
	public:
//---------CONSTRUCTEURS------------------------------------------------
	Pendule (double M, double MV, double R, double L,const Vecteur& P_, double fr = 0, const Vecteur& P_prime = {0} , const Vecteur& F = {0,0,0}, const Vecteur& O = {0,0,0}, const Vecteur& dir = {1,0,0});			//déja un constructeur de copie ?

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
	virtual Vecteur evolution(Vecteur Dt1 = Vecteur({0.0}), Vecteur Dt2 = Vecteur({0.0})) const override;	//héritée d'ObjetMobile, décrit l'équation d'évolution du pendule
	virtual std::ostream& affiche(std::ostream& sortie) const override;										//permet l'affichage polymorphique (en particulier pour surcharger << dans Objet)
	virtual Vecteur getPosition() const override;															//"getter" de position
	virtual Vecteur getVitesse() const override;															//"getter" de vitesse
	virtual void setVitesse(Vecteur const& vect) override;					// a modif						//"setter" de vitesse
	virtual void dessine_sur(SupportADessin& support) override;												//permet le dessin d'un pendule sur un support (appelle dessine())
	virtual std::unique_ptr<ObjetMobile> copie() const override;											//héritée d'ObjetMobile, permet la copie polymorphique
	virtual Vecteur calc_force() const override;
	virtual Vecteur getforce_totale() const override;														//force y compris la tension
	virtual void applique_champ(ChampForces &) override;													//applique ou non la poussée d'archimède
	
//----------MÉTHODES_PROPRES_A_PENDULE----------------------------------
	Vecteur get_tang() const;
	private:
	virtual std:: string get_nom() const override;															//retourne le mot "pendule"
	double frottement;				
	const double longueur;
	Vecteur origine;																						//point d'attache
	Vecteur direction;																						//plan dans lequel le pendule oscille
};
