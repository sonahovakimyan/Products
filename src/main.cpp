//
//  main.cpp
//

#include <iostream>
#include <map>
namespace {
    std::pair<const std::string, int> getPair(const std::string& src) {
        auto index = src.find_last_of(" ");
        
        const int price = std::atoi(src.substr(index + 1, src.size()).c_str());
        const std::string name = src.substr(0, index);
        
        return std::pair<const std::string, int>(name, price);
        
    }
} // unnamed namespace

int main(int argc, const char * argv[]) {
    
    int numberOfProducts;
    std::cout << "Please enter the number of ordered products: ";
    std::cin >> numberOfProducts;
    
    std::cout << "Please enter the products and the prices. " << std::endl;
    
    std::map<const std::string, int> products;
    std::string product;
    
    for(size_t i = 0; i <= numberOfProducts; ++i) {
        std::getline(std::cin, product);
        auto pair = getPair(product);
        if(products.find(pair.first) == products.end()) {
            products.emplace(getPair(product));
        } else {
            products.at(pair.first) += pair.second;
        }
    }
    
    for(const auto& p: products) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    
    return 0;
}
