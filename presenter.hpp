#pragma once
#include <memory>
using namespace std;
#include "objClassesDef.cpp"

class Presenter
{
private:
        // Define objects as smart pointers
    // Vendor
    unique_ptr<Vendor> vendorPtr = make_unique<Vendor>("Ana", "Lebowski");
    // Shirts
        // Short sleeve mao collar
    unique_ptr<Shirts> shortStandardMao = make_unique<Shirts>(0.90, 1.0, 1.03, 100);
    unique_ptr<Shirts> shortPremiumMao = make_unique<Shirts>(0.90, 1.30, 1.03, 100);
        // Short sleeve normal collar
    unique_ptr<Shirts> shortStandardNormal = make_unique<Shirts>(0.90, 1.0, 0, 150);
    unique_ptr<Shirts> shortPremiumNormal = make_unique<Shirts>(0.90, 1.30, 0, 150);
        // Large sleeve mao collar
    unique_ptr<Shirts> largeStandardMao = make_unique<Shirts>(1, 1.0, 1.03, 75);
    unique_ptr<Shirts> largePremiumMao = make_unique<Shirts>(1, 1.30, 1.03, 75);
        // Large sleeve normal collar
    unique_ptr<Shirts> largeStandardNormal = make_unique<Shirts>(1, 1.0, 0, 175);
    unique_ptr<Shirts> largePremiumNormal = make_unique<Shirts>(1, 1.30, 0, 175);

    // Pants
        // Skinny
    unique_ptr<Pants> skinnyStandard = make_unique<Pants>(0.88, 1.0, 750);
    unique_ptr<Pants> skinnyPremium = make_unique<Pants>(0.88, 1.30, 750);
        // Not skinny
    unique_ptr<Pants> normalStandard = make_unique<Pants>(1, 1.0, 250);
    unique_ptr<Pants> normalPremium = make_unique<Pants>(1, 1.30, 250);

        // Get normal pointers to use them in functions
    Vendor* vendor = vendorPtr.get();

public:
    void presRecojer(int weapon);
    void presDisparar();
    void presDejar();
    void presArmaActual();
};