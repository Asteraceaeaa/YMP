#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

const int NOTES_COUNT = 15;

struct NOTE {

    /* Поля структуры */

    char full_name[50];
    char phone_number[20];
    char email[100];      
    int date_of_birth[3];

    /* Методы структуры */

    // Форматный вывод экземпляра структуры
    void print() {
        std::printf("%s | %s | %s | %02d.%02d.%d\n", full_name, phone_number, email,
                    date_of_birth[0], date_of_birth[1], date_of_birth[2]);
    }

    // Считывание данных из строки
    void read_from_console(const std::string& line) {

        std::stringstream sstr(line); // Создаем поток
        char name[50];
        char surname[50];

        // Записываем данные из потока с проверкой
        if (sstr >> surname >> name >> phone_number >> email >> date_of_birth[0] >>
            date_of_birth[1] >> date_of_birth[2]) {

            // Составляем полное имя посимвольно
            int pos = 0;
            int l_full_name = sizeof(full_name) / sizeof(full_name[0]) - 1;


            for (int i = 0; surname[i] != '\0' && pos < l_full_name; i++) {
                full_name[pos++] = surname[i];
            }

            if (pos < l_full_name) {
                full_name[pos++] = ' ';
            }

            for (int i = 0; name[i] != '\0' && pos < l_full_name; i++) {
                full_name[pos++] = name[i];
            }

            full_name[pos] = '\0';
            std::cout << "\nЗапись успешно добавлена!\n\n";

        } else {
            std::cout << "\nНеверный формат данных.\n\n";
            full_name[0] = '\0'; // Если формат неверный записываем в поле имени пустую последовательность
        }
    }

    // Вспомогательная функция для поиска, чтобы получить именно фамилию
    std::string get_surname() const {
        std::string lastname;
        int pos = 0;
        while (full_name[pos] != ' ' && full_name[pos] != '\0') {
            lastname += full_name[pos++];
        }
        return lastname;
    }
};

// Сортирвка массива струтур по фамилии по алфавиту
void SortNotes(NOTE* notes, int count) {
    
    // Пузырьковая сортирвка
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            int pos = 0;

            while (notes[j].full_name[pos] == notes[j + 1].full_name[pos] &&
                   notes[j].full_name[pos] != '\0') {
                pos++;
            }

            if (notes[j].full_name[pos] != '\0' && notes[j + 1].full_name[pos] != '\0') {
                if (notes[j].full_name[pos] > notes[j + 1].full_name[pos]) {
                    NOTE temp = notes[j];
                    notes[j] = notes[j + 1];
                    notes[j + 1] = temp;
                }
            } else if (notes[j].full_name[pos] == ' ' && notes[j + 1].full_name[pos] == '\0') {
                NOTE temp = notes[j];
                notes[j] = notes[j + 1];
                notes[j + 1] = temp;
            }
        }
    }
}

// Функция для сохранения в бинарный файл
bool SaveToBin(std::string path, NOTE* notes, int count) {
    
    std::ofstream fout(path, std::ios::binary);

    if (!fout.is_open()) {
        std::cerr << "\nНе удалось откыть файл.\n";
        return false; 
    }

    // Записываем единым блоком все структруры
    for (int i = 0; i < count; i++) {
        fout.write((char*)&notes[i], sizeof(notes[i]));
    }

    fout.close();

    return true;
}

