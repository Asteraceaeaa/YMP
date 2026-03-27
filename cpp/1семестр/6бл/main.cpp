#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// 1. СОРТИРОВКА ВЫБОРОМ
void selectionSort(vector<int>& arr, bool IsAscendingOrder, int len) {
    for (int i = 0; i < len - 1; i++) {
        int curIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (IsAscendingOrder ? arr[j] < arr[curIndex] : arr[j] > arr[curIndex]) {
                curIndex = j;
            }
        }
        swap(arr[i], arr[curIndex]);
    }
}

// 2. ПУЗЫРЬКОВАЯ СОРТИРОВКА
void bubbleSort(vector<int>& arr, bool flag, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (flag ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 3. БЫСТРАЯ СОРТИРОВКА
int partition(vector<int>& arr, int low, int high, bool IsAscendingOrder) {
    int p = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (IsAscendingOrder ? arr[j] <= p : arr[j] >= p) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, bool IsAscendingOrder) {
    if (low < high) {
        int pi = partition(arr, low, high, IsAscendingOrder);
        quickSort(arr, low, pi - 1, IsAscendingOrder);
        quickSort(arr, pi + 1, high, IsAscendingOrder);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    // Чтение данных из файла
    ifstream input("input.txt");
    if (!input) {
        cout << "Ошибка: не удалось открыть файл input.txt\n";
        return 1;
    }

    int n;
    input >> n;

    vector<int> inputData(n);
    for (int i = 0; i < n; i++) {
        input >> inputData[i];
    }
    input.close();

    // Выполнение всех алгоритмов сортировки
    cout << "Сортировка для массива из " << n << " элементов\n\n";


    // 1. СОРТИРОВКА ВЫБОРОМ

    {
        // Копируем исходный массив
        vector<int> arr_asc = inputData;
        vector<int> arr_desc = inputData;

        // Сортировка по возрастанию
        selectionSort(arr_asc, true, arr_asc.size());

        // Сортировка по убыванию
        selectionSort(arr_desc, false, arr_desc.size());

        // Запись в файл
        ofstream output("output_selection.txt");
        output << "По возрастанию:\n";
        for (int num : arr_asc) {
            output << num << " ";
        }
        output << "\n\nПо убыванию:\n";
        for (int num : arr_desc) {
            output << num << " ";
        }
        output << "\n";
        output.close();

        cout << "Сортировка выбором завершена. Результат в output_selection.txt\n";
    }


    // 2. ПУЗЫРЬКОВАЯ СОРТИРОВКА

    {
        // Копируем исходный массив
        vector<int> arr_asc = inputData;
        vector<int> arr_desc = inputData;

        // Сортировка по возрастанию
        bubbleSort(arr_asc, true, arr_asc.size());

        // Сортировка по убыванию
        bubbleSort(arr_desc, false, arr_desc.size());

        // Запись в файл
        ofstream output("output_bubble.txt");
        output << "По возрастанию:\n";
        for (int num : arr_asc) {
            output << num << " ";
        }
        output << "\n\nПо убыванию:\n";
        for (int num : arr_desc) {
            output << num << " ";
        }
        output << "\n";
        output.close();

        cout << "Пузырьковая сортировка завершена. Результат в output_bubble.txt\n";
    }

    // 3. БЫСТРАЯ СОРТИРОВКА
 
    {
        // Копируем исходный массив
        vector<int> arr_asc = inputData;
        vector<int> arr_desc = inputData;

        // Сортировка по возрастанию
        quickSort(arr_asc, 0, arr_asc.size() - 1, true);

        // Сортировка по убыванию
        quickSort(arr_desc, 0, arr_desc.size() - 1, false);

        // Запись в файл
        ofstream output("output_quick.txt");
        output << "По возрастанию:\n";
        for (int num : arr_asc) {
            output << num << " ";
        }
        output << "\n\nПо убыванию:\n";
        for (int num : arr_desc) {
            output << num << " ";
        }
        output << "\n";
        output.close();

        cout << "Быстрая сортировка завершена. Результат в output_quick.txt\n";
    }

    cout << "\nВсе алгоритмы выполнены успешно!\n";
    return 0;
}