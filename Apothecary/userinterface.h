#ifndef USERINTERFACE
#define USERINTERFACE

#include "cstdio"
#include <apothecary.h>
#include <salesinvoice.h>

#include <iostream>

// ���������
class UserInterface
{
private:

    // ��������� �� ��� ���������

    Stock* ptrStok;
    StockInputScreen* ptrStokInputScreen;

    SalesInvoiceRecord* ptrSalesInvoiceRecord;
    SalesInvoiceInputSceen* ptrSalesInputScreen;

    char ch;

public:

    // ����������� � ����������
    UserInterface();
    ~UserInterface();

    // ����������� ����������
    void interact();

};

#endif // USERINTERFACE

