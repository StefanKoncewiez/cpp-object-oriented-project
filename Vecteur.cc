#include <iostream>
#include <vector>
#include <initializer_list>
#include <cmath>
#include "Vecteur.h"
#include "constantes.h"

using namespace std;


Vecteur:: Vecteur (size_t dimension)
	: vecteur_(dimension, 0.0)
{}
Vecteur:: Vecteur (double x, double y, double z)
	: vecteur_({x,y,z})
{}
Vecteur:: Vecteur (const initializer_list<double> & autre)
	:vecteur_({autre})
{}
Vecteur:: Vecteur (const Vecteur & autre)
	:vecteur_(autre.vecteur_)
{}

Vecteur:: Vecteur (const vector<double> & autre)
	:vecteur_(autre)
{}



void Vecteur:: augmente(double ajoute_vecteur){
	vecteur_.push_back(ajoute_vecteur);
}
void Vecteur:: set_coord(size_t position, double valeur){
	vecteur_[position] = valeur;
}
Vecteur Vecteur:: operator^(const Vecteur & autre) const{
	if ( vecteur_.size() != 3 or autre.vecteur_.size() != 3 ){
		erreur(autre);
		return 0;
	}else{
		Vecteur retour(vecteur_);
		double x,y,z;
		x = retour.vecteur_[1] * autre.vecteur_[2] - retour.vecteur_[2] * autre.vecteur_[1];
		y = retour.vecteur_[2] * autre.vecteur_[0] - retour.vecteur_[0] * autre.vecteur_[2];
		z = retour.vecteur_[0] * autre.vecteur_[1] - retour.vecteur_[1] * autre.vecteur_[0];
		retour.set_coord(0,x);
		retour.set_coord(1,y);
		retour.set_coord(2,z);
		return retour;
	}
		
}
bool Vecteur:: operator==(const Vecteur & autre) const{
	if ( vecteur_.size() != autre.vecteur_.size() ){
		return false;
	}else{
		for (size_t i(0); i< vecteur_.size(); ++i ){
			if ( vecteur_[i] - autre.vecteur_[i] > epsilon ){
				return false;
			}
		}return true;													//On retourne vrai car on a pu sortir de la boucle sans s'être arrêté
	}
}

bool Vecteur:: operator!=(const Vecteur & autre) const{
return (not	((*this) == autre) );										//Utilisation d'un operateur déjà disponible
}


Vecteur& Vecteur:: operator+=(const Vecteur & autre){
	for (size_t i(0); i< vecteur_.size(); ++i ){
		vecteur_[i] += autre.vecteur_[i];
	}
	return *this;
}

Vecteur Vecteur:: operator- () const{
	return Vecteur(vecteur_.size()) - Vecteur (*this);
}

Vecteur& Vecteur:: operator -= (const Vecteur & autre){
	for (size_t i(0); i< vecteur_.size(); ++i ){
		vecteur_[i] -= autre.vecteur_[i];
	}
	return *this;
}
Vecteur& Vecteur:: operator *= (const double & nb){
	for (auto& element : vecteur_){
		element *= nb;
	}
	return *this;
}
double Vecteur:: operator*=(const Vecteur & autre){
	double retour(0);
	for (size_t i(0); i< vecteur_.size(); ++i ){
		retour += vecteur_[i] * autre.vecteur_[i];
	}
	return retour;
}


Vecteur Vecteur:: operator+ (const Vecteur & autre) const{
if ( vecteur_.size() == autre.getvecteur().size()) {
		return (Vecteur(*this) += autre);
	}else {
		erreur(autre);													//Message d'erreur sur le terminal. Pas d'opération effectuée ()
		return Vecteur(autre.getvecteur().size());
	}///On aurait également pu retourner un vecteur arbitraire ou transformer les deux vecteurs en vecteurs de meme taille.
}	 ///Mais cela n'a pas de sens d'un point de vu physique : cela conduirait par exemple à ajouter une force arbitraire à la gravité

Vecteur Vecteur:: operator-(const Vecteur & autre) const{
	
	if ( vecteur_.size() == autre.getvecteur().size()) {
		return Vecteur(*this) -= autre;
	}else {
		erreur(autre);
		return Vecteur(autre.getvecteur().size());
	}
}
	

Vecteur Vecteur:: operator*(const double & nb) const{
	return Vecteur(*this) *= nb;
}

double Vecteur:: operator*(const Vecteur & autre) const{
	if ( vecteur_.size() == autre.getvecteur().size()) {
	return Vecteur(*this) *= autre;
	}else {
		erreur(autre);
		return 0;
	}
}

Vecteur Vecteur:: operator~ () const{
	const double n( (*this).norme() );
	if (abs(n)>epsilon){
		return Vecteur(*this) *= (1/n);
		}else{
			cerr << "Problème, division par zéro car norme nulle";
			return Vecteur(vecteur_.size());
		}
}

void Vecteur:: erreur(Vecteur const& autre) const {
	cerr << "Problème, les vecteurs sont de taille différentes, respectivement :"<<endl;
	cerr << vecteur_.size() << " et " << autre.getvecteur().size() << endl; 
	}


double Vecteur:: norme() const{
	return sqrt(norme2());												//Utilisation d'une méthode déjà à disposition 
}
double Vecteur:: norme2() const{/// L'opérateur* prend une vecteur en paramètre fait la somme de la multiplication des composantes entre elles
	return (*this * *this);
}
ostream& Vecteur:: affiche(ostream& sortie) const{
	for (auto valeur : vecteur_ ){
		sortie << valeur << " ";
	}return sortie;
}

///L'operateur d'affichage externe appelle une methode interne (voir question [Question P4.3])
std::ostream& operator<<(std::ostream& sortie, Vecteur const & vec){return vec.affiche(sortie);}

Vecteur operator*(double nb, const Vecteur & vect){
return vect*nb;
}

