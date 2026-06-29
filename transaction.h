#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Transaction
{
    string TransactionID;
    string stud_ID;
    string book_inv_ID;
    string issueDate;
    string returnDate;
    string status;
    string librarian;
public:
    Transaction();
    Transaction(string, string, string, string, string, string, string);

    void close_transaction(string);
    void display();

    string getID(){return TransactionID;}
    string getStudID(){return stud_ID;}
    string getInvNum(){return book_inv_ID;}
    string getStatus(){return status;}

    void setStatus(string newStatus){status = newStatus;}
    void setRtrnDate(string newRtrnDate){returnDate = newRtrnDate;}
    void setLibrarian(string newLinrarian){librarian = newLinrarian;}
    void setID(string newID){TransactionID = newID;}
    void setStudID(string newStudID){stud_ID = newStudID;}
    void setBookID(string newBookID){book_inv_ID = newBookID;}
    void setIssDate(string newIssDate){issueDate = newIssDate;}

    void save_to_file(ofstream&) const;
    void load_from_file(ifstream&);

};

#endif // TRANSACTION_H
