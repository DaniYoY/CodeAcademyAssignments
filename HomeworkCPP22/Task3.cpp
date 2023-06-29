// Задача 03
// Напишете нова версия на vector-а от Задача 01, която използва unique_ptr за данните
// за да може той да се грижи за работата с динамичната памет автоматично.

#include<iostream>
#include<memory>

class CustomString

{
private:
    static const size_t initSize{0};

    size_t m_size;
    size_t m_capacity;
    std::unique_ptr<int[]> m_arr;
    void updateArray(std::unique_ptr<int[]>&& currentArray, size_t & capacity){    
        if(capacity == 0) capacity = 1;
        capacity *=2;
        std::unique_ptr<int[]> newArray = std::unique_ptr<int[]> (new int[capacity]);

        for (size_t i = 0; i < m_size; i++)
        {
            newArray[i]  = currentArray[i];
        }
        currentArray.reset(newArray.release());
        newArray.get_deleter();
    }

public:
    CustomString(): m_size{initSize}, m_capacity{initSize}, m_arr{std::unique_ptr<int[]>( new int[initSize])} {
        
    };
    CustomString(const size_t& capacity): m_size{capacity}, m_capacity{capacity}, m_arr{std::unique_ptr<int[]>( new int[initSize])}  {
        for (size_t i = 0; i < capacity; i++)
        {
            *(m_arr.get()+i) = 0;
        }
    };
    // CustomVector(const CustomVector& obj)
    // {
    //     m_size = obj.m_size;
    //     m_capacity = obj.m_capacity;

    //     m_arr = std::unique_ptr<int>( new int[initSize]);
    //     for (size_t i = 0; i < m_size; i++)
    //     {
    //         *(m_arr.get()+i) = *(obj.m_arr.get()+i);
    //     }
        
