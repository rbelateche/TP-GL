#include "symbole.h"
#include <iostream>


bool Symbole::isTerminal(){
   return (this->ident != EXPR);
}

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Expr::getValeur(){
   return this->valeur;
}

int Entier::getValeur(){
   return this->valeur;
}



