// Задача 09
// Имплементирайте итератор-типове за List класа от предходната задача, заедно със съответните членове на list,
// които работят с итератори.

template <typename T>
class List
{
    struct Node
    {
        explicit Node(const T &data, Node *next = nullptr,Node *prev = nullptr)
            : data_{data}, next_{next}, prev_{prev} {}
        explicit Node(T &&data, Node *next = nullptr, Node *prev = nullptr)
            : data_(std::move(data)), next_{next}, prev_{prev} {}
        T data_;
        Node *next_;
        Node *prev_;
    };
    class iterator
    {
    public:
        using value_type = List::value_type;
        using difference_type = List::difference_type;
        using reference = List::reference;
        using pointer = List::pointer;
        iterator() : ptr_{nullptr} {};
        iterator(T *ptr) : ptr_{ptr} {};

    private:
        T *ptr_;
    };

    size_t size = 0;
    Node *head_ = nullptr;
    Node *tail_ = nullptr;

public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using const_pointer = const T *;
    List() = default;
    
  
    void push_front(const_reference value)
    {
        Node* newNode = new Node(value, head_);
        if (head_)
        {
            head_->prev_ = newNode;
            head_ = newNode
        }else{
            head_ = newNode;
            tail_ = newNode;
        }
       
    }
    void push_front(T &&value)
    {
        Node* newNode = new Node(std::move(value), head_);
        if (head_)
        {
            head_->prev_ = newNode;
            head_ = newNode
        }else{
            head_ = newNode;
            tail_ = newNode;
        }
    }
    void push_back(const T &value)
    {
        Node *newNode = new Node(value, nullptr, tail_);
        if (tail_)
        {
            tail_->next_ = newNode;
            tail_ = newNode
        }else{
            if (!head_)
            {
                head_ = newNode;            
            }
            tail_ = newNode;
            
        }
    }
    void push_back(T &&value)
    {
        Node *newNode = new Node(std::move(value), nullptr, tail_);
   if (tail_)
        {
            tail_->next_ = newNode;
            tail_ = newNode
        }else{
            if (!head_)
            {
                head_ = newNode;            
            }
            tail_ = newNode; 
        }
    }

    void pop_front()
    {
        if(!head_->prev_){
            head_ = head_->next_;
            delete head_->prev_;
            head_->prev_ = nullptr;
        }
    }
    void pop_back()
    {
        if(!tail_->next_){
            tail_ = tail_->prev_;
            delete tail_->next_;
            tail_->next_ = nullptr;
        }
    }
};