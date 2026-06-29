#include "book.h"

Book::Book():book_id(""), author(""), title(""), total_copies(0), available_copies(0){}

Book::Book(string ID, string book_author, string book_title, int total, int left):
    book_id(ID), author(book_author), title(book_title), total_copies(total), available_copies(left){}

bool Book::isAvailable(){
    return available_copies > 0;
}

void Book::issue_book(){
    if(isAvailable()){
        available_copies--;
    }
}

void Book::return_book(){
    if(isAvailable()){
        available_copies++;
    }
}

void Book::display(){
    cout << "Inventory Number: " << book_id << "\n"
         << "Title: " << title << " by " << author << "\n"
         << "Total Copies: " << total_copies << "\n"
         << "Issued Copies: " << total_copies - available_copies << "\n"
         << "Available Copies: " << available_copies << endl;
}

void Book::save_to_file(ofstream& out) const{
    out << book_id << "|" << author << "|" << title << "|"
        << total_copies << "|" << available_copies << endl;
}

void Book::load_from_file(ifstream & in){
    getline(in, book_id, '|');
    getline(in, author, '|');
    getline(in, title, '|');
    in >> total_copies;
    in.ignore();
    in >> available_copies;
    in.ignore();
}
