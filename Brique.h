#pragma once
#include "obstacles.h"
#include "Vecteur.h"
#include "ObjetsMobiles.h"
#include "SupportADessin.h"

class Brique : public Obstacle {
	public:
	
//---------CONSTRUCTEURS------------------------------------------------
	Brique (const Vecteur& origine, const Vecteur& L, const Vecteur& l, double H);

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
	virtual Vecteur point_plus_proche(const ObjetMobile& objet) const override;			//permet de trouver le point le plus proche à la brique
	virtual std::ostream& affiche(std::ostream& sortie) const override;					//permet l'affichage polymorphique (en particulier pour surcharger << dans Objet
	virtual std::unique_ptr<Obstacle> copie() const override;							//héritée d'Obstacle, permet la copie polymorphique
	void dessine_sur(SupportADessin& support) override;									//permet le dessin d'une brique sur un support (appelle dessine())

//----------MÉTHODES PROPRES_À_LA_BRIQUE--------------------------------

	Vecteur getvectlong();
	Vecteur getvectlarg();
	
	private:
	Vecteur calclargeur();																//projette la longueur sur le vecteur sur le Vecteur orthogonal à la longueur
	Vecteur calcnormal();																//Calcule le vecteur normal unitaire grâce aux Vecteur longueur et largeur
	
	Vecteur longueur;
	Vecteur largeur;
	double hauteur;
	Vecteur normal;
};
