#include "Systeme.h"
#include "ObjetsMobiles.h"
#include "ChampForce.h"
#include "obstacles.h"
#include "integrateur.h"

using namespace std;

//---------CONSTRUCTEUR/DESTRUCTEUR-------------------------------------
Systeme:: Systeme(Integrateur const & integr, double dt)
	:integrateur_(integr.copie()), dt_(dt)
{}

Systeme:: ~Systeme (){																//afin de désallouer la memoire de l'intégrateur
delete integrateur_;
}

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
void Systeme:: dessine_sur(SupportADessin& support){ 
		support.dessine(*this);														//En effet, toute classe Dessinable doit redéfinir cette méthode à l'identique
	}


//----------MÉTHODES_PROPRES_A_SYSTEME----------------------------------

ostream& Systeme:: affiche(ostream& out) const{										//Pour afficher un système, on affiche chacun des Objet le composant
	out << "Le système est constitué de :" << endl<<endl;
	if (not objets_.empty()){out << "objets mobiles :"<<endl<<endl;}
	for (auto const& objet : objets_) { 
		objet->affiche(out)<<endl;
	} 
	if (not obstacles_.empty()){out << "obstacles :"<<endl;}
	for (auto const& obstacle :  obstacles_) { 
		obstacle->affiche(out)<<endl; 
	}
	if (not champ_forces_.empty()){out << "champs de force :"<<endl;
	}
	for (auto const& champ_forces :  champ_forces_) { 
		champ_forces->affiche(out)<<endl; 
	}
	integrateur_->affiche(out);														//L'attribut dt est un attribut static de la classe Systeme
	out << "dt = " << dt_ << endl;
	return out;	
}


void Systeme:: evolue(){
	for (auto const& objet : objets_){
		objet->reset_force();														//Cette methode permet de mettre à jour les forces afin d'éviter un comportement infini :
		for (auto const & champ_force : champ_forces_){								//ex : une balle qui rebondirait sur un sol et ne retomberait pas sous l'effet de la gravité
			champ_force->agir_sur(*objet);
		}
		for (auto const& obstacle: obstacles_){
			//cout << "distance = "<<obstacle->distance(*objet);
			//cout << "force =" << objet->getforce();
			obstacle->agir_sur(*objet);
			//cout << "force =" << objet->getforce();
		}
	
	}
	size_t taille (getlongobj());
	if (taille >1){
		for (size_t j(0); j< taille; j+= 2){
			objets_[j]->agir_sur(*objets_[j+1]);
		}
	}

	for (auto const& objet : objets_){
		//cout << "vitesse avant =" << objet->getVitesse();
		integrateur_->integre(*objet, dt_);
		//cout << "vitesse apres =" << objet->getVitesse();
		//cout << "evolution =" << objet->evolution();
		//cout << "force =" << objet->getforce();
	}
}

ObjetMobile& Systeme:: operator[] (size_t i) const{									//Cette méthode est utilisée dans le TextViewer (voir remarque)
	return *(objets_[i]);															//surcharge de l'opérateur[] qui retourne le i eme pointeur du tableau d'objets mobiles
}

double Systeme:: getlongobj() const{return objets_.size();}

void Systeme:: ajoute_objet( ObjetMobile const & objet) {							//La méthode copie() permet d'ajouter un objet à un systeme et non pas une référence vers un objet.
		objets_.push_back( objet.copie() );											//Cela permet une meilleure cohérence en programmeur concepteur et utilisateur (car on passe l'objet en paramètre et pas directemet le pointeur)
	}
	
void Systeme:: ajoute_obstacle( Obstacle const & obstacle ) {						//mêmes commentaires que ci dessus
		obstacles_.push_back( obstacle.copie() );
	}
void Systeme:: ajoute_champ( ChampForces const & champ_force ) {					//mêmes commentaires que ci dessus
		champ_forces_.push_back( champ_force.copie() );
	}


std::ostream& operator<<(std::ostream& sortie, Systeme const & syst){				//Cette méthode affiche le systeme de façon complète (contrairement au TextViwer)
	return syst.affiche(sortie);
}
