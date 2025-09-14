CXX = g++
CC = $(CXX)


CXXFLAGS += -pedantic -Wall -std=c++11
# pour les purs et durs
# CXXFLAGS += -g                    # pour debugger
# CXXFLAGS += -O2                   # pour optimiser la vitesse

all: testBalle testVecteur testRessort ExerciceP11 testObstacles testVentilateur testPendule testChocs testVent testIntegrateur1 testIntegrateur2 ExerciceP12 testChocs_systeme Systeme testRessort


Vecteur.o: Vecteur.cc Vecteur.h
testVecteur.o: testVecteur.cc Vecteur.h
Balle.o: Balle.cc constantes.h Balle.h Vecteur.h ObjetsMobiles.h SupportADessin.h ChampForce.h
ChampForce.o: ChampForce.cc constantes.h ChampForce.h SupportADessin.h  Vecteur.h ObjetsMobiles.h Objet.h Systeme.h
constantes.o: constantes.cc constantes.h Vecteur.h
ObjetsMobiles.o: ObjetsMobiles.cc ObjetsMobiles.h Vecteur.h Objet.h Systeme.h ChampForce.h constantes.h
Pendule.o: Pendule.cc constantes.h Pendule.h Vecteur.h ObjetsMobiles.h SupportADessin.h ChampForce.h
obstacles.o: obstacles.cc obstacles.h Vecteur.h ObjetsMobiles.h Objet.h Systeme.h constantes.h
Plan.o: Plan.cc Plan.h obstacles.h Vecteur.h ObjetsMobiles.h SupportADessin.h
PortionPlan.o: PortionPlan.cc PortionPlan.h Vecteur.h obstacles.h Plan.h ObjetsMobiles.h SupportADessin.h
Brique.o: Brique.cc PortionPlan.h Brique.h obstacles.h Vecteur.h ObjetsMobiles.h SupportADessin.h
integrateur.o: integrateur.cc constantes.h Vecteur.h integrateur.h ObjetsMobiles.h
Objet.o : Objet.cc Objet.h Dessinable.h
TextViewer.o: TextViewer.cc TextViewer.h SupportADessin.h ChampForce.h Plan.h PortionPlan.h Balle.h Pendule.h Brique.h Systeme.h Ressort.h Vent.h
Dessinable.o: Dessinable.cc Dessinable.h
Systeme.o: Systeme.cc Dessinable.h SupportADessin.h Systeme.h ObjetsMobiles.h ChampForce.h obstacles.h integrateur.h
SupportADessin.o: SupportADessin.cc SupportADessin.h
Vent.o: Vent.cc Vent.h ChampForce.h ObjetsMobiles.h Vecteur.h SupportADessin.h PortionPlan.h
Ventilateur.o: Ventilateur.cc Vent.h Ventilateur.h Objet.h Brique.h Vecteur.h
Ressort.o : Ressort.cc Ressort.h Vecteur.h ChampForce.h ObjetsMobiles.h SupportADessin.h

testPendule.o: testPendule.cc ChampForce.h Pendule.h constantes.h Objet.h integrateur.h
testBalle.o: testBalle.cc Balle.h ChampForce.h constantes.h Objet.h
testObstacles.o: testObstacles.cc Brique.h Plan.h Balle.h Objet.h PortionPlan.h Systeme.h
ExerciceP9a.o : ExerciceP9a.cc Systeme.h Balle.h TextViewer.h constantes.h integrateur.h Objet.h ChampForce.h ObjetsMobiles.h
testIntegrateur1.o: testIntegrateur1.cc ChampForce.h Balle.h constantes.h Objet.h integrateur.h ObjetsMobiles.h 
testIntegrateur2.o: testIntegrateur2.cc ChampForce.h Balle.h constantes.h Objet.h integrateur.h
testChocs.o :testChocs.cc Balle.h Plan.h ChampForce.h constantes.h Objet.h Pendule.h
testVentilateur.o : testVentilateur.cc Ventilateur.h TextViewer.h Brique.h Balle.h ChampForce.h constantes.h integrateur.h Objet.h
testVent.o : testVent.cc Vent.h Balle.h ChampForce.h constantes.h integrateur.h Objet.h 
ExerciceP12.o : ExerciceP12.cc ChampForce.h Balle.h constantes.h Objet.h integrateur.h ObjetsMobiles.h Pendule.h Systeme.h TextViewer.h
testChocs_systeme.o: testChocs_systeme.cc Systeme.h Balle.h TextViewer.h Pendule.h constantes.h integrateur.h Plan.h ChampForce.h
ExerciceP11.o: ExerciceP11.cc Systeme.h Balle.h Objet.h TextViewer.h constantes.h integrateur.h Ventilateur.h Brique.h
testRessort.o : testRessort.cc Ressort.h constantes.h integrateur.h ChampForce.h Objet.h

