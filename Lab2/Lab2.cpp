#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class list
{
private:
    class data_of_list
    {
    public:
        string town;
        string street;
        int number_of_house;
        int type_of_house;
        data_of_list* next_data;
        data_of_list(string town_for_write, string street_for_write, int number_of_houses_for_write, int type_of_houses_for_write)
        {
            town = town_for_write;
            street = street_for_write;
            number_of_house = number_of_houses_for_write;
            type_of_house = type_of_houses_for_write;
            next_data = nullptr;
        }
    };
    data_of_list* first_element;
public:
    list()
    {
        first_element = nullptr;
    }
    void insert_town(string town, string street, int number_of_house, int type_of_house)
    {
        if (first_element == nullptr)
        {
            data_of_list* start = new data_of_list(town, street, number_of_house, type_of_house);
            first_element = start;
        }
        else
        {
            data_of_list* start = first_element;
            data_of_list* new_town = new data_of_list(town, street, number_of_house, type_of_house);
            while (start->next_data != nullptr)
            {
                start = start->next_data;
            }
            start->next_data = new_town;
        }
    }
};

vector<string> string_to_vector(string message) {
    int counter = 0;
    int ln = message.length();

}

int main()
{
    list spisok;
    setlocale(LC_ALL, "ru_RU.utf8");
    string message;
    ifstream file; 
    file.open("address_o.csv");
    if (file.is_open())
    {
        while (getline(file, message))
        {
            spisok.insert_town("", "", 0, 0);
            std::cout << message << std::endl;
        }
    }
    file.close();
}
