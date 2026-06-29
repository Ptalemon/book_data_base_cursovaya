#include "Student.h"
#include "book.h"

Student::Student():name(""), ent_date(0), group(""), record_book_id(""), institute(""){}

Student::Student(string name_stud, int adm_date, string group_num,
                 string rec_book_id, string inst):
    name(name_stud), ent_date(adm_date), group(group_num), record_book_id(rec_book_id), institute(inst){
}

void Student::display(){
    cout << "Student ID: " << record_book_id << "\n"
         << "Name: " << name << "\n"
         << "Admission Year: " << ent_date << "\n"
         << "Group: " << group << "\n"
         << "Institute: " << institute << endl;
}

void Student::save_to_file(ofstream& out) const{
    out << name << "|" << ent_date << "|" << group << "|"
        << record_book_id << "|" << institute << endl;
}

void Student::load_from_file(ifstream& in){
    getline(in, name, '|');
    in >> ent_date;
    in.ignore();
    getline(in, group, '|');
    getline(in, record_book_id, '|');
    getline(in, institute);
}
