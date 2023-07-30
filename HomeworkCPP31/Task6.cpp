// Задача 06
// Модифицирайте вектора със следната shrink стратегия: при намаляне на броя елементи от някоя операция, ако size
// е станал по-малък от 1/4 от капацитета, то реалокираме с капацитет 1/2 от предишния.

template <typename T>
class Vector
{
private:
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
    T *data_ = nullptr;

public:
    using value_type = T;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    Vector(){};
    Vector(size_type size): size_{size}, capacity_{size}, data_ { size ? new T[size] : nullptr; }
    {
    }
    ~Vector()
    {
        if (data_)
        {
            delete data_;
        }
    }

    class iterator
    {
    public:
        using value_type = Vector::value_type;
        using difference_type = Vector::difference_type;
        using reference = Vector::reference;
        using pointer = Vector::pointer;
        iterator() : ptr_{nullptr} {};
        iterator(T *ptr) : ptr_{ptr} {};

    private:
        T *ptr_;
    };

 class citerator
    {
    public:
        using value_type = Vector::value_type;
        using difference_type = Vector::difference_type;
        using reference = Vector::reference;
        using pointer = Vector::pointer;
        citerator() : ptr_{nullptr} {};
        citerator(const T *ptr) : ptr_{ptr} {};
        
    private:
        T *ptr_;
    };

    void erase( Vector::iterator position)
    {
        difference_type pos = position - data_;
        for (size_t i = pos; i < size_; i++)
        {
            arr[i] = std::move(arr[i + 1]);
        }
    }

    void shrink(){
        capacity_ = size_ == capacity_ /4 ? capacity_/2 : capacity_;
    }
   
};