#include "Inventory.h"
#include "Product.h"

Inventory::Inventory() : m_shopName("New Shop")
    {
        m_products = {};
    }
Inventory::Inventory(const std::string & name) : m_shopName(name)
    {
        m_products = {};
    }
std::string Inventory::getName() const
    {
        return this->m_shopName;
    }
std::vector<Product> Inventory::getProducts() const{
        return this->m_products;
    }

void Inventory::setName(const std::string & name){
        this->m_shopName = name;
    }

void Inventory::addProducts(const Product & p) {
        this->m_products.push_back(p);
        std::cout<< "Added product"<<p.getName()<<std::endl;
        return;
    }
