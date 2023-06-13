// Задача 06
// Напишете клас, който да репрезентира клиентска поръчка. Напишете функция, която да сортира клиентски
// поръчки по зададен от потребителя критерий за сравняване на две поръчки (function pointer parameter).
// Сортирайте поръчките по:
// 1. Статус (ако едната има статус “започната”, а другата - не, то първата е по-малка)
// 2. Приоритет (ако едната е “high prio”, а другата е “normal prio”, то първата е по-малка).
// Използвайте stable sort алгоритъм.

#include <algorithm>
#include<string>
#include<iostream>
#include<vector>


enum ClientOrderPriority{
    low=1, high
 };
enum ClientOrderStatus {
    pending =1, started, completed, delivered
 };
class ClientOrder
{

private:
    std::string name;
    ClientOrderPriority prio;
    ClientOrderStatus status;
public:
    using clientOrderComparator = bool (*)(ClientOrder,ClientOrder);
    ClientOrder(const std::string & val, ClientOrderPriority priority = ClientOrderPriority::low, ClientOrderStatus currentStatus = ClientOrderStatus::pending): name{val} {
        prio= priority;
        status = currentStatus;
    };
    const std::string getName () const{
        if (this == nullptr)
        {
            return "The client order is not found";
        }
        
        return this->name;
    }
    static bool compareByStatus(ClientOrder p1, ClientOrder p2){
        return p1.status < p2.status;
    }
    static bool compareByPriority(ClientOrder p1, ClientOrder p2){
        return p1.prio < p2.prio;
    }
};

void sortOrders(std::vector<ClientOrder> & v, ClientOrder::clientOrderComparator comparator)
{
    std::sort(v.begin(),v.end(), comparator); 
}

int main(int argc, char const *argv[])
{
    std::vector<ClientOrder> v {
        ClientOrder("low comp", ClientOrderPriority::low, ClientOrderStatus::completed),
        ClientOrder("low pend", ClientOrderPriority::low, ClientOrderStatus::pending),
        ClientOrder("hi comp", ClientOrderPriority::high, ClientOrderStatus::completed),
        ClientOrder("hi del", ClientOrderPriority::high, ClientOrderStatus::delivered),
        ClientOrder("hi pen", ClientOrderPriority::high, ClientOrderStatus::pending),
        ClientOrder("low sta", ClientOrderPriority::low, ClientOrderStatus::started)
    };
    sortOrders(v,ClientOrder::compareByPriority);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout<< v[i].getName() << std::endl;
    }
    std::cout << std::endl;
    sortOrders(v,ClientOrder::compareByStatus);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout<< v[i].getName() << std::endl;
    }

    return 0;
}
