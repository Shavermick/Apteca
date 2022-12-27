#include <invoice.h>

// ����������� ����������� ����
Invoice::Invoice(Date _date):date(_date)
{

}

// �������� ����
double Invoice::getPrice()
{
    return price;
}

// �������� �����
double Invoice::getSumOfRows()
{
    return sum;
}

// �������� ����
Date Invoice::getDate()
{
    return date;
}

// �������� �������� ���������
string Invoice::getNameMedicine()
{
    return nameMedicine;
}

// �������� ����������
int Invoice::getAmount()
{
    return amount;
}

// ���������� ������
void Invoice::setInvoiceOfDay(string _name, double _price, int _amount, double _sum)
{

    nameMedicine = _name;
    price = _price;
    amount = _amount;
    sum = _price * _amount;

}
