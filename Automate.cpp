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
        cout << "symbole lu";
        s->Affiche();
        cout << endl;
        state = stateStack.back()->transition(*this,s);
    }
    int resultat = ((Expr*) symboleStack.back())->getValeur();
    cout << endl;
    cout << " = " << resultat << endl;
}

void Automate::decalage(Symbole * s, State * state){
    stateStack.push_back(state);
    symboleStack.push_back(s);
    // if its a terminal symbol, then move forward
    if (s->isTerminal()){
        cout << "terminal ";
        s->Affiche();
        cout << endl;
        lexer->Avancer();
    } else {
        cout << "non terminal";
        cout << endl;
    }
}


void Automate::reduction(int n, Symbole * s){

    for (int i=0; i<n; i++){
        delete(stateStack.back());
        stateStack.pop_back();
    }
    stateStack.back()->transition(*this, s);
}



Expr *Automate::popSymbol(){
    Expr * eval = (Expr *) (symboleStack.back());
    cout <<"symbole stack : " << endl;
    symboleStack.back()->Affiche();
    cout << endl;
    cout << " value from popSymbol : ";
    eval->Affiche();
    cout << endl;
    cout << "taille de symbole stack : " << symboleStack.size() << endl;
    symboleStack.pop_back();
    cout << "end popSymbol " << endl;
    return eval;
}

void Automate::pushSymbol(Symbole * s){
    //symboleStack.push_back(s);
    lexer->pushSymbol(s);
}

void Automate::popAndDestroySymbol(){
    delete(symboleStack.back());
    symboleStack.pop_back();
}


