#pragma once
#include "obstacles.h"
#include "Vecteur.h"
#include "ObjetsMobiles.h"
#include "SupportADessin.h"

class Plan : public Obstacle {
	public:
//---------CONSTRUCTEUR/DESTRUCTEUR-------------------------------------
	Plan (const Vecteur& origine, const Vecteur& norm);
	virtual ~Plan();

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
	virtual Vecteur point_plus_proche (const ObjetMobile& objet) const override;			//Retourne le point du plan le plus proche de l'ObjetMobile
	virtual std::ostream& affiche(std::ostream& sortie) const override;						//méthode d'affihcage polymorphique qui sert à surcharger l'opérateur << de manière polymorphique dans Objet
	virtual std::unique_ptr<Obstacle> copie() const override;								//permet la copie profonde polymorphique des sous-classes d'Obstacle, retournant un pointeur sur Obstacle.
	void dessine_sur(SupportADessin& support) override;										//permet le dessin d'un plan sur un support (appelle dessine())
	
	protected:
	Vecteur normal;
};

