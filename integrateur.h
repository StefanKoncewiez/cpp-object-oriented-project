#pragma once
#include "ObjetsMobiles.h"
#include <iostream>

class Integrateur{
public :

//---------DESTRUCTEUR--------------------------------------------------
	virtual ~Integrateur();

//----------MÉTHODES_VIRTUELLES_PURES-----------------------------------
	virtual void integre(ObjetMobile& objet, double delta_T) = 0;						//fonction integre(), spécifique à chauqe intégrateur, qui va intégrer des ObjetMobile sur un pas de temps
	virtual Integrateur* copie() const = 0;												//copie d'un polymorphique d'intégrateur. Pour son utilité, voir la classe Systeme (meilleure cohérence entre utilisateur et programmeur) 
	
//----------MÉTHODES_POLYMORPHIQUES-------------------------------------
	virtual std::ostream& affiche(std::ostream& sortie) const;							//permet l'affichage polymorphique (en particulier pour surcharger l'opérateur << dans Integrateur 
};

std:: ostream& operator<< (std:: ostream& sortie, const Integrateur& inte);				//Surcharge de l'opérateur << de manière polymorphique

//======================================================================

class IntegrateurEuler : public Integrateur{
public:
//---------DESTRUCTEUR--------------------------------------------------
	virtual ~IntegrateurEuler();
	
//----------MÉTHODES_POLYMORPHIQUES-------------------------------------
	virtual std::ostream& affiche(std::ostream& sortie) const override;					//redéfinie, permet l'affichage polymorphique
	virtual void integre (ObjetMobile& objet, double delta_T) override;					//redefinie, intègre un ObjetMobile selon un pas de temps
	virtual Integrateur* copie() const override;

protected:
//----------MÉTHODES_PROPRES_INTEGRATEUR_EULER--------------------------------
	Vecteur integre_P_derivee(ObjetMobile& objet, double delta_T);						//méthode qui integre le vecteur de paramètres dérivés
	Vecteur integre_Param(ObjetMobile& objet, double delta_T);							//méthode qui integre le vecteur de paramètres
};

//======================================================================

///Le fait que IntegrateurEuleurCromer soit un IntegrateurEuleur permet d'éviter la duplication : les méthodes héritées sont utilisées pour intégrer l'ObjetMobile
class IntegrateurEulerCromer : public IntegrateurEuler{
public:
//----------MÉTHODES_POLYMORPHIQUES-------------------------------------
	virtual std::ostream& affiche(std::ostream& sortie) const override;					//redéfinie, permet l'affichage polymorphique
	virtual void integre (ObjetMobile& objet, double delta_T) override;					//redefinie, intègre un ObjetMobile selon un pas de temps
	virtual Integrateur* copie() const override;
};

//======================================================================

class IntegrateurNewark: public Integrateur{
public:
//----------MÉTHODES_POLYMORPHIQUES-------------------------------------
	virtual void integre (ObjetMobile& objet, double delta_T) override;					//redefinie, intègre un ObjetMobile selon un pas de temps
	virtual Integrateur* copie() const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;					//redéfinie, permet l'affichage polymorphique
};

//======================================================================

class IntegrateurRungeKutta: public Integrateur{
public:
//----------MÉTHODES_POLYMORPHIQUES-------------------------------------
	virtual void integre (ObjetMobile& objet, double delta_T) override;					//redefinie, intègre un ObjetMobile selon un pas de temps
	virtual Integrateur* copie() const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;					//redéfinie, permet l'affichage polymorphique
};













/*protected:
static double delta_T;
void integre_P_derivee(ObjetMobile& objet);
void integre_Param(ObjetMobile& objet);		// dans constantes.h ??

public:
virtual std::ostream& affiche(std::ostream& sortie) const;
void integre (ObjetMobile& objet);
};

//=====================================================================================================================================================================
class IntegrateurEulerCromer : public Integrateur{
public:
virtual std::ostream& affiche(std::ostream& sortie) const override;
void integre_EulerCromer(ObjetMobile& objet);
};
*/
