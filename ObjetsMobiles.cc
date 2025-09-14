#include "ObjetsMobiles.h"
#include "constantes.h"
#include <cmath>

using namespace std;

//---------CONSTRUCTEURS------------------------------------------------
	ObjetMobile:: ObjetMobile (double M, double MV, double R, const Vecteur& F, const Vecteur& P_, const Vecteur& P_prime)
	: masse_(M), m_v(MV) , rayon_(R),force_(F),  P(P_), P_derive(P_prime)
	{
if (M==0 and MV!=0) {masse_= masse();}
else if (M!=0 and MV==0) {m_v= masse_volumique();}
else if ((M!=0 and MV!=0) or (M==0 and MV==0)) {cout << "Définnissez soit une masse, soit une masse volumique à votre objet !"<< endl;}

}

ObjetMobile:: ObjetMobile (const ObjetMobile& autre)
: masse_(autre.masse_), rayon_(autre.rayon_), force_(autre.force_), P(autre.P), P_derive(autre.P_derive)
{}

//---------DÉSTRUCTEUR--------------------------------------------------
ObjetMobile:: ~ObjetMobile() = default;

//----------MÉTHODES_POLYMORPHIQUES-----------------------------------
Vecteur ObjetMobile:: calc_force() const {
	return getforce();}

void ObjetMobile:: agir_sur(ObjetMobile& objet) {											//effectue les chocs entre 2 ObjetMobile, modifie leur vitesse et leur forces
																							//Implémenté grâce aux complément mathématique
	Vecteur diff ( (*this).getPosition()-objet.getPosition() );
	Vecteur n (~diff);																		// vecteur unitaire normal au choc
	double m1(masse_);
	double m2(objet.masse_);
	double alpha (alpha_);//alpha (coefficient de restitution) modifiable dans constantes.h
	double lambda ((1+alpha)*m2/(m1+m2));
	double mu(mu_);//mu (coefficient de frottement entre corps) modifiable dans constantes.
	
	
	Vecteur deltaV(3);																		// vecteur nul à 3 dim
	
	if ( diff.norme() < rayon_+ objet.rayon_) { 
	double Fn1 ((*this).calc_force()*n);
	
	double Fn2 (objet.calc_force()*n);
		if (Fn1<0){
		force_ = force_ - n*Fn1;
																							//force_ = (*this).calc_force();
		objet.force_ = objet.force_ + n*Fn1;
																							//objet.force_ = objet.calc_force();
		}
		if (Fn2>0){
		force_ = force_ + n*Fn2;
																							//force_ = (*this).calc_force();
		objet.force_ = objet.force_ - n*Fn2;
																							//objet.force_ = objet.calc_force();
		}
	double V_ ((objet.getVitesse() - (*this).getVitesse())*n);
	Vecteur Vc ( (*this).getVitesse() - objet.getVitesse() + (n*V_) );
	
		if ( (7*mu*(1+alpha)*V_) >= Vc.norme()*2 ) {
		deltaV = n*(lambda*V_) - Vc*( 2*m2 / (7*(m1+m2)) ) ;
		} else {																			//sinon ( Vc forcément non nul)
		deltaV = (n - (~Vc)*mu)*lambda*V_ ;
		}
	force_ = (*this).calc_force();
	objet.force_ = objet.calc_force();
	(*this).setVitesse (getVitesse() + deltaV);
	//cout << "objet.getVitesse() - deltaV*(m1/m2)" << objet.getVitesse() - deltaV*(m1/m2);	//DEBUG
	objet.setVitesse (objet.getVitesse() - deltaV*(m1/m2));


	//DEBOGGING :
	cout << "n =" << n<<endl;
	cout << "lambda =" << lambda<< endl;
	cout << "F1n =" << Fn1<<endl;
	cout << "F2n =" << Fn2<< endl;
	cout << "vstar = " << V_<<endl;
	cout << "vc = " << Vc << endl;
	cout << "7*µ*(1+alpha)*vstar = " << 7*mu*(1+alpha)*V_<< endl;
	cout << "2*vc.norme()" << Vc.norme()*2 << endl;
	cout << "dv = " << deltaV;
	cout << endl<<endl;
	}
}

void ObjetMobile:: ajoute_a (Systeme & systeme) const{
	systeme.ajoute_objet(*this);
}

double ObjetMobile:: distance(const ObjetMobile& obj) const{	
	return ( (this->getPosition() - obj.getPosition()).norme() - (rayon_+obj.rayon_) );
}

ostream& ObjetMobile:: affiche(ostream& sortie) const{										//On définit une méthode affiche dans ObjetMobile car en général, pour eviter la copie de code
	sortie << masse_ << " # masse " << get_nom() << endl;
	sortie << rayon_ << " # rayon " << get_nom() << endl;									
	sortie << masse_volumique()<< " # masse volumique " << get_nom() << endl;
	sortie << getPosition() << " # position " << get_nom() << endl << getVitesse() << " # vitesse " << get_nom() << endl << getforce_totale() << " # force " << get_nom() << endl;
	return sortie;
}

//----------MÉTHODES_PROPRES_A_OBJETMOBILE------------------------------

//"getteurs"
Vecteur ObjetMobile:: getParam() const{
	if (P.getvecteur().empty()) {															//on teste si le vecteur de paramètres est vide, et si c'est le cas on envoie un message d'erreur
		cout << "Pas de vecteur de paramètres"<< endl;
		return Vecteur({0,0,0});}
	else return P;
}

Vecteur ObjetMobile:: getP_derive() const{
	if (P_derive.getvecteur().empty()) {													//on teste si le vecteur de paramètres dérivés est vide, et si c'est le cas on envoie un message d'erreur
		cout << "Pas de vecteur de paramètres dérivé"<< endl;
		return Vecteur({0,0,0});}
	else return P_derive;
}
double ObjetMobile:: getrayon() const {return rayon_;}
Vecteur ObjetMobile:: getforce() const {return force_;}
Vecteur ObjetMobile:: getforce_totale() const {return getforce();}
double ObjetMobile:: getmasse() const {return masse_;}


//"setteurs"
void ObjetMobile:: setParam(const Vecteur& p){
if (P.getvecteur().size() == p.getvecteur().size()) P=p;									//test pour interdire d'affecter un Vecteur à un autre de dimension différente
else {cout << "probleme de dimension pour P"<< endl;}
}
void ObjetMobile:: setP_derive(const Vecteur& p_prime){
if (P_derive.getvecteur().size() == p_prime.getvecteur().size()) P_derive=p_prime;			//test pour interdire d'affecter un Vecteur à un autre de dimension différente
else {cout << "probleme de dimension pour P_dérive" << endl;}
}
void ObjetMobile:: setrayon(double const& r){rayon_ = r;}
void ObjetMobile:: setforce(Vecteur const& f){force_ = f;}
void ObjetMobile::reset_force(){setforce(Vecteur( force_.getvecteur().size() ) );}


//autres
void ObjetMobile:: ajoute_force(Vecteur const& df){
	force_ = force_ + df;
}
double ObjetMobile:: masse_volumique() const{
	return 3*masse_ / (4 * M_PI * rayon_*rayon_*rayon_);
}

double ObjetMobile:: masse() const{
return m_v * 4/3 * M_PI * rayon_*rayon_*rayon_;
}
