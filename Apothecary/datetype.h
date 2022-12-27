#ifndef DATETYPE
#define DATETYPE

// “ип данных дата, нужен дл€ заполнение даты в программе
struct Date
{
public:

    int dd; // день
    int mm; // мес€ц

    // проверка введенной дн€ и мес€ца
    bool static ChechData(int);

};

#endif // DATETYPE
