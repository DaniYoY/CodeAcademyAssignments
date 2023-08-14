#include "Product.h"

 Product::Product() : m_quantity(0),m_price(0.0),m_name("New product")
    {
    }
Product::Product(int quantity, double price,const std::string & name): m_quantity(quantity), m_price(price), m_name(name)
    {
    }
int Product::getQuantity () const{
        return this->m_quantity; 
    }
double Product::getPrice () const{
        return this->m_price;
    } 
const std::string& Product::getName() const{
        return this->m_name;
    } 
void Product::setQuantity(int val){
        this->m_quantity= val;
    }
void Product::setPrice(double val){
        this->m_price= val;
    }
void Product::setName(const std::string & val) 
    {
        this->m_name= val;
    }