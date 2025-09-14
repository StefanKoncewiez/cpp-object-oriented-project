#include "PortionPlan.h"
#include "Brique.h"

using namespace std;

//---------CONSTRUCTEUR(S)------------------------------------------------
Brique:: Brique (const Vecteur& origine, const Vecteur& L, const Vecteur& l, double H)
: Obstacle(origine), longueur(L), largeur(l), hauteur(H), normal(calcnormal())
{	largeur = calclargeur();																//on affecte à la largeur sa composante orthogonal à la longueur
	normal = calcnormal();}																	//on affecte à la normale le vecteur unitaire orthogonal à la longueur et la largeur 

//----------MÉTHODES POLYMORPHIQUES-------------------------------------
ostream& Brique:: affiche(ostream& sortie)const {
	sortie << "Une brique : "<< endl;
	Obstacle:: affiche(sortie);
	sortie << longueur << " #longueur brique" << endl;
	sortie << largeur << " #largeur brique" << endl;
	sortie << hauteur << " #hauteur brique" << endl;
	return sortie;
	}

unique_ptr<Obstacle> Brique:: copie() const{
	return unique_ptr<Obstacle>(new Brique(*this));											//Retourne un unique_ptr sur un Objstacle, initialisé à l'instance courante de Brique
}

Vecteur Brique:: point_plus_proche(const ObjetMobile& objet) const{
	
Vecteur O (position);
Vecteur el(~largeur);
Vecteur eL(~longueur);
double h(hauteur);
double L(longueur.norme());
double l(largeur.norme());
Vecteur n (normal);

//construction des faces de la brique
Portionplan face1 (O, n, L, l, eL);
Portionplan face2 (O, -el, h, L, -n);
Portionplan face3 (O, -eL, l, h, el);
Portionplan face4 (O + eL*L, eL, h, l, -n);
Portionplan face5 (O + el*l, el, L, h, eL);
Portionplan face6 (O - n*h, -n, l, L, el);

vector <Portionplan> brique ({face1, face2, face3, face4, face5, face6});						//on construit une brique qui est un tableau constitué de 6 PortionPlan déclarées ci-dessus
	double plus_petite_distance(face1.distance(objet));
	int numeroface(0);
	
	for (size_t i(0); i<brique.size(); ++i) {	
	if (brique[i].distance(objet) < plus_petite_distance) {
	plus_petite_distance = brique[i].distance(objet);
	numeroface = i;
		}
	}
	//cout << "face " <<numeroface <<"la plus proche"<<endl;;									//DEBUG affichant le numero de face la plus proche
	return Vecteur(brique[numeroface].point_plus_proche(objet));								//on retourne le point de cette face (la plus proche) qui est le plus proche de l'objet

}

void Brique:: dessine_sur(SupportADessin& support){
	support.dessine(*this); }


//----------MÉTHODES PROPRES_À_LA_BRIQUE--------------------------------
Vecteur Brique:: calclargeur(){
	if (largeur*longueur != 0) {																//si longueur et largeur ne sont pas orthogonales, on prend la composante orthogonal au vecteur longueur
	largeur = largeur - (~longueur)*(largeur*(~longueur));
	}
return largeur;
}

Vecteur Brique:: calcnormal(){																	//retourne à la normale le vecteur unitaire orthogonal à la longueur et la largeur
return ~(longueur^largeur);
}



Vecteur Brique:: getvectlong(){return longueur;}
Vecteur Brique:: getvectlarg(){return largeur;}




