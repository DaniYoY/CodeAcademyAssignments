// templaten class, koito da chete ot failovete, da pravi mapove s nujnoto info 

#include<map>
#include"FileHandler.hpp"
#include<algorithm>

template< typename T>
class DataBaseManager
{
private:
    std::string m_filename;
public:
    using ID = int;
    explicit DataBaseManager(const std::string& filename) : m_filename(filename);
    ~DataBaseManager(){};

    std::map<ID,T> get()
    {
        FileHandler fh(m_fileName);
        int index{0};
        std::map<ID,T> mapping;
        while (!(fh.get()>>std::ws).eof())
        {
            mapping.emplace(index++, T(fh.get()));
        }   
        return mapping;
    }

    void update(const std::map(ID,T)& mapping)
    {
        FileHandler fh(m_fileName);
        std::for_each(std::begin(mapping), std::end(mapping), [&](std::pair<ID,T>& p){ fh.get()<< p.second<< " \n";});
    }
};
