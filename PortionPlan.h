#pragma once
#include "Vecteur.h"
#include "Plan.h"
#include "obstacles.h"
#include "ObjetsMobiles.h"
#include "SupportADessin.h"
#include <iostream>
#include <memory>

class Portionplan : public Plan {
public:
//---------CONSTRUCTEUR-------------------------------------------------
Portionplan (const Vecteur& origine, const Vecteur& normal_, double L_, double l_, const Vecteur& vectLONGUEUR);

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
virtual Vecteur point_plus_proche(const ObjetMobile& objet)const override;					//Retourne le point de la portion de plan le plus proche de l'ObjetMobile
virtual std::ostream& affiche(std::ostream& sortie) const override;							//méthode d'affihcage polymorphique qui sert à surcharger l'opérateur << de manière polymorphique dans Objet
virtual std::unique_ptr<Obstacle> copie() const override;									//permet la copie profonde polymorphique des sous-classes d'Obstacle, retournant un pointeur sur Obstacle.
virtual void dessine_sur(SupportADessin& support) override;									//permet le dessin d'une portion de plan sur un support (appelle dessine())

private:
Vecteur Longueur;
Vecteur largeur;
	
};
