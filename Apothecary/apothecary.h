#include <list>
#include <string>
#include <datetype.h>

#ifndef APOTHECARY
#define APOTHECARY

using namespace std;

///// class ��������� /////
class Medicine
{
private:

    int serialNumber; // �������� �����
    string name; // �������� ���������
    string manufacturer; // �������������
    Date sellBy; // ���� ������������
    bool recipe; // ����� �� ������
    int amount; // ����������
    double price; // ���� �������


public:
    Medicine(int _serNu, string _name, string _manuf, Date _date, bool _rec, int _amount, double _price); // �����������
    ~Medicine(); // ����������

    int getSerialNumber(); // ��������� ��������� ������
    string getName(); // ��������� �������� ���������
    string getManufacturer(); // ��������� �������������
    Date getSellBy(); // �������� ���� ������������ ���������
    bool getRecipe(); // �������� ������
    int getAmount(); // �������� ����������
    double getPrice(); // �������� ����

};

///// ����� ����� /////
class Stock
{
private:
    list <Medicine*> setPtrsMedicine; // ������ �������� �� ������
    list <Medicine*>::iterator iter;

public:
    ~Stock();

    void insertMedicine(Medicine*); // ��������� ��������� �� �����

    int getSerialNumber(string); // �������� �������� ����� ���������, ������� ���������
    bool existMedicineeName(string); // �������� ���������� �� ��������� �� ������
    bool existMedicineSirialNumber(int); // �������� ������������� ��������� � ����� �� �������� �������

    void display(); // ������� �� ����� ��� ��������� �� ������
};

class StockInputScreen
{
private:

    Stock *ptrStock; // ��������� �� �����

    int tSerialNumber; // �������� �����  |
    string tName; // �������� ���������   |
    string tManufacturer; // �������������|
    Date tSellBy; // ���� ������������    |  ���������� ��� ��������� �����������
    bool tRecipe; // ����� �� ������      |
    int tAmount; // ����������            |
    double tPrice; // ���� �������        |


public:
    StockInputScreen(Stock* _ptrStock):ptrStock(_ptrStock) // �����������
    {

    }

    void setMedicine(); // ������ ��������� � ��������� ��� �� �����
    bool getLength(int,int); // �������� ����� ��������� ������

};

#endif // APOTHECARY
