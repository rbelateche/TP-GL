#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {
   string chaine("1+34*123");
   cout << chaine << endl;
   auto *automate = new Automate(chaine);
   automate->run();
   delete(automate);
   return 0;
   
}

