#include "classes.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

string YesNo;

int selected_option = 0;

int tourist_count = 0; 


string Tourist::getFirstName() {
    return first_name;
}

string Tourist::getLastName() {
    return last_name;
}

int Tourist::getAge() {
        return age;
    }
    string Tourist::getNationality() {
        return nationality;
    }
    bool Tourist::getVisaStatus(){
        return visa_status;
    }
    int Tourist::getBalance() {
        return balance;
    }

    void Tourist::setFirstName(string newName) {
        first_name = newName;
    }
    void Tourist::setLastName(string newLastName) {
        last_name = newLastName;
    }
    void Tourist::setAge(int newAge) {
        age = newAge;
    }
    void Tourist::setNationality(string newNationality) {
        nationality = newNationality;
    }
    void Tourist::setVisaStatus(bool newVisaStatus) {
        visa_status = newVisaStatus;
    }
    void Tourist::setBalance(int newBalance) {
        balance = newBalance;
    }

    
        
    void Tourist::to_pay(Tourist client) {
        cout << endl << "До сплати " << client.total_sum << ". Готові сплатити? (Так/Ні)" << endl;

        cin >> YesNo;
        if (YesNo == "")
        {
            if (balance <= client.total_sum)
            {
                cout << "Недостатньо коштів на рахунку" << endl;
                return;
            }
            
            balance -= client.total_sum;
            cout << "Дякую що обираєте нас)" << endl;
        } else if (YesNo == "No")
        {
            return;
        }
        
        
    }

    void Tourist::top_up_account(Tourist client) {
        int balance;
        cout << "Введіть суму коштів на яку хочете поповнити рахунок" << endl;

        cin >> balance;

        client.setBalance(balance);
        cout << "Ваш рахунок був поповнений" << endl;

    }
    
    
    void Tourist::book_trip(Tourist client) {
    if (client.getFirstName() == "") {
        cout << "Ви ще не створили обліковий запис!" << endl;
        return; 
    }

    cout << "Куди хочете полетіти?" << endl << "1. USA" << endl << "2. Greece" << endl << "3. Poland" << endl;
    int selected_country;
    cin >> selected_country; 

    switch (selected_country) {
        case 1: 
            client.total_sum += 1000;
            cout << "Чи хочете оформити страховий поліс за 200$? (Так/Ні)" << endl;
            cin >> YesNo;

            if (YesNo == "Так" || YesNo == "так") {
                client.total_sum += 200;
                client.create_visa(client);
                client.select_day(client);

            } else {
                client.create_visa(client);
                client.select_day(client);
            }
            
            
            
            break;
        case 2:
            client.total_sum += 2000;
            cout << "Чи хочете оформити страховий поліс за 200$? (Так/Ні)" << endl;
            cin >> YesNo;

            if (YesNo == "Так" || YesNo == "так") {
                client.total_sum += 200;
                
                client.select_day(client);
                
            } else {
                
                client.select_day(client);
            }
            
            break;
            case 3:
                client.total_sum += 100;
            cout << "Чи хочете оформити страховий поліс за 200$? (Так/Ні)" << endl;
            cin >> YesNo;

            if (YesNo == "Так" || YesNo == "так") {
                client.total_sum += 200;
                client.select_day(client);
                
            } else {
                
                client.select_day(client);
            }
            
            break;
        default:
            cout << "Неправильний вибір!" << endl;
            break;
    }
}
    
    
    void Tourist::select_day(Tourist client) {
     
        cout << "Якщо ви оберете одну з цих дат поїздки, на вас чекатиме знижка" << endl;
        while (true) {
        cout << "1. 20.11.2026" << endl << "2. 31.11.2026 " << endl;
        cin >> selected_option;

        if (selected_option == 1) {
            client.total_sum -= 300;
            break; 
        } else if (selected_option == 2) {
            client.total_sum -= 100;
            break; 
        } else {
            
            cout << "Неправильно ввели відповідь. Будь ласка, введіть 1 або 2." << endl << endl;
        }
    }

        
        
    }   
    void Tourist::create_visa(Tourist client) {
        cout << "Потрібна віза. Допомогти з оформленням (+400$)? (Так/Ні)" << endl;
                cin >> YesNo;
                if (YesNo == "Так" || YesNo == "так") {
                    client.total_sum += 400;
                }
                client.setVisaStatus(true);
                
    }


    //////////////////////////////

    Tourist TravelAgency::register_tourist() {

        Tourist new_tourist;
        
        string newName;
        cout << "Введіть Ім'я: " << endl;
        cin >> newName;
        new_tourist.setFirstName(newName);
        

        string newLastName;
        cout << "Введіть прізвище:" << endl;
        cin >> newLastName;
        new_tourist.setLastName(newLastName);
        

        int newAge;
        cout << "Введіть Ваш вік: " << endl;
        cin >> newAge;
        new_tourist.setAge(newAge);


        string newNationality;
        cout << "Введіть Вашу національність: " << endl;
        cin >> newNationality;
        new_tourist.setNationality(newNationality);



        return new_tourist;
    }
    
    
    void TravelAgency::write_in_file(Tourist tourest_array[]) {

        fstream file("Tourists.txt", ios::out | ios::app);

        if (file.is_open())
        {
            for (int i = 0; i < tourist_count; i++)
            {
                file << tourest_array[i].getFirstName() << " " << tourest_array[i].getLastName() << " " << tourest_array[i].getAge() << " " << tourest_array[i].getNationality() << " " << tourest_array[i].getVisaStatus();
            }
            cout << "Туристи успішно записані в файл" << endl;
            
        }
        file.close();
        
    }
    
    void TravelAgency::get_out_of_file(Tourist tourest_array[]) {

    string first_name;
    string last_name;
    int age;
    string nationality;
    bool visa_status ;
        
        fstream file("Tourists.txt", ios::in);

        if (file.is_open())
        {
            for (int i = 0; i < tourist_count; i++)
            {
                if (file >> first_name >> last_name >> age >> nationality >> visa_status)
                {
                     tourest_array[i].setFirstName(first_name);
                     tourest_array[i].setLastName(last_name);
                     tourest_array[i].setAge(age);
                     tourest_array[i].setNationality(nationality);
                     tourest_array[i].setVisaStatus(visa_status);

                     cout << tourest_array[i].getFirstName() << " " << tourest_array[i].getLastName() << " " << tourest_array[i].getAge() << " " << tourest_array[i].getNationality() << " " << tourest_array[i].getVisaStatus() << endl;
                }
            }
            
            
        }
        file.close();
        
    }
    void TravelAgency::sort_random_ages() {
        srand(time(0));
    int n = (rand() % 15) + 5;
    int* array = new int[n];

    
    for (int i = 0; i < n; i++) {
        array[i] = (rand() % 43) + 18; 
    }

    int term_n = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] >= array[j + 1])
            {
                term_n = array[j];
                array[j] = array[j + 1];
                array[j + 1] = term_n;
            }
            
        }
    }

    
    cout << "Відсортований вік туристів: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
}
