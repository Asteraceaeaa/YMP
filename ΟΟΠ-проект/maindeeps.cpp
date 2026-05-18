#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

// ----- Абстрактный класс счета -----
class Account {
 protected:
  std::string number;
  double balance;
  std::string pin;

 public:
  Account(std::string num, double bal, std::string p)
      : number(num), balance(bal), pin(p) {}

  virtual ~Account() = default;

  bool verifyPin(const std::string& input) const { return pin == input; }

  double getBalance() const { return balance; }

  std::string getNumber() const { return number; }

  std::string getPin() const { return pin; }

  virtual void deposit(double amount) {
    if (amount > 0) balance += amount;
  }

  virtual bool withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount;
      return true;
    }
    return false;
  }

  virtual void showInfo() const {
    std::cout << "Счет " << number << ", баланс: " << std::fixed
              << std::setprecision(2) << balance << " руб.\n";
  }

  virtual std::string getType() const { return "NORMAL"; }

  virtual double getExtraParam() const { return 0.0; }
};

// ----- Наследование: сберегательный счет -----
class SavingsAccount : public Account {
  double interestRate;

 public:
  SavingsAccount(std::string num, double bal, std::string p, double rate)
      : Account(num, bal, p), interestRate(rate) {}

  void addInterest() { balance += balance * interestRate / 100; }

  void showInfo() const override {
    Account::showInfo();
    std::cout << "  (Сберегательный счет, ставка " << interestRate
              << "% годовых)\n";
  }

  std::string getType() const override { return "SAVINGS"; }

  double getExtraParam() const override { return interestRate; }

  double getInterestRate() const { return interestRate; }
};

// ----- Абстрактный класс транзакции (полиморфизм) -----
class Transaction {
 protected:
  double amount;

 public:
  Transaction(double amt) : amount(amt) {}
  virtual ~Transaction() = default;
  virtual bool execute(Account& acc) = 0;
  virtual std::string getType() const = 0;
};

class Withdrawal : public Transaction {
 public:
  Withdrawal(double amt) : Transaction(amt) {}

  bool execute(Account& acc) override { return acc.withdraw(amount); }

  std::string getType() const override { return "Снятие"; }
};

class Deposit : public Transaction {
 public:
  Deposit(double amt) : Transaction(amt) {}

  bool execute(Account& acc) override {
    acc.deposit(amount);
    return true;
  }

  std::string getType() const override { return "Пополнение"; }
};

// ----- Класс Банкомат (управление + работа с файлом) -----
class ATM {
 private:
  std::vector<std::unique_ptr<Account>> accounts;
  Account* currentAccount = nullptr;

