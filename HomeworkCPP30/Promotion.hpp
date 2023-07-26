#include"Product.hpp"
#include<string>
#include<vector>

class Promotion
{
private:
    using productID = int;
    
    int m_percentage;
    std::vector<productID> m_discountedProducts;
public:
    Promotion(int percentage = 0, std::vector<productID>& productList) : m_percentage{percentage}, m_discountedProducts{productList} 
    {
    };
    ~Promotion();
    
    
};
