// Задача 01
// Напишете собствен vector клас, който има елементи от тип int. Класът трябва да дефинира следното:
// ● Default constructor, който създава празен vector.
// ● Конструктор, който приема размер и инициализира елементите на 0
// ● size операция, която връща броя елементи в контейнера
// ● at операция, работеща по същия начин като vector<int>::at от стандартната библиотека (проверява за
// валиден достъп по индекс и може да хвърли exception.
// ● Copy control members
// ○ Имплементирайте swap операция и използвайте copy-and-swap идиома за присвояването.
// ○ Контейнерът трябва да работи по сходен начин с std::vector и да прави deep copy на паметта с
// елементите на heap-a при копиране.
// ● Имплементирайте логика с удвояващ се капацитет всеки път когато добавяме елемент и сме
// достигнали максималния капацитет.
// ● push_back reserve и capacity методи, сходни на тези на std::vector
// С цел упражнение, използвайте new[] и delete[].
// ● Напишете тестов код, който проверява дали всичко работи правилно с lvalues и с rvalues

#include<iostream>
#include<vector>

class CustomString

{
private:
    static const size_t initSize{0};

    size_t m_size;
    size_t m_capacity;
    int* m_arr;
    int* updateArray(int* & currentArray, size_t & size){    
        bool wasZeroSize{false};
        if(size ==0) 
        {
            size = 1;
            wasZeroSize = true;
        }
        size *=2;
        int * newArray = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            newArray[i] = *(currentArray + i);
        }
        if(!wasZeroSize){
            delete[] currentArray;
        }
        currentArray = nullptr;
        return newArray;
    }

public:
    CustomString(): m_size{initSize}, m_capacity{initSize}, m_arr{new int[initSize]} {
    };
    CustomString(const size_t& capacity): m_size{capacity}, m_capacity{capacity}, m_arr{new int[capacity]}  {
        for (size_t i = 0; i < capacity; i++)
        {
            m_arr[i] = 0;
        }
    };
    CustomString(const CustomString& obj)
    {
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;

        m_arr = new int[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_arr[i] = obj.m_arr[i];
        }
        
    };
    CustomString(CustomString&& obj){
        m_size = obj.m_size;
        obj.m_size = 0;

        m_capacity = obj.m_capacity;
        obj.m_capacity = 0;

        m_arr = obj.m_arr;
        obj.m_arr = nullptr;
    }
    ~CustomString(){
        if(m_capacity == 0 || m_size == 0){
            delete[] m_arr;
            m_arr = nullptr;
        }
        m_size =0;
        m_capacity =0;
        std::cout<< "Destroyed" << std::endl;
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
            return *(m_arr + position);
        }
        catch(const std::exception& e)
        {
            std::cerr << "no such position" << '\n';
        }
    };
    void push_back(int number){
        
        if (m_size >=m_capacity)
        {
            m_arr = updateArray(m_arr,m_capacity);
        }
        m_arr [m_size] = number;
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
                temp = m_arr[i];
                m_arr[i]= m_arr[size()-1-i];
                m_arr[size()-1-i] = temp;
            }
        }else{
             int * newArray = new int[newCapacity];
             for (size_t i = 0; i < size(); i++)
            {
                newArray[i] = *(m_arr +size()-1- i);
            }
            for (size_t i = size(); i < capacity(); i++)
            {
                newArray[i] = 0;
            }

            m_capacity = newCapacity;    
        
            delete[] m_arr;
            m_arr = newArray;
            newArray = nullptr;
        } 
    };
    void swap(CustomString& obj){
            size_t temp_capacity = m_capacity; 
            m_capacity = obj.m_capacity;
            obj.m_capacity = temp_capacity;

            size_t temp_size = m_size;
            m_size = obj.m_size;
            obj.m_size = temp_size;
            
            int * tempPtr = m_arr;
            m_arr = obj.m_arr;
            obj.m_arr = tempPtr;

    };
    // shallow copy
    CustomString& operator=(const CustomString& obj){
        m_capacity = obj.m_capacity;
        m_size = obj.m_size;
        m_arr = obj.m_arr;
        return *this;
    };  
    CustomString& operator=(CustomString&& obj){
        if(m_size != 0){
        delete[] m_arr;
    }
        m_arr = nullptr;

        m_capacity = obj.m_capacity;
        m_size = obj.m_size;
        m_arr = obj.m_arr;

        obj.m_capacity = 0;
        obj.m_size = 0;
        obj.m_arr = nullptr;
        return *this;
    }
    void print(){
        for (size_t i = 0; i < m_size; i++)
        {
            std::cout << *(m_arr+i) << ' ';
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
    std::cout << "Test copy constr number: " << ++testNum << std::endl;
    vec1.push_back(23);
    CustomString vec3(vec1);
    vec3.print();
    // create rvlue constructor
    std::cout << "Test && constr number: " << ++testNum << std::endl;
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
    std::cout << "Test = number: " << ++testNum << std::endl;
    vec6 = vec7;
    std::cout<< "vec 6: ";
    vec6.print();
    std::cout<< "vec 7: ";
    vec7.print();
    
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
