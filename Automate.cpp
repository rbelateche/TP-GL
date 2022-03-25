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

int Automate::run(){
    bool state = true;
    while(state){
        Symbole *s = lexer->Consulter();
        lexer->Avancer();  
        state = stateStack.back()->transition(*this,s);
    }
    // on teste si on retrouve une erreur dans la syntaxe 
    if (*symboleStack.back() == ERREUR){
        cout << "Erreur dans la syntaxe de l'expression" << endl;
        return (-1);
    } else {
        int resultat = ((Expr*) symboleStack.back())->getValeur();
        cout << " = " << resultat << endl;
        return resultat;
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


// pops the symbol from the symbol stack, as an EXPR, and returns it 
Expr *Automate::popSymbol(){
    Expr * eval = (Expr *) (symboleStack.back());
    symboleStack.pop_back();
    return eval;
}

// pushes 
void Automate::pushSymbol(Symbole * s){
    lexer->pushSymbol(s);
}

void Automate::popAndDestroySymbol(){
    delete(symboleStack.back());
    symboleStack.pop_back();
}


