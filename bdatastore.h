#ifndef BDATASTORE_H
#define BDATASTORE_H
#include <string>
#include <set>
#include <map>
#include <vector>
#include "product.h"
#include "user.h"

#include "datastore.h"

typedef std::set<Product*> productSet;
typedef std::map<std::string, User*> userMap;
typedef std::map<std::string, productSet> kMap;
typedef std::vector<Product*> productList;

class BDataStore : public DataStore {

public:
    BDataStore() {}
    ~BDataStore() {
        productSet::iterator it;
        for (it = products.begin(); it != products.end(); ++it) {
            delete (*it);
        }

        userMap::iterator mt;
        for (mt = users.begin() ; mt != users.end() ; ++mt) {
            delete (mt->second);
        }
    }
    void addProduct(Product *p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);

    void addToCart(std::string& u, std::vector<int>& indexes);
    void viewCart(std::string& u);
    void buyCart(std::string& u);


private:
    productSet products;
    userMap users;
    kMap keywordMap;

    productList productSearchResults;
    std::map<User*, productList> carts;

    inline bool checkUser(std::string& u) {
        if (users.find(u) != users.end()) {
            return true;
        }
        return false;
    }


};

#endif