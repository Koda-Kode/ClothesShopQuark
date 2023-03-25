#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <memory>
using namespace std;
#include "viewDef.cpp"


int main(){
        // An attempt to generate "real" random numbers
    srand(time(0));
    unique_ptr<View> objView = make_unique<View>();

    objView->programLoop();

    return 0;
}