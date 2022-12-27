#ifndef PURCHASEINVOICE
#define PURCHASEINVOICE

#include <invoice.h>
#include <list>

// ��������� ���������
class PurchaseInvoiceRecord
{
private:

    list<Invoice*> setPtrPurchaseInvoice; // ������ ��������� ���������
    list<Invoice*>::iterator iter;

public:

    ~PurchaseInvoiceRecord(); // ����������

    double getSumOfPurchaseInvoice(); // ������� ����� �� ���������
    double displaySummaryDocument(); // ������� � ������� ������� ��������� ��������� � ������� ����� �� ���������
    void insertPurchaseInvoice(Date, string, double, int, double); // �������� ������
    void display(); // ������� ������
};

// ����� �����
class PurchaseInvoiceInputSceen
{
private:

    PurchaseInvoiceRecord* ptrPurchaseInvoice; // ��������� �� ��������� ���������

    Date tDate; // ��������� ����
    string tName; // ��������� ��������
    double tPrice; // ��������� ����
    int tAmount; // ��������� ����������

public:

    // �����������
    PurchaseInvoiceInputSceen(PurchaseInvoiceRecord* tPtrPIR):ptrPurchaseInvoice(tPtrPIR)
    {

    }

    // ��������
    void setPurchaseInvoice();
};

#endif // PURCHASEINVOICE
