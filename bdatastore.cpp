#include <string>
#include <set>
#include <map>
#include <vector>
#include "product.h"
#include "user.h"

#include "datastore.h"
#include "bdatastore.h"

void BDataStore::addProduct(Product *p) {
    std::set<std::string> currWords = p->keywords();

    //Update keywords to acknowledge new product
    std::set<std::string>::iterator st;
    for (st = currWords.begin() ; st != currWords.end(); ++st) {
        keywordMap[*st].emplace(p);
    }
    //Add product
    products.emplace(p);
}

void BDataStore::addUser(User* u) {
    users.emplace(u->getName(), u);
}

//type: 0 for AND, 1 for OR
std::vector<Product*> BDataStore::search(std::vector<std::string>& terms, int type) {

    productSet results;

    bool initialSetFromTerms = true;

    for (const std::string& term : terms) {
        kMap::iterator termIterator = keywordMap.find(convToLower(term));

        if (termIterator == keywordMap.end())
            continue;

        productSet& ps = termIterator->second;
        productSet::iterator st;
        productSet intersectSet; //Only used if we are doing AND
        for(st = ps.begin() ; st != ps.end() ; ++st) {
            if (type || initialSetFromTerms){ //If doing OR, or first iteration for either
                results.emplace(*st);
            }
            if(!type && !initialSetFromTerms) { //If doing AND, and is not first iteration
                intersectSet.emplace(*st);
            }
        }

        if (!type && !initialSetFromTerms) { //If doing AND, and is not first iteration
            results = setIntersection(results, intersectSet);
        }

        initialSetFromTerms=false;
    }

    return (productSearchResults = productList(results.begin(), results.end()));
}

void BDataStore::dump(std::ostream& ofile) {
    ofile << "<products>" << std::endl;
    productSet::iterator pt;
    for (pt = products.begin() ; pt != products.end() ; ++pt) {
        (*pt)->dump(ofile);
    }
    ofile << "</products>" << std::endl;
    ofile << "<users>" << std::endl;
    userMap::iterator mt;
    for (mt = users.begin() ; mt != users.end() ; ++ mt) {
        mt->second->dump(ofile);
    }
    ofile << "</users>" << std::endl ;

}


void BDataStore::addToCart(std::string& u, std::vector<int>& indexes) {
    if (!checkUser(u)) {
        std::cout << "Invalid request" << std::endl;
        return;
    }
    User* user = users[u];
    for (size_t index : indexes) {
        if (productSearchResults.size() == 0 || index < 1 || index > productSearchResults.size()) {
            std::cout << "Invalid request" << std::endl;
            return;
        }
        carts[user].push_back(productSearchResults[index - 1]);
    }
}

void BDataStore::viewCart(std::string& u) {
    if (!checkUser(u)) {
        std::cout << "Invalid username" << std::endl;
        return;
    }
    User* user = users[u];
    productList& cart = carts[user];
    for (size_t i = 0 ; i < cart.size() ; i++) {
        std::cout << "Item " << (i+1) << ": " << cart[i]->displayString() << std::endl;
    }

}

void BDataStore::buyCart(std::string& u) {
    if (!checkUser(u)) {
        std::cout << "Invalid username" << std::endl;
        return;
    }
    User* user = users[u];
    productList& cart = carts[user];

    productList::iterator lt;
    for (lt = cart.begin() ; lt != cart.end() ; ) {
        Product* currentP = *lt;
        if ( (currentP->getQty() >= 1) && (user->getBalance() >= currentP->getPrice())) { //Buyable
            currentP->subtractQty(1);
            user->deductAmount(currentP->getPrice());

            lt = cart.erase(lt);
        } else { //Not Buyable, move on to next item
            ++lt;
        }
    }
}