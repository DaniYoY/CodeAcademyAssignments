// ● Различни видове продукти, всеки с различна информация. 
// Някои се продават с гаранция.
//  Други се продават на грамаж. Трети се
// продават само на лица над 18 години. 
// Някои имат специални предупреждения, които се принтират при продажба.

#include <string>

class Product
{
private:
    int m_id;
    double m_price;
    std::string m_name;
    std::string m_description;

public:
    Product(int id, int price, const std::string& name, const std::string& description)
     : m_id{id}, m_price{price}, m_name{name}, m_description{description} {};
    ~Product() {};
    
    const std::string getName() const { return m_name;}
    const std::string getDescription() const { return m_description;}
    int getPrice() const { return m_price;}
    int getId() const { return m_id;}

      friend std::ostream& operator<<(std::ostream& stream, const Product& detail){ 
            stream << detail.m_id << ' ' << detail.m_price << ' ' << detail.m_name << ' ' << detail.m_description << ' ';
            return stream;
    }
    friend std::istream& operator>>(std::istream& stream, Product& detail){ 
            stream >> detail.m_id >> detail.m_price >> detail.m_name >> detail.m_description;
            return stream;
    }
    friend bool operator==(const Product& d1, const Product& d2){
        return d1.m_name == d2.m_name && d1.m_price == d2.m_price && d1.m_description == d2.m_description;
    }
    friend bool operator!=(const Product& d1, const Product& d2){
        return d1==d2;
    }
    friend bool operator<(const Product& d1, const Product& d2){
        if(d1.m_id == d2.m_id){
            if(d1.m_price == d2.m_price){
                if (d1.m_name == d2.m_name){
                    return d1.m_description < d2.m_description;
                }
                return d1.m_name < d2.m_name;
            }
            return d1.m_price < d2.m_price;
        }
        return d1.m_id < d2.m_id;
    }
    friend bool operator>(const Product& d1, const Product& d2){
        if(d1.m_id == d2.m_id){
            if(d1.m_price == d2.m_price){
                if (d1.m_name == d2.m_name){
                    return d1.m_description > d2.m_description;
                }
                return d1.m_name > d2.m_name;
            }
            return d1.m_price > d2.m_price;
        }
        return d1.m_id > d2.m_id;
    }

};
