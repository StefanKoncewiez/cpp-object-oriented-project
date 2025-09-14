#pragma once
#include "Objet.h" 
#include "Brique.h"
#include "Vecteur.h"


class Ventilateur : public ObjetCompose {
public:
//---------CONSTRUCTEURS------------------------------------------------
Ventilateur (Brique b, double profondeur, double vitesse );		
Ventilateur (const Vecteur& ori, const Vecteur& L, const Vecteur& l, double Hbrique, double prof, double vitesse);

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
virtual std::ostream& affiche(std::ostream& sortie) const override;			//permet l'affichage polymorphique (en particulier pour surcharger << dans Objet
};
