#include "apothecary.h"
#include <iostream>
#include <iomanip>

// ����������� �������������� ���� ��������� ���� ����������, ������� � ���� ���������
Medicine::Medicine(int _serNu, string _name, string _manuf, Date _date, bool _rec, int _amount, double _price):serialNumber(_serNu),name(_name), manufacturer(_manuf),sellBy(_date),recipe(_rec),amount(_amount), price(_price)
{

}

// ����������
Medicine::~Medicine()
{

}

// ���������� ����������
int Medicine::getAmount()
{
    return amount;
}

// ���������� �������� �����
int Medicine::getSerialNumber()
{
    return serialNumber;
}

// ���������� �������� ���������
string Medicine::getName()
{
    return name;
}

// ���������� �������������
string Medicine::getManufacturer()
{
    return manufacturer;
}

// ���������� ���� ������������
Date Medicine::getSellBy()
{
    return sellBy;
}

// ���������� ������
bool Medicine::getRecipe()
{
    return recipe;
}

// ���������� ���� ������� ���������
double Medicine::getPrice()
{
    return price;
}

//----------------------------------------------------------------------

// ��������� ������ �� ��������� �����
bool StockInputScreen::getLength(int number, int needLength)
{
    int result = 0;

    // ���� �� ��� ���, ���� ��������� ����� �� ����� 0
    while (number != 0)
    {
        number /= 10; // ����� ����� �� 10
        result++; // ����������� ���������� ��� �������� ����� �����
    }

    // ���� ����� ����� ��������� � ��������� ���������� ������, � ��������� ������ ����
    if (result == needLength)
    {
        return true;
    }

    return false;
}

// ����� ����� ���������
void StockInputScreen::setMedicine()
{
    char answer;

        try
        {
            cout << "������� �������� ����� ���������\n";
            cin >> tSerialNumber;

            if (!cin)
                throw "������ �����! �������� ����� ������ �������� �� ����! \n";

            if (!getLength(tSerialNumber, 8))
            {
                throw "������ �����! ����� ��������� ������ ������ �������� �� 8 ����! \n";
            }

            if (ptrStock->existMedicineSirialNumber(tSerialNumber))
            {
                cout << "��������� � ����� ������� ��� ��������! \n";
                return;
            }
            cout << "������� �������� ���������\n";
            cin >> tName;

            cout << "������� ������������� ���������\n";
            cin >> tManufacturer;

            cout << "������� ���� �������� ���������(�� ��)\n";
            cin >> tSellBy.dd >> tSellBy.mm;

            if (!cin)
                throw "������ �����! ���� ������ ���� ������� ������!\n";

           if (tSellBy.dd>31 || tSellBy.mm>12 || tSellBy.dd<1 || tSellBy.mm<1)
               throw "������ �����! ����������, ������� �������� ���� \n";

            cout << "����� �� ������ ��� ��������� (y \ n) \n";
            cin >> answer;

            while(answer != 'y' && answer != 'n')
            {
                cin.clear();
                fflush(stdin);
                cout << "������ ������������ ������! ������� y \ n: ";
                cin >> answer;
            }

            if (answer == 'y')
            {
                tRecipe = true;
            }
            else
            {
                tRecipe = false;
            }

            cout << "������� ���������� �������� ���������\n";
            cin >> tAmount;

            if (!cin)
                throw "������ �����! ���������� �������� ������ ���� �����! \n";

            cout << "������� ���� �� �������� ���������\n";
            cin >> tPrice;

            if (!cin)
                throw "������ �����! ������� ������������ ����! \n";
            if (tPrice<=0)
                throw "������ �����! ���� ������ ������ ���� ������������! \n";
           // �������� ���������� ���������
           Medicine* ptrMedicine = new Medicine(tSerialNumber,tName,tManufacturer,tSellBy,tRecipe,tAmount, tPrice);

           // ��������� ��������� �� �����
           ptrStock->insertMedicine(ptrMedicine);

        }
        catch(const char* mess) // ����� ������
        {
           cout << mess << endl;
        }
}


//----------------------------------------------------------------------

// ���������� ������, ������� ��� ��������� �� ������
Stock::~Stock()
{
    while (!setPtrsMedicine.empty())
    {
        iter = setPtrsMedicine.begin();
        delete *iter;
        setPtrsMedicine.erase(iter);
    }
}


// ��������� ��������� � ������
void Stock::insertMedicine(Medicine *ptrM)
{
    setPtrsMedicine.push_back(ptrM);
}


// �������� �������� ����� ���������� ���������
int Stock::getSerialNumber(string tName)
{
    // �������� ������ ������
    iter = setPtrsMedicine.begin();

    // ���� ���� �� �������� ������
    while (iter != setPtrsMedicine.end())
    {
        // ���������� �������� ��������� �� ������ � ����������
        if (tName == ((*iter)->getName()))
        {
            // ���������� �������� �����, � �������� ������ -1
            return (*iter)->getSerialNumber();
        }
    }

    return -1;
}


// �������� �� ������������� ������ ��������� �� ������
bool Stock::existMedicineSirialNumber(int _serialNumber)
{
    // �������� ������ ������
    iter = setPtrsMedicine.begin();

    // ���� ���� �� ����� ������
    while (iter != setPtrsMedicine.end())
    {
        // ���������� �������� �����
        if ((*iter)->getSerialNumber() == _serialNumber)
        {
            // ���� ������
            return true;
        }
        iter++;
    }
    // ���� �� ������
    return false;
}


// �������� �� ������������� ��������� �� ������
bool Stock::existMedicineeName(string tName)
{
    // �������� ������ ������
    iter = setPtrsMedicine.begin();


    // ���� ���� �� ����� ������
    while (iter != setPtrsMedicine.end())
    {
        // �������� ���������� ���������� ��������� � ��������� �� ������
        if (tName == ((*iter)->getName()))
        {
            // ���� �������
            return true;
        }
        iter++;
    }
    // ���� ���
    return false;
}

// ����� �� ����� �������� �� ������
void Stock::display()
{
    // ��������, ������ �� �����
    if (setPtrsMedicine.empty())
    {
        cout << "�� ������ ��� ��������! \n";
    }
    else
    {
        // ���� �� ������ �������� ������ ������
        iter = setPtrsMedicine.begin();

        // ����� ����� �������
        cout << string(98,'-') << endl;
        cout << "| \t\t\t\t\t ������ �� ������ � ���������� \t\t\t\t | \n";
        cout << string(98,'-') << endl;
        cout << "|  Serial  | \t Name \t |  Amount | \t Manufacturer \t |  Sell By  | \t Recipe | \t Price \t |\n" ;
        cout << string(98,'-') << endl;

        // ���� ���� �� ����� ������ ������� ��� ���������
        while (iter != setPtrsMedicine.end())
        {
            cout << "| " << (*iter)->getSerialNumber() << " | " <<(*iter)->getName() << "\t |   " <<(*iter)->getAmount()<< "   | \t\t" << (*iter)->getManufacturer()
                 << " |     " << (*iter)->getSellBy().dd << "." << (*iter)->getSellBy().mm << " | ";

            if ((*iter)->getRecipe())
            {
                cout << "�����\t" << "| ";
            }
            else
            {
                cout << "�� �����\t" << "| ";
            }

            cout << "\t" << (*iter)->getPrice() << "\t | " << "\n";
            cout << string(98,'-') << endl;
            *iter++;
        }
    }
}
