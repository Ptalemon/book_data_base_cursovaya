#include "book.h"

Book::Book(int ID, string author, string title, int year, int total, int left){
    data_book = {ID, author, title, year, total, left};
}

Book::Book(book struct_book_data){
    int id = struct_book_data.book_id;
    string author = struct_book_data.author;
    string title = struct_book_data.title;
    int year = struct_book_data.year_published;
    int total = struct_book_data.total_copies;
    int left = struct_book_data.available_copies;
    data_book = {id, author, title, year, total, left};
}

Book::~Book(){
    data_book = {NULL, NULL, NULL, NULL, NULL, NULL};
}

bool Book::check_availability(){
    //Check amount of book
    if(data_book.available_copies != 0){
        cout << "There're some books " << data_book.title << " by " <<
                data_book.author << ". There're left: " <<
                data_book.available_copies << " copies." << endl;
        return true;
    }
    if(data_book.available_copies == 0){
      cout << "There're no more copies of such book" << endl;
      return false;
    }
    else{
        cout << "Error appeared. Please, recalculate." << endl;
        return false;
    }
}

void Book::update_copies(int change, int status = 0){
    //Update amount of books. 0 - decrease, 1 - increase
    if(((data_book.available_copies - change) > 0) and status == 0){
        data_book.available_copies -= change;
    }
    if(((data_book.available_copies + change) < data_book.total_copies) and status == 1){
        data_book.available_copies += change;
    }
    else{
        cout << "There're not enough books for such operation or too much."
                " Please, enter new amount." << endl;
    }
}
