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
        cout << "��� ����� ������ ������� i\n"
             << "��� ������ ������� ������� d\n"
             << "��� ������ ������� q\n"
             << "�� �������: ";
        cin >> ch;

        if (ch == 'i')
        {
            system("cls");
            cout << "��� ���������� ������ ��������� �� ����� ������� m\n"
                 << "��� ������ ���������� ��������� ������� s\n"
                 << "��� ����������� ��������� �� ����� ��������� ������� b\n"
                 << "��� ���������� ������ �� ������ ����� ������� o\n"
                 << "��� ������ � ���� ������� q \n"
                 << "�� �������: ";
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

                    cout << "������ ��� ���� ���������? (y / n) \n";
                    cout << "�� �����: ";
                    cin >> ch;

                    while (ch != 'y' && ch != 'n')
                    {
                        cout << "������ ������������ ������! ������� y ��� n ! \n";
                        cout << "�� �����: ";
                        cin >> ch;
                    }
                }

                cin.clear();
                fflush(stdin);

                cout << "������� � ������� ����!\n";
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

                    cout << "������ ��� ���� ��������� ���������? (y / n) \n";
                    cout << "�� �����: ";
                    cin >> ch;

                    while (ch != 'y' && ch != 'n')
                    {
                        cout << "������ ������������ ������! ������� y ��� n ! \n";
                        cout << "�� �����: ";
                        cin >> ch;
                    }
                }

                cin.clear();
                fflush(stdin);

                cout << "������� � ������� ����!\n";
                system("pause");
                break;

            case 'b':
                cout << "������� ��������� � ����������! \n";
                system("pause");
                break;

            case 'o':
                cout << "������� ��������� � ����������! \n";
                system("pause");
                break;

            case 'q':
                cout << "�� ������������� � ������� ���� \n";
                system("pause");
                break;

            default:
                cout << "����������� �������. ���������� ��� ���. \n";
                system("pause");
                break;
            }
        }
        else if (ch == 'd')
        {
            system("cls");
            cout << "��� ������������ ������ ��������� �� ����� ������� n\n"
                 << "��� ������������ ������ �� ������� ������� d\n"
                 << "��� ������������ ������ �� �������� ������� r\n"
                 << "��� ������������ ������ �� ������� � �������� ������� o\n"
                 << "��� ������ � ���� ������� q \n"
                 << "�� �������: ";
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
                cout << "������� ��������� � ����������! \n";
                system("pause");
                break;

            case 'o':
                cout << "������� ��������� � ����������! \n";
                system("pause");
                break;

            case 'q':
                cout << "�� ������������� � ������� ���� \n";
                system("pause");
                break;

            default:
                cout << "����������� �������. ���������� ��� ���. \n";
                system("pause");
                break;
            }
        }
        else if (ch == 'q')
        {
            cout << "����� �������!\n";
            return;
        }
        else
        {

            cout << "����������� �������. ���������� ��� ���. \n";
            system("pause");
        }
    }
}
