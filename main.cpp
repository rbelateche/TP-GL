#include <iostream>
#include "lexer.h"
#include "Automate.h"
#include <map>

int main(void) {
    
    map <string, int> myMap;
    myMap["1+1"] = 2;
    myMap["2*2"] = 4;
    myMap["(1+2)*3"] = 9;
    map <string, int> ::iterator iterMAP;
    for (iterMAP = myMap.begin(); iterMAP != myMap.end(); iterMAP++) {
        string chaine(iterMAP->first);
        cout << chaine << endl;
        auto* automate = new Automate(chaine);
        int res = automate->run();
        if (res != -1){
            cout << "le résultat de notre automate est " << res << endl;
            cout << "le résultat espéré est " << iterMAP->second << endl;
            if (res == iterMAP->second) {
                cout << "TEST VALIDE" << endl;
            }
            else {
                cout << "TEST NON VALDIE" << endl;
            }
        }

        delete(automate);
    }



    return 0;

}