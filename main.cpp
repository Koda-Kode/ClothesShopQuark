#include <memory>
    // Laziness for the win
using namespace std;

#include "viewDef.cpp"


int main(){
    unique_ptr<View> objView = make_unique<View>();

    objView->startMenu();
    objView->programLoop();

    return 0;
}