#pragma once

class Point
{
protected:
    double m_x1;
    double m_x2;

public:

    Point();
    Point(double x1, double x2);

    virtual ~Point();
    /*
    При создании объекта класса с виртуальными функциями в нём создаётся специальный указатель
     * (vptr), который указывает на виртуальную таблицу (vtable) этого класса. vtable содержит
     * записи для каждой виртуальной функции, инициализированные указателями на их реализации. При
     * вызове виртуальной функции через указатель на базовый класс происходит поиск адреса vtable
     * для класса, затем в таблице находится указатель на вызываемую функцию, и через него
     * вызывается сама функция.
     * */

    double getX1() const;
    double getX2() const;

    void setX1(double val);
    void setX2(double val);

    double distTo(Point& p) const;

    virtual void print();
};