#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include<iostream>
#include<string>
#include<fstream>

class FileHandler
{
    private:
        std::string m_filename;
        std::fstream m_file;
    public:

    explicit FileHandler(const std::string & filename, std::ios_base::openmode mode = std::ios::in) : m_filename{filename}
    {
        try
        {
            m_file.open(filename, std::fstream::in | std::fstream::out | mode);
            if (!m_file)
            {
                throw std::invalid_argument("file is not open, Check the file, it may not be found");
            }
            std::cout << filename << " is opened\n";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        } 
    }

    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
    ~FileHandler()
    {
        m_file.close();
        std::cout << m_filename << " is closed\n";
    }

    std::fstream & get(){
        return m_file;
    }
};
#endif