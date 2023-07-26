#include <vector>
#include<map>
#include"Order.hpp"
#include"User.hpp"
#include"Inventory.hpp"
#include"Promotion.hpp"

class Shop
{
private:
    std::vector<User> m_users;  
    std::vector<Promotion> m_promotions;  
    Inventory inv;    
public:
    Shop();
    ~Shop();
};

