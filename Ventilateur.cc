#include "Ventilateur.h"
#include "Vent.h"
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

//---------CONSTRUCTEURS------------------------------------------------
Ventilateur:: Ventilateur (Brique b, double prof, double vit_vent)
: ObjetCompose()
{																					//DEBUG pout verifier qu'on a bien construit un vent dans le sens voulu:
Vent vent (b.getorigine(), b.getvectlarg(), b.getvectlong(), prof, vit_vent);		//cout << "direction vent" << vent.get_direction_vent();

composants.push_back(std:: unique_ptr <Objet> (new Brique (b)));					//On ajoute un pointeur une brique au tableau des composants d'ObjetCompose
composants.push_back(std:: unique_ptr <Objet> (new Vent (vent)));					//On ajoute un pointeur un vent au tableau des composants d'ObjetCompose
}		

Ventilateur:: Ventilateur (const Vecteur& ori, const Vecteur& L, const Vecteur& l, double Hbrique, double prof, double vitesse)
:ObjetCompose()
{
Brique brique (ori, L, l, Hbrique);
Vent vent (ori, l, L, prof, vitesse);												//La hauteur du vent est la longueur de la brique
composants.push_back(std:: unique_ptr <Objet> (new Brique (brique)));				//On ajoute un pointeur une brique au tableau des composants d'ObjetCompose
composants.push_back(std:: unique_ptr <Objet> (new Vent (vent)));					//On ajoute un pointeur un vent au tableau des composants d'ObjetCompose
}


//----------MÉTHODES POLYMORPHIQUES-------------------------------------
std::ostream& Ventilateur:: affiche(std::ostream& sortie) const{					//affichage d'un ventilateur
std::cout << "un ventilateur : "<< std::endl;
ObjetCompose::affiche(sortie);														//résolution de portée de la méthode affiche d'ObjetCompose
return sortie;
}