int main() {

    NOTE notes[NOTES_COUNT];  // Массив структур
    int notes_count = 0; // Глобальный счетчик записей

    /* Запускаем управляемый бесконечный цикл с телом программы. */
    while (true) {

        /* ===== МЕНЮ ===== */

        std::cout << "\n\nВыберите действие (1-5):\n\n";

        std::cout << "1. Добавить записи.\n"
                  << "2. Найти запись\n"
                  << "3. Сохранить записи в файл\n"
                  << "4. Отредактировать номер телефона и почту\n"
                  << "5. Вывести записи из бинарного файла\n";
        std::cout << "Дополнительные опции: \n6. Вывести все записи в консоль. \n7. Заполнить базу из "
                     "txt-файла.\n\n";
        std::cout << "Для выхода из программы введите \"q\".\n\n";

        // Считываем ввод
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "q") {
            break; // Выходим, если "q"
        }

        if (choice == "1") {

            /* ========== ВВОД С КЛАВИАТУРЫ ========== */

            std::cout << "\n\nДля выхода из режима ввода в консоль наберите \"q\"\n\n";

            // Осуществляем ввод через цикл
            while (notes_count < NOTES_COUNT) {

                std::cout << "Введите данные в формате: Ковин Владимир +79171112233 "
                             "kovin@gmail.com 17 10 2007\n\n";


                std::string line;
                std::getline(std::cin, line);  // Считывем ввод

                if (line == "q") {
                    break; // Выходим, если "q"
                }

                notes[notes_count].read_from_console(line); // С помощью функции структуры пытаемся запихнуть данные

                if (notes[notes_count].full_name[0] != '\0') { // Проверяем, верный ли ввод
                    notes_count++;  
                }

            }

            SortNotes(notes, notes_count); // Сортируем

            if (notes_count == NOTES_COUNT) {
                std::cout << "\nБаза данныйх заполнена.\n\n";
            }

        } else if (choice == "2") {

            /* ========== ПОИСК В БАЗЕ ПО ФАМИЛИИ ========== */

            if (notes_count == 0) {
                std::cout << "В базе еще нет записей \n\n";
            } else {
                std::cout << "Для выхода из режима поиска введите \"q\".\n\n";

                // Запускаем цикл для ввода данных
                while (true) {

                    NOTE finded[notes_count];
                    int finded_count = 0;

                    // Получаем фамилию
                    std::string line;
                    std::cout << "\nВведите фамилию, чтобы найти: ";
                    std::getline(std::cin, line);

                    if (line == "q") {
                        break;
                    }
                    // Ищем в базе по фамилии
                    for (int i = 0; i < notes_count; i++) {
                        if (notes[i].get_surname() == line) {
                            finded[finded_count++] = notes[i];
                        }
                    }
                    // Выводим результат
                    if (finded_count > 0) {

                        std::cout << "\nНашлось " << " записей: " << finded_count << "\n\n";

                        for (int i = 0; i < finded_count; i++) {
                            finded[i].print();
                        }

                    } else {
                        std::cout << "\nЗаписей не нашлось.\n\n";
                    }
                }
            }

        } else if (choice == "3") {

            /* ========== СОХРАНЕНИЕ ДАННЫХ В БИНАРНИК ========== */

            // Запрашиваем путь
            std::string path;
            std::cout << "Введите имя файла\n";
            std::getline(std::cin, path);

            // Пытаемся сохранить через SaveToBin()
            if (SaveToBin(path, notes, notes_count)) {
                std::cout << "\nБаза успешно сохранена в файл!\n\n";
            } 

        } else if (choice == "4") {

            /* ========== РЕДАКТИРОВАНИЕ ЗАПИСИ В БИНАРНИКЕ ПО ЕЁ НОМЕРУ ========== */

            // Запрашиваем имя файла
            std::string path;
            std::cout << "Введите имя файла\n";
            std::getline(std::cin, path);

            std::fstream bf(path, std::ios::in | std::ios::out); // Открываем в режиме бинарного ввода/вывода

            if (bf.is_open()) {

                bf.seekg(0, bf.end);  // Установка текущей позиции в файле на его конец
                int n_record = bf.tellg() / sizeof(NOTE);  // Определение длины файла в записях
                std::cout << "В файле " << n_record << " записей.\n";

                int num;
                while (true) {
                    
                    std::cout << "Введите номер записи или -1:\n";
                    std::cin >> num;
                    std::cin.ignore();

                    if (num < 1 || num > n_record) {
                        std::cerr << "В файле нет такого номера\n";
                        break;
                    }

                    std::size_t full_name_l =
                        sizeof(notes[0].full_name);  
                    bf.seekg((num - 1) * sizeof(NOTE) + full_name_l, bf.beg);
                    
                    char phone[20], email[100];
                    std::cout << "\nВведите новый номер: \n";

                    // Проверяем, адекватная ли длина
                    while (!std::cin.getline(phone, 20)) {
                        std::cerr << "Слишком длинный номер! Максимальная длина - 19 цифр. Введите "
                                     "снова:\n";
                        std::cin.clear();              // Сбрасываем флаг ошибки
                        std::cin.ignore(10000, '\n');  // Очищаем буфер
                    }
                    
                    std::cout << "\nВведите новую почту: \n";

                    // Проверяем, адекватная ли длина
                    while(!std::cin.getline(email, 100)) {
                        std::cerr << "Слишком длинная почта! Максимальная длина - 49 символов. "
                                     "Введите снова:\n";
                        std::cin.clear();              // Сбрасываем флаг ошибки
                        std::cin.ignore(10000, '\n');  // Очищаем буфер
                    }

                    // Записываем в соответствующие байты
                    bf.write((char*)&phone, sizeof(phone));
                    bf.write((char*)&email, sizeof(email));
                }

                bf.close();
                std::cout << "\nКорректировка бинарного файла завершена!\n";
            } else {
                std::cout << "\nНе удалось открыть файл.\n\n";
            }

        } else if (choice == "5") {

            /* ========== ВЫВОД ЗАПИСЕЙ ИЗ БИНАРНИКА ========== */

            std::string path;
            std::cout << "Введите имя файла\n";
            std::getline(std::cin, path);

            std::ifstream bfin(path, std::ios::binary);

            if (!bfin.is_open()) {
                std::cerr << "\nНе удалось откыть файл.\n";
            } else {

                // Узнаем длину файла
                bfin.seekg(0, bfin.end); // Ставим указатель на конец
                const int n_record = bfin.tellg() / sizeof(NOTE);
                std::cout << "В файле " << n_record << " записей:\n\n";


                NOTE bnotes[n_record];
                bfin.seekg(0, bfin.beg);

                // Считываем записи в массив
                for (int i = 0; i < n_record; i++) {
                    bfin.read((char*)&bnotes[i], sizeof(NOTE));
                }

                bfin.close();

                SortNotes(bnotes, n_record); // Сортируем

                // Выводим записи 
                for (int i = 0; i < n_record; i++) {
                    bnotes[i].print();
                }
            }

            /* ========== ДОП ФУНКЦИИ ДЛЯ ТЕСТИРОВАНИЯ И ОТЛАДКИ ========== */

        } else if (choice == "6") {

            /* ========== ВЫВОД ВСЕХ ЗАПИСЕЙ ИЗ МАССИВА В КОНСОЛЬ ========== */

            for (int i = 0; i < notes_count; i++) {
                notes[i].print();
            }

        } else if (choice == "7") {

            /* ========== ЗАПОЛНЕНИЕ БАЗЫ ИЗ ТЕКСТОВОГО ФАЙЛА ========== */

            notes_count = 0;
            std::string path, line;
            std::cout << "Введите имя файла\n";
            std::getline(std::cin, path);

            std::ifstream fin(path);
            if (!fin.is_open()) { std::cout << "Не удалось открыть файл.\n\n"; }

            for (int i = 0; i < NOTES_COUNT && std::getline(fin, line); i++) {

                std::stringstream sstr(line);
                char name[50];
                char surname[50];

                if (sstr >> surname >> name >> notes[i].phone_number >> notes[i].email >>
                    notes[i].date_of_birth[0] >> notes[i].date_of_birth[1] >>
                    notes[i].date_of_birth[2]) {
                    int pos = 0;
                    int l_full_name =
                        sizeof(notes[i].full_name) / sizeof(notes[i].full_name[0]) - 1;

                    for (int j = 0; surname[j] != '\0' && pos < l_full_name; j++) {
                        notes[i].full_name[pos++] = surname[j];
                    }

                    if (pos < l_full_name) {
                        notes[i].full_name[pos++] = ' ';
                    }

                    for (int j = 0; name[j] != '\0' && pos < l_full_name; j++) {
                        notes[i].full_name[pos++] = name[j];
                    }

                    notes[i].full_name[pos] = '\0';
                    std::cout << "Загружено: " << surname << " " << name << "\n";
                    notes_count++; 

                } else {
                    std::cout << "\nНеверный формат данных.\n\n";
                    std::cout << "Пропущена строка: " << line << "\n";
                    notes[i].full_name[0] = '\0';
                    i--; 
                }

                
            }
            SortNotes(notes, notes_count);
        } else {
            std::cout << "Неверный ввод. Используйте цифры 1-5 или 'q' для выхода.\n\n";
        }
    }

    std::cout << "\nМанипуляции завершены. Выход...\n\n";

    return 0;
}
