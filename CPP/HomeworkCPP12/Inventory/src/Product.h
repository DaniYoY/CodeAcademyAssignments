#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include<vector>
#include<iostream>
#include<fstream>

class Product
{
private:
    int m_quantity;
    double m_price;
    std::string m_name;

public: 
    Product();
    Product(int quantity, double price,const std::string & name);
    Product(int quantity, double price, std::string & name);
    inline int getQuantity () const;
    inline double getPrice () const;
    inline const std::string & getName () const;
    inline void setQuantity(int val);
    inline void setPrice(double val);
    inline void setName(const std::string & val);
};

#endif
