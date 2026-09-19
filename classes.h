#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Tourist
{
private:
    string first_name;
    string last_name;
    int age;
    string nationality;
    bool visa_status = false;
    int balance = 0;

public:
    string selected_cantry;
    bool ready_to_select_day;
    int total_sum;

    string getFirstName();
    string getLastName();
    int getAge();
    string getNationality();
    bool getVisaStatus();
    int getBalance();

    void setFirstName(string newName);
    void setLastName(string newLastName);
    void setAge(int newAge);
    void setNationality(string newNationality);
    void setVisaStatus(bool newVisaStatus);
    void setBalance(int newBalance);

    void to_pay(Tourist client);

    void book_trip(Tourist client);

    void top_up_account(Tourist client);

    void select_day(Tourist client);
    void create_visa(Tourist client);
};

class TravelAgency
{
private:
    string agency_name;
    bool licensed;
    string countries[20];
    bool is_open;
    string main_phone_number;

public:
    string main_email_address;
    Tourist current_client;
    string CEO;

    Tourist register_tourist();

    void write_in_file(Tourist tourest_array[]);

    void get_out_of_file(Tourist tourest_array[]);
    void sort_random_ages();

    void order_guide() ;
};

class Guide
{
    string first_name;
    string last_name;
    int age;
    int rating;
    string info;

public:
    Guide(string first_name, string last_name, int age, int rating, string info) 
        : first_name(first_name), last_name(last_name), age(age), rating(rating), info(info) {};

    
    string getFirstName() { return first_name; }
    string getLastName() { return last_name; }
    int getAge() { return age; }
    int getRating() { return rating; }
    string getInfo() { return info; }

    
    void setFirstName(string newName) { first_name = newName; }
    void setLastName(string newLastName) { last_name = newLastName; }
    void setAge(int newAge) { age = newAge; }
    void setRating(int newRating) { rating = newRating; }
    void setInfo(string newInfo) { info = newInfo; }
};

class Contract
{
    string association_name;
    Tourist *tourist_group;
    int group_size;
    TravelAgency *agency;
    Guide *guide;

public:
    Contract(string name, Tourist *group, int size, TravelAgency *ag, Guide *g)
        : association_name(name), tourist_group(group), group_size(size), agency(ag), guide(g) {}

    void printContractInfo()
    {
        cout << endl;
        cout << "=======================================" << endl;
        cout << "              ДОГОВІР                   " << endl;
        cout << "======================================" << endl;
        cout << "Тип туру: " << association_name << endl;
        
        if (guide != nullptr) {
            cout << "Гід групи: " << guide->getFirstName() << " (" << guide->getInfo() << ")" << endl;
        } else {
            cout << "Гід групи: Без гіда" << endl;
        }
        
        cout << "Кількість учасників: " << group_size << endl;
        cout << "-------------------------------------" << endl;
        cout << "Учасники туру:" << endl;
        
        for (int i = 0; i < group_size; i++) {
            cout << i + 1 << ". " << tourist_group[i].getFirstName() << " " 
                 << tourist_group[i].getLastName() << ", " 
                 << tourist_group[i].getAge() << " років (" 
                 << tourist_group[i].getNationality() << ")" << endl;
        }
        
        cout << "--------------------------------------" << endl;
        cout << "Загальна сума до оплати: " << tourist_group[0].total_sum << "$" << endl;
        cout << "======================================" << endl;
    }
};