#ifndef USERINTERFACE
#define USERINTERFACE

#include "cstdio"
#include <apothecary.h>
#include <salesinvoice.h>

#include <iostream>

// интерфейс
class UserInterface
{
private:

    // указатели на все документы

    Stock* ptrStok;
    StockInputScreen* ptrStokInputScreen;

    SalesInvoiceRecord* ptrSalesInvoiceRecord;
    SalesInvoiceInputSceen* ptrSalesInputScreen;

    char ch;

public:

    // конструктор и деструктор
    UserInterface();
    ~UserInterface();

    // отображение интерфейса
    void interact();

};

#endif // USERINTERFACE

