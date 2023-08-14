// Задача 05
// Дефинрайте собствена версия на shared_ptr (без да поддържаме weak_ptr)

#include <iostream>
template<class Val>
class SharedPtr
{

private:
    static const int NON_EXISTEN_VALUE = -1;
    Val *ptr_;
    int *count_;

public:
    SharedPtr<Val>() : ptr_{nullptr}, count_{nullptr} {};
    SharedPtr<Val>(Val x) : ptr_{new Val(x)}, count_{new int(1)} {};
    ~SharedPtr<Val>()
    {
        if(*count_ > 1){
            (*count_)--;
        }else{
            delete ptr_; 
            delete count_;
        }
        ptr_ = nullptr;
        count_ = nullptr;
    }
    SharedPtr<Val>(const SharedPtr & other)
    {
        ptr_ = other.ptr_;
        count_ = other.count_;
        (*count_)++; 
    }
    SharedPtr<Val> &operator=(const SharedPtr & other)
    {
        ptr_ = other.ptr_;
        count_ = other.count_;
        (*count_)++; 
        return *this;
    }
    SharedPtr<Val>(SharedPtr &&lhs) noexcept : ptr_{lhs.ptr_}
    { 
        lhs.ptr_ = nullptr; 
    }
    SharedPtr<Val> &operator=(SharedPtr &&lhs) noexcept
    {
        if (this != &lhs)
        {
            delete ptr_;
            ptr_ = lhs.ptr_;
            lhs.ptr_ = nullptr;
        }
        return *this;
    }
    Val &operator*() {return *ptr_; }
    const Val &operator*() const { return *ptr_; }
    Val *operator->() const { return ptr_; }
    int count() const {return *count_; }

};

int main(int argc, char const *argv[])
{
    int x = 60;
    int y = 999;
// test with int
    SharedPtr<int> p1;

    SharedPtr<int> p2(x);
    std::cout << *p2 << std::endl;
    p1 = p2;
    std::cout << *p1 << std::endl;
    SharedPtr<int> p3(p1);
    std::cout << *p3 << std::endl;
    std::cout << p3.count() << std::endl;
    {
        SharedPtr<int> p4(p3);
        std::cout << p3.count() << std::endl;
    }
    std::cout << p3.count() << std::endl;


// test with string
    SharedPtr<std::string> p5;

    SharedPtr<std::string> p6("string");
    std::cout << *p6 << std::endl;
    p5 = p6;
    std::cout << *p5 << std::endl;
    SharedPtr<std::string> p7(p5);
    std::cout << *p7 << std::endl;
    std::cout << p7.count() << std::endl;
    {
        SharedPtr<std::string> p8(p7);
        std::cout << p7.count() << std::endl;
    }
    std::cout << p7.count() << std::endl;


    return 0;
}
