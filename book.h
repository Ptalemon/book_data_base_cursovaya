#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

using namespace std;

struct book{
    int book_id;
    string author;
    string title;
    int year_published;
    int total_copies;
    int available_copies;
};

class Book
{
    book data_book;
public:
    Book(int, string, string, int, int, int);
    Book(book);
    ~Book();
    Book(const Book&);

    bool check_availability();
    void update_copies(int, int);
};

#endif // BOOK_H
