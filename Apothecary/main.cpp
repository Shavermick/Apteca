#include "userinterface.h"
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    UserInterface theUserInterface;

    theUserInterface.interact();
    return 0;
}

