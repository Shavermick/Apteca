#ifndef INVOICE
#define INVOICE

#include <datetype.h>
#include <string>

using namespace std;

// Состав накладной
class Invoice
{
private:

    Date date; // дата
    string nameMedicine; // название лекарства
    double price; // цена
    int amount; // количество
    double sum; // сумма

public:

    Invoice(Date);
    void setInvoiceOfDay(string, double, int, double); // заполнить поля накладной
    double getSumOfRows(); // получить сумму
    Date getDate(); // получить дату
    int getAmount(); // получить количество
    double getPrice(); // получить ценуж
    string getNameMedicine(); // получить название лекарства

};

#endif // INVOICE
