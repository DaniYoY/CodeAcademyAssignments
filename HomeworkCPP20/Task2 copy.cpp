// Задача 02
// Напишете таймер клас, който да може да приема callback callable и да го извиква след опеределено време.
// Класа трябва да има следните методи:
// ● Функция за стартиране на обратното броене, която приема callable и време, което да отброи.
// ● Функция Update, в която се проверява дали времето е изтекло и ако е - извиква callback-a.

#include <iostream>
#include <memory>
#include <functional>
#include <chrono>
#include <thread>
class Timer
{
private:
    std::chrono::time_point<std::chrono::system_clock> timeOfInit;
    std::chrono::time_point<std::chrono::system_clock> timeOfStart;
    int m_a{0};
    int m_b{0};
    std::function<int(int, int)> fun;

    std::chrono::time_point<std::chrono::system_clock> setNow()
    {
        return std::chrono::system_clock::now();
    }

    double getDuration()
    {
        std::chrono::duration<double> time = timeOfStart - timeOfInit;
        return time.count();
    }

public:
    Timer()
    {
        timeOfInit = setNow();
    };
    // Timer(int a, int b) : m_a{a}, m_b{b}
    // {
    //     timeOfInit = setNow();
    // };
    Timer(int a = 0, int b = 0, std::function<int(int, int)> func = 0) : m_a{a}, m_b{b}, fun{func}
    {
        timeOfInit = setNow();
    };
    void getSimpleMathFunction(int (*func)(int a, int b), int secondsDelay)
    {
        timeOfStart = setNow();
        if (getDuration() >= secondsDelay)
        {
            std::cout << func(m_a, m_b) << std::endl;
        }
    }
    void update(int secondsDelay)
    {
        timeOfStart = setNow();
        if (getDuration() >= secondsDelay)
        {
            std::cout << this->fun(m_a, m_b) << std::endl;
        }
    }

    void updateAuto(int secondsDelay)
    {
        while (getDuration() >= secondsDelay)
        {
            timeOfStart = setNow();
        }
        std::cout << this->fun(m_a, m_b) << std::endl;
    }
    ~Timer(){};
};

int sum(int a, int b)
{
    return a + b;
}
int multiply(int a, int b)
{
    return a * b;
}
int main(int argc, char const *argv[])
{
    std::shared_ptr<Timer> p1 = std::make_shared<Timer>(5, 4);
    (*p1).getSimpleMathFunction(sum, 5);
    (*p1).getSimpleMathFunction(multiply, 10);
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    (*p1).getSimpleMathFunction(sum, 5);
    (*p1).getSimpleMathFunction(multiply, 10);

    std::cout << "P2 testing" << std::endl;
    std::shared_ptr<Timer> p2 = std::make_shared<Timer>(5, 5, sum);
    (*p2).update(5);
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    (*p2).update(5);

    std::cout << "P3 testing" << std::endl;
    std::shared_ptr<Timer> p3 = std::make_shared<Timer>(5, 6, multiply);
    (*p3).updateAuto(5);
    return 0;
}
