#ifndef REPORT
#define REPORT

#include <salesinvoice.h>
#include <expense.h>
#include <purchaseinvoice.h>

#include <string>

// отчет
class Report
{

private:

    ExpenseRecord* ptrER; // указатель на оплату счета
    SalesInvoiceRecord* ptrSIR; // указатель на расходную накладную
    PurchaseInvoiceRecord* ptrPIR; // указатель на приходную накладную

    double expenses, income, purchase; // нужны для подсчетов

public:

    Report(ExpenseRecord*, SalesInvoiceRecord*, PurchaseInvoiceRecord*); // конструктор
    void display(); // вывод на экран отчета
};

#endif // REPORT

