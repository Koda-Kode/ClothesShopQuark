#include <memory>
using namespace std;
#include "presenter.hpp"

void Presenter::presRecojer(int weapon){
    if (weapon==1)
    {
        soldado->recoger(revolver);
    }
    else if (weapon==2)
    {
        soldado->recoger(escopeta);
    }
    else if (weapon==3)
    {
        soldado->recoger(rifle);
    }
}

void Presenter::presDisparar(){
    soldado->disparar();
}

void Presenter::presDejar(){
    soldado->dejar();
}

void Presenter::presArmaActual(){
    soldado->armaActual();
}