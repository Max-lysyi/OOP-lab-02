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
    void setAge(int newAge) ;
    void setNationality(string newNationality);
    void setVisaStatus(bool newVisaStatus);
    void setBalance(int newBalance);

    
        
    void to_pay(Tourist client);
    
    
    void book_trip(Tourist client);

    void top_up_account(Tourist client);
    
    
    void select_day(Tourist client) ;
    void create_visa(Tourist client) ;
    
};

class TravelAgency {
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

    Tourist register_tourist() ;
    
    void write_in_file(Tourist tourest_array[]) ;
    
    void get_out_of_file(Tourist tourest_array[]) ;
    void sort_random_ages() ;

};

