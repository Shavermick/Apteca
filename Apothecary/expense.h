#ifndef EXPENSE
#define EXPENSE

#include "datetype.h"
#include <string>
#include <vector>

using namespace std;

// ���������� �� �������
class Expense
{

private:

    Date date; // ���� ������
    string payee; // �������� ������
    double amount; // �����

public:

    Expense(Date _date, string _payee, double _amount):date(_date),payee(_payee),amount(_amount) // �����������
    {

    }

    Date getDate(); // �������� ���� ������
    string getPayee(); // �������� �������� ������
    double getAmount(); // �������� �����

};

// ������ �����
class ExpenseRecord
{

private:

    vector<Expense*> vectPtrExpenses; // ������ �����
    vector<Expense*>::iterator iter;

public:

    ~ExpenseRecord(); // ����������

    double displaySummaryDocument(); // ����� ���������� �� ������� ��� ������ � ������� �������� �����

    void insertExp(Expense*); // ������� � ������ ������
    void display(); // ����� �� ����� �����

};

// ����� ����� ������
class ExpenseInputScreen
{
private:

    ExpenseRecord* ptrExpenseRecord;

public:

    ExpenseInputScreen(ExpenseRecord*); //�����������

    void setExpense(); // ��������� ������

};

#endif // EXPENSE

