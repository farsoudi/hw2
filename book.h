#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

class Book : public Product {
public:
    Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string Author)
    :   Product(category, name, price, qty),
        ISBN(ISBN),
        Author(Author)
    {};


    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

    inline std::string getISBN() { return this->ISBN; }
    inline std::string getAuthor() { return this->Author; }

private:
    std::string ISBN;
    std::string Author;
};


#endif