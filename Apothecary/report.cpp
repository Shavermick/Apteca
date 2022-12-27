#include <report.h>
#include <iostream>

Report::Report(ExpenseRecord *pER, SalesInvoiceRecord *pSIR, PurchaseInvoiceRecord *pPIR):ptrER(pER), ptrSIR(pSIR), ptrPIR(pPIR)
{

}

void Report::display()
{

    cout << string(58,'-') << endl;
    cout << "| \t Отчет за все время работы аптеки \t\t | \n";
    cout << string(58,'-') << endl;

    cout << "| \t\t\t Доходы \t\t\t | \n";

    cout << string(58, '-') << endl;

    income = ptrSIR->displaySummaryDocument();

    if (income == 0)
    {
        cout << string(58, '-') << endl;
        cout << "| \t\t Доходов от продажи нет! \t\t |" << endl;
        cout << string(58, '-') << endl;
    }
    else
    {
        cout << string(58, '-') << endl;
        cout << "| \t\t Итого: \t\t| \t " << income << " \t |\n";
        cout << string(58, '-') << endl;
    }

    cout << "| \t\t\t Расходы \t\t\t | \n";

    expenses = ptrER->displaySummaryDocument();

    if (expenses == 0)
    {
        cout << string(58, '-') << endl;
        cout << "| \t\t Расходов по услугам/аренде нет! \t |" << endl;
        cout << string(58, '-') << endl;
    }
    else
    {
        cout << "| \t\t Итого: \t\t| -" << expenses << " \t |\n";
        cout << string(58, '-') << endl;
    }

    purchase = ptrPIR->displaySummaryDocument();

    if (purchase == 0)
    {
         cout << string(58, '-') << endl;
         cout << "| \t       Расходов по приобретению лекарств нет! \t |" << endl;
         cout << string(58, '-') << endl;
    }
    else
    {
        cout << string(58, '-') << endl;
        cout << "| \t\t Итого: \t\t| \t -" << purchase << " \t |\n";
        cout << string(58, '-') << endl;
    }


    cout << "| \t\t Баланс \t\t | ";

    cout << " \t " << (income - (expenses+purchase)) << "\t |\n";

    cout << string(58, '-') << endl;
}
