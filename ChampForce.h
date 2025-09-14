#pragma once
#include "Vecteur.h"
#include "Objet.h"
#include <iostream>
#include "ObjetsMobiles.h"
#include "SupportADessin.h"
#include "Systeme.h"

class ChampForces: public ObjetSimple {
public:
//---------CONSTRUCTEURS/DESTRUCTEUR------------------------------------
ChampForces (double x = 0.0, double y = 0.0, double z = 0.0);
ChampForces (Vecteur const& vect);
virtual ~ChampForces();																//Le destructeur virtual permet la désallocation dans les sous-classes si l'on utilise des pointeurs

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
virtual void agir_sur(ObjetMobile& objet) override;									//le ChampForce s'applique à l'ObjetMobile
virtual std::ostream& affiche(std::ostream& sortie) const override;					//permet l'affichage polymorphique (en particulier pour surcharger << dans Objet
virtual double distance(const ObjetMobile&) const override;							//retourne la distance entre le champ de force et un objet mobile passé en paramètres, ici 0 par defaut.
virtual std::unique_ptr<ChampForces> copie() const;									//permet la copie profonde polymorphique des ChampForce et ses sous-classes, retournant un pointeur sur ChampForce.
virtual void dessine_sur(SupportADessin& support) override;							//permet le dessin d'un ChampForce sur un support (appelle dessine())
virtual void ajoute_a(Systeme &) const override;									//ajoute un champ de force au systeme, utilisées notamment par ObjetCompose pour ajouter ses composantes au bon tableau dans systeme

//----------MÉTHODES PROPRES_À_CHAMPFORCE-------------------------------
Vecteur getchamp() const;															//getteur de champ_forces
protected:
Vecteur champ_forces;
};
