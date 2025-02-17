#include <sstream>
#include <iomanip>
#include <set>
#include <string>
#include "product.h"
#include "util.h"

using namespace std;

Product::Product(const std::string category, const std::string name, double price, int qty) :
    name_(name),
    price_(price),
    qty_(qty),
    category_(category)
{

}

Product::~Product()
{

}


double Product::getPrice() const
{
    return price_;
}

std::string Product::getName() const
{
    return name_;
}

void Product::subtractQty(int num)
{
    qty_ -= num;
}

int Product::getQty() const
{
    return qty_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Product::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Product::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
}

void Product::emplaceBaseKeywords(std::set<std::string>& keywords) const {
    std::set<std::string> nameKeywords = parseStringToWords(convToLower(name_));
    keywords = setUnion<std::string>(keywords, nameKeywords);
}