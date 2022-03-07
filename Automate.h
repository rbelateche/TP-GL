#pragma once

#include <string>
#include <vector>
#include "symbole.h"
#include "state.h"
#include "lexer.h"
using namespace std;

class Automate {


    private: 
        vector<State*> stateStack;
        vector<Symbole*> symboleStack;
        Lexer * lexer;

    public:
        Automate(string chaine);
        virtual ~Automate();
        void run();
        void decalage(Symbole * s, State * state);
        void reduction(int n, Symbole * s);
        


};