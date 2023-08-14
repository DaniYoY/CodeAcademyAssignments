#include<string>
#include<vector>
#include"Product.hpp"
#include"User.hpp"
#include<algorithm>
#include<map>

class Order
{
private:
    using productID = int;
    using quantity = int;
    int m_id;
    double total;
    User user;
    std::map<productID, quantity> shoppingCart;

public:
    Order();
    ~Order();
    //buyer operator
    void addProductToCart(const Product& prod);
    //buyer operator
    void removeProductToCart(const Product& prod);
};

