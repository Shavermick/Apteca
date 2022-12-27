#include <list>
#include <string>
#include <datetype.h>

#ifndef APOTHECARY
#define APOTHECARY

using namespace std;

///// class Лекарство /////
class Medicine
{
private:

    int serialNumber; // серийный номер
    string name; // название лекарства
    string manufacturer; // производитель
    Date sellBy; // дата изготовления
    bool recipe; // нужен ли рецепт
    int amount; // количество
    double price; // цена продажи


public:
    Medicine(int _serNu, string _name, string _manuf, Date _date, bool _rec, int _amount, double _price); // конструктор
    ~Medicine(); // деструктор

    int getSerialNumber(); // получение серийного номера
    string getName(); // получение название лекарства
    string getManufacturer(); // получение производителя
    Date getSellBy(); // получить дату изготовления лекарства
    bool getRecipe(); // получить рецепт
    int getAmount(); // получить количество
    double getPrice(); // получить цену

};

///// класс Склад /////
class Stock
{
private:
    list <Medicine*> setPtrsMedicine; // массив лекарств на складе
    list <Medicine*>::iterator iter;

public:
    ~Stock();

    void insertMedicine(Medicine*); // поместить лекарство на склад

    int getSerialNumber(string); // получить серийный номер лекарства, нужного лекарства
    bool existMedicineeName(string); // проверка существует ли лекарство на складе
    bool existMedicineSirialNumber(int); // проверка существование лекарства с таким же серийным номером

    void display(); // вывести на экран все лекарство на складе
};

class StockInputScreen
{
private:

    Stock *ptrStock; // указатель на склад

    int tSerialNumber; // серийный номер  |
    string tName; // название лекарства   |
    string tManufacturer; // производитель|
    Date tSellBy; // дата изготовления    |  Переменные для временных манипуляций
    bool tRecipe; // нужен ли рецепт      |
    int tAmount; // количество            |
    double tPrice; // цена продажи        |


public:
    StockInputScreen(Stock* _ptrStock):ptrStock(_ptrStock) // конструктор
    {

    }

    void setMedicine(); // ввести лекарство и поместить его на склад
    bool getLength(int,int); // проверка длины серийного номера

};

#endif // APOTHECARY