 public:
  // Сохранение всех счетов в CSV файл
  void saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
      std::cerr << "Ошибка: не удалось открыть файл " << filename
                << " для сохранения!\n";
      return;
    }

    // Формат: тип|номер|баланс|pin|доп.параметр
    for (const auto& acc : accounts) {
      file << acc->getType() << "|" << acc->getNumber() << "|" << std::fixed
           << std::setprecision(2) << acc->getBalance() << "|" << acc->getPin()
           << "|" << acc->getExtraParam() << "\n";
    }

    file.close();
    std::cout << "Данные успешно сохранены в " << filename << "\n";
  }

  // Загрузка счетов из CSV файла
  void loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cout << "Файл " << filename
                << " не найден. Создана новая база данных.\n";
      return;
    }

    accounts.clear();
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
      lineNumber++;
      if (line.empty()) continue;

      std::stringstream ss(line);
      std::string type, number, pin, extraStr;
      double balance;

      // Парсим строку
      std::getline(ss, type, '|');
      std::getline(ss, number, '|');

      std::string balanceStr;
      std::getline(ss, balanceStr, '|');
      try {
        balance = std::stod(balanceStr);
      } catch (...) {
        std::cerr << "Ошибка в строке " << lineNumber << ": неверный баланс\n";
        continue;
      }

      std::getline(ss, pin, '|');
      std::getline(ss, extraStr, '|');

      // Создаём соответствующий тип счета
      if (type == "SAVINGS") {
        double rate = 0.0;
        try {
          rate = std::stod(extraStr);
        } catch (...) {
          rate = 0.0;
        }
        accounts.push_back(
            std::make_unique<SavingsAccount>(number, balance, pin, rate));
      } else {
        accounts.push_back(std::make_unique<Account>(number, balance, pin));
      }
    }

    file.close();
    std::cout << "Загружено " << accounts.size() << " счет(ов) из " << filename
              << "\n";
  }

  // Добавление нового счета
  void addAccount(std::unique_ptr<Account> acc) {
    accounts.push_back(std::move(acc));
  }

  // Создание нового счета через консоль
  void createNewAccount() {
    std::string number, pin, type;
    double initialBalance, extraParam = 0.0;

    std::cout << "\n--- Создание нового счета ---\n";
    std::cout << "Номер счета: ";
    std::cin >> number;

    // Проверка на существующий номер
    for (const auto& acc : accounts) {
      if (acc->getNumber() == number) {
        std::cout << "Счет с таким номером уже существует!\n";
        return;
      }
    }

    std::cout << "PIN-код (4 цифры): ";
    std::cin >> pin;

    std::cout << "Начальный баланс: ";
    std::cin >> initialBalance;

    std::cout << "Тип счета (1 - обычный, 2 - сберегательный): ";
    int typeChoice;
    std::cin >> typeChoice;

    if (typeChoice == 2) {
      std::cout << "Процентная ставка (% годовых): ";
      std::cin >> extraParam;
      addAccount(std::make_unique<SavingsAccount>(number, initialBalance, pin,
                                                  extraParam));
      std::cout << "Сберегательный счет успешно создан!\n";
    } else {
      addAccount(std::make_unique<Account>(number, initialBalance, pin));
      std::cout << "Обычный счет успешно создан!\n";
    }
  }

  // Авторизация пользователя
  bool login() {
    std::string num, pin;
    std::cout << "\n=== Вход в банкомат ===\n";
    std::cout << "Номер счета: ";
    std::cin >> num;
    std::cout << "PIN-код: ";
    std::cin >> pin;

    for (auto& acc : accounts) {
      if (acc->getNumber() == num && acc->verifyPin(pin)) {
        currentAccount = acc.get();
        std::cout << "\nДобро пожаловать, " << num << "!\n";
        return true;
      }
    }

    std::cout << "Неверный номер счета или PIN-код!\n";
    return false;
  }

  // Главное меню после авторизации
  void showMenu() {
    if (!currentAccount) return;

    int choice;
    do {
      std::cout << "\n=== Меню ===";
      std::cout << "\n1. Проверить баланс";
      std::cout << "\n2. Снять наличные";
      std::cout << "\n3. Внести наличные";
      std::cout << "\n4. Информация о счете";
      std::cout << "\n5. Начислить проценты (только для сберегательного)";
      std::cout << "\n0. Выйти из аккаунта";
      std::cout << "\n> ";
      std::cin >> choice;

      switch (choice) {
        case 1: {
          std::cout << "Ваш баланс: " << std::fixed << std::setprecision(2)
                    << currentAccount->getBalance() << " руб.\n";
          break;
        }
        case 2: {
          double amt;
          std::cout << "Сумма для снятия: ";
          std::cin >> amt;

          if (amt <= 0) {
            std::cout << "Неверная сумма!\n";
            break;
          }

          std::unique_ptr<Transaction> t = std::make_unique<Withdrawal>(amt);
          if (t->execute(*currentAccount)) {
            std::cout << "Операция выполнена. Снято " << std::fixed
                      << std::setprecision(2) << amt << " руб.\n";
          } else {
            std::cout << "Ошибка: недостаточно средств!\n";
          }
          break;
        }
        case 3: {
          double amt;
          std::cout << "Сумма для внесения: ";
          std::cin >> amt;

          if (amt <= 0) {
            std::cout << "Неверная сумма!\n";
            break;
          }

          std::unique_ptr<Transaction> t = std::make_unique<Deposit>(amt);
          t->execute(*currentAccount);
          std::cout << "Операция выполнена. Внесено " << std::fixed
                    << std::setprecision(2) << amt << " руб.\n";
          break;
        }
        case 4:
          currentAccount->showInfo();
          break;
        case 5: {
          // Начисление процентов (если это сберегательный счет)
          if (auto* savings = dynamic_cast<SavingsAccount*>(currentAccount)) {
            savings->addInterest();
            std::cout << "Проценты начислены. Новый баланс: " << std::fixed
                      << std::setprecision(2) << savings->getBalance()
                      << " руб.\n";
          } else {
            std::cout
                << "Эта функция доступна только для сберегательного счета!\n";
          }
          break;
        }
        case 0:
          std::cout << "До свидания!\n";
          break;
        default:
          std::cout << "Неверный выбор. Попробуйте снова.\n";
      }
    } while (choice != 0);

    currentAccount = nullptr;
  }

  // Отображение всех счетов (для администратора)
  void showAllAccounts() const {
    std::cout << "\n=== Все счета в системе ===\n";
    if (accounts.empty()) {
      std::cout << "Нет зарегистрированных счетов.\n";
      return;
    }

    for (size_t i = 0; i < accounts.size(); ++i) {
      std::cout << i + 1 << ". ";
      accounts[i]->showInfo();
    }
  }
};

// ----- Главная функция -----
int main() {
  ATM atm;
  const std::string dataFile = "accounts.csv";

  std::cout << "=== Банкомат ===\n";

  // Загружаем данные из файла
  atm.loadFromFile(dataFile);

  int mainChoice;
  do {
    std::cout << "\n--- Главное меню ---";
    std::cout << "\n1. Войти в аккаунт";
    std::cout << "\n2. Создать новый счет";
    std::cout << "\n3. Показать все счета";
    std::cout << "\n0. Выход";
    std::cout << "\n> ";
    std::cin >> mainChoice;

    switch (mainChoice) {
      case 1:
        if (atm.login()) {
          atm.showMenu();
        }
        break;
      case 2:
        atm.createNewAccount();
        break;
      case 3:
        atm.showAllAccounts();
        break;
      case 0:
        std::cout << "Завершение работы. Сохраняем данные...\n";
        break;
      default:
        std::cout << "Неверный выбор!\n";
    }
  } while (mainChoice != 0);

  // Сохраняем данные перед выходом
  atm.saveToFile(dataFile);

  std::cout << "Программа завершена.\n";
  return 0;
}