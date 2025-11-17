#include "menuFuncs.hpp"


int main()
{
    int menuChoice = 0;
    do
    {
        displayMenu(menuChoice);
        processMenuChoice(menuChoice);
    } while (menuChoice != 7);

    return 0;
}
