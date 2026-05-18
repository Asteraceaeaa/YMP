#include "../include/Account.h"
#include <iostream>
#include <cctype> // isdigit()
#include <string>

const unsigned NUMBER_LENGHT = 4;
const unsigned PIN_LENGHT = 4;

Account::Account(std::string num, std::string pin, double balance) : m_number(num), m_pin(pin), m_balance(balance)
{
  if (num.length() != NUMBER_LENGHT) {
    throw std::invalid_argument("Длина номера должна равняться " +
                                std::to_string(NUMBER_LENGHT));
  }

  for (char c : num)
  {
    if (!isdigit(c))
    {
      throw std::invalid_argument("Номер должен состоять только из цифр");
    }
  }

  if (pin.length() != PIN_LENGHT) {
    throw std::invalid_argument("Длина PIN должна равняться " +
                                std::to_string(PIN_LENGHT));
  }

  for (char c : pin) {
    if (!isdigit(c)) 
    {
      throw std::invalid_argument("PIN должен состоять только из цифр");
    }
  }
}

std::string Account::getNumber() const
{
    return m_number;
}

std::string Account::getPin() const
{
    return m_pin;
}

double Account::getBalance() const
{
    return m_balance;
}

// void Account::setNumber(std::string new_number)
// {
//     if (new_number.length() != NUMBER_LENGHT) {
//       throw std::invalid_argument("Длина номера должна равняться " +
//                                   std::to_string(NUMBER_LENGHT));
//     }
//     m_number = new_number;
// }

void Account::setPin(const std::string& new_pin)
{
  if (new_pin.length() != PIN_LENGHT) {
    throw std::invalid_argument("Длина номера должна равняться " +
                                std::to_string(PIN_LENGHT));
  }

  for (char c : new_pin) {
    if (!isdigit(c)) {
      throw std::invalid_argument("PIN должен состоять только из цифр");
    }
  }

  if (m_pin == new_pin) { throw std::invalid_argument("Новый PIN не может совпадать со старым.")}

  m_pin = new_pin;
}

void Account::setBalance(double new_balance)
{
    m_balance = new_balance;
}

bool Account::validatePin(const std::string& pin) const 
{
    return m_pin == pin;
}