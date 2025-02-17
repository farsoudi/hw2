#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "book.h"
#include "util.h"

using namespace std;

std::set<std::string> Book::keywords() const {
    std::set<std::string> keywords;
    emplaceBaseKeywords(keywords);
    
    keywords.insert(convToLower(ISBN));

    std::set<std::string> authorWords = parseStringToWords(convToLower(Author));
    keywords = setUnion<std::string>(keywords, authorWords);

    return keywords;
}

std::string Book::displayString() const {
    stringstream ss;
    ss << name_ << endl 
    << "Author: " << Author << " ISBN: " << ISBN << endl
    << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left." << endl;

    return ss.str();
        
}

void Book::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN << "\n" << Author << endl;
}