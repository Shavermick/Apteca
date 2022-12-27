#ifndef PURCHASEINVOICE
#define PURCHASEINVOICE

#include <invoice.h>
#include <list>

// Приходная накладная
class PurchaseInvoiceRecord
{
private:

    list<Invoice*> setPtrPurchaseInvoice; // Список приходной накладной
    list<Invoice*>::iterator iter;

public:

    ~PurchaseInvoiceRecord(); // деструктор

    double getSumOfPurchaseInvoice(); // вернуть сумму по документу
    double displaySummaryDocument(); // вывести в разделе расходы приходную накладную и вернуть сумму по документу
    void insertPurchaseInvoice(Date, string, double, int, double); // вставить данные
    void display(); // вывести данные
};

// экран ввода
class PurchaseInvoiceInputSceen
{
private:

    PurchaseInvoiceRecord* ptrPurchaseInvoice; // указатель на приходную накладную

    Date tDate; // временная дата
    string tName; // временное название
    double tPrice; // временное цена
    int tAmount; // временное количество

public:

    // конструктор
    PurchaseInvoiceInputSceen(PurchaseInvoiceRecord* tPtrPIR):ptrPurchaseInvoice(tPtrPIR)
    {

    }

    // записать
    void setPurchaseInvoice();
};

#endif // PURCHASEINVOICE
