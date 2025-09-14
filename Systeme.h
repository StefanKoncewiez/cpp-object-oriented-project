#pragma once
#include <iostream>
#include "Dessinable.h"
#include "SupportADessin.h"
#include <vector>
#include <memory>

class Integrateur;
class Obstacle;
class ChampForces;
class ObjetMobile;

class Systeme : public Dessinable {
public:
//---------CONSTRUCTEUR/DESTRUCTEUR-------------------------------------
	Systeme(Integrateur const&, double dt);
///Comme le temps d'intégration est affiché lors de l'affichage d'un systeme, on a décidé de le mettre comme attribut
///On a décidé de pouvoir l'initialiser avec un systeme plutôt que de l'avoir comme attribut static,
///afin de ne pas avoir à revenir dans la classe lors d'un changement de temps dans un test.
	~Systeme();

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
	virtual void dessine_sur(SupportADessin& support) override;
	
//----------MÉTHODES_PROPRES_A_SYSTEME----------------------------------
	void ajoute_objet( ObjetMobile const & objet);
	void ajoute_obstacle( Obstacle const & obstacle );
	void ajoute_champ( ChampForces const & champ_force );
	double getlongobj() const;
	ObjetMobile& operator[] (size_t i) const;
	std::ostream& affiche(std::ostream& sortie) const;
	void evolue();
private:
	std::vector<std::unique_ptr<ObjetMobile>> objets_;
	std::vector<std::unique_ptr<ChampForces>> champ_forces_;
	std::vector<std::unique_ptr<Obstacle>> obstacles_;
	Integrateur* integrateur_ = nullptr;
	const double dt_;
	
//Afin d'éviter les copies, non sens car Systeme composé de tableaux de unique_ptr (Voir remarque TextViwer + [Question P8.3]) :
	Systeme(Systeme const&) = delete;
	Systeme& operator=(Systeme const&) = delete;
};
std::ostream& operator<<(std::ostream& sortie, Systeme const & syst);
