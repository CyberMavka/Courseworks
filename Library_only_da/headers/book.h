#pragma once
#include "date.h"
#include <iostream>
#include <iomanip>
struct Book {
    Date date;
    std::string name;
    std::string author;
    std::string genre;
    int coast;
    int rating;
    int id;
    int idReader = 0;
    int idDayOfReceipt = 0;
};

Book* addBook(Book*& books, Book book, int num);
Book* removeBook(Book*& books, int id, int num);
Book createBook();
void printBook(Book* books, int num);
void editBook(Book& book);
void sortByAuthor(Book*& books, int number);
void sortByRating(Book*& books, int number);
void sortByName(Book*& books, int number);
void sortByGenre(Book*& books, int number);
bool existIdBook(Book *&books,int id, int number);
Book & findById(Book *&books,int id, int number);
void printMostPopularBooks(Book *&books, int number);
void booksOnHand(Book *&books, int number);
void findByGenre(Book *&books, int number);
void findByAuthor(Book *&books, int number);
void findByName(Book *&books, int number);

