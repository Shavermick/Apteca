#ifndef DATETYPE
#define DATETYPE

// ��� ������ ����, ����� ��� ���������� ���� � ���������
struct Date
{
public:

    int dd; // ����
    int mm; // �����

    // �������� ��������� ��� � ������
    bool static ChechData(int);

};

#endif // DATETYPE
