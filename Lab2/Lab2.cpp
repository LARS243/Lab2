#include <iostream>
#include <string>
#include <fstream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    std::string message;
    std::ifstream file;       // поток для чтения
    file.open("address_o.csv"); // окрываем файл для чтения
    for (file >> message; !file.eof(); file >> message) {
        cout << message << "\n";
    }
}
