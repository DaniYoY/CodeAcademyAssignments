#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include<vector>
#include<iostream>
#include<fstream>
class Product;

class Inventory
{
private:
    std::string m_shopName;
    std::vector<Product> m_products;
public:
    Inventory();
    Inventory(const std::string & name);
    inline std::string getName() const;
    inline std::vector<Product> getProducts() const;
    inline void setName(const std::string & name);
    inline void addProducts(const Product & p);
};
#endif
