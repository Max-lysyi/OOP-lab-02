#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "classes.cpp"

using namespace std;

int main()
{
    TravelAgency main_agency;
    Tourist tourest_array[5];

    Tourist *term_tourist_array = new Tourist[5];

    Tourist *ptr = &tourest_array[1];

    cout << "Доброго дня! Чим можу допомогти?" << endl;

    Guide guide_array[3] = {
        Guide("Артем", "Попов", 24, 7, "Альпініст, знає Непал, Добре розбирається в стародавній історії"),
        Guide("Нікіта", "Олешко", 67, 9, "Добре знає арабсюку культуру"),
        Guide("Іван", "Кухар", 37, 8, "Знавець української культури"),

    };
    // Guide g1("Артем (Експерт з Непалу)");
    // Guide g2("Нікіта (Бізнес-гід Дубай)");
    // Guide g3("Іван (Гід по Сатанову)");

    // Tourist nepal_group[2];
    // nepal_group[0].setFirstName("Олег");
    // nepal_group[1].setFirstName("Максим");

    // Tourist dubai_group[2];
    // dubai_group[0].setFirstName("Ігор");
    // dubai_group[1].setFirstName("Андрій");

    // Tourist sataniv_group[3];
    // sataniv_group[0].setFirstName("Анна");
    // sataniv_group[1].setFirstName("Олена");
    // sataniv_group[2].setFirstName("Світлана");

    // Contract alpinists("Асоціація альпіністів (Непал)", nepal_group, 2, &main_agency, &g1);
    // Contract businessmen("Асоціація добросовісних бізнесменів (Дубай)", dubai_group, 2, &main_agency, &g2);
    // Contract students("Студентська туристична спілка (Сатанів)", sataniv_group, 3, &main_agency, &g3);

    // alpinists.printContractInfo();
    // businessmen.printContractInfo();
    // students.printContractInfo();

    while (true)
    {

        cout << "1. Зареєструвати акаунт " << endl;
        cout << "2. Замовити путівку " << endl;
        cout << "3. Поповнити рахунок " << endl;
        cout << "4. Записати в файл користувача " << endl;
        cout << "5. Зчитати файл зі всіма користувачами " << endl;
        cout << "6. Завершити роботу " << endl;
        cin >> selected_option;

        switch (selected_option)
        {
        case 1:

            tourest_array[tourist_count] = main_agency.register_tourist();
            tourist_count++;
            cout << "Реєстрація успішна!" << endl;
            break;
        case 2:
        {
            if (tourest_array[0].getFirstName() == "")
            {
                cout << "Ви ще не створили обліковий запис! Спочатку оберіть пункт 1." << endl;
                break; 
            }

            cout << "Як ви бажаєте подорожувати?" << endl;
            cout << "1. Сам" << endl;
            cout << "2. З групою" << endl;
            int trip_type;
            cin >> trip_type;

            int people_count = 1;
            if (trip_type == 2)
            {
                cout << "Скільки людей у вашій групі (включно з вами)?" << endl;
                cin >> people_count;
                cout << "Чудово, оформлюємо тур для " << people_count << " осіб." << endl;
            }

            Tourist *current_group = new Tourist[people_count];
            
            current_group[0] = tourest_array[0];

            if (people_count > 1) {
                cout << "--- Реєстрація інших учасників туру ---" << endl;
                for (int i = 1; i < people_count; i++) {
                    cout << "Введіть дані для учасника #" << i + 1 << ":" << endl;
                    current_group[i] = main_agency.register_tourist();
                }
            }

            cout << "Чи бажаєте замовити гіда? (Так/Ні)" << endl;
            cin >> YesNo;

            Guide *chosen_guide = nullptr;
            int guide_price = 0;

            if (YesNo == "Так" || YesNo == "так")
            {
                cout << "Доступні гіди:" << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << "--- " << i + 1 << " ---" << endl;
                    cout << "Ім'я: " << guide_array[i].getFirstName() << endl;
                    cout << "Прізвище: " << guide_array[i].getLastName() << endl;
                    cout << "Вік: " << guide_array[i].getAge() << endl;
                    cout << "Рейтинг: " << guide_array[i].getRating() << "/10" << endl;
                    cout << "Додаткова інформація: " << guide_array[i].getInfo() << endl;
                    cout << endl;
                }
                
                cout << "Оберіть номер гіда (1-3): ";
                int guide_choice;
                cin >> guide_choice;

                if (guide_choice >= 1 && guide_choice <= 3)
                {
                    chosen_guide = &guide_array[guide_choice - 1];
                    guide_price = 500;
                    current_group[0].total_sum += guide_price;
                    cout << "Гіда " << chosen_guide->getFirstName() << " успішно додано! До вартості додано 500$." << endl;
                }
            }

            cout << "--- Оформлення напрямку та деталей ---" << endl;
            current_group[0].book_trip(current_group[0]);

            if (people_count > 1)
            {
                int cost_per_person = current_group[0].total_sum - guide_price;
                current_group[0].total_sum = (cost_per_person * people_count) + guide_price;
                cout << "Загальна вартість для групи з " << people_count << " осіб становить: " << current_group[0].total_sum << "$" << endl;
            }

            string contract_name = (trip_type == 2) ? "Груповий туристичний договір" : "Індивідуальний туристичний договір";
            Contract final_contract(contract_name, current_group, people_count, &main_agency, chosen_guide);
            
            final_contract.printContractInfo();

            tourest_array[0] = current_group[0];

            break;
        }
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
            cout << endl
                 << "До скорої зустрічі " << endl
                 << endl;
            delete[] term_tourist_array;
            return 0;

            break;
        default:
            cout << "Ви ввели неправильне значення." << endl;
            break;
        }
    }
}