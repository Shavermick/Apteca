#include "expense.h"
#include <iostream>

using namespace std;

//-----------------------------------------------------------

// �������� ����
Date Expense::getDate()
{
    return date;
}

// �������� �������� ������
string Expense::getPayee()
{
    return payee;
}

// �������� ����� ������
double Expense::getAmount()
{
    return amount;
}

//-----------------------------------------------------------

// �������� ���� ����� �� ������
ExpenseRecord::~ExpenseRecord()
{
    while (!vectPtrExpenses.empty())
    {
        iter = vectPtrExpenses.begin();
        delete *iter;
        vectPtrExpenses.erase(iter);
    }
}

// �������� ������ � ������
void ExpenseRecord::insertExp(Expense *ptrExp)
{
    vectPtrExpenses.push_back(ptrExp);
}

// ����� ���� ����� �� �����
void ExpenseRecord::display()
{
    if (vectPtrExpenses.size() == 0)
    {
        cout << "������� ��� �� �������! \n";
    }
    else
    {
        cout << string(50,'-') << endl;
        cout << "| \t\t ���������� ������� \t\t | \n";
        cout << string(50,'-') << endl;
        cout << "| \t �������� ������ \t | \t ����� \t | \n";
        cout << string(50,'-') << endl;

        iter = vectPtrExpenses.begin();

        while (iter != vectPtrExpenses.end())
        {
            cout << "| \t" << (*iter)->getDate().dd << "." << (*iter)->getDate().mm << " " << (*iter)->getPayee()
                 << "\t\t | \t" << (*iter)->getAmount() << "\t | \n";
            cout << string(50,'-') << endl;
            iter++;
        }

    }
}

// ����� ���� ����� � ����� � ��������� ������ ���� ������
double ExpenseRecord::displaySummaryDocument()
{
    double sumExpense = 0;

    if(vectPtrExpenses.size() == 0)
    {
        return 0;
    }

    iter = vectPtrExpenses.begin();

    cout << string(58, '-') << endl;

    while (iter != vectPtrExpenses.end())
    {

        cout << "| ������ " << (*iter)->getDate().dd << "." << (*iter)->getDate().mm << " �� " << (*iter)->getPayee() << " \t\t | \t\t" << "-" << (*iter)->getAmount() << " \t | \n";
        sumExpense += (*iter)->getAmount();
        cout << string(58, '-') << endl;
        iter++;
    }

    return sumExpense;

}

//-----------------------------------------------------------

// �����������
ExpenseInputScreen::ExpenseInputScreen(ExpenseRecord *per):ptrExpenseRecord(per)
{

}

// ���� ���������� �� �������
void ExpenseInputScreen::setExpense()
{
    Date tDate;
    string tPayee;
    double tAmount;

    try
    {
        cout << "������� ���� ������ (dd mm): ";
        cin >> tDate.dd >> tDate.mm;

        if (!cin)
            throw "������ �����! ���� ������ ���� ������� ������!\n";

        if (tDate.dd>31 || tDate.mm>12 || tDate.dd<1 || tDate.mm<1)
            throw "������ �����! ����������, ������� �������� ���� \n";

        cout << "������� �������� ������: ";
        cin >> tPayee;

        cout << "������� ����� ������: ";

        cin >> tAmount;

        if (!cin)
            throw "������ �����! ����� ������ ���� ������!\n";

        Expense* ptrExpense = new Expense(tDate, tPayee, tAmount);
        ptrExpenseRecord->insertExp(ptrExpense);
    }
    catch(const char* mess)
    {
        cout << mess;
    }
}

//-----------------------------------------------------------
