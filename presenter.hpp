#pragma once
#include "objClassesDef.cpp"

class Presenter
{
private:
    unique_ptr<Shop> shopPtr = make_unique<Shop>("Good Buy", "Schestakow Avenue 4566");

public:
    void printShopInfo();
    void printVendorInfo();
    void printVendorInvoices();
    void createInvoice(int itemID, int unit, int quan);
};