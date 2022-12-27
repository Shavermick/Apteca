#ifndef REPORT
#define REPORT

#include <salesinvoice.h>
#include <expense.h>
#include <purchaseinvoice.h>

#include <string>

// �����
class Report
{

private:

    ExpenseRecord* ptrER; // ��������� �� ������ �����
    SalesInvoiceRecord* ptrSIR; // ��������� �� ��������� ���������
    PurchaseInvoiceRecord* ptrPIR; // ��������� �� ��������� ���������

    double expenses, income, purchase; // ����� ��� ���������

public:

    Report(ExpenseRecord*, SalesInvoiceRecord*, PurchaseInvoiceRecord*); // �����������
    void display(); // ����� �� ����� ������
};

#endif // REPORT

