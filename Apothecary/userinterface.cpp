#include "userinterface.h"

using namespace std;

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
            cout << "��� ���������� ������ ��������� �� ����� ������� n\n"
                 << "��� ������ ���������� ��������� ������� s\n"
                 << "��� ����������� ��������� �� ����� ��������� ������� b\n"
                 << "��� ���������� ������ �� ������ ����� ������� o\n"
                 << "��� ������ � ���� ������� q \n"
                 << "�� �������: ";
            cin >> ch;

            switch (ch) {
            case 'n':
                cout << "������� ��������� � ����������! \n";
                system("pause");
                break;

            case 's':
                cout << "������� ��������� � ����������! \n";
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
                 << "��� ������������ ���������� ������ �� ������� ������� d\n"
                 << "��� ������������ ���������� ������ �� �������� ������� r\n"
                 << "��� ������������ ���������� ������ �� ������� � �������� ������� o\n"
                 << "��� ������ � ���� ������� q \n"
                 << "�� �������: ";
            cin >> ch;

            switch (ch) {
            case 'n':
                cout << "������� ��������� � ����������! \n";
                system("pause");
                break;

            case 'd':
                cout << "������� ��������� � ����������! \n";
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
