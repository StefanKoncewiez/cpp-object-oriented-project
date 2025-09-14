#pragma once
#include "Vecteur.h"
#include "ObjetsMobiles.h"
#include "SupportADessin.h"
#include "ChampForce.h"
#include <string>
#include <iostream>

class Balle : public ObjetMobile {
	public: 

//---------CONSTRUCTEURS------------------------------------------------
	Balle (Balle const & autre);
	Balle (double M=0, double MV=0,double R=1, const Vecteur& F = {0.0, 0.0, 0.0}, const Vecteur& P_ = {0.0, 0.0, 0.0}, const Vecteur& P_prime = {0.0, 0.0, 0.0});

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
	Vecteur evolution(Vecteur Dt1 = Vecteur({0.0}), Vecteur Dt2 = Vecteur({0.0})) const override;	//héritée d'ObjetMobile, décrit l'équation d'évolution de la balle (Voir [Question P12.1] pour les paramètres par défaut)
	virtual std::unique_ptr<ObjetMobile> copie() const override;									//héritée d'ObjetMobile, permet la copie polymorphique
	virtual void setVitesse(Vecteur const&) override;												//"setter" de vitesse
	virtual void dessine_sur(SupportADessin& support) override;										//permet le dessin d'une balle sur un support (appelle dessine())
	virtual std::ostream& affiche(std::ostream& sortie) const override;								//permet l'affichage polymorphique (en particulier pour surcharger << dans Objet
	virtual Vecteur getPosition() const override;													//"getter" de position
	virtual Vecteur getVitesse() const override;													//"getter" de vitesse
	virtual void applique_champ(ChampForces &) override;

//----------MÉTHODES_PROPRES_À_LA_BALLE---------------------------------
	void setPosition(Vecteur const&);																//"setter" de vitesse propre à le balle
	private:
	virtual std::string get_nom() const override;													//retourne le mot "balle"

};



