#include "menu.h"

Menu::Menu(LibraryDB& DB, const string& filename):library(DB),filename(filename){
    loadData(filename);
}




void Menu::saveData(string filename){
    library.save_to_file(filename);
}

void Menu::loadData(string filename){
    library.load_from_file(filename);
}




void Menu::displayStudentMenu() {
    bool exitStudentMenu = false;
    while (!exitStudentMenu) {
        cout << "\n=== Student Management ===\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Update Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, group, recordBookID, institute;
            int entDate;

            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter admission year: ";
            cin >> entDate;
            cout << "Enter group: ";
            cin.ignore();
            getline(cin, group);
            cout << "Enter record book ID: ";
            getline(cin, recordBookID);
            cout << "Enter institute: ";
            getline(cin, institute);

            library.addStudent(Student(name, entDate, group, recordBookID, institute));
            cout << "Student added successfully!\n";
            break;
        }
        case 2: {
            string studentID;
            cout << "Enter student ID to remove: ";
            cin >> studentID;
            library.removeStudent(studentID);
            break;
        }
        case 3: {
            string studentID;
            cout << "Enter student ID to update: ";
            cin >> studentID;
            library.updateStudentMenu(studentID);
            break;
        }
        case 4: {
            library.displayAllStudents();
            break;
        }
        case 5:
            exitStudentMenu = true;
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    }
}




void Menu::displayBookMenu(){
    bool exitMenu = false;
    while (!exitMenu) {
        cout << "\n=== Book Management ===\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Update Book\n";
        cout << "4. Info about some Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";

        int choice;

        cin >> choice;

        switch(choice){
        case 1: {

            string id, book_author, book_title;
            int book_total_copies, book_available_copies;

            cout << "Enter book ID: ";
            cin >> id;
            cout << "Enter author: ";
            cin.ignore();
            getline(cin, book_author);
            cout << "Enter title: ";
            getline(cin, book_title);
            cout << "Enter total copies: ";
            cin >> book_total_copies;
            cout << "Enter available copies: ";
            cin >> book_available_copies;

            library.addBook(Book(id, book_author, book_title, book_total_copies,
                                 book_available_copies));
            cout << "Book added successfully!\n";
            break;
        }
        case 2: {
            string bookID;
            cout << "Enter book ID to remove: ";
            cin >> bookID;
            library.removeBook(bookID);
            break;
        }
        case 3: {
            string bookID;
            cout << "Enter book ID to update: ";
            cin >> bookID;
            library.updateBookMenu(bookID);
            break;
        }
        case 4: {
            string bookID;
                cout << "Enter book ID: ";
            library.displayBookDetails(bookID);
            break;
        }
        case 5: {
            library.displayAllBooks();
            break;
        }
        case 6:
            exitMenu = true;
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    }
}




void Menu::displayTransactionMenu() {

    bool exitTransactionMenu = false;

    while (!exitTransactionMenu) {
        cout << "\n=== Transaction Management ===\n";
        cout << "1. Issue Book\n";
        cout << "2. Return Book\n";
        cout << "3. Display All Transactions\n";
        cout << "4. Students, who Issued Some Book\n";
        cout << "5. Books, which are Issued to Student\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string studentID, bookID, issDate, librarian;

            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter book ID: ";
            cin >> bookID;
            cout << "Enter issue date (in format DD.MM.YYYY): ";
            cin >> issDate;
            cout << "Enter librarian name: ";
            cin.ignore();
            getline(cin, librarian);

            library.issueBook(studentID, bookID, issDate, librarian);
            break;
        }
        case 2: {
            string studentID, bookID, rtrnDate;

            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter book ID: ";
            cin >> bookID;
            cout << "Enter return date: ";
            cin >> rtrnDate;

            library.returnBook(studentID, bookID, rtrnDate);
            break;
        }
        case 3: {
            library.displayAllTransactions();
            break;
        }
        case 4: {
            string bookID;
            cout << "Enter book ID:";
            cin >> bookID;
            library.displayStudentsWhoIssuedBook(bookID);
            break;
        }
        case 5: {
            string studID;
            cout << "Enter student ID: ";
            cin >> studID;
            library.displayBooksIssuedtoStud(studID);
        }
        case 6:
            exitTransactionMenu = true;
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    }
}




void Menu::runMenu(){

    bool exitMainMenu = false;

    while (!exitMainMenu) {

        cout << "\n=== Library Management System ===\n";
        cout << "1. Manage Students\n";
        cout << "2. Manage Books\n";
        cout << "3. Manage Transactions\n";
        cout << "4. Display All Data\n";
        cout << "5. Save and Exit\n";
        cout << "CAUTION! Do not close the programm in other ways except Exit choice.\n"
                "If you do exit in other ways, you might lose all your data!\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            displayStudentMenu();
            break;
        case 2:
            displayBookMenu();
            break;
        case 3:
            displayTransactionMenu();
            break;
        case 4: {
            cout << "\n=== All Data ===\n";
            library.displayAllStudents();
            library.displayAllBooks();
            library.displayAllTransactions();
            break;
        }
        case 5:
            exitMainMenu = true;
            cout << "Exiting the program. Goodbye!\n";
            saveData(filename);
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    }
}
