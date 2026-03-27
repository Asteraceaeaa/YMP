#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const int MAX_NOTES = 15;

struct NOTE {
    std::string full_name;
    std::string phone_number;
    std::string email;
    int date_of_birth[3];
};

std::vector<NOTE> ReadDataFromFile(const std::string& path, const int count,
                                   const std::string& mode = "txt");

void EnterFromConsole(std::vector<NOTE> &notes, int MAX_NOTES = MAX_NOTES);

void ShowAllNotes(std::vector<NOTE> &notes);

NOTE ReadFromLine(const std::string& line, bool show_m = true) {
    std::stringstream sstr(line);
    NOTE note;
    std::string name, surname;

    if (sstr >> name >> surname >> note.phone_number >> note.email >> note.date_of_birth[0] >>
        note.date_of_birth[1] >> note.date_of_birth[2]) {
        note.full_name = name + " " + surname;
        if (show_m) {
            std::cout << "Запись добавлена!\n\n";
        }
        return note;
    } else {
        if (show_m) {
            std::cout << "Ошибка! Неверный формат вводимых данных.\n";
        }
    }
    return NOTE{};
}

std::vector<NOTE> FindNote(const std::vector<NOTE>& notes, const std::string& surname);

void Sort(std::vector<NOTE> &notes);

int main() {

    // std::vector<NOTE> notes = ReadDataFromFile("1t_input_data.txt", MAX_NOTES);
    // short i = 0;
    // while (true && i < MAX_NOTES) {
    //     std::cout << "Введите данные: ";
    //     std::string line;
    //     std::getline(std::cin, line);
    //     if (line.empty() || line == "exit") { break; }
    //     notes.push_back(ReadFromLine(line));
    // }
    std::vector<NOTE> notes;
    while (true) {

        std::cout << "Выберите действие (1-5):\n\n";

        std::cout << "1. Добавить записи.\n" << "2. Найти запись\n" << "3. Сохранить записи в файл\n"; 
        std::cout << "Дополнительные опции: \n4. Вывести все записи в консоль. \n5. Достать из txt-файла.\n\n";
        std::cout << "Для выхода из программы напишите \"exit\".\n\n";
        std::string line;
    

        std::getline(std::cin, line);
        if (line == "exit") {
            break;
        }

        if (line=="1") { 
            EnterFromConsole(notes);
            Sort(notes);
            std::cout << "Выход из режима ввода в консоль... \n" << "Введенные данные: \n";
            ShowAllNotes(notes); std::cout << "\n\n";
            std::cin.ignore();
        }else if (line == "2") {
            std::cout << "Введите фамилию, чтобы найти:\n";

            std::string surname;
            std::cin >> surname;

            std::vector<NOTE> finded = FindNote(notes, surname);
            if (finded.empty()) {
                std::cout << "Записей не найдено.\n\n";
            } else {
                std::cout << "\n=== Найденные записи ===\n";
                int i = 1;
                for (const NOTE &note : finded) {
                    std::cout << i++ << ". " << note.full_name
                              << " | Тел: " << note.phone_number
                              << " | Email: " << note.email
                              << " | Дата: " << note.date_of_birth[0] << "."
                              << note.date_of_birth[1] << "." << note.date_of_birth[2]
                              << "\n";
                }
            
            std::cout << "Выход из режима ввода в консоль... \n\n";
            std::cin.ignore();
        }
        } else if (line == "3") {
            EnterFromConsole(notes);
            std::cout << "Выход из режима ввода в консоль... \n" << "Введенные данные: \n";
            ShowAllNotes(notes);
        } else if (line == "4") {
            ShowAllNotes(notes);
            std::cout << "\n\n";
        } else if (line == "5") {
            int count = 0;
            std::string path;
            std::cout << "Введите путь к файлу: ";

            std::getline(std::cin, path);
            std::cout << "Введите количество записей: ";
            std::cin >> count;

            notes = ReadDataFromFile(path, count);
            if (!notes.empty()) {
                std::cout << "Данные прочитаны успешно!\n\n";
            } else {
                std::cout << "Не удалось прочесть данные из файла\n\n";
            }
            std::cin.ignore();
        } else {
            std::cout << "Неверный ввод.\n\n";
        }
    } 

    std::cout << "Манипуляции завершены. Выход...\n\n";


    return 0;
}

