#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "movie.h"
#include "util.h"

using namespace std;

std::set<std::string> Movie::keywords() const {
    std::set<std::string> keywords;
    emplaceBaseKeywords(keywords);
    keywords.insert(convToLower(Genre));
    return keywords;
}

std::string Movie::displayString() const {
    stringstream ss;
    ss << name_ << endl 
    << "Genre: " << Genre << " Rating: " << Rating << endl
    << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left." << endl;

    return ss.str();
        
}

void Movie::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << Genre << "\n" << Rating << endl;
}