#pragma once
#include <string>

class Point
{
protected:
    double m_x1;
    double m_x2;

public:

    Point();
    Point(double x1, double x2);

    virtual ~Point() = default;
    /*
    При создании объекта класса с виртуальными функциями в нём создаётся специальный указатель
     * (vptr), который указывает на виртуальную таблицу (vtable) этого класса. vtable содержит
     * записи для каждой виртуальной функции, инициализированные указателями на их реализации. При
     * вызове виртуальной функции через указатель на базовый класс происходит поиск адреса vtable
     * для класса, затем в таблице находится указатель на вызываемую функцию, и через него
     * вызывается сама функция.
     * */

    virtual double getX1() const;
    virtual double getX2() const;

    virtual void setX1(double val);
    virtual void setX2(double val);

    double distTo(Point& p) const;

    virtual void print() const;
    virtual std::string toStr() const;
};