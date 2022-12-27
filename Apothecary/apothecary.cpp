#include "apothecary.h"
#include <iostream>
#include <iomanip>

// конструктор инициализирует поля лекарства теми значениями, которые в него поместили
Medicine::Medicine(int _serNu, string _name, string _manuf, Date _date, bool _rec, int _amount, double _price):serialNumber(_serNu),name(_name), manufacturer(_manuf),sellBy(_date),recipe(_rec),amount(_amount), price(_price)
{

}

// деструктор
Medicine::~Medicine()
{

}

// возвращает количество
int Medicine::getAmount()
{
    return amount;
}

// возвращает серийный номер
int Medicine::getSerialNumber()
{
    return serialNumber;
}

// возвращает название лекарства
string Medicine::getName()
{
    return name;
}

// возвращает производителя
string Medicine::getManufacturer()
{
    return manufacturer;
}

// возвращает дату изготовления
Date Medicine::getSellBy()
{
    return sellBy;
}

// возвращает рецепт
bool Medicine::getRecipe()
{
    return recipe;
}

// возвращает цену продажи лекарства
double Medicine::getPrice()
{
    return price;
}

//----------------------------------------------------------------------

// Проверяет числно на введенную длину
bool StockInputScreen::getLength(int number, int needLength)
{
    int result = 0;

    // цикл до тех пор, пока введенное число не будет 0
    while (number != 0)
    {
        number /= 10; // делим число на 10
        result++; // увеличиваем переменную для подсчета длины числа
    }

    // если длина числа совпадает с введенной возвращаем истину, в противном случае ложь
    if (result == needLength)
    {
        return true;
    }

    return false;
}

// Экран ввода лекарства
void StockInputScreen::setMedicine()
{
    char answer;

        try
        {
            cout << "Введите серийный номер лекарства\n";
            cin >> tSerialNumber;

            if (!cin)
                throw "Ошибка ввода! Серийный номер должен состоять из цифр! \n";

            if (!getLength(tSerialNumber, 8))
            {
                throw "Ошибка ввода! Длина серийного номера должна состоять из 8 цифр! \n";
            }

            if (ptrStock->existMedicineSirialNumber(tSerialNumber))
            {
                cout << "Лекарство с таким номером уже записано! \n";
                return;
            }
            cout << "Введите название лекарства\n";
            cin >> tName;

            cout << "Введите производителя лекарства\n";
            cin >> tManufacturer;

            cout << "Введите срок годности лекарства(дд мм)\n";
            cin >> tSellBy.dd >> tSellBy.mm;

            if (!cin)
                throw "Ошибка ввода! Дата должна быть введена числом!\n";

           if (tSellBy.dd>31 || tSellBy.mm>12 || tSellBy.dd<1 || tSellBy.mm<1)
               throw "Ошибка ввода! Пожалуйста, введите реальную дату \n";

            cout << "Нужен ли рецепт для лекарства (y \ n) \n";
            cin >> answer;

            while(answer != 'y' && answer != 'n')
            {
                cin.clear();
                fflush(stdin);
                cout << "Введен недопустимый символ! Введите y \ n: ";
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

            cout << "Введите количество упаковок лекарства\n";
            cin >> tAmount;

            if (!cin)
                throw "Ошибка ввода! Количество упаковок должно быть число! \n";

            cout << "Введите цену за упаковку лекарства\n";
            cin >> tPrice;

            if (!cin)
                throw "Ошибка ввода! Введена некорректная цена! \n";
            if (tPrice<=0)
                throw "Ошибка ввода! Цена товара должна быть положительна! \n";
           // создание экземпляра лекарства
           Medicine* ptrMedicine = new Medicine(tSerialNumber,tName,tManufacturer,tSellBy,tRecipe,tAmount, tPrice);

           // помещение лекарства на склад
           ptrStock->insertMedicine(ptrMedicine);

        }
        catch(const char* mess) // отлов ошибок
        {
           cout << mess << endl;
        }
}


//----------------------------------------------------------------------

// деструктор склада, удаляет все лекарство со склада
Stock::~Stock()
{
    while (!setPtrsMedicine.empty())
    {
        iter = setPtrsMedicine.begin();
        delete *iter;
        setPtrsMedicine.erase(iter);
    }
}


// помещение лекарство в список
void Stock::insertMedicine(Medicine *ptrM)
{
    setPtrsMedicine.push_back(ptrM);
}


// получить серийный номер введенного лекарства
int Stock::getSerialNumber(string tName)
{
    // получаем начало списка
    iter = setPtrsMedicine.begin();

    // цикл пока не кончится список
    while (iter != setPtrsMedicine.end())
    {
        // сравниваем название лекарство на складе и введенного
        if (tName == ((*iter)->getName()))
        {
            // возвращаем серийный номер, в проивном случае -1
            return (*iter)->getSerialNumber();
        }
    }

    return -1;
}


// проверка на существование номера лекарства на складе
bool Stock::existMedicineSirialNumber(int _serialNumber)
{
    // получаем начало списка
    iter = setPtrsMedicine.begin();

    // цикл пока не конец списка
    while (iter != setPtrsMedicine.end())
    {
        // сравниваем серийный номер
        if ((*iter)->getSerialNumber() == _serialNumber)
        {
            // если совпал
            return true;
        }
        iter++;
    }
    // если не совпал
    return false;
}


// проверка на существование лекарства на складе
bool Stock::existMedicineeName(string tName)
{
    // получаем начало списка
    iter = setPtrsMedicine.begin();


    // цикл пока не конец списка
    while (iter != setPtrsMedicine.end())
    {
        // проверка совпадение введенного лекарства и лекарство на складе
        if (tName == ((*iter)->getName()))
        {
            // если совпало
            return true;
        }
        iter++;
    }
    // если нет
    return false;
}

// Вывод на экран лекарств со склада
void Stock::display()
{
    // проверка, пустой ли склад
    if (setPtrsMedicine.empty())
    {
        cout << "На складе нет лекарств! \n";
    }
    else
    {
        // если не пустой получаем начало списка
        iter = setPtrsMedicine.begin();

        // вывод шапки таблицы
        cout << string(98,'-') << endl;
        cout << "| \t\t\t\t\t Данные по складу с лекарством \t\t\t\t | \n";
        cout << string(98,'-') << endl;
        cout << "|  Serial  | \t Name \t |  Amount | \t Manufacturer \t |  Sell By  | \t Recipe | \t Price \t |\n" ;
        cout << string(98,'-') << endl;

        // цикл пока не конец списка выводим все лекарства
        while (iter != setPtrsMedicine.end())
        {
            cout << "| " << (*iter)->getSerialNumber() << " | " <<(*iter)->getName() << "\t |   " <<(*iter)->getAmount()<< "   | \t\t" << (*iter)->getManufacturer()
                 << " |     " << (*iter)->getSellBy().dd << "." << (*iter)->getSellBy().mm << " | ";

            if ((*iter)->getRecipe())
            {
                cout << "нужен\t" << "| ";
            }
            else
            {
                cout << "не нужен\t" << "| ";
            }

            cout << "\t" << (*iter)->getPrice() << "\t | " << "\n";
            cout << string(98,'-') << endl;
            *iter++;
        }
    }
}
