#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <Student.h>
#include <string>
#include <iostream>

struct transaction{
    student student_data;
    string issue_date;
    string return_date; //If NULL - the book is taken
    string librarian;
};

class Transaction: public Student
{
    transaction transaction_data;
public:
    Transaction(student, string, string, string);
    ~Transaction();
    Transaction(const Transaction&, const student&);

    void close_transaction();
};

#endif // TRANSACTION_H
