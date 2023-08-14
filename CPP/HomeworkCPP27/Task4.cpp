// Задача 04
// Дефинрайте собствена версия на unique_ptr.

#include <iostream>
template<class Val>
class UnikPtr
{

private:
    static const int NON_EXISTEN_VALUE = -1;
    Val *ptr_;
    

public:
    UnikPtr<Val>() : ptr_{nullptr}, count_{nullptr} {};
    UnikPtr<Val>( UnikPtr<Val>&) = delete; 
    UnikPtr<Val>(Val x) : ptr_{new Val(x)} {};
    ~UnikPtr<Val>()
    {
        delete ptr_; 
    
        
        ptr_ = nullptr;
    }
    UnikPtr<Val>(const UnikPtr & other)
    {
        ptr_ = other.ptr_;
    }
    UnikPtr<Val> &operator=(const UnikPtr & other) = delete;
    
    UnikPtr<Val>(UnikPtr<Val> &&lhs) : ptr_{lhs.ptr_} noexcept 
    { 
        lhs.ptr_ = nullptr; 
    }
    UnikPtr<Val> &operator=(UnikPtr &&lhs) noexcept
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
};
