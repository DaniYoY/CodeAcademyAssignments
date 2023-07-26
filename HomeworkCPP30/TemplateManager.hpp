
#include<string>
#include<iostream>
#include<set>
#include<memory>
#include <algorithm>

#include"FileHandler.hpp"
template<typename T>
class TemplateManager
{
private:
        const std::string AUTH_DETAILS_FILE {""};
        std::set<std::unique_ptr<T>> details;
        
public:
    TemplateManager(){
        FileHandler fh{AUTH_DETAILS_FILE};
        while (!(fh.get()>>std::ws).eof())
        {
            addInstance(T(fh.get()));
        }  
    };
    T* getInstance(const T& ref){
        auto ref  = details.find(ref);
        if (ref == nullptr)
        {
            throw std::out_of_range("No such element");
        }
        return ref;
    }
    void addInstance(const T& ref){
            details.emplace(std::unique_ptr<T>(new T(ref)));
    }
    ~TemplateManager(){
        FileHandler fh{AUTH_DETAILS_FILE};
        std::for_each(details.begin(), details.end(), [&](std::unique_ptr<T> ref){ fh.get() << *ref <<'\n';});
    };

};
