// Задача 04
// Напишете нова версия на FileHandler-а от Задача 02, която използва unique_ptr за
// автоматичната деалокация на ресурса (затваряне на файла)

#include<memory>
#include<iostream>
#include<fstream>
#include<string>

class FileHandler
{
private:
    std::unique_ptr<std::string> filePath;
    std::unique_ptr<std::fstream> file;
    void tryOpeningFile(){
             try
        {
            (*file).open(*filePath);
            while (!(*file).eof())
            {
                (*file).get();
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "File hasn't opened" << '\n';
        } 
    };
public:
    FileHandler() : filePath{std::unique_ptr<std::string>(new std::string)}, file{std::unique_ptr<std::fstream>(new std::fstream)} {
        tryOpeningFile();
    };
    FileHandler(const std::string& path) :  filePath{std::unique_ptr<std::string>(new std::string(path))}, file{std::unique_ptr<std::fstream>(new std::fstream)} {
        tryOpeningFile();
    };
    FileHandler(FileHandler&& obj) noexcept : filePath{std::unique_ptr<std::string>(obj.filePath.release())}, file{std::unique_ptr<std::fstream>(obj.file.release())}{
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
        while (!std::getline(*file, line).eof())
        {
            std::cout << line << std::endl;
        }
    };
    void changeContent(){
        std::string line{""};
        std::cin >> line;
        (*file).app;
        *file << line;
    };
    FileHandler& operator=(FileHandler&& obj) noexcept{
        file = std::move(obj.file);
        return *this;
    };
 
    FileHandler& operator=(const FileHandler&) = delete;
    ~FileHandler(){
    };
};
