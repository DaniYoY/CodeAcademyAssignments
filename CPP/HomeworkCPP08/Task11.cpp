// Задача 11
// Добавете функционалност в програмата за складова наличност на продукти в супермаркет (тема 05,
// задача 15) за сериализация и десериализация на инвентара.
// ● За целта дефинирайте функции за сериализация и десериализация на класа за инвентарен продукт.
// ● Програмата трябва да прочита данните от файл при стартиране и да ги записва при промяна от
// страна на потребителя в същия файл.

#include<string>
#include<iostream>
#include<fstream>
#include<random>

class Product
{
private:
    int quantity;
    double price;
    std::string name;

public: 
    Product()
    {
    quantity =0;
    price = 0.0;
    name = "";
    };
    Product(int quantity, double price,const std::string & name){
        this->quantity = quantity;
        this->price = price;
        this->name = name;
    };
       Product(int quantity, double price, std::string & name){
        this->quantity = quantity;
        this->price = price;
        this->name = name;
    };
    int getQuantity () const{
        return this->quantity; 
    }; 
    double getPrice () const{
        return this->price;
    }; 
    std::string getName () const{
        return this->name;
    }; 
    void setQuantity(int val){
        this->quantity= val;
    }
    void setPrice(double val){
        this->price= val;
    }
    void setName(const std::string & val){
        this->name= val;
    }
};

class Inventory
{
private:
    std::string shopName;
    std::vector<Product> products;
public:
    Inventory()
    {
    shopName ="";
    products = {};
    };
    Inventory(const std::string & name)
    {
    this->shopName =name;
    products = {};
    };
    const std::string & getName() const
    {
        return this->shopName;
    }
    const std::vector<Product> getProducts() const{
        return this->products;
    }
    void setName(const std::string & name){
        this->shopName = name;
    };
    void addProducts(Product p) {
        this->products.push_back(p);
        std::cout<< "Added product"<<p.getName()<<std::endl;
        return;
    };
};

std::string serializeProduct(Product p){
    return p.getName() + " " + std::to_string(p.getQuantity()) + " " + std::to_string( p.getPrice());
}

void serializeInventoryInFile(Inventory inv){
    std::fstream file;
    std::string fileName = inv.getName() + ".txt";
    file.open(fileName, std::fstream::app);
    if (file)
    {
       for (size_t i = 0; i < inv.getProducts().size(); i++)
       {
        file<< serializeProduct(inv.getProducts()[i])<<std::endl;
       }
    }
    file.close();
}

Inventory deserializeInventoryFromFile(std::string fileName){
    Inventory inv{};
    inv.setName(fileName.substr(0,fileName.size()-4));
    std::fstream file;
    file.open(fileName, std::fstream::in);
    while (!file.eof())
    {
        Product p;
        std::string name{""};
        double pricing{0.0};
        int quantity{0};
        file >> name >> quantity >> pricing;
        p.setName(name);
        p.setPrice(pricing);
        p.setQuantity(quantity);
        inv.addProducts(p);
    }
    file.close();
    return inv;
}

int main(int argc, char const *argv[])
{
    Product pizza(3, 2.5, "Pizza"), mac(2, 4.5, "macaronni"), cheese(32, 12.5, "cheese"), tomato(102, 5, "tomato");
    Inventory inv("MladostShop");
    inv.addProducts(pizza);
    inv.addProducts(mac);
    inv.addProducts(cheese);
    inv.addProducts(tomato);
    serializeInventoryInFile(inv);
    Inventory inv2 = deserializeInventoryFromFile("MladostShop.txt");
    std::cout<< inv.getName()<<std::endl;
    for (auto && prod : inv2.getProducts())
    {
        std::cout<< prod.getName() <<" P: "<< prod.getPrice()<< " Q: "<< prod.getQuantity() <<"\n";
    }
    return 0;
}
