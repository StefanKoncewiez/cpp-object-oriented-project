#pragma once
#include "Vecteur.h"
#include "ObjetsMobiles.h"
#include "Objet.h"
#include <memory>
#include "Systeme.h"

class Systeme;

class Obstacle : public ObjetSimple {
public :
//---------CONSTRUCTEUR/DESTRUCTEUR------------------------------------
Obstacle (Vecteur origine);
virtual ~Obstacle();

//----------MÉTHODES VIRTUELLES PURES-------------------------------------
virtual Vecteur point_plus_proche(const ObjetMobile& objet) const = 0;				//Retourne le point de l'obstacle le plus proche de l'ObjetMobile
virtual std::unique_ptr<Obstacle> copie() const = 0;								//permet la copie polymorphique des sous-classes d'Obstacle, retournant un pointeur sur Obstacle.

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
virtual void agir_sur(ObjetMobile& objet) override;									//méthode qui effectue les chocs entre un Obstacle et un ObjetMobile
virtual double distance(const ObjetMobile&) const override;							//calcule la distance entre l'obstacle et un objet mobile passé en paramètres
virtual void ajoute_a (Systeme & systeme) const override;							//ajoute un obstacle au systeme, utilisées notamment par ObjetCompose pour ajouter ses composantes au bon tableau dans systeme
virtual std::ostream& affiche(std::ostream& sortie) const override;					//méthode d'affihcage polymorphique qui sert à surcharger l'opérateur << de manière polymorphique dans Objet

//----------MÉTHODES_PROPRES_À_OBSTACLE---------------------------------
Vecteur getorigine() const;

protected :
Vecteur position;
};
