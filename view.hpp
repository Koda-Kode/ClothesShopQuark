#pragma once
#include "presenterDef.cpp"

class View
{
private:
    unique_ptr<Presenter> pres = make_unique<Presenter>();
public:
    void programLoop();
    void topPart();
    void dotLine();
    void startMenu();
    void invoiceHistoryMenu();
        // Invoice creator menus
    void topInvoicePart();
    void bottomInvoicePart();

    void clothType();
    void shirtSleeve();
    void shirtCollar();
    void pantSkinny();
    void Premium();
    void unitPrice(int *price);
    void unitQuantity(int *quantity, int itemID);
    void creating();
};