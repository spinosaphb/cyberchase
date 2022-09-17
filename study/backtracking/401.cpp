#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

vector<string> binaryWatch(int turnedOn) {

    vector<string> bin;
    int inCont, outCont = 0;
    int initialTurnedOn = 0;

    if(turnedOn == 0){
        bin = {"0:00"};
    } else {

        for(int i = pow(2, outCont); i <= pow(2, 3); i = pow(2, outCont)){
            if(initialTurnedOn == turnedOn){
                initialTurnedOn = 0;
            }

            outCont++;
            for(int j = pow(2, inCont); j <= pow(2, 5); j = pow(2, inCont)){

            }

            inCont = 0;

        }   

    }

    return bin;
}

int main() {
    
    return 0;
}
