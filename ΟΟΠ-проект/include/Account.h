#pragma once
#include <string>

class Account 
{
private:
  std::string m_number;
  std::string m_pin;
  double m_balance;

public:

// Конструкторы
  Account() = default;
  Account(std::string number, std::string pin, double money = 0);

  // Геттеры
  std::string getNumber() const;
  std::string getPin() const;
  double getBalance() const;

  // Сеттеры
//   void setNumber(std::string new_number);
  void setPin(const std::string& new_pin);
  void setBalance(double new_balance);

  // Проверки
  bool validatePin(const std::string& pin) const;
};