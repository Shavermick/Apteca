#include <invoice.h>

// конструктор заполняющий дату
Invoice::Invoice(Date _date):date(_date)
{

}

// получить цену
double Invoice::getPrice()
{
    return price;
}

// получить сумму
double Invoice::getSumOfRows()
{
    return sum;
}

// получить дату
Date Invoice::getDate()
{
    return date;
}

// получить название лекарства
string Invoice::getNameMedicine()
{
    return nameMedicine;
}

// получить количество
int Invoice::getAmount()
{
    return amount;
}

// установить данные
void Invoice::setInvoiceOfDay(string _name, double _price, int _amount, double _sum)
{

    nameMedicine = _name;
    price = _price;
    amount = _amount;
    sum = _price * _amount;

}
