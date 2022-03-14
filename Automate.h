#ifndef AUTOMATE_H
#define AUTOMATE_H


#include <string>
#include <vector>
#include "symbole.h"
#include "lexer.h"
using namespace std;
class State;
class Automate {


    private: 
        vector<State*> stateStack;
        vector<Symbole*> symboleStack;
        Lexer * lexer;

    public:
        explicit Automate(string chaine);
        ~Automate();
        void run();
        void decalage(Symbole * s, State * state);
        void reduction(int n, Symbole * s);
        Expr * popSymbol();
        void pushSymbol(Symbole * symbole);
        void popAndDestroySymbol();


};

#endif