#include "transaction.h"

Transaction::Transaction():TransactionID(""), stud_ID(""), book_inv_ID(""),
    issueDate(""), returnDate(""), status(""), librarian(""){}

Transaction::Transaction(string transID, string student_id, string invNum,
                         string trans_status, string issue_date, string return_date,
                         string iss_librarian):TransactionID(transID),
    stud_ID(student_id), book_inv_ID(invNum),
    issueDate(issue_date), returnDate(return_date),
    status(trans_status), librarian(iss_librarian){}

void Transaction::close_transaction(string rtrn_Date){
    returnDate = rtrn_Date;
    status = "Returned";
}

void Transaction::display(){
    cout << "Transaction ID: " << TransactionID << "\n"
         << "Student's ID number: " << stud_ID << "\n"
         << "Book's ID number: " << book_inv_ID << "\n"
         << "Issue Date: " << issueDate << "\n"
         << "Return Date: " << returnDate << "\n"
         << "Status: " << status << "\n"
         << "Librarian: " << librarian << endl;
}

void Transaction::save_to_file(ofstream & out) const{
    out << TransactionID << "|" << stud_ID << "|" << book_inv_ID << "|"
        << status << "|" << issueDate << "|" << returnDate << "|" << librarian << endl;
}

void Transaction::load_from_file(ifstream & in){
    getline(in, TransactionID, '|');
    getline(in, stud_ID, '|');
    getline(in, book_inv_ID, '|');
    getline(in, status, '|');
    getline(in, issueDate, '|');
    getline(in, returnDate, '|');
    getline(in, librarian);
}
