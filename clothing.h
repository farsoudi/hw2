#ifndef CLOTHING_H
#define CLOTHING_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

class Clothing : public Product {
public:
    Clothing(const std::string category, const std::string name, double price, int qty, std::string Size, std::string Brand)
    :   Product(category, name, price, qty),
        Size(Size),
        Brand(Brand)
    {};


    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

    inline std::string getSize() { return this->Size; }
    inline std::string getBrand() { return this->Brand; }

private:
    std::string Size;
    std::string Brand;
};


#endif