// Задача 01
// Напишете собствена, опростена версия на shared pointer към int. За целта, дефинрайте член данна, която да
// използвате за броене не shared указателите от една група, сочещи към споделен ресурс (т.е., имплменетирайте
// reference counting).
// За да може тази член данна да е споделена (подобно на ресурса - int в случая) и правилно синхронизирана м/у
// повече от два shared указателя, тя трябва да живее на heap-а.

#include <iostream>

class SharedPtrInt
{

private:
    static const int NON_EXISTEN_VALUE = -1;
    int *ptr_;
    int *count_;

public:
    SharedPtrInt() : ptr_{nullptr}, count_{nullptr} {};
    SharedPtrInt(int x) : ptr_{new int(x)}, count_{new int(1)} {};
    ~SharedPtrInt()
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
    SharedPtrInt(const SharedPtrInt & other)
    {
        ptr_ = other.ptr_;
        count_ = other.count_;
        (*count_)++; 
    }
    SharedPtrInt &operator=(const SharedPtrInt & other)
    {
        ptr_ = other.ptr_;
        count_ = other.count_;
        (*count_)++; 
        return *this;
    }
    SharedPtrInt(SharedPtrInt &&lhs) noexcept : ptr_{lhs.ptr_}
    { 
        lhs.ptr_ = nullptr; 
    }
    SharedPtrInt &operator=(SharedPtrInt &&lhs) noexcept
    {
        if (this != &lhs)
        {
            delete ptr_;
            ptr_ = lhs.ptr_;
            lhs.ptr_ = nullptr;
        }
        return *this;
    }
    int &operator*() {return *ptr_; }
    const int &operator*() const { return *ptr_; }
    int *operator->() const { return ptr_; }
    int count() const {return *count_; }

};

int main(int argc, char const *argv[])
{
    int x = 60;
    int y = 999;

    SharedPtrInt p1;
    // std::cout << *p1 << std::endl;
    SharedPtrInt p2(x);
    std::cout << *p2 << std::endl;
    p1 = p2;
    std::cout << *p1 << std::endl;
    SharedPtrInt p3(p1);
    std::cout << *p3 << std::endl;
    std::cout << p3.count() << std::endl;
    {
        SharedPtrInt p4(p3);
        std::cout << p3.count() << std::endl;
    }
    std::cout << p3.count() << std::endl;

    return 0;
}
