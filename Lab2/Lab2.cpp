#include <iostream>
#include <string>
#include <fstream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.utf8");
    string message;
    ifstream file; 
    file.open("address_o.csv");
    if (file.is_open())
    {
        while (getline(file, message))
        {
            cout << message << endl;
        }
    }
    file.close();
}
