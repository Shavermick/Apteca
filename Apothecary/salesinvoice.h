#ifndef SALESINVOICE
#define SALESINVOICE

#include <apothecary.h>
#include <invoice.h>

// ��������� ���������
class SalesInvoiceRecord
{
private:

    list<Invoice*> setPtrSalesInvoice; // ������ � ��������� ���������
    list<Invoice*>::iterator iter;

public:

    ~SalesInvoiceRecord();

    double getSumOfSalesInvoice(); // �������� ����� ���������
    double displaySummaryDocument(); // ����� �� ����� ������ ������� �� ��������� ��������� � ������� �������� ������ �� ���������
    void insertSalesInvoice(Date, string, double, int, double); // �������� ������
    void display(); // ������� ������

};

// ����� ����� ��������� ���������
class SalesInvoiceInputSceen
{
private:

    SalesInvoiceRecord* ptrSalesInvoice; // ��������� �� ��������� ���������
    Stock* ptrStockList; // ��������� �� �����

    Date tDate; // ��������� ����
    string tName; // ��������� �������� ���������
    double tPrice; // ��������� ����
    int tAmount; // ��������� ����������

public:

    // �����������
    SalesInvoiceInputSceen(SalesInvoiceRecord* tPtrSIR, Stock* tPtrStock):ptrSalesInvoice(tPtrSIR),ptrStockList(tPtrStock)
    {

    }

    // ������ ��������� ���������
    void setSalesInvoice();
};

#endif // SALESINVOICE

