#ifndef LIBRARYDB_H
#define LIBRARYDB_H
#include <vector>
#include <Student.h>
#include <book.h>
#include <transaction.h>
#include <fstream>

using namespace std;

class LibraryDB
{
    vector<Student> students;
    vector<Book> books;
    vector<Transaction> transactions;
public:

    LibraryDB();

    void addStudent(Student);
    void addBook(Book);
    void addTransaction(Transaction);

    void removeStudent(string);
    void removeBook(string);
    void removeTransaction(string);

    void updateStudentMenu(string);
    void updateBookMenu(string);
    void updateTransactionMenu(string);

    void displayAllStudents();
    void displayAllBooks();
    void displayAllTransactions();

    void issueBook(string, string, string, string);
    void returnBook(string, string, string);

    void displayStudentsWhoIssuedBook(string);
    void displayBooksIssuedtoStud(string);
    void displayBookDetails(string);

    void save_to_file(const string&);
    void load_from_file(const string&);
};

#endif // LIBRARYDB_H
