#ifndef MENU_H
#define MENU_H

#include <librarydb.h>


class Menu
{
    LibraryDB& library;
    string filename;

    void displayStudentMenu();
    void displayBookMenu();
    void displayTransactionMenu();

public:
    Menu(LibraryDB&, const string&);

    void runMenu();

    void loadData(string);
    void saveData(string);
};

#endif // MENU_H
