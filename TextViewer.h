#pragma once
#include <iostream>
#include "SupportADessin.h"
#include "ChampForce.h" 
#include "Plan.h" 
#include "PortionPlan.h" 
#include "Balle.h" 
#include "Pendule.h" 
#include "Brique.h" 
#include "Systeme.h"
#include "Ressort.h"
#include "Vent.h"

//La classe TextViewer indique que l'on souhaite afficher la simulation sous forme textuelle sur un flot (avec "cout" pour designer le terminal)
class TextViewer : public SupportADessin{
public:

//---------CONSTRUCTEUR-------------------------------------------------
	TextViewer(std::ostream& f);

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
//Définition des méthode virtuelles pures de la classe SupportADessin , selon la manière dont on veut l'affichage


	virtual void dessine(Systeme const&) override;
	
//ObjetsMobiles à dessiner:
	virtual void dessine(Pendule const&) override;
	virtual void dessine(Balle const&) override;
	virtual void dessine(Ressort const&) override;
	
//Obstacles à dessiner:
	virtual void dessine(Plan const&) override;
	virtual void dessine(Portionplan const&) override;
	virtual void dessine(Brique const&) override;
//Champs de force à dessiner:
	virtual void dessine(ChampForces const&) override;
	virtual void dessine(Vent const&) override;

private:
	 std::ostream& flot;														//flor sur lequel on souhaite "dessiner" le systeme
};
