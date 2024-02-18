#include "main.h"

class ClientOrder {
public:
    string id;
    string name;
    string surname;
    string device;
    string repairCost;
    int repair_Cost;
    int id_int;

    void inputOrderData() {

        system("cls");

        cout << "Введите имя клиента: ";
        cin >> ws;
        getline(cin, name);

        cout << "Введите Фамилию: ";
        cin >> ws;
        getline(cin, surname);

        cout << "Введите устройство: ";
        cin >> ws;
        getline(cin, device);

        cout << "Введите стоимость ремонта: ";
        cin >> repairCost;
        int repair_Cost = stoi(repairCost);
    }
    void displayClientData() const {
        cout << "Id: " << id << "\nИмя: " << name << "\nФамилия: " << surname << "\nУстройство: " << device << "\nСтоимость ремонта: " << repair_Cost << endl;
    }
};


class SystemService {
private:
    vector<ClientOrder> clients;

public:
    void showMenu() {
        cout << "===== Меню =====\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Просмотреть список клиентов\n";
        cout << "3. Сортировка по имени (А->Я)\n";
        cout << "4. Сортировка по устройству\n";
        cout << "5. Сортировка по стоимости ремонта\n";
        cout << "6. Заказ готов (удалить заявку)\n";
        cout << "7. Выход\n";
    }
    void addClient() {
        loadFromFile();

        ClientOrder newClient;

        newClient.inputOrderData();

        int id_int;
        if (clients.empty()) {
            newClient.id = "1";
        }
        else {
            auto& id_string = clients[clients.size() - 1].id;
            id_int = stoi(id_string);
            id_int++;
            newClient.id = to_string(id_int);
        }

        clients.push_back(newClient);

        saveToFile();

        cout << "Клиент добавлен!\n\n";
    }

    void displayClients() {
        system("cls");
        loadFromFile();

        if (clients.empty()) {
            cout << "Список клиентов пуст.\n";
            return;
        }

        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
            client.displayClientData();
            cout << "-----------------\n";
        }
    }

    void sortClientsByNameMax() {
        system("cls");

        loadFromFile();

        if (clients.empty()) {
            cout << "Список клиентов пуст.\n";
            return;
        }

        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
        }


        // insert sort
        int j;
        string buff;

        int n = clients.size();

        for (int i = 1; i < n; i++)
        {
            if (clients[i - 1].name > clients[i].name) {
                buff = clients[i].name;
                j = i - 1;
                while (j >= 0 && clients[j].name > buff)
                {
                    clients[j + 1].name = clients[j].name;
                    j--;
                }
                clients[j + 1].name = buff;
            }
        }

        cout << "Список клиентов отсортирован по имени(А->Я).\n";
        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
            client.displayClientData();
            cout << "-----------------\n";
        }
    }

    void sortClientsByNameMin() {
        system("cls");

        loadFromFile();

        if (clients.empty()) {
            cout << "Список клиентов пуст.\n";
            return;
        }

        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
        }


        // insert sort
        int j;
        string buff;

        int n = clients.size();

        for (int i = 1; i < n; i++)
        {
            if (clients[i - 1].name > clients[i].name) {
                buff = clients[i].name;
                j = i - 1;
                while (j >= 0 && clients[j].name < buff)
                {
                    clients[j + 1].name = clients[j].name;
                    j--;
                }
                clients[j + 1].name = buff;
            }
        }

        cout << "Список клиентов отсортирован по имени(А->Я).\n";
        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
            client.displayClientData();
            cout << "-----------------\n";
        }
    }

    void sortClientsByDevice() {
        system("cls");
        loadFromFile();

        if (clients.empty()) {
            cout << "Список клиентов пуст.\n";
            return;
        }

        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
        }

        // buuble sort with flag
        bool swapped;
        int n = clients.size();
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (clients[j].device < clients[j + 1].device) {
                    swap(clients[j], clients[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
        cout << "Список клиентов отсортирован по девайсам.\n";
        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
            client.displayClientData();
            cout << "-----------------\n";
        }
    }

    void sortClientsByRepairCostMax() {
        system("cls");
        loadFromFile();

        if (clients.empty()) {
            cout << "Список клиентов пуст.\n";
            return;
        }

        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
        }

        // buuble sort with flag
        bool swapped;
        int n = clients.size();
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (clients[j].repair_Cost < clients[j + 1].repair_Cost) {
                    swap(clients[j], clients[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
        cout << "Список клиентов отсортирован по стоимости ремонта(max->min).\n";
        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
            client.displayClientData();
            cout << "-----------------\n";
        }
    }

    void sortClientsByRepairCostMin() {
        system("cls");
        loadFromFile();

        if (clients.empty()) {
            cout << "Список клиентов пуст.\n";
            return;
        }

        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
        }

        // choise sort
        int temp;
        int n = clients.size();

        for (int i = 0; i < n - 1; i++)
        {
            int eMin = i;
            for (int j = i + 1; j < n; j++)
            {
                if (clients[j].repair_Cost < clients[eMin].repair_Cost) {
                    eMin = j;
                }
            }
            temp = clients[i].repair_Cost;
            clients[i].repair_Cost = clients[eMin].repair_Cost;
            clients[eMin].repair_Cost = temp;
        }


        cout << "Список клиентов отсортирован по стоимости ремонта(min->max).\n";
        for (auto& client : clients) {
            int temp = stoi(client.repairCost);
            client.repair_Cost = temp;
            client.displayClientData();
            cout << "-----------------\n";
        }
    }

    void DeleteTask() {
        loadFromFile();
        system("cls");
        cout << "Введите id заказа для удаления: ";
        fstream file("Orders.txt", ios::in | ios::out);
        ofstream tempFile("temp.txt");

        string choice_string;

        cin >> choice_string;

        string line;
        for (auto& client : clients) {
            if (client.id == choice_string) {
                string lineToDelete = client.id + "," + client.name + "," + client.surname + "," + client.device + "," + client.repairCost;
                while (getline(file, line))
                {
                    if (line != lineToDelete)
                    {
                        tempFile << line << endl;
                    }
                }
            }
        }

        file.close();
        tempFile.close();
        remove("Orders.txt");
        rename("temp.txt", "Orders.txt");
        cout << "Удаление завершено успешно!\n";
    }

    void saveToFile() const {
        string filename = "Orders.txt";

        ofstream file(filename);
        if (file.is_open()) {
            for (auto& client : clients) {
                file << client.id << "," << client.name << "," << client.surname << "," << client.device << "," << client.repairCost << "\n";
            }
            cout << "Данные сохранены в файл.\n";
        }
        else {
            cerr << "Не удалось открыть файл для записи.\n";
        }
    }

    void loadFromFile() {
        string filename = "Orders.txt";

        clients.clear();
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                ClientOrder client;
                istringstream iss(line);
                getline(iss, client.id, ',');
                getline(iss, client.name, ',');
                getline(iss, client.surname, ',');
                getline(iss, client.device, ',');
                iss >> client.repairCost;
                clients.push_back(client);
            }
            cout << "Данные загружены из файла.\n";
        }
        else {
            cerr << "Не удалось открыть файл для чтения.\n";
        }
    }
};



