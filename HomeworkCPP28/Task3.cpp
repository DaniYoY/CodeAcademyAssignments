// Задача 03
// Дефинирайте template клас Point2d за работа с точки/вектори в равнината. 
// Трябва да можем да имаме точки с различни типове за координатите: float, double, int, ..

template <class T> class Point2d{
    T x;
    T y;
public:
    Point2d() : x{0}, y{0} {};
};

