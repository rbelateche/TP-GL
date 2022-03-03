#pragma once

#include <string>
#include <stack>
#include "symbole.h"
#include "state.h"
#include "lexer.h"
using namespace std;

class Automate {


    private: 
        stack<State> stateStack;
        stack<Symbole*> symboleStack;
        Lexer * lexer;

    public:
        Automate(string chaine);
        virtual ~Automate();
        void decalage(Symbole * s, State * state);
        void reduction(int n, Symbole * s);


};