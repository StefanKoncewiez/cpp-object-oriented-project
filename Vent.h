#pragma once
#include "ChampForce.h"
#include "ObjetsMobiles.h" 
#include "Vecteur.h"
#include "SupportADessin.h"
#include <memory>
#include <iostream>

class Vent: public ChampForces {
public:

//---------CONSTRUCTEUR-------------------------------------------------
Vent (const Vecteur& Ori, const Vecteur& l, const Vecteur& H, double prof, double V0);

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
virtual void agir_sur(ObjetMobile& objet) override;								//le vent s'applique sur l'objet, modifie les froces extérierus qui s'y appliquent
virtual std::unique_ptr<ChampForces> copie() const override;					//permet la copie profonde polymorphique, retournant un pointeur sur ChampForce.
virtual void dessine_sur(SupportADessin& support) override;						//permet le dessin d'un vent sur un support (appelle dessine())
virtual std::ostream& affiche(std::ostream& sortie) const override;				//permet l'affichage polymorphique (en particulier pour surcharger << dans Objet
virtual double distance(const ObjetMobile&) const override;						//retourne la distance entre "l'origine du vent" et un ObjetMobile passé en paramètre, spécifiquement à cet Objet.

//----------MÉTHODES_PROPRES_AU_VENT------------------------------------
Vecteur get_direction_vent();													//getteur de direction

private:
bool est_dans_vent (const ObjetMobile& objet);									//test si l'ObjetMobile en paramétre se situe dans le champ d'action du vent
double get_vitesse_vent ()const;												//getteur de le vitesse du vent

Vecteur origine;
Vecteur largeur;
Vecteur hauteur;
Vecteur profondeur;
};