void EnterFromConsole(std::vector<NOTE>& notes, int MAX_NOTES) {
    short i = 0;
    std::cout << "Ввод данных через консоль. Для выхода напишите exit или оставьте строку пустой.\n";
    std::cout << "Формат ввода в одну строку. Например: \nДурачок Ивашка +74252676661 vanbka228@mail.ru 07 10 2007\n\n";
    while (i < MAX_NOTES) {
        std::cout << "Введите данные: ";
        std::string line;
        std::getline(std::cin, line);

        if (line.empty() || line == "exit") {
            break;
        }

        notes.push_back(ReadFromLine(line));
    }
}

void ShowAllNotes(std::vector<NOTE>& notes) {
    std::cout << "\n=== ВСЕ ЗАПИСИ ===\n";
    for (size_t i = 0; i < notes.size(); i++) {
        std::cout << i + 1 << ". " << notes[i].full_name << " | Тел: " << notes[i].phone_number
                  << " | Email: " << notes[i].email << " | Дата: " << notes[i].date_of_birth[0]
                  << "." << notes[i].date_of_birth[1] << "." << notes[i].date_of_birth[2] << "\n";
    }
}

void Sort(std::vector<NOTE>& notes) {
    std::sort(notes.begin(), notes.end(), [](const NOTE& note1, const NOTE& note2) {
        if (note1.full_name != note2.full_name) {
            return note1.full_name < note2.full_name;
        }
        return false;
    });
}

void SaveToBin(std::vector<NOTE> &notes, std::string &path) {
    std::ofstream fbin(path, std::ios::binary);
    if ( !fbin.is_open() ) { std::cerr << "Не удалось открыть файл " << path << std::endl << std::endl; }

    std::size_t len = notes.size();
    fbin.write(reinterpret_cast<char*>(&len), sizeof(len));

    for (const NOTE &note : notes) {

        len = note.full_name.size();
        fbin.write(note.full_name.c_str(), len);
        
        len = note.phone_number.size();
        fbin.write(note.phone_number.c_str(), len);

        len = note.email.size();
        fbin.write(note.email.c_str(), len);

        std::string date = note.date_of_birth[0] + " " + note.date_of_birth[1] + " " + note.date_of_birth[2];
        fbin.write(date.c_str(), date.size());
    }
    
}

std::vector<NOTE> ReadDataFromFile(const std::string& path, int count, const std::string& mode) {   
    std::vector<NOTE> notes;
    std::ifstream file;
    int records_read = 0;

    if (mode == "txt") {
        file.open(path);

        if (file) {
            std::string line;
            while ((count == 0 || records_read < count) && std::getline(file, line)) {
                if (line.empty()) {
                    continue;  // Пропускаем пустые строки
                }

                NOTE note = ReadFromLine(line, false);
                if (!note.full_name.empty()) {  // Проверяем, что запись успешно прочитана
                    notes.push_back(note);
                    records_read++;
                }
            }
            file.close();
        }
    } else {
        return notes;
        file.open(path, std::ios::binary);

        // if (file) {

        // }
    }

    return notes;
}

std::vector<NOTE> FindNote(const std::vector<NOTE>& notes, const std::string &surname) {
    std::string name, surnamee;
    std::vector<NOTE> finded;

    for (const NOTE& note : notes) {
        std::stringstream sstr(note.full_name);

        if (sstr >> surnamee >> name) {
            if (surnamee == surname) {finded.push_back(note);}
        }
    }

    return finded;

    // for (const NOTE& note : notes) {
    //     std::size_t spos = note.full_name.find(' ');
    //     std::string surnamee = note.full_name.substr(0, spos + 1);
    //     if (surname == surnamee) {
    //         finded.push_back(note);
    //     }
    // }

    // return finded;

}