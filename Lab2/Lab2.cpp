#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
//s
class List
{
private:
    class list_of_towns
    {
    private:
        class list_of_first_symbol
        {
        private:
            class list_of_streets
            {
            private:
                class list_of_type_homes
                {
                public:
                    string count;
                    string type;
                    int counters;
                    list_of_type_homes* next_type;
                    list_of_type_homes(string& new_type, string& new_count)
                    {
                        counters = 0;
                        count = new_count;
                        type = new_type;
                        next_type = nullptr;
                    }
                };
                list_of_type_homes* first_type;
            public:
                string street;
                list_of_streets* next_street;
                list_of_streets(string& new_street)
                {
                    street = new_street;
                    first_type = nullptr;
                    next_street = nullptr;
                }

                void print_all_types()
                {
                    list_of_type_homes* start = first_type;
                    cout << start->type << "|" << start->count << " " << "request: " << start->counters << endl;
                }

                void insert_new_type(string& new_type, string& new_home)
                {
                    if (first_type == nullptr)
                    {
                        list_of_type_homes* start = new list_of_type_homes(new_type, new_home);
                        first_type = start;
                    }
                    else
                    {
                        list_of_type_homes* start = first_type;
                        while (start->next_type != nullptr and start->type != new_type)
                        {
                            start = start->next_type;
                        }
                        if (start->type == new_type)
                        {
                            start->counters += 1;
                        }
                        else
                        {
                            list_of_type_homes* real_new_street = new list_of_type_homes(new_type, new_home);
                            start->next_type = real_new_street;
                        }
                    }
                }
            };
            list_of_streets* first_street;
        public:
            char symbol;
            list_of_first_symbol* next_symbol;
            list_of_first_symbol(char& new_symbol)
            {
                first_street = nullptr;
                symbol = new_symbol;
                next_symbol = nullptr;
            }

            void print_all_streets()
            {
                list_of_streets* start = first_street;
                while (start != nullptr)
                {
                    cout << start->street << "|";
                    start->print_all_types();
                    cout << endl;
                    start = start->next_street;
                }
            }

            void insert_new_street(string& new_street, string& new_type, string& new_home)
            {
                if (first_street == nullptr)
                {
                    list_of_streets* start = new list_of_streets(new_street);
                    first_street = start;
                    start->insert_new_type(new_type, new_home);
                }
                else
                {
                    list_of_streets* start = first_street;
                    while (start->next_street != nullptr and start->street != new_street)
                    {
                        start = start->next_street;
                    }
                    if (start->street == new_street)
                    {
                        start->insert_new_type(new_type, new_home);
                    }
                    else
                    {
                        list_of_streets* real_new_street = new list_of_streets(new_street);
                        start->next_street = real_new_street;
                        real_new_street->insert_new_type(new_type, new_home);
                    }
                }
            }
        };
        list_of_first_symbol* first_symbol;
    public:
        string town;
        list_of_towns* next_town;
        list_of_towns(string& new_town)
        {
            first_symbol = nullptr;
            town = new_town;
            next_town = nullptr;
        }

        void print_all_symbols()
        {
            list_of_first_symbol* start = first_symbol;
            while (start != nullptr)
            {
                cout << start->symbol << "|";
                start->print_all_streets();
                cout << endl;
                start = start->next_symbol;
            }
        }

        void insert_new_symbol(string& new_street, string& new_type, string& new_home)
        {
            char new_symbol = new_street.at(1);
            if (first_symbol == nullptr)
            {
                list_of_first_symbol* start = new list_of_first_symbol(new_symbol);
                first_symbol = start;
                start->insert_new_street(new_street, new_type, new_home);
            }
            else
            {
                list_of_first_symbol* start = first_symbol;
                while (start->next_symbol != nullptr and start->symbol != new_symbol)
                {
                    start = start->next_symbol;
                }
                if (start->symbol == new_symbol)
                {
                    start->insert_new_street(new_street, new_type, new_home);
                }
                else
                {
                    list_of_first_symbol* real_new_symbol = new list_of_first_symbol(new_symbol);
                    start->next_symbol = real_new_symbol;
                    real_new_symbol->insert_new_street(new_street, new_type, new_home);
                }
            }
        }
    };
    list_of_towns* first_town;
public:
    List()
    {
        first_town = nullptr;
    }

    void print_all_list()
    {
        list_of_towns* start = first_town;
        while (start != nullptr)
        {
            cout << start->town << endl;
            start->print_all_symbols();
            cout << endl;
            start = start->next_town;
        }
    }

    void insert_new_town(string& new_town, string& new_street, string& new_type, string& new_home)
    {
        if (first_town == nullptr)
        {
            list_of_towns* start = new list_of_towns(new_town);
            first_town = start;
            start->insert_new_symbol(new_street, new_type, new_home);
        }
        else
        {
            list_of_towns* start = first_town;
            while (start->next_town != nullptr and start->town != new_town)
            {
                start = start->next_town;
            }
            if (start->town == new_town)
            {
                start->insert_new_symbol(new_street, new_type, new_home);
            }
            else
            {
                list_of_towns* real_new_town = new list_of_towns(new_town);
                start->next_town = real_new_town;
                real_new_town->insert_new_symbol(new_street, new_type, new_home);
            }
        }
    }
};

vector<string> string_to_vector(string& message) {
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
    List spisok;
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
            spisok.insert_new_town(matrix[0], matrix[1], matrix[2], matrix[3]);
        }
    }
    file.close();
    spisok.print_all_list();
}
