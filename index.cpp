#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "classes.cpp"

using namespace std;



int main() {
    TravelAgency main_agency;
    Tourist tourest_array[5];

    Tourist* term_tourist_array = new Tourist[5];

    Tourist* ptr = &tourest_array[1];
    

    
    cout << "Доброго дня! Чим можу допомогти?" << endl;
    while (true)
    {
        
    cout << "1. Зареєструвати акаунт " << endl;
    cout << "2. Замовити путівку " << endl;
    cout << "3. Поповнити рахунок " << endl;
    cout << "4. Записати в файл користувача " << endl;
    cout << "5. Зчитати файл зі всіма користувачами " << endl;
    cout << "6. Завершити роботу " << endl;
    cin >> selected_option;

    switch (selected_option) {
        case 1:
            
            tourest_array[tourist_count] = main_agency.register_tourist();
            tourist_count++;
            cout << "Реєстрація успішна!" << endl;
            break;
        case 2:
            
                tourest_array[0].book_trip(tourest_array[0]);
            
            break;
        case 3:
        
            tourest_array[0].top_up_account(tourest_array[0]);
        break;
        case 4:
            main_agency.write_in_file(tourest_array);
            
        break;
        case 5:
            main_agency.get_out_of_file(tourest_array);
        break;
        case 6:
            cout << endl << "До скорої зустрічі " << endl << endl;
            delete[] term_tourist_array;
            return 0;
            
        break;
        default:
            cout << "Ви ввели неправильне значення." << endl;
            break;
    }
    
    }
    
    
}