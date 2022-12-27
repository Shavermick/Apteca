#include "salesinvoice.h"
#include <iostream>

//--------------------------------------------------------

SalesInvoiceRecord::~SalesInvoiceRecord()
{
    while (!setPtrSalesInvoice.empty())
    {
        iter = setPtrSalesInvoice.begin();

        delete *iter;
        setPtrSalesInvoice.erase(iter);
    }
}

void SalesInvoiceRecord::insertSalesInvoice(Date _date, string _name, double _price, int _amount, double _sum)
{
    iter = setPtrSalesInvoice.begin();

    while (iter != setPtrSalesInvoice.end())
    {
        // ������� ���������� ����
        if (_date.dd == (*iter)->getDate().dd  && _date.mm == (*iter)->getDate().mm && _name == (*iter)->getNameMedicine())
        {
            int tAmount = (*iter)->getAmount() + _amount;

            int tPrice = (*iter)->getPrice();

            (*iter)->setInvoiceOfDay(_name, tPrice, tAmount, _sum);

            return;
        }
        else
        {
            iter++;
        }

    }

    Invoice* ptrSalesInvoice = new Invoice(_date);
    ptrSalesInvoice->setInvoiceOfDay(_name, _price, _amount, _sum);
    setPtrSalesInvoice.push_back(ptrSalesInvoice);

}


void SalesInvoiceRecord::display()
{
    if (setPtrSalesInvoice.empty())
    {
        cout << "������� ��� �� ��������!";
    }
    else
    {
        cout << string(90,'-') << endl;

        cout << "|\t\t\t\t\t ������� \t\t\t\t\t | \n";

        cout << string(90,'-') << endl;

        cout << "|\t Date \t | \t Name \t | \t Price \t | \t Amount \t | \t Sum  \t | \n";

        cout << string(90,'-') << endl;

        iter = setPtrSalesInvoice.begin();

        while (iter != setPtrSalesInvoice.end())
        {
            // ����� ������
            cout << "| \t " << (*iter)->getDate().dd << "." << (*iter)->getDate().mm << "\t | \t" << (*iter)->getNameMedicine() << "\t | \t"
                 << (*iter)->getPrice() << "\t | \t\t" <<(*iter)->getAmount() << "\t | \t" << (*iter)->getSumOfRows() << "\t | \n";
            cout << string(90,'-') << endl;iter++;
        }

        cout << "| \t\t �����: \t\t\t\t | \t\t" << getSumOfSalesInvoice() << "\t\t | \n";
        cout << string(90,'-') << endl;
    }
}


double SalesInvoiceRecord::displaySummaryDocument()
{
    double sumSalesInvoice = 0;

    if (setPtrSalesInvoice.size() == 0)
    {
        return 0;
    }

    iter = setPtrSalesInvoice.begin();

    while (iter != setPtrSalesInvoice.end())
    {
        cout << "| ������� " << (*iter)->getDate().dd << "." << (*iter)->getDate().mm  << " ��������� \t | \t\t" << (*iter)->getSumOfRows() << " \t | \n";
        sumSalesInvoice += (*iter)->getSumOfRows();
        iter++;
    }

    return sumSalesInvoice;

}

// ������� ����� ���������

double SalesInvoiceRecord::getSumOfSalesInvoice()
{
    double sumRows = 0;

    iter = setPtrSalesInvoice.begin();

    while (iter != setPtrSalesInvoice.end())
    {
        sumRows += (*iter)->getSumOfRows();
        iter++;
    }

    return sumRows;
}

//-----------------------------------------------------------


void SalesInvoiceInputSceen::setSalesInvoice()
{
    cout << "������� �������� ���������: ";
    cin >> tName;

    if (ptrStockList->existMedicineeName(tName))
    {
        try
        {
            cout << "������� ���� ������� (dd mm): ";
            cin >> tDate.dd >> tDate.mm;

            if (tDate.dd>31 || tDate.mm>12 || tDate.dd<1 || tDate.mm<1)
                throw "������ �����! ����������, ������� �������� ���� \n";
            cout << "������� ���� �������: ";
            cin >> tPrice;

            if (!cin)
                throw "������ �����! ���� ������ ������ ���� ������! \n";
            if (tPrice<=0)
                throw "������ �����! ���� ������ ������ ���� ������������! \n";
            cout << "������� ���������� ���������� ������: ";
            cin >> tAmount;

            if (!cin)
                throw "������ �����! ���������� �������� ������ ���� �����! \n";

            double tSum = tPrice * tAmount;

            ptrSalesInvoice->insertSalesInvoice(tDate, tName, tPrice, tAmount, tSum);

        }
        catch(const char* mess)
        {
            cout << mess;
        }
    }
    else
    {
        cout << "������� ��������� ��� �� ������!\n";
    }
}
