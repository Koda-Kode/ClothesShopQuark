#pragma once
#include <memory>
using namespace std;
#include "objClassesDef.cpp"

class Presenter
{
private:
        // Definir los objetos como punteros inteligentes
    unique_ptr<Vendor> vendorExample = make_unique<Vendor>("Ana","Vincenc");

        // Obtener punteros estandar para poder usarlos en funciones
    Vendor* vendor = vendorExample.get();

public:
    void presRecojer(int weapon);
    void presDisparar();
    void presDejar();
    void presArmaActual();
};