    // };
    CustomString(CustomString&& obj){
        m_size = obj.m_size;
        obj.m_size = 0;

        m_capacity = obj.m_capacity;
        obj.m_capacity = 0;
    
        m_arr.reset(obj.m_arr.release());
        obj.m_arr.get_deleter();
    }
    ~CustomString(){
    };
    size_t size() const{
        return m_size;
    };
    size_t capacity() const{
        return m_capacity;
    };
    int& at(const size_t position){
        try
        {
            return *(m_arr.get() + position);
        }
        catch(const std::exception& e)
        {
            std::cerr << "no such position" << '\n';
        }
    };
    void push_back(int number){
        
        if (m_size >=m_capacity)
        {
            updateArray(std::move(m_arr),m_capacity);
        }
        m_arr[m_size] = number;
        m_size++;
    };
    void reserve(const size_t& newCapacity =0){
        if (newCapacity !=0 && newCapacity < m_capacity)
        {
            return;
        }else if (newCapacity == m_capacity || newCapacity == 0)
        {
            int temp{0};
            for (size_t i = 0; i != size()/2; i++)
            {
                temp = m_arr.get()[i];
                m_arr.get()[i]= m_arr.get()[size()-1-i];
                m_arr.get()[size()-1-i] = temp;
            }
        }else{
             std::unique_ptr<int[]> newArray =std::unique_ptr<int[]>( new int[newCapacity]);
             for (size_t i = 0; i < size(); i++)
            {
                newArray.get()[i] = *(m_arr.get() +size()-1- i);
            }
            for (size_t i = size(); i < capacity(); i++)
            {
                newArray.get()[i] = 0;
            }

            m_capacity = newCapacity;    
        
            m_arr.reset(newArray.release());
            newArray.get_deleter();
        } 
    };
    void swap(CustomString& obj){
            size_t temp_capacity = m_capacity; 
            m_capacity = obj.m_capacity;
            obj.m_capacity = temp_capacity;

            size_t temp_size = m_size;
            m_size = obj.m_size;
            obj.m_size = temp_size;
            
            std::unique_ptr<int[]> tempPtr (std::move(m_arr));
            m_arr.reset(obj.m_arr.release());
            obj.m_arr.reset(tempPtr.release());
            tempPtr.get_deleter();
    };
    // shallow copy
    // CustomVector& operator=(const CustomVector& obj){
    //     m_capacity = obj.m_capacity;
    //     m_size = obj.m_size;
    //     m_arr = obj.m_arr.get();
    //     return *this;
    // };  
    CustomString& operator=(CustomString&& obj){
       
       
        m_capacity = obj.m_capacity;
        m_size = obj.m_size;
        m_arr.reset( obj.m_arr.release());
        obj.m_arr.get_deleter();
        obj.m_capacity = 0;
        obj.m_size = 0;
        return *this;
    }
    void print(){
        for (size_t i = 0; i < m_size; i++)
        {
            std::cout << *(m_arr.get()+i) << ' ';
        }
        std::cout << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    int testNum{0};
    // create default constructor
    std::cout << "Test def constr number: " << ++testNum << std::endl;
    CustomString vec1;
    vec1.print();
    // create capacity constructor
    std::cout << "Test cap constr number: " << ++testNum << std::endl;
    CustomString vec2(3);
    vec2.print();
    // create copy Constructor and push_back no resizing
    // std::cout << "Test copy constr number: " << ++testNum << std::endl;
    // vec1.push_back(23);
    // CustomVector vec3(vec1);
    // vec3.print();
    // create rvlue constructor
    std::cout << "Test && constr number: " << ++testNum << std::endl;
    vec1.push_back(2);
    vec1.print();
    CustomString vec4(std::move(vec1));
    vec4.print();
    vec1.print();
    // destructor, size, capacity
    std::cout << "Test size, capacity, destruct number: " << ++testNum << std::endl;
    {
        CustomString vec5;
        vec5.push_back(25);
        vec5.push_back(7924);
        vec5.push_back(12);
        vec5.push_back(257);
        vec5.push_back(2975);
        std:: cout<< "capacity: " << vec5.capacity() << '\n';
        std:: cout<< "size: " << vec5.size() << '\n';
    }
    // test on swap and 2 operators;
    std::cout << "Test swap number: " << ++testNum << std::endl;
    CustomString vec6;
    vec6.push_back(666666);
    CustomString vec7;
    vec7.push_back(7777777);
    std::cout<< "vec 6: ";
    vec6.print();
    std::cout<< "vec 7: ";
    vec7.print();
    vec6.swap(vec7);
    std::cout<< "vec 6: ";
    vec6.print();
    std::cout<< "vec 7: ";
    vec7.print();
    // std::cout << "Test = number: " << ++testNum << std::endl;
    // vec6 = vec7;
    // std::cout<< "vec 6: ";
    // vec6.print();
    // std::cout<< "vec 7: ";
    // vec7.print();
    
    std::cout << "Test = && number: " << ++testNum << std::endl;
    CustomString vec8; 
    std::cout<< "vec 6: ";
    vec6.print();
    std::cout<< "vec 8: ";
    vec8.print();

    vec8 = std::move(vec6);
    std::cout<< "vec 6: ";
    vec6.print();
    std::cout<< "vec 8: ";
    vec8.print();

    // reverse
    std::cout << "Test reverse number: " << ++testNum << std::endl;
    CustomString vec9;
    vec9.push_back(1);
    vec9.push_back(2);
    vec9.push_back(3);
    vec9.print();
    vec9.reserve();
    vec9.print();
    std::cout << "Test reverse & increase number: " << ++testNum << std::endl;
    vec9.reserve(2);
    vec9.print();
    std::cout << "capacity before reversing: " <<vec9.capacity() << '\n';
    vec9.reserve(26);
    std::cout << "capacity after reversing: " <<vec9.capacity() << '\n';
    // at
    std::cout << "Test  at number: " << ++testNum << std::endl;
    std::cout << "element on a position in vec9: " <<vec9.at(2) << '\n';
    std::cout << "element on a  position outside vec9: " <<vec9.at(100) << '\n';

    return 0;
}
