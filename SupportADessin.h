#pragma once

//Déclaration de certaines classes pour que le compilateur sache qu'elles existent 
//La classe SupportADessin indique sous quelle forme on souhaite afficher la simulation (textuelle, graphique...)
//C'est une classe abstraite dont hérite la classe TextViewer (simulation textuelle)

class Systeme;
class Balle;
class Pendule;
class Brique;
class Plan;
class Portionplan;
class ChampForces;
class Ressort;
class Vent;

class SupportADessin {
public:

//Méthodes virtuelles pures qui indiquent comment afficher les différents objets de la simulation
//La classe SupportADessin ne sait pas encore comment la simulation va être faite, d'où le choix de virtuelles pures
	virtual ~SupportADessin();

	SupportADessin(){}													//La classe ne possède pas d'attrubuts, donc le constructeur ne fait rien

	virtual void dessine(Systeme const&) = 0;
	
	//ObjetsMobiles à dessiner:
	virtual void dessine(Pendule const&) = 0;
	virtual void dessine(Balle const&) = 0;
	virtual void dessine(Ressort const&) = 0;
	
	//Obstacles à dessiner:
	virtual void dessine(Plan const&) = 0;
	virtual void dessine(Portionplan const&) = 0;
	virtual void dessine(Brique const&) = 0;
	
	//Champs de force à dessiner ??
	virtual void dessine(ChampForces const&) = 0;
	virtual void dessine(Vent const&) =0;

protected:
	//Eviter les copies de support à dessin, qui n'auraient pas de sens 
		SupportADessin(SupportADessin const&) = delete;
		SupportADessin& operator=(SupportADessin const&) = delete;

};
