#ifndef INVOICE
#define INVOICE

#include <datetype.h>
#include <string>

using namespace std;

// ������ ���������
class Invoice
{
private:

    Date date; // ����
    string nameMedicine; // �������� ���������
    double price; // ����
    int amount; // ����������
    double sum; // �����

public:

    Invoice(Date);
    void setInvoiceOfDay(string, double, int, double); // ��������� ���� ���������
    double getSumOfRows(); // �������� �����
    Date getDate(); // �������� ����
    int getAmount(); // �������� ����������
    double getPrice(); // �������� �����
    string getNameMedicine(); // �������� �������� ���������

};

#endif // INVOICE
