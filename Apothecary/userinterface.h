#ifndef USERINTERFACE
#define USERINTERFACE

#include "cstdio"
#include <apothecary.h>
#include <salesinvoice.h>
#include <expense.h>
#include <purchaseinvoice.h>
#include <report.h>

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

    PurchaseInvoiceRecord* ptrPurchaseInvoiceRecord;
    PurchaseInvoiceInputSceen* ptrPurchaseInputScreen;

    ExpenseRecord* ptrExpenseRecord;
    ExpenseInputScreen* ptrExpenseInputScreen;

    Report* ptrReport;

    char ch;

public:

    // ����������� � ����������
    UserInterface();
    ~UserInterface();

    // ����������� ����������
    void interact();

};

#endif // USERINTERFACE

