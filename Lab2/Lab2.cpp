#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.utf8");
    std::string message;
    std::ifstream file;       // поток для чтения
    file.open("address_o.csv"); // окрываем файл для чтения
    for (file >> message; !file.eof(); file >> message) {
        cout << message << "\n";
        //cout << endl;
    }
}
