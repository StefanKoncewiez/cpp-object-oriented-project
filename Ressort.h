#pragma once
#include "Vecteur.h"
#include "ObjetsMobiles.h"
#include "SupportADessin.h"
#include "ChampForce.h"
#include <iostream>

using namespace std;

class Ressort: public ObjetMobile{

public:
//---------CONSTRUCTEUR-------------------------------------------------
Ressort (double M, double MV, double R, double k,const Vecteur& P_, double fr = 0, const Vecteur& P_prime = {0} , const Vecteur& F = {0,0,0}, const Vecteur& O = {0,0,0}, const Vecteur& dir = {1,0,0});

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
virtual Vecteur evolution(Vecteur Dt1 = Vecteur({0.0}), Vecteur Dt2 = Vecteur({0.0})) const override;		//redéfinie d'ObjetMobile, décrit l'équation d'évolution du ressort
virtual Vecteur getPosition() const override;																//"getter" de position
virtual Vecteur getVitesse() const override;																//"getter" de vitesse
virtual void setVitesse(Vecteur const& vect) override;														//"setter" de vitesse
virtual std::unique_ptr<ObjetMobile> copie() const override;												//héritée d'ObjetMobile, permet la copie polymorphique
virtual string get_nom() const override;
virtual void dessine_sur(SupportADessin& support) override;													//permet le dessin d'un ressort
virtual ostream& affiche(ostream& sortie) const override;													//permet l'affichage polymorphique (en particulier pour surcharger << dans Objet)
virtual void applique_champ(ChampForces &) override;														//applique ou non la poussée d'archimède

private:
	double k;
	double frottement;
	Vecteur origine;
	Vecteur direction;																						//direction d'oscillation
};
