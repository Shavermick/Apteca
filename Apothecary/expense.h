#ifndef EXPENSE
#define EXPENSE

#include "datetype.h"
#include <string>
#include <vector>

using namespace std;

// Информация об оплатах
class Expense
{

private:

    Date date; // дата оплаты
    string payee; // название оплаты
    double amount; // сумма

public:

    Expense(Date _date, string _payee, double _amount):date(_date),payee(_payee),amount(_amount) // конструктор
    {

    }

    Date getDate(); // получить дату оплаты
    string getPayee(); // получить название оплаты
    double getAmount(); // получить сумму

};

// Список оплат
class ExpenseRecord
{

private:

    vector<Expense*> vectPtrExpenses; // список оплат
    vector<Expense*>::iterator iter;

public:

    ~ExpenseRecord(); // деструктор

    double displaySummaryDocument(); // вывод информации об оплатах для отчета и возврат иноговой суммы

    void insertExp(Expense*); // вставка в список оплаты
    void display(); // вывод на экран оплат

};

// экран ввода оплаты
class ExpenseInputScreen
{
private:

    ExpenseRecord* ptrExpenseRecord;

public:

    ExpenseInputScreen(ExpenseRecord*); //конструктор

    void setExpense(); // вставиить оплату

};

#endif // EXPENSE

