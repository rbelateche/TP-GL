#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR , EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" , "EXPR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      bool isTerminal();
      virtual void Affiche();
      

   protected:
      int ident;
};


class OpenPar : public Symbole {
   public : 
      OpenPar() : Symbole(OPENPAR) {};
      ~OpenPar() {}
      virtual void Affiche();
};

class ClosePar : public Symbole {
   public : 
      ClosePar() : Symbole(CLOSEPAR) {};
      ~ClosePar() {}
      virtual void Affiche();
};

class Expr : public Symbole { // only one expression with one value 
   public:
      Expr(int v) : Symbole(EXPR), valeur(v) {}
      ~Expr();
      virtual void Affiche();
      int getValeur();

   protected: 
      int valeur;
};

class Plus : public Expr {
   public: 
      Plus(Expr * expr1, Expr * expr2) : Expr(expr1->getValeur() + expr2->getValeur()) {}
      ~Plus();
      virtual void Affiche();
};

class Mult : public Expr {
   public: 
      Mult(Expr * expr1, Expr * expr2) : Expr(expr1->getValeur() * expr2->getValeur()) {}
      ~Mult();
      virtual void Affiche();
};


class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur();
   protected:
      int valeur;
};


class Fin : public Symbole {
   public: 
      Fin() : Symbole(FIN) {}
      ~Fin();
      virtual void Affiche();
};

class Erreur : public Symbole {
   public: 
      Erreur() : Symbole(ERREUR) {}
      ~Erreur();
      virtual void Affiche();
};




