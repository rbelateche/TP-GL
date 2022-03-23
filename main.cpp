#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {
   string chaine("(1+2*3)*4+1");
   cout << chaine << endl;
   auto *automate = new Automate(chaine);
   cout << "automate cree" << endl;
   automate->run();
   delete(automate);
   return 0;
   
}

