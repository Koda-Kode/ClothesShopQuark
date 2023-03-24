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