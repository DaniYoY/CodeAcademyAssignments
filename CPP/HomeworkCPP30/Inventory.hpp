#include"Product.hpp"
#include"FileHandler.hpp"
#include<memory>
#include <vector>
#include<map>
class Inventory
{
private:
    using productID = int;
    using quantity = int;
    static const std::string inventoryFile;
    std::map<int,std::unique_ptr<Product>> m_products; 
    std::map<productID, quantity> m_shelves;

   
public:
    Inventory(){};
    Inventory(const Inventory&) = delete;
    Inventory(Inventory&&) = delete;
    Inventory& operator=(const Inventory&) = delete;
    Inventory& operator=(Inventory&&) = delete;
    ~Inventory();
  
    //admin
    void addProductToList();
    //admin
    void removeProductFromList();

    void updateQuantities();
    
};


