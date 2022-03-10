#pragma once

#include <string>
#include <iostream>
#include "symbole.h"
#include "Automate.h"
using namespace std;

class State {

    public: 
        explicit State(const string &name);
        virtual ~State();
        void showTransition();
        virtual bool transition(Automate & automate, Symbole * s);
        

    protected:
        string name;

};


class State0 : public State{
    public:
        explicit State0();
        virtual ~State0() override;
        bool transition(Automate & automate, Symbole * s) override;
};


class State1 : public State{
    public:
        explicit State1();
        virtual ~State1() override;
        bool transition(Automate & automate, Symbole * s) override;
};


class State2 : public State{
    public:
        explicit State2();
        virtual ~State2() override;
        bool transition(Automate & automate, Symbole * s) override;
};

class State3 : public State{
    public:
        explicit State3();
        virtual ~State3() override;
        bool transition(Automate & automate, Symbole * s) override;
};

class State4 : public State{
    public:
        explicit State4();
        virtual ~State4() override;
        bool transition(Automate & automate, Symbole * s) override;
};


class State5 : public State{
    public:
        explicit State5();
        virtual ~State5() override;
        bool transition(Automate & automate, Symbole * s) override;
};


class State6 : public State{
    public:
        explicit State6();
        virtual ~State6() override;
        bool transition(Automate & automate, Symbole * s) override;
};


class State7 : public State{
    public:
        explicit State7();
        virtual ~State7() override;
        bool transition(Automate & automate, Symbole * s) override;
};


class State8 : public State{
    public:
        explicit State8();
        virtual ~State8() override;
        bool transition(Automate & automate, Symbole * s) override;
};


class State9 : public State{
    public:
        explicit State9();
        virtual ~State9() override;
        bool transition(Automate & automate, Symbole * s) override;
};