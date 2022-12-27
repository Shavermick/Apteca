#include <report.h>
#include <iostream>

Report::Report(ExpenseRecord *pER, SalesInvoiceRecord *pSIR, PurchaseInvoiceRecord *pPIR):ptrER(pER), ptrSIR(pSIR), ptrPIR(pPIR)
{

}

void Report::display()
{

    cout << string(58,'-') << endl;
    cout << "| \t ����� �� ��� ����� ������ ������ \t\t | \n";
    cout << string(58,'-') << endl;

    cout << "| \t\t\t ������ \t\t\t | \n";

    cout << string(58, '-') << endl;

    income = ptrSIR->displaySummaryDocument();

    if (income == 0)
    {
        cout << string(58, '-') << endl;
        cout << "| \t\t ������� �� ������� ���! \t\t |" << endl;
        cout << string(58, '-') << endl;
    }
    else
    {
        cout << string(58, '-') << endl;
        cout << "| \t\t �����: \t\t| \t " << income << " \t |\n";
        cout << string(58, '-') << endl;
    }

    cout << "| \t\t\t ������� \t\t\t | \n";

    expenses = ptrER->displaySummaryDocument();

    if (expenses == 0)
    {
        cout << string(58, '-') << endl;
        cout << "| \t\t �������� �� �������/������ ���! \t |" << endl;
        cout << string(58, '-') << endl;
    }
    else
    {
        cout << "| \t\t �����: \t\t| -" << expenses << " \t |\n";
        cout << string(58, '-') << endl;
    }

    purchase = ptrPIR->displaySummaryDocument();

    if (purchase == 0)
    {
         cout << string(58, '-') << endl;
         cout << "| \t       �������� �� ������������ �������� ���! \t |" << endl;
         cout << string(58, '-') << endl;
    }
    else
    {
        cout << string(58, '-') << endl;
        cout << "| \t\t �����: \t\t| \t -" << purchase << " \t |\n";
        cout << string(58, '-') << endl;
    }


    cout << "| \t\t ������ \t\t | ";

    cout << " \t " << (income - (expenses+purchase)) << "\t |\n";

    cout << string(58, '-') << endl;
}
