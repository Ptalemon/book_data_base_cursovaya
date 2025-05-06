#include "Student.h"
#include "book.h"

Student::Student(int book_id, string author, string title, int year_published, int total_copies,
                 int available_copies, string first_name, string last_name,
                 string middle_name, string ent_date, string ID,
                 string group, string univ):Book(book_id, author, title, year_published, total_copies, available_copies){
    data_student = {first_name, last_name, middle_name, ent_date, group, ID, univ, {book_id, author, title, year_published, total_copies, available_copies}};
}

Student::~Student(){
    data_student = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, {NULL, NULL, NULL, NULL, NULL, NULL}};
}

Student::Student(student struct_student_data):Book(struct_student_data.taken_book){
    book take_from_book = struct_student_data.taken_book;

    string first_name = struct_student_data.first_name;
    string last_name = struct_student_data.last_name;
    string middle_name = struct_student_data.middle_name;
    string ent_date = struct_student_data.ent_date;
    string group = struct_student_data.group;
    string record_book_id = struct_student_data.record_book_id;
    string institute = struct_student_data.institute;
    int book_id = take_from_book.book_id;
    string author = take_from_book.author;
    string title = take_from_book.title;
    int year_published = take_from_book.year_published;
    int total_copies = take_from_book.total_copies;
    int available_copies = take_from_book.available_copies;

    data_student = {first_name, last_name, middle_name, ent_date, group, record_book_id, institute, {book_id, author, title, year_published, total_copies, available_copies}};
}

Student::Student(const Student& copy_rec, const book& copy_book_rec):Book(copy_book_rec){
    student copy_from = copy_rec.data_student;

    data_student = {copy_from.first_name, copy_from.last_name, copy_from.middle_name,
                    copy_from.ent_date, copy_from.group,
                    copy_from.record_book_id, copy_from.institute,
                    {copy_book_rec.book_id, copy_book_rec.author, copy_book_rec.title,
                    copy_book_rec.year_published,
                     copy_book_rec.total_copies, copy_book_rec.available_copies}};
}

void Student::get_borrowed_books(){
    cout << "This studentd's record borrowed book with ID: " <<data_student.taken_book.book_id << ", " <<
            data_student.taken_book.title << " by " <<
            data_student.taken_book.author << "released in " << data_student.taken_book.year_published << endl;
}
