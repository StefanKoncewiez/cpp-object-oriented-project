#pragma once
#include <iostream>
#include "Dessinable.h"
#include <vector>
#include <memory>

class Systeme;
class ObjetMobile;



class Objet : public Dessinable {
public:
//---------DESTRUCTEUR--------------------------------------------------
virtual ~Objet();

//----------MÉTHODES_VIRTUELLES_PURES-----------------------------------
virtual std::ostream& affiche(std::ostream& sortie) const = 0;						//méthode qui sert à faire une surcharge polymorphique de l'opérateur << : elle est redéfinie dans tous les objets selon la manière dont ils s'affichent
virtual void agir_sur (ObjetMobile& objet) = 0;										//tous les objets ont cette méthode, chacun a sa manière d'agir sur des objets mobiles : les champs de force exercent une force sur eux, les objets entre en collision avec, les obstacles entre en collision avec
virtual void ajoute_a(Systeme &) const = 0;											//ajoute n'importe quel Objet au Systeme, utilisée notamment par ObjetCompose pour ajouter ses composantes au bon tableau dans systeme
virtual double distance(const ObjetMobile&) const = 0;								//retourne la distance entre l'Objet et un ObjetMobile passé en paramètre, spécifiquement à cet Objet.
};

std::ostream& operator<< (std::ostream& sortie, const Objet& obj);					//surchage de l'operateur de manière polymorphique pour afficher TOUS les Objet

//====================================================================================================================================================================

class ObjetSimple : public Objet {								//presque vide, principalement pour organiser le code
public:
//---------DESTRUCTEUR--------------------------------------------------
virtual ~ObjetSimple();
};

//====================================================================================================================================================================

class ObjetCompose : public Objet {
public:
//---------DESTRUCTEUR--------------------------------------------------
virtual ~ObjetCompose();

//----------MÉTHODES_PLYMORPHIQUES--------------------------------------
virtual std::ostream& affiche(std::ostream& sortie) const override;					//méthode qui sert à faire une surcharge polymorphique de l'opérateur << dans Objet
virtual void agir_sur(ObjetMobile& objet) override;									//définit comment un ObjetCompose agit sur un ObjetMobile
virtual void ajoute_a (Systeme& systeme) const override;							//permet d'ajouter un ObjetCompose au systeme : elle ajoute ses composantes au bon tableau dans systeme
virtual double distance(const ObjetMobile&) const override;							//retourne la distance entre l'ObjetComposr et un ObjetMobile passé en paramètre
virtual void dessine_sur(SupportADessin& support) override;							//permet le dessin d'une balle sur un support (appelle dessine())

protected:
std::vector <std::unique_ptr<Objet>> composants;									//unique_ptr car les composantes sont propres à l'objet composé + polymorphisme
};

