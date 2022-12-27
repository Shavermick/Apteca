#ifndef SALESINVOICE
#define SALESINVOICE

#include <apothecary.h>
#include <invoice.h>

// расходная накладная
class SalesInvoiceRecord
{
private:

    list<Invoice*> setPtrSalesInvoice; // список с расходной накладной
    list<Invoice*>::iterator iter;

public:

    ~SalesInvoiceRecord();

    double getSumOfSalesInvoice(); // получить сумму документа
    double displaySummaryDocument(); // вывод на экран отчета доходов от расходной накладной и возврат итоговой суммой по документу
    void insertSalesInvoice(Date, string, double, int, double); // вставить данные
    void display(); // вывести данные

};

// экран ввода расходной накладной
class SalesInvoiceInputSceen
{
private:

    SalesInvoiceRecord* ptrSalesInvoice; // указатель на расходную накладную
    Stock* ptrStockList; // указатель на склад

    Date tDate; // временная дата
    string tName; // временное название лекарства
    double tPrice; // временная цена
    int tAmount; // временное количество

public:

    // конструктор
    SalesInvoiceInputSceen(SalesInvoiceRecord* tPtrSIR, Stock* tPtrStock):ptrSalesInvoice(tPtrSIR),ptrStockList(tPtrStock)
    {

    }

    // ввести расходную накладную
    void setSalesInvoice();
};

#endif // SALESINVOICE

