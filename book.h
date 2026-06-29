#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class Book
{
    string book_id;
    string author;
    string title;
    int total_copies;
    int available_copies;
public:
    Book();
    Book(string, string, string, int, int);

    void display();


    bool isAvailable();
    string getID(){return book_id;}
    void setID(string newID){book_id = newID;}
    void setAuthor(string newAuthor){author = newAuthor;}
    void setTitle(string newTitle){title = newTitle;}
    void setTotal(int newTotal){total_copies = newTotal;}
    void setAvail(int newAvail){available_copies = newAvail;}


    void issue_book();
    void return_book();

    void save_to_file(ofstream&) const;
    void load_from_file(ifstream&);

};

#endif // BOOK_H
