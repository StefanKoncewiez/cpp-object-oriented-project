#pragma once
#include "Vecteur.h"
#include "Objet.h"
#include "ChampForce.h"
#include <iostream>
#include <string>
#include "Systeme.h"


class ObjetMobile : public ObjetSimple {
public:
//---------CONSTRUCTEURS------------------------------------------------
	ObjetMobile (double M, double MV, double R, const Vecteur& F, const Vecteur& P_, const Vecteur& P_prime);
	ObjetMobile (const ObjetMobile& autre);

//---------DÉSTRUCTEUR--------------------------------------------------
	virtual ~ObjetMobile ();

//----------MÉTHODES_VIRTUELLES_PURES-----------------------------------
	virtual Vecteur evolution(Vecteur Dt1 = Vecteur({0.0}), Vecteur Dt2 = Vecteur({0.0})) const = 0;			//définit comment chaque objet mobile va évoluer de manière spécifique
	virtual std::unique_ptr<ObjetMobile> copie() const = 0;														//permet la copie polymorphique des sous-classes d'ObjetMobile, retournant un pointeur sur ObjetMobile.
	virtual Vecteur getPosition() const = 0;																	//retourne la position, specifiquement à chque objet mobile
	virtual Vecteur getVitesse() const = 0;																		//retourne la vitesse, specifiquement à chque objet mobile
	virtual std:: string get_nom() const = 0;																	//retourne le nom de l'objet, specifiquement à chaque objet mobile
	virtual void setVitesse(Vecteur const& vect) = 0;															//permet d'affecter une vitesse à uj objet mobile, de manière spécifique
	virtual void applique_champ(ChampForces &) = 0;																//permet d'appliquer ou non la force d'Archimède selon le type d'objet mobile utilisé
	
//----------MÉTHODES_PLYMORPHIQUES--------------------------------------
	virtual Vecteur calc_force() const;
	virtual void agir_sur (ObjetMobile& objet) override;														//permet aux ObjetMobile d'agir les uns sur les autres (chocs)
	virtual double distance(const ObjetMobile&) const override;													//retourne la distance entre 2 ObjetMobile
	virtual std::ostream& affiche(std::ostream& sortie) const override;											//méthode d'affihcage polymorphique qui sert à surcharger l'opérateur << de manière polymorphique dans Objet
	virtual Vecteur getforce() const;
	virtual Vecteur getforce_totale() const;																	//retourne la force totale : pour les pendule et retourne y compris la froce centripète
	virtual void ajoute_a (Systeme & systeme) const override;													//ajoute un objet mobile au systeme, utilisées notamment par ObjetCompose pour ajouter ses composantes au bon tableau dans systeme
//----------MÉTHODES_PROPRES_A_OBJETMOBILE------------------------------
	//"getteurs"
	Vecteur getParam() const;																
	Vecteur getP_derive() const;
	double getrayon() const;
	double getmasse() const;
	//"setteurs"													
	void setParam(const Vecteur& p);
	void setP_derive(const Vecteur& p_prime);
	void reset_force();
	void setrayon(double const& r);
	void setforce(Vecteur const& f);
	//autres
	double masse_volumique() const;																				//retoune la masse volumique à partir de la masse et du rayon
	double masse() const;																						//retoune la masse à partir de la masse volumique et du rayon
	void ajoute_force(Vecteur const& df);																		//ajoute un force au Vecteur "force_" en attribut


	protected:
	double masse_;
	double m_v;
	double rayon_;
	Vecteur force_;
	Vecteur P;
	Vecteur P_derive;
};
