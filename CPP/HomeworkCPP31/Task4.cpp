// Задача 04
// Дефинирайте insert overloaded член функциите на Vector класа (поне две версии)

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
    Vector(size_type size) : size_{size}, capacity_{size}, data_ { size ? new T[size] : nullptr; }
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
    void erase(Vector::iterator position)
    {
        difference_type pos = position - data_;
        for (size_t i = pos; i < size_; i++)
        {
            arr[i] = std::move(arr[i + 1]);
        }
    }
    void insert(T &value)
    {
        if (size_ == capacity_)
        {
            T interim[] = new T[capacity_ * 2];
            for (size_type i = 0; i < capacity_; i++)
            {
                interim[i] = data_[i];
            }
            delete data_;

            data_ = interim;
            capacity_ *= 2;

            data_[size_] = value;
            ++size_;
        }
        else
        {
            data_[size_] = value;
            ++size_;
        }
    }
    void insert(T &value, size_type position)
    {
        if (position < size_ && size_ + 1 < capacity_)
        {
            for (size_type i = size_; i > position; --i)
            {
                data_[i] = std::move(data_[i - 1])
            }
            data_[position] = value;
        }
        else if (position == size_)
        {
            insert(value);
        }
    }
};