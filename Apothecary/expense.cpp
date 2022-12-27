#include "expense.h"
#include <iostream>

using namespace std;

//-----------------------------------------------------------

// получить дату
Date Expense::getDate()
{
    return date;
}

// получить название оплаты
string Expense::getPayee()
{
    return payee;
}

// получить сумму оплаты
double Expense::getAmount()
{
    return amount;
}

//-----------------------------------------------------------

// удаление всех оплат из списка
ExpenseRecord::~ExpenseRecord()
{
    while (!vectPtrExpenses.empty())
    {
        iter = vectPtrExpenses.begin();
        delete *iter;
        vectPtrExpenses.erase(iter);
    }
}

// вставить оплаты в список
void ExpenseRecord::insertExp(Expense *ptrExp)
{
    vectPtrExpenses.push_back(ptrExp);
}

// вывод всех оплат на экран
void ExpenseRecord::display()
{
    if (vectPtrExpenses.size() == 0)
    {
        cout << "Расходы еще не введены! \n";
    }
    else
    {
        cout << string(50,'-') << endl;
        cout << "| \t\t Оплаченные расходы \t\t | \n";
        cout << string(50,'-') << endl;
        cout << "| \t Название оплаты \t | \t Сумма \t | \n";
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

// вывод всех оплат в отчет и получение оплаты всех счетов
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

        cout << "| Оплата " << (*iter)->getDate().dd << "." << (*iter)->getDate().mm << " за " << (*iter)->getPayee() << " \t\t | \t\t" << "-" << (*iter)->getAmount() << " \t | \n";
        sumExpense += (*iter)->getAmount();
        cout << string(58, '-') << endl;
        iter++;
    }

    return sumExpense;

}

//-----------------------------------------------------------

// конструктор
ExpenseInputScreen::ExpenseInputScreen(ExpenseRecord *per):ptrExpenseRecord(per)
{

}

// ввод информации по оплатам
void ExpenseInputScreen::setExpense()
{
    Date tDate;
    string tPayee;
    double tAmount;

    try
    {
        cout << "Введите дату оплаты (dd mm): ";
        cin >> tDate.dd >> tDate.mm;

        if (!cin)
            throw "Ошибка ввода! Дата должна быть введена числом!\n";

        if (tDate.dd>31 || tDate.mm>12 || tDate.dd<1 || tDate.mm<1)
            throw "Ошибка ввода! Пожалуйста, введите реальную дату \n";

        cout << "Введите название оплаты: ";
        cin >> tPayee;

        cout << "Введите сумму оплаты: ";

        cin >> tAmount;

        if (!cin)
            throw "Ошибка ввода! Сумма должна быть числом!\n";

        Expense* ptrExpense = new Expense(tDate, tPayee, tAmount);
        ptrExpenseRecord->insertExp(ptrExpense);
    }
    catch(const char* mess)
    {
        cout << mess;
    }
}

//-----------------------------------------------------------
