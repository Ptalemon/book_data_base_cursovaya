#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class Student
{
    string name;
    int ent_date;
    string group;
    string record_book_id;
    string institute;
public:
    Student();
    Student(string, int, string, string, string);

    void display();

    string getID(){return record_book_id;}
    void setName(string newName){name = newName;}
    void setGroup(string newGroup){group = newGroup;}
    void setInstitute(string newInstitute){institute = newInstitute;}
    void setEntDate(int newEntDate){ent_date = newEntDate;}
    void setRecBookID(string newRecBookID){record_book_id = newRecBookID;}

    void save_to_file(ofstream&) const;
    void load_from_file(ifstream&);

};

#endif // BASE_DB_H
