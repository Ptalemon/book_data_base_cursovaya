#include "librarydb.h"

LibraryDB::LibraryDB(){
    cout << "Database created!" << endl;
}




void LibraryDB::addStudent(Student student){
    students.push_back(student);
}

void LibraryDB::addBook(Book book){
    books.push_back(book);
}




void LibraryDB::removeStudent(string studentID){
    for(int i = 0; i < students.size(); i++){
        if(students[i].getID() == studentID){
            students.erase(students.begin() + i);
            cout << "Student removed successfully!" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void LibraryDB::removeBook(string bookID){
    for(int i = 0; i < books.size(); i++){
        if(books[i].getID() == bookID){
            books.erase(books.begin() + i);
            cout << "Book removed successfully!" << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void LibraryDB::removeTransaction(string transactionID){
    for(int i = 0; i < transactions.size(); i++){
        if(transactions[i].getID() == transactionID){
            transactions.erase(transactions.begin() + i);
            cout << "Transaction removed successfully!" << endl;
            return;
        }
    }
    cout << "Transaction not found!" << endl;
}




void LibraryDB::updateStudentMenu(string studentID){

    bool exitMenu = false;

    for(int i = 0; i < students.size(); i++){
        if (students[i].getID() == studentID) {
            while(!exitMenu){
                system("cls");
                cout << "Update Student: " << studentID << endl;
                cout << "1. Update Name" << endl;
                cout << "2. Update Group" << endl;
                cout << "3. Update Institute" << endl;
                cout << "4. Exit" << endl;

                int choice;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: {
                    string newName;
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, newName);
                    students[i].setName(newName);
                    break;
                }
                case 2: {
                    string newGroup;
                    cout << "Enter new group: ";
                    cin.ignore();
                    getline(cin, newGroup);
                    students[i].setGroup(newGroup);
                    break;
                }
                case 3: {
                    string newInstitute;
                    cout << "Enter new institute: ";
                    cin.ignore();
                    getline(cin, newInstitute);
                    students[i].setInstitute(newInstitute);
                    break;
                }
                case 4:
                    cout << "Exiting update menu." << endl;
                    exitMenu = true;
                    return;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }
            }

        }

        cout << "Student not found!" << endl;

    }
}

void LibraryDB::updateBookMenu(string bookID) {
    bool exitMenu = false;
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].getID() == bookID) {
            while (!exitMenu){
                cout << "Update Book: " << bookID << endl;
                cout << "1. Update Title" << endl;
                cout << "2. Update Author" << endl;
                cout << "3. Update Total Copies" << endl;
                cout << "4. Update Available Copies" << endl;
                cout << "5. Exit" << endl;

                int choice;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: {
                    string newTitle;
                    cout << "Enter new title: ";
                    cin.ignore();
                    getline(cin, newTitle);
                    books[i].setTitle(newTitle);
                    break;
                }
                case 2: {
                    string newAuthor;
                    cout << "Enter new author: ";
                    cin.ignore();
                    getline(cin, newAuthor);
                    books[i].setAuthor(newAuthor);
                    break;
                }
                case 3: {
                    int newTotal;
                    cout << "Enter new total copies: ";
                    cin >> newTotal;
                    books[i].setTotal(newTotal);
                    break;
                }
                case 4: {
                    int newAvailable;
                    cout << "Enter new available copies: ";
                    cin >> newAvailable;
                    books[i].setAvail(newAvailable);
                    break;
                }
                case 5:
                    cout << "Exiting update menu." << endl;
                    exitMenu = true;
                    return;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }

                cout << "Book updated successfully!" << endl;
                return;
            }
        }
    }
    cout << "Book not found!" << endl;
}

void LibraryDB::updateTransactionMenu(string transactionID) {
    bool exitMenu =  false;
    for (size_t i = 0; i < transactions.size(); ++i) {
        if (transactions[i].getID() == transactionID) {
            while(!exitMenu){
                cout << "Update Transaction: " << transactionID << endl;
                cout << "1. Update Status" << endl;
                cout << "2. Update Return Date" << endl;
                cout << "3. Update Librarian" << endl;
                cout << "4. Exit" << endl;

                int choice;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: {
                    string newStatus;
                    cout << "Enter new status: ";
                    cin.ignore();
                    getline(cin, newStatus);
                    transactions[i].setStatus(newStatus);
                    break;
                }
                case 2: {
                    string newReturnDate;
                    cout << "Enter new return date: ";
                    cin.ignore();
                    getline(cin, newReturnDate);
                    transactions[i].setRtrnDate(newReturnDate);
                    break;
                }
                case 3: {
                    string newLibrarian;
                    cout << "Enter new librarian: ";
                    cin.ignore();
                    getline(cin, newLibrarian);
                    transactions[i].setLibrarian(newLibrarian);
                    break;
                }
                case 4:
                    cout << "Exiting update menu." << endl;
                    exitMenu = true;
                    return;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }

                cout << "Transaction updated successfully!" << endl;
                return;
            }
        }
    }
    cout << "Transaction not found!" << endl;
}




