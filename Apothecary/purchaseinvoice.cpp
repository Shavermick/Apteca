#include <purchaseinvoice.h>
#include <iostream>

PurchaseInvoiceRecord::~PurchaseInvoiceRecord()
{
    while (!setPtrPurchaseInvoice.empty())
    {
        iter = setPtrPurchaseInvoice.begin();
        delete *iter;
        setPtrPurchaseInvoice.erase(iter);
    }
}

double PurchaseInvoiceRecord::getSumOfPurchaseInvoice()
{
    double sumRows = 0;

    iter = setPtrPurchaseInvoice.begin();

    while (iter != setPtrPurchaseInvoice.end())
    {
        sumRows += (*iter)->getSumOfRows();
        iter++;
    }

    return sumRows;

}

double PurchaseInvoiceRecord::displaySummaryDocument()
{
    double sumPurchaseInvoice = 0;

    if (setPtrPurchaseInvoice.size() == 0)
    {
        return 0;
    }

    iter = setPtrPurchaseInvoice.begin();

    while (iter != setPtrPurchaseInvoice.end())
    {
        cout << "| Приобретение " << (*iter)->getDate().dd << "." << (*iter)->getDate().mm << " лекарства \t\t | \t -" << (*iter)->getSumOfRows() << " \t | \n";
        sumPurchaseInvoice += (*iter)->getSumOfRows();
        iter++;
    }

    return sumPurchaseInvoice;
}

void PurchaseInvoiceRecord::insertPurchaseInvoice(Date _date, string _name, double _price, int _amount, double _sum)
{
   Invoice* ptrPurchaseInvoice = new Invoice(_date);
   ptrPurchaseInvoice->setInvoiceOfDay(_name, _price, _amount, _sum);
   setPtrPurchaseInvoice.push_back(ptrPurchaseInvoice);
}

void PurchaseInvoiceRecord::display()
{
    if (setPtrPurchaseInvoice.empty())
    {
        cout << "Нет заказов на лекарство";
    }
    else
    {
        cout << string(90,'-') << endl;
        cout << "| \t\t\t\t\t Заказанное лекарство \t\t\t\t |\n";
        cout << string(90,'-') << endl;

        cout << "|\t Date \t | \t Name \t | \t Price \t | \t Amount \t | \t Sum  \t | \n";
        cout << string(90,'-') << endl;
        iter = setPtrPurchaseInvoice.begin();

        while (iter != setPtrPurchaseInvoice.end())
        {
            cout << "| \t " << (*iter)->getDate().dd << "." << (*iter)->getDate().mm << "\t | \t" << (*iter)->getNameMedicine() << "\t | \t"
                 << (*iter)->getPrice() << "\t | \t\t" <<(*iter)->getAmount() << "\t | \t" << (*iter)->getSumOfRows() << "\t | \n";

            cout << string(90,'-') << endl;
            iter++;
        }

        cout << "| \t\t Итого: \t\t\t\t | \t\t" << getSumOfPurchaseInvoice() << "\t\t | \n";
        cout << string(90,'-') << endl;
    }
}

//--------------------------------------------------------

void PurchaseInvoiceInputSceen::setPurchaseInvoice()
{
    try
    {
        cout << "Введите дату заказа (dd mm): ";
        cin >> tDate.dd >> tDate.mm;

        if (tDate.dd>31 || tDate.mm>12 || tDate.dd<1 || tDate.mm<1)
            throw "Ошибка ввода! Пожалуйста, введите реальную дату \n";
        cout << "Введите название лекарства: ";
        cin >> tName;

        cout << "Введите цену лекарства: ";
        cin >> tPrice;

        if (!cin)
            throw "Ошибка ввода! Цена товара должно быть число! \n";
        if (tPrice<=0)
            throw "Ошибка ввода! Цена товара должна быть положительна! \n";
        cout << "Введите количество покупки: ";
        cin >> tAmount;

        if (!cin)
            throw "Ошибка ввода! Количество упаковок должно быть число! \n";

        double tSum = tPrice * tAmount;

        ptrPurchaseInvoice->insertPurchaseInvoice(tDate, tName, tPrice, tAmount, tSum);
    }
    catch(const char* mess)
    {
        cout << mess;
    }
}

//--------------------------------------------------------
