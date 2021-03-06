#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class Lexer {

   public:
      //Lexer() = default;
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() { }

      Symbole * Consulter();
      void Avancer();
      void pushSymbol(Symbole * s);

   protected:
      string flux;
      int tete;
      Symbole * tampon;
};
