#include "Automate.h"
#include "State.h"
#include <iostream>
#include <stack>


Automate::Automate(string chaine){
    lexer = new Lexer(chaine);
    stateStack.push_back(new State0);
}


Automate::~Automate(){
    delete(lexer);
    while(!stateStack.empty()){
        delete(stateStack.back());
        stateStack.pop_back();
    }
    while(!symboleStack.empty()){
        delete(symboleStack.back());
        symboleStack.pop_back();
    }
}

void Automate::run(){
    bool state = true;
    while(state){
        Symbole *s = lexer->Consulter();
        lexer->Avancer();
        stateStack.back()->transition(*this,s);
    }
}

void Automate::decalage(Symbole * s, State * state){
    stateStack.push_back(state);
    symboleStack.push_back(s);
    // if its a terminal symbol, then move forward
    if (s->isTerminal()){
        lexer->Avancer();
    }
}


void Automate::reduction(int n, Symbole * s){
    for (int i=0; i<n; i++){
        delete(stateStack.back());
        stateStack.pop_back();
    }
    stateStack.back()->transition(*this, s);
}



Expr* Automate::popSymbol(){
    Expr* eval = dynamic_cast<Expr *>(symboleStack.back());
    symboleStack.pop_back();
    return eval;
}

void Automate::pushSymbol(Symbole * s){
    symboleStack.push_back(s);
}

void Automate::popAndDestroySymbol(){
    delete(symboleStack.back());
    symboleStack.pop_back();
}


