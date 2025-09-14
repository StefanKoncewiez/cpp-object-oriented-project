#pragma once
#include <iostream>
#include <initializer_list>
#include <vector>


class Vecteur{
public:

Vecteur (size_t dimension);
Vecteur (double x, double y, double z);
Vecteur (const std::initializer_list <double> & autre);
Vecteur (const std::vector<double> & autre);
Vecteur (const Vecteur & autre);

void augmente(double ajoute_vecteur);
void set_coord(size_t position, double valeur);
Vecteur operator^(const Vecteur & autre) const;
bool operator==(const Vecteur & autre) const;
bool operator!=(const Vecteur & autre) const;

Vecteur operator- () const;
Vecteur operator+(const Vecteur & autre) const;
Vecteur operator-(const Vecteur & autre) const;
Vecteur operator*(const double & nb) const; 							//mulitication par un scalaire
double operator*(const Vecteur & autre) const;							//mulitication par un Vecteur --> On ne risque donc pas d'ambiguité en ces 2 méthodes 
Vecteur operator~() const;

double norme() const;
double norme2() const;
std::ostream& affiche(std::ostream& sortie) const;
std::vector <double> getvecteur() const {return vecteur_;}

private:
std::vector <double> vecteur_;
//Méthode privée de la class Vecteur :
//Ces méthodes sont uniquement utilisée afin de définir les opérateurs arithmétique de base et n'ont donc aucune raison d'etre utilisé par l'extérieur
Vecteur& operator+=(const Vecteur & autre);
Vecteur& operator -= (const Vecteur & autre);
Vecteur& operator *= (const double & nb);
double operator*=(const Vecteur & autre);

void erreur(Vecteur const&) const;										//Methode qui affiche une erreur sous forme textuelle (pas utilisable depuis l'extérieur)
};

Vecteur operator*(double nb, const Vecteur & vect);

std::ostream& operator<<(std::ostream& sortie, Vecteur const & vec);
