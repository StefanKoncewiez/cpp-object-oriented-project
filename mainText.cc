#include <iostream>
#include "TextViewer.h"

using namespace std;

int main()
{
  /* Nous voulons un support à dessin :                          *
   * ici un TextViewer qui écrit sur cout                        */
  TextViewer ecran(cout);
  
  // Nous voulons un contenu à dessiner


  // Nous dessinons notre contenu  sur notre support à dessin précédent
  c.dessine_sur(ecran);

  return 0;
}
