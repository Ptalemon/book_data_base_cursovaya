#ifndef STUDENT_H
#define STUDENT_H
#include <book.h>
#include <string>
#include <iostream>

using namespace std;

struct student{
    string first_name;
    string last_name;
    string middle_name;
    string ent_date;
    string group;
    string record_book_id;
    string institute;
    book taken_book;
};


class Student:public Book
{
    student data_student;
public:
    Student(int, string, string, int, int, int, string, string,
            string, string, string, string, string);
    ~Student();
    Student(student);
    Student(const Student&, const book&);

    void get_borrowed_books();
};

#endif // BASE_DB_H
