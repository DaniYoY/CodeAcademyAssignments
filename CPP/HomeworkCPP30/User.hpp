#include"AuthenticationDetail.hpp"
#include"Product.hpp"
#include<vector>
class User
{
    
 
public:
    enum class UserRole{ADMIN, OPERATOR, CLIENT};
    User();
    ~User();

    
private:
    int m_id;
    std::string displayName;
    AuthenticationDetail login;
    std::vector<UserRole> roles; 
   
};
