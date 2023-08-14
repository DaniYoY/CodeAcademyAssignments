// Задача 01
// Напишете каше-клас за дълги имена на неща, които често се повтарят, който ще помогне с пестенето на памет като
// заделя едно и също име само по веднъж и предоставя на клиентите shared_ptr към името.
// Използвайте контейнер от shared_ptr обекти и дефинирайте функция за вземане на име, която ако го има налично,
// връща shared_ptr към него, а ако го няма, го създава, добавя в контейнера и го връща


#include<iostream>
#include<string>
#include<memory>
#include<vector>

class PointFactory
{
private:
    std::vector<std::shared_ptr<std::string>> pointPool;
public:
    PointFactory(){};
    ~PointFactory(){};
    std::string getName(const std::string & name)
    {
        for (const std::shared_ptr<std::string> & pointer : pointPool)
        {
            if(*pointer == name){
                return *pointer;
            }
        }
        return *(getPointer(name));    
    }

    std::shared_ptr<std::string> getPointer(const std::string & name)
    {
        for (const std::shared_ptr<std::string> & pointer : pointPool)
        {
            if(*pointer == name){
                return pointer;
            }
        }
        std::shared_ptr<std::string> p = std::make_shared<std::string>(name);
        pointPool.push_back(p);
        return getPointer(name);
    }

};

