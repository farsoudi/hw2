#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

class Movie: public Product 
{
  public: 
    Movie(const std::string category, const std::string name, double price, int qty, const std::string Genre, const std::string Rating)
    :   Product(category, name, price, qty),
        Genre(Genre),
        Rating(Rating)
    {};

    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

    inline std::string getGenre() { return this->Genre; }
    inline std::string getRating() { return this->Rating; }

  private:
    std::string Genre;
    std::string Rating;
};


#endif