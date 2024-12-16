#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
//s
class list
{
private:
    class data_of_list
    {
    public:
        string town;
        string street;
        string number_of_house;
        string type_of_house;
        data_of_list* next_data;
        int counter;
        data_of_list(string town_for_write, string street_for_write, string number_of_houses_for_write, string type_of_houses_for_write)
        {
            town = town_for_write;
            street = street_for_write;
            number_of_house = number_of_houses_for_write;
            type_of_house = type_of_houses_for_write;
            next_data = nullptr;
            counter = 0;
        }
    };
    data_of_list* first_element;
public:
    list()
    {
        first_element = nullptr;
    }
    void insert_town(string town, string street, string number_of_house, string type_of_house)
    {
        if (first_element == nullptr)
        {
            data_of_list* start = new data_of_list(town, street, number_of_house, type_of_house);
            first_element = start;
        }
        else
        {
            data_of_list* start = first_element;
            while (start->next_data != nullptr)
            {
                if (start->town == town and start->street == street and start->type_of_house == type_of_house and start->town == town)
                {
                    start->counter += 1;
                    return;
                }
                else
                {
                    start = start->next_data;
                }
            }
            data_of_list* new_town = new data_of_list(town, street, number_of_house, type_of_house);
            start->next_data = new_town;
        }
    }
    void print_all_list()
    {
        data_of_list* start = first_element;
        while (start->next_data != nullptr)
        {
            if (start->counter > 0)
            {
                cout << start->town << "|" << start->street << "|" << start->number_of_house << "|" 
                    << start->type_of_house << "| Повторений: " << start->counter+1;
            }
        }
    }
};

vector<string> string_to_vector(string message) {
    vector<string> matrix;
    int counter = 0;
    int ln = message.length();
    string new_object = "";
    string point_with_sealed = ";";
    for (int i = 0; i < ln; i++) {
        if (message[i] == point_with_sealed[0]) {
            matrix.push_back(new_object);
            new_object = "";
        }
        else {
            new_object += message[i];
        }
    }
    matrix.push_back(new_object);
    return matrix;
}

int main()
{
    list spisok;
    setlocale(LC_ALL, "ru_RU.utf8");
    string message;
    vector<string> matrix;
    ifstream file; 
    file.open("address_o.csv");
    if (file.is_open())
    {
        while (getline(file, message))
        {
            matrix = string_to_vector(message);
            spisok.insert_town(matrix[0], matrix[1], matrix[2], matrix[3]);
        }
    }
    file.close();
    spisok.print_all_list();
}
