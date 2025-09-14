#include "Plan.h"

using namespace std;

//---------CONSTRUCTEUR/DESTRUCTEURS------------------------------------
Plan:: Plan(const Vecteur& origine, const Vecteur& norm)
: Obstacle(origine),normal(norm)
{}

Plan:: ~Plan() = default;


//----------MÉTHODES POLYMORPHIQUES-------------------------------------
Vecteur Plan:: point_plus_proche (const ObjetMobile& objet) const {				//Retourne le point le plus proche du plan, implémenté grâce aux compléments mathématiques
	Vecteur x1 (objet.getPosition());
	return Vecteur (x1 + ((position - x1)* normal)*normal);
	}

ostream& Plan:: affiche(ostream& sortie) const{
sortie << "plan : "<< endl;
Obstacle:: affiche(sortie);
sortie << normal << "#normale plan" <<endl;
return sortie;}

void Plan:: dessine_sur(SupportADessin& support){
	support.dessine(*this); }

std::unique_ptr<Obstacle> Plan:: copie() const{
	return std::unique_ptr<Obstacle>(new Plan(*this)); 
}

