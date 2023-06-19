// Задача 01
// Напишете клас за продукт с име и цена. Създайте списък от продукти.
// Създайте други два списъка, копия на първия, единия от които е със сортирани по
// цена във възходящ ред продукти, другия - със сортирани по цена във низходящ ред
// продукти.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Product
{
private:
    double price;
    std::string name;

public:
    Product(double pricing=0.0, std::string neim="") : price{pricing}, name{neim}
    {
    }
    const double getPrice() const
    {
        return this->price;
    }
    const std::string getName() const
    {
        return this->name;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<Product> ogList{Product(2.0, "kola"), Product(9.0, "chicken"), Product(6.0, "pizza"), Product(1.0, "vafla"), Product(2.0, "fanta"), Product(2.2, "beer"), Product(4.0, "strawberry")};

    std::vector<Product> asc(ogList.size()), desc(ogList.size());
    std::sort(ogList.begin(), ogList.end(),
              [](Product a, Product b)
              {
                  return a.getPrice() < b.getPrice();
              });
    std::copy(ogList.begin(), ogList.end(), asc.begin());
    std::sort(ogList.begin(), ogList.end(),
              [](Product a, Product b)
              {
                  return a.getPrice() > b.getPrice();
              });
    std::copy(ogList.begin(), ogList.end(), desc.begin());
    for (size_t i = 0; i < asc.size(); i++)
    {
        std::cout << asc[i].getName() << ' ';
    }
    std::cout << std::endl;
    for (size_t i = 0; i < desc.size(); i++)
    {
        std::cout << desc[i].getName() << ' ';
    }
    return 0;
}
