#include "presenter.hpp"

void Presenter::printShopInfo(){
    shopPtr->printInfo();
}

void Presenter::printVendorInfo(){
    shopPtr->printVendInfo();
}

void Presenter::printVendorInvoices(){
    shopPtr->printVendInvoices();
}

void Presenter::createInvoice(int itemID, int unit, int quan){
    shopPtr->selectItem(itemID,unit,quan);
}

int Presenter::returnUnits(int itemID){
    return shopPtr->returnStock(itemID);
}

string Presenter::returnNames(int itemID){
    return shopPtr->returnName(itemID);
}