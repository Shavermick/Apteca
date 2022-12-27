#include "userinterface.h"

using namespace std;

UserInterface::UserInterface()
{
    ptrStok = new Stock;
    ptrSalesInvoiceRecord = new SalesInvoiceRecord;
}

UserInterface::~UserInterface()
{
    delete ptrStok;
    delete ptrSalesInvoiceRecord;
}

void UserInterface::interact()
{
    while(true)
    {
        system("cls");
        cout << "Для ввода данных нажмите i\n"
             << "Для вывода отчетов нажмите d\n"
             << "Для выхода нажмите q\n"
             << "Вы выбрали: ";
        cin >> ch;

        if (ch == 'i')
        {
            system("cls");
            cout << "Для добавление нового лекарства на склад нажмите m\n"
                 << "Для записи проданного лекарства нажмите s\n"
                 << "Для составление накладной на заказ лекарства нажмите b\n"
                 << "Для добавление записи об оплате услуг нажмите o\n"
                 << "Для выхода в меню нажмите q \n"
                 << "Вы выбрали: ";
            cin >> ch;

            switch (ch) {
            case 'm':

                while (ch != 'n')
                {
                    system("cls");

                    ptrStokInputScreen = new StockInputScreen(ptrStok);
                    ptrStokInputScreen->setMedicine();
                    delete ptrStokInputScreen;

                    cin.clear();
                    fflush(stdin);

                    cout << "Ввести ещё одно лекарство? (y / n) \n";
                    cout << "Вы ввели: ";
                    cin >> ch;

                    while (ch != 'y' && ch != 'n')
                    {
                        cout << "Введен недопустимый символ! Введите y или n ! \n";
                        cout << "Вы ввели: ";
                        cin >> ch;
                    }
                }

                cin.clear();
                fflush(stdin);

                cout << "Переход в главное меню!\n";
                system("pause");
                break;

            case 's':

                while (ch != 'n')
                {
                    system("cls");

                    ptrSalesInputScreen = new SalesInvoiceInputSceen(ptrSalesInvoiceRecord, ptrStok);
                    ptrSalesInputScreen->setSalesInvoice();
                    delete ptrSalesInputScreen;

                    cin.clear();
                    fflush(stdin);

                    cout << "Ввести ещё одну расходную накладную? (y / n) \n";
                    cout << "Вы ввели: ";
                    cin >> ch;

                    while (ch != 'y' && ch != 'n')
                    {
                        cout << "Введен недопустимый символ! Введите y или n ! \n";
                        cout << "Вы ввели: ";
                        cin >> ch;
                    }
                }

                cin.clear();
                fflush(stdin);

                cout << "Переход в главное меню!\n";
                system("pause");
                break;

            case 'b':
                cout << "Функция находится в разработке! \n";
                system("pause");
                break;

            case 'o':
                cout << "Функция находится в разработке! \n";
                system("pause");
                break;

            case 'q':
                cout << "Вы возвращаетесь в главное меню \n";
                system("pause");
                break;

            default:
                cout << "Неизвестная функция. Попробуйте ещё раз. \n";
                system("pause");
                break;
            }
        }
        else if (ch == 'd')
        {
            system("cls");
            cout << "Для формирования отчета лекарства на склад нажмите n\n"
                 << "Для формирования отчета по доходам нажмите d\n"
                 << "Для формирования отчета по расходам нажмите r\n"
                 << "Для формирования отчета по доходам и расходам нажмите o\n"
                 << "Для выхода в меню нажмите q \n"
                 << "Вы выбрали: ";
            cin >> ch;

            switch (ch) {
            case 'n':
                
		system("cls");

                ptrStok->display();

                system("pause");
                break;

            case 'd':
               
		system("cls");

                ptrSalesInvoiceRecord->display();

                system("pause");
                break;

            case 'r':
                cout << "Функция находится в разработке! \n";
                system("pause");
                break;

            case 'o':
                cout << "Функция находится в разработке! \n";
                system("pause");
                break;

            case 'q':
                cout << "Вы возвращаетесь в главное меню \n";
                system("pause");
                break;

            default:
                cout << "Неизвестная функция. Попробуйте ещё раз. \n";
                system("pause");
                break;
            }
        }
        else if (ch == 'q')
        {
            cout << "Всего доброго!\n";
            return;
        }
        else
        {

            cout << "Неизвестная функция. Попробуйте ещё раз. \n";
            system("pause");
        }
    }
}
