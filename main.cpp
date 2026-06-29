#include <iostream>
#include <menu.h>

using namespace std;

int main()
{

    LibraryDB* library = new LibraryDB();

    string filename = "library.dat";

    Menu* menu = new Menu(*library, filename);

    menu->runMenu();

    delete menu;
    delete library;

    return 0;
}
