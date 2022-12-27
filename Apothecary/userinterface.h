#ifndef USERINTERFACE
#define USERINTERFACE

#include "cstdio"
#include <apothecary.h>
#include <salesinvoice.h>
#include <expense.h>
#include <purchaseinvoice.h>
#include <report.h>

#include <iostream>

// Интерфейс
class UserInterface
{
private:

    // указатели на все документы

    Stock* ptrStok;
    StockInputScreen* ptrStokInputScreen;

    SalesInvoiceRecord* ptrSalesInvoiceRecord;
    SalesInvoiceInputSceen* ptrSalesInputScreen;

    PurchaseInvoiceRecord* ptrPurchaseInvoiceRecord;
    PurchaseInvoiceInputSceen* ptrPurchaseInputScreen;

    ExpenseRecord* ptrExpenseRecord;
    ExpenseInputScreen* ptrExpenseInputScreen;

    Report* ptrReport;

    char ch;

public:

    // конструктор и деструктор
    UserInterface();
    ~UserInterface();

    // отображение интерфейса
    void interact();

};

#endif // USERINTERFACE

