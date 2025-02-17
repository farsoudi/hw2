#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "clothing.h"
#include "util.h"

using namespace std;

std::set<std::string> Clothing::keywords() const {
    std::set<std::string> keywords;
    emplaceBaseKeywords(keywords);
    

    std::set<std::string> brandWords = parseStringToWords(convToLower(Brand));
    keywords = setUnion<std::string>(keywords, brandWords);

    return keywords;
}

std::string Clothing::displayString() const {
    stringstream ss;
    ss << name_ << endl 
    << "Size: " << Size << " Brand: " << Brand << endl
    << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left." << endl;

    return ss.str();
        
}

void Clothing::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << Size << "\n" << Brand << endl;
}