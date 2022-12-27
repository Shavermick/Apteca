#include "userinterface.h"

using namespace std;

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
            cout << "Для добавление нового лекарства на склад нажмите n\n"
                 << "Для записи проданного лекарства нажмите s\n"
                 << "Для составление накладной на заказ лекарства нажмите b\n"
                 << "Для добавление записи об оплате услуг нажмите o\n"
                 << "Для выхода в меню нажмите q \n"
                 << "Вы выбрали: ";
            cin >> ch;

            switch (ch) {
            case 'n':
                cout << "Функция находится в разработке! \n";
                system("pause");
                break;

            case 's':
                cout << "Функция находится в разработке! \n";
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
                 << "Для формирования недельного отчета по доходам нажмите d\n"
                 << "Для формирования недельного отчета по расходам нажмите r\n"
                 << "Для формирования недельного отчета по доходам и расходам нажмите o\n"
                 << "Для выхода в меню нажмите q \n"
                 << "Вы выбрали: ";
            cin >> ch;

            switch (ch) {
            case 'n':
                cout << "Функция находится в разработке! \n";
                system("pause");
                break;

            case 'd':
                cout << "Функция находится в разработке! \n";
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