void LibraryDB::displayAllStudents(){
    if(students.empty()){
        cout << "No students found\n";
        return;
    }
    cout << "All students: \n";
    for(int i = 0; i < students.size(); i++){
        students[i].display();
        cout << "--------------\n";
    }
}

void LibraryDB::displayAllBooks(){
    if(books.empty()){
        cout << "No books found\n";
        return;
    }
    cout << "All books: \n";
    for(int i = 0; i < books.size(); i++){
        books[i].display();
        cout << "--------------\n";
    }
}

void LibraryDB::displayAllTransactions(){
    if(transactions.empty()){
        cout << "No transactions found\n";
        return;
    }
    cout << "All transactions: \n";
    for(int i = 0; i < transactions.size(); i++){
        transactions[i].display();
        cout << "--------------\n";
    }
}




void LibraryDB::issueBook(string studID, string invNum, string issDate,
                          string issLibrarian){
    for(int i = 0; i < books.size(); i++){
        if (books[i].getID() == invNum && books[i].isAvailable()){
            books[i].issue_book();
            string transactionID = "T" + to_string(transactions.size() + 1);
            transactions.push_back(Transaction(transactionID, studID, invNum, "Issued", issDate, "", issLibrarian));
            return;
        }
    }
    cout << "Book not found or not available" << endl;
}

void LibraryDB::returnBook(string studID, string invNum, string rtrnDate){
    for(int i = 0; i < transactions.size(); i++){
        if(transactions[i].getStudID() == studID &&
                transactions[i].getInvNum() == invNum &&
                transactions[i].getStatus() == "Issued"){
            transactions[i].close_transaction(rtrnDate);
            for(int j = 0; j < books.size(); j++){
                if(books[j].getID() == invNum){
                    books[j].return_book();
                    return;
                }
            }
        }
    }
    cout << "No such transaction found" << endl;
}




void LibraryDB::displayStudentsWhoIssuedBook(string invNum){
    cout << "Students who issued book " << invNum << ":\n";
    for(int i = 0; i < transactions.size(); i++){
        if(transactions[i].getInvNum() == invNum &&
                transactions[i].getStatus() == "Issued"){
            for(int j = 0; j < students.size(); j++){
                if(students[j].getID() == transactions[i].getStudID()){
                    students[j].display();
                }
            }
        }
    }
}

void LibraryDB::displayBooksIssuedtoStud(string stud_ID){
    cout << "Books issued to student " << stud_ID << ":\n";
    for(int i = 0; i < transactions.size(); i++){
        if(transactions[i].getStudID() == stud_ID &&
                transactions[i].getStatus() == "Issued"){
            transactions[i].display();
        }
    }
}

void LibraryDB::displayBookDetails(string invNum){
    for(int i = 0; i < books.size(); i++){
        if(books[i].getID() == invNum){
            books[i].display();
            return;
        }
    }
    cout << "Book not found" << endl;
}




void LibraryDB::load_from_file(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error opening file for reading" << endl;
        return;
    }

    string line;

    getline(in, line);
    while (getline(in, line) && line != "Books") {
        Student student;
        size_t pos = 0;

        pos = line.find('|');
        student.setName(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        student.setEntDate(stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);

        pos = line.find('|');
        student.setGroup(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        student.setRecBookID(line.substr(0, pos));
        line.erase(0, pos + 1);

        student.setInstitute(line);

        students.push_back(student);
    }

    while (getline(in, line) && line != "Transactions") {
        Book book;
        size_t pos = 0;

        pos = line.find('|');
        book.setID(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        book.setAuthor(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        book.setTitle(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        book.setTotal(stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);

        book.setAvail(stoi(line));

        books.push_back(book);
    }

    while (getline(in, line)) {
        Transaction transaction;
        size_t pos = 0;

        pos = line.find('|');
        transaction.setID(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        transaction.setStudID(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        transaction.setBookID(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        transaction.setStatus(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        transaction.setIssDate(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find('|');
        transaction.setRtrnDate(line.substr(0, pos));
        line.erase(0, pos + 1);

        transaction.setLibrarian(line);

        transactions.push_back(transaction);
    }

    in.close();
}


void LibraryDB::save_to_file(const string & filename){
    ofstream out(filename);
    if (!out) {
        cerr << "Error opening file for writing" << endl;
        return;
    }

    out << "Students\n";
    for (int i = 0; i < students.size(); ++i) {
        students[i].save_to_file(out);
    }

    out << "Books\n";
    for (int i = 0; i < books.size(); ++i) {
        books[i].save_to_file(out);
    }

    out << "Transactions\n";
    for (int i = 0; i < transactions.size(); ++i) {
        transactions[i].save_to_file(out);
    }

    out.close();
}
