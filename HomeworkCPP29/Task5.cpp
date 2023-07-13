// Задача 5
// Дефинирайте макрос, който може да бъде използван в тялото на клас за да забрани копиране,
// присвояване и move на обекти от типа.

#define FORBID_COPY_AND_MOVE(className) className(const className &) = delete; \
    className(className &&) = delete;
#include<utility>
class Klass
{
private:
    
public:
    Klass(){};
    FORBID_COPY_AND_MOVE(Klass);
    ~Klass();
};

int main(int argc, char const *argv[])
{
    Klass k;
    Klass z;
    // k= z; 
    // k = std::move(z); 
    return 0;
}


