#pragma once

// Объявляем класс 
class Complex {

// Публичная секция
public: 

    /* Конструкторы */
    Complex() = default;
    Complex(double real, double imag);
    
    /* Операторы */
    Complex operator+(const Complex& x);
    Complex operator-(const Complex& x);
    Complex operator*(const Complex& x);
    Complex operator/(const Complex& x);

    /* Вспомогательные методы */
    void print(); // Функция для вывода в консоль

// Приватная секция
private: 

    /* Поля класса */
    double m_real = 0.0; // Вещественная часть(По умолчанию - 0)
    double m_imag = 0.0; // Мнимая часть(По умолчанию - 0)
    
};