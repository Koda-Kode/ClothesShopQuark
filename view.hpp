#pragma once
#include "presenterDef.cpp"

class View
{
private:
    unique_ptr<Presenter> pres = make_unique<Presenter>();
public:
    void topPart();
    void dotLine();
    void startMenu();
    void invoiceHistoryMenu();
    void programLoop();
};