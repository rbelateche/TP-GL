#include "state.h"
#include "Automate.h"
#include <iostream>

State::State(const string &name) {
    this->name = name;
}

State::~State() {}

void State::showTransition(){
    cout << "current state : " << this->name << endl;
}


State0::State0() : State("E0") {};


bool State0::transition(Automate & automate, Symbole * s){
    
    switch(*s)
    {
        case INT:
            automate.decalage(s, new State3);
            break;
        case OPENPAR:
            automate.decalage(s, new State2);
            break;
        case EXPR:
            automate.decalage(s, new State1);
            break;

        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false;  
    }
    return true;
}


State1::State1() : State("E1") {};

bool State1::transition(Automate & automate, Symbole * s){

    switch(*s)
    {
        case PLUS:
            automate.decalage(s, new State4);
            break;
        case MULT:
            automate.decalage(s, new State5);
            break;
        case FIN: // case of $
            delete(s);
            return false; // false for sure ?
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}

State2::State2() : State("E2") {};


bool State2::transition(Automate & automate, Symbole * s){
    switch(*s)
    {
        case INT:
            automate.decalage(s, new State3);
            break;
        case OPENPAR:
            automate.decalage(s, new State2);
            break;
        case EXPR: // case of $
            automate.decalage(s, new State6);
            break;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}


State3::State3() : State("E3") {};

bool State3::transition(Automate & automate, Symbole * s){
    switch(*s)
    {
        case PLUS:
            automate.reduction(1, new Plus);
            break;
        case MULT:
            automate.reduction(1, new Mult);
            break;
        case CLOSEPAR: // case of $
            automate.reduction(1, new ClosePar);
            break;
        case FIN:
            automate.reduction(1, new Fin);
            break;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}



State4::State4() : State("E4") {};

bool State4::transition(Automate & automate, Symbole * s){
    switch(*s)
    {
        case INT:
            automate.decalage(s, new State3);
            break;
        case OPENPAR: // case of $
            automate.decalage(s, new State2);
            break;
        case EXPR:
            automate.decalage(s, new State7);
            break;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}


State5::State5() : State("E5") {};

bool State5::transition(Automate & automate, Symbole * s){
    switch(*s)
    {
        case INT:
            automate.decalage(s, new State3);
            break;
        case OPENPAR: // case of $
            automate.decalage(s, new State2);
            break;
        case EXPR:
            automate.decalage(s, new State8);
            break;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}


State6::State6() : State("E6") {};

bool State6::transition(Automate & automate, Symbole * s){

    switch(*s)
    {
        case PLUS:
            automate.decalage(s, new State4);
            break;
        case MULT:
            automate.decalage(s, new State5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new State9);
            break;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}


State7::State7() : State("E7") {};

bool State7::transition(Automate & automate, Symbole * s){

    switch(*s)
    {
        case PLUS:
            automate.reduction(1, new Plus);
            break;
        case MULT:
            automate.decalage(s, new State5);
            break;
        case CLOSEPAR:
            automate.reduction(1, new ClosePar);
            break;
        case FIN:
            automate.reduction(1, new Fin);
            break;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}


State8::State8() : State("E8") {};

bool State8::transition(Automate & automate, Symbole * s){

    switch(*s)
    {
        case PLUS:
            automate.reduction(1, new Plus);
            break;
        case MULT:
            automate.reduction(1, new Mult);
            break;
        case CLOSEPAR:
            automate.reduction(1, new ClosePar);
            break;
        case FIN:
            automate.reduction(1, new Fin);
            break;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}


State9::State9() : State("E9") {};

bool State9::transition(Automate & automate, Symbole * s){

    switch(*s)
    {
        case PLUS:
            automate.reduction(1, new Plus);
            break;
        case MULT:
            automate.reduction(1, new Mult);
            break;
        case CLOSEPAR:
            automate.reduction(1, new ClosePar);
            break;
        case FIN:
            automate.reduction(1, new Fin);
            break;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}