Systeme : ExerciceP9a.o Systeme.o Balle.o TextViewer.o constantes.o integrateur.o Vecteur.o ObjetsMobiles.o ChampForce.o TextViewer.o SupportADessin.o obstacles.o Objet.o Dessinable.o 
ExerciceP11 : ExerciceP11.o SupportADessin.o Vecteur.o Systeme.o Balle.o Objet.o TextViewer.o constantes.o integrateur.o Ventilateur.o Brique.o Dessinable.o ChampForce.o TextViewer.o ObjetsMobiles.o obstacles.o Vent.o PortionPlan.o Plan.o
testVecteur : testVecteur.o Vecteur.o constantes.o
testBalle : testBalle.o Balle.o Vecteur.o constantes.o ChampForce.o ObjetsMobiles.o Objet.o Dessinable.o Systeme.o
testPendule : testPendule.o Vecteur.o ObjetsMobiles.o ChampForce.o Pendule.o constantes.o Objet.o integrateur.o Dessinable.o Systeme.o
testObstacles : testObstacles.o Brique.o Plan.o Balle.o Objet.o ObjetsMobiles.o Vecteur.o PortionPlan.o obstacles.o Systeme.o Dessinable.o constantes.o ChampForce.o
testIntegrateur1 : testIntegrateur1.o ChampForce.o Balle.o constantes.o Objet.o integrateur.o ObjetsMobiles.o Vecteur.o Dessinable.o Systeme.o
testIntegrateur2 : testIntegrateur2.o ChampForce.o Balle.o constantes.o Objet.o integrateur.o Vecteur.o ObjetsMobiles.o Dessinable.o Systeme.o
testChocs : testChocs.o Balle.o Plan.o ChampForce.o constantes.o Objet.o ObjetsMobiles.o Vecteur.o obstacles.o Pendule.o Dessinable.o Systeme.o
testVentilateur : testVentilateur.o TextViewer.o SupportADessin.o Vent.o Ventilateur.o Brique.o Balle.o Dessinable.o ChampForce.o constantes.o integrateur.o Objet.o Vecteur.o obstacles.o ObjetsMobiles.o Plan.o PortionPlan.o Systeme.o
testVent: testVent.o Vent.o Balle.o PortionPlan.o Plan.o obstacles.o ChampForce.o constantes.o integrateur.o Objet.o Dessinable.o Vecteur.o ObjetsMobiles.o Systeme.o
ExerciceP12 : ExerciceP12.o ChampForce.o Balle.o constantes.o Objet.o integrateur.o ObjetsMobiles.o Vecteur.o Pendule.o Systeme.o TextViewer.o obstacles.o Plan.o Dessinable.o ChampForce.o Plan.o SupportADessin.o
testChocs_systeme : testChocs_systeme.o Systeme.o Balle.o TextViewer.o Pendule.o constantes.o integrateur.o Vecteur.o ObjetsMobiles.o obstacles.o Dessinable.o Objet.o ChampForce.o Plan.o SupportADessin.o
testRessort : testRessort.o Ressort.o constantes.o integrateur.o ChampForce.o Objet.o Vecteur.o integrateur.o ObjetsMobiles.o Dessinable.o Systeme.o