int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    SystemService system_;

    bool menuBool = true;
    int choice, choice_r;

    int counter = 0;

    while (menuBool) {
        if (counter >= 3) {
            system("cls");
            counter = 0;
        }
        string choice, choice_;

        system_.showMenu();
        cout << "Введите номер действия: ";

        cin >> choice;


        try {
            int number_ch = stoi(choice);

            switch (number_ch) {
            case 1:
                system_.addClient();
                break;
            case 2:
                system_.displayClients();
                break;
            case 3:
                cout << "1. Сортировать от А к Я\n";
                cout << "2. Сортировать от Я к А\n";
                cout << "Введите номер действия: ";
                cin >> choice_;
                choice_r = stoi(choice_);
                if (choice_r == 1) {
                    system_.sortClientsByNameMax();
                }
                else if (choice_r == 2) {
                    system_.sortClientsByNameMin();
                }

                break;
            case 4:
                system_.sortClientsByDevice();
                break;
            case 5:
                cout << "1. Сортировать от min к max\n";
                cout << "2. Сортировать от max к min\n";
                cout << "Введите номер действия: ";
                cin >> choice_;
                choice_r = stoi(choice_);
                if (choice_r == 1) {
                    system_.sortClientsByRepairCostMin();
                }
                else if (choice_r == 2) {
                    system_.sortClientsByRepairCostMax();
                }
                break;
            case 6:
                system_.DeleteTask();
                break;
            case 7:
                cout << "Выход.\n";
                menuBool = false;
                break;
            default:
                cout << "Неверный выбор. Попробуйте еще раз.\n";
                counter++;
                break;
            }
        }
        catch (invalid_argument&) {
            cout << "Вы ввели строку. Требуется числовой формат. Повторите попытку" << endl;
            counter++;
        }
    }

    return 0;
}
