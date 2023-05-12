// Задача 15
// Напишете клас за инвентарен продукт в инвентарен модул на софтуер за супермаркет със следните член
// данни: име, цена, брой наличност.
// Напишете клас за инвентар - множество от различни инвентарни продукти, налични в магазин от веригата.
// Напишете програма за работа с инвентара, която поддържа следната функционалност:
// ● Добавяне на нов продукт от потребителя.
// ● Промяна на наличността на продукт от потребителя.
// ● Принтиране на цялостната парична стойност на продуктите в инвентара.

#include <iostream>
#include <string>
#include <vector>
#include <list>

class Product
{
public:
    int quantity;
    double price;
    std::string name;
    Product();
    ~Product();
};

Product::Product()
{
    quantity =0;
    price = 0.0;
    name = "";
}


Product::~Product()
{
}

class Inventory
{
public:
    std::string shopName;
    std::vector<Product> products;
    Inventory();
    ~Inventory();
};

Inventory::Inventory()
{
    shopName ="";
    products = {};
}

Inventory::~Inventory()
{
}


Product makeProduct();

void addNewProdoct(Inventory & inv){
    Product p {};
    p = makeProduct();
    inv.products.push_back(p);
    std::cout << "Product added" << std::endl;
}

Product makeProduct(){
    Product p{};
    std::cout<<"Please enter the new Product name and press Enter"<<std::endl;
    std::cin >> p.name;
    std::cout<<"Please enter the new Product price and press Enter"<<std::endl;
    std::cin >> p.price;
    std::cout<<"Please enter the new Product quantity and press Enter"<<std::endl;
    std::cin >> p.quantity;
    return p;
}

void changeQuantity(Inventory & inv, std::string & pName, int newQantity){
   for (Product prod : inv.products)
   {
    if(prod.name == pName){
        prod.quantity = newQantity;
        std::cout << pName << " quantity is now "<<prod.quantity << std::endl;
        break;
    }
   }
}

void printMonetaryValue(Inventory inv){
    double total {0.0};
    for (Product p : inv.products)
    {
        total += p.quantity*p.price;
    }
    std::cout<< "In shop " << inv.shopName <<" total monetary value of the inventory is " << total<< std::endl;    
}

