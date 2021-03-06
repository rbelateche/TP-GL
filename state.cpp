#include "state.h"
#include <iostream>

State::State(const string &name) {
    this->name = name;
}

State::~State() = default;

void State::showTransition(){
    cout << "current state : " << this->name << endl;
}


State0::State0() : State("E0") {};

State0::~State0() = default;

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

State1::~State1() = default;

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
            return false;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}

State2::State2() : State("E2") {};

State2::~State2() = default;


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

State3::~State3() = default;

bool State3::transition(Automate & automate, Symbole * s){
    switch(*s)
    {
        case PLUS:
        case MULT:
        case CLOSEPAR: // case of $   
        case FIN:
        {    
           
           
            auto *val = (Entier *) automate.popSymbol();
            automate.reduction(1, new Expr(val->getValeur()));
            delete(val);
            automate.pushSymbol(s);
            break;
        } 
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}



State4::State4() : State("E4") {};

State4::~State4() = default;

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

State5::~State5() = default;

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

State6::~State6() = default;

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

State7::~State7() = default;

bool State7::transition(Automate & automate, Symbole * s){
    switch(*s)
    {
        case PLUS:
        case CLOSEPAR:
        case FIN:
        {
            Expr * s1 = automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr * s2 = automate.popSymbol();
            automate.reduction(3, new Plus(s1, s2));
            delete(s1);
            delete(s2);
            automate.pushSymbol(s);
            break;
        }     
        case MULT:
            automate.decalage(s, new State5);
            break;
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}


State8::State8() : State("E8") {};

State8::~State8() = default;

bool State8::transition(Automate & automate, Symbole * s){
    switch(*s)
    {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            Expr * s1 = automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr * s2 = automate.popSymbol();
            automate.reduction(3, new Mult(s1, s2));
            delete(s1);
            delete(s2);
            automate.pushSymbol(s);
            break;
        }
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}


State9::State9() : State("E9") {};

State9::~State9() = default;

bool State9::transition(Automate & automate, Symbole * s){
    switch(*s)
    {
        case PLUS:
        case MULT:       
        case CLOSEPAR:         
        case FIN:
        {
            automate.popAndDestroySymbol();
            auto * val = (Entier*) automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.reduction(3, new Expr(val->getValeur()));
            delete(val);
            automate.pushSymbol(s);
            break;
        }        
        default:
            delete(s);
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false; 
    }
    return true;
}
























