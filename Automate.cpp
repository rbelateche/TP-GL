#include "Automate.h"
#include <iostream>
#include <stack>


Automate::Automate(string chaine){
    lexer = new Lexer(chaine);
    stateStack.push(*(new State0));
}

void Automate::decalage(Symbole * s, State * state){
    stateStack.push(*state);
    symboleStack.push(s);

}


void Automate::reduction(int n, Symbole * s){

}



