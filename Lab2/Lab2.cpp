#include <iostream>
#include <string>
#include <fstream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.utf8");
    std::string message;
    std::ifstream file;       // поток для чтения
    file.open("address_o.csv"); // окрываем файл для чтения
    if (file.is_open())
    {
        while (std::getline(file, message))
        {
            std::cout << message << std::endl;
        }
    }
    file.close();     // закрываем файл
}
