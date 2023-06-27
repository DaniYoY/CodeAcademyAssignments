// Задача 02
// Напишете клас FileHandler, който държи отворен файл, докато съществува и го затваря
// автоматично при унищожаване. С цел упражение, не използвайте smart pointers.
// ● Забранете операциите за присвояване и копиране
// ● Дефинирайте copy control операции за move и swap.
// ● Дефинирайте методи за принтиране и промяна на съдържанието на отворения
// файл

#include<iostream>
#include<fstream>
#include<string>

class FileHandler
{
private:
    std::string filePath;
    std::fstream file;
    void tryOpeningFile(){
             try
        {
            file.open(filePath);
            while (!file.eof())
            {
                file.get();
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "File hasn't opened" << '\n';
        } 
    };
public:
    FileHandler() : filePath{""}, file{} {
        tryOpeningFile();
    };
    FileHandler(const std::string& path) : filePath{path}, file{} {
        tryOpeningFile();
    };
    FileHandler(FileHandler&& obj) noexcept : filePath{std::move(obj.filePath)}, file{std::move(obj.file)}{
        tryOpeningFile();
    };
    FileHandler(const FileHandler&) = delete;

    void swap(FileHandler obj1, FileHandler obj2){
        auto temp = std::move(obj1);
        obj1 = std::move(obj2);
        obj2 = std::move(temp);
    }
    void printContent(){
        std::string line{""};
        while (!std::getline(file, line).eof())
        {
            std::cout << line << std::endl;
        }
    };
    void changeContent(){
        std::string line{""};
        std::cin >> line;
        file.app;
        file << line;
    };
    FileHandler& operator=(FileHandler&& obj) noexcept{
        file = std::move(obj.file);
        return *this;
    };
 
    FileHandler& operator=(const FileHandler&) = delete;
    ~FileHandler(){
        file.close();
    };
};

