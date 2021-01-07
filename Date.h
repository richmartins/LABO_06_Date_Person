/*-----------------------------------------------------------------------------------
Laboratoire    : 06 Class Date & Person
Nom de fichier : Date.h
Auteur(s)      : Tobie Praz & Richard V. M. Tenorio
Date création  : 02.01.21
Description    : <remplir>
Remarque(s)    : <remplir>
Compilateur    : gcc version 10.2.0 (Homebrew GCC 10.2.0) & Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/

#ifndef LABO_06_DATE_PERSON_DATE_H
#define LABO_06_DATE_PERSON_DATE_H

#include <string>

enum class Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

class Date {
private:
    unsigned day = 1,
             month = 1,
             year = 1900;
    bool     correct = true;
public:
    Date() = default;
    explicit Date(const std::string&);
    Date(unsigned day, unsigned month, unsigned year);
    Date(const Date& date);

    void setDay(unsigned);
    void setMonth(unsigned);
    void setMonth(Month);
    void setMonth(const std::string&);
    void setYear(unsigned);

    unsigned getDay() const;
    unsigned getMonthNo() const;
    Month getMonthEnum() const;
    std::string getMonthString() const;
    unsigned getYear() const;

    bool operator<(const Date &rhs) const;
    bool operator>(const Date &rhs) const;
    bool operator<=(const Date &rhs) const;
    bool operator>=(const Date &rhs) const;
    bool operator==(const Date &rhs) const;
    bool operator!=(const Date &rhs) const;

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    Date& operator+=(int);
    Date& operator-=(int);

    friend Date operator+(Date lhs, int rhs);
    friend Date operator+(int lhs, const Date& rhs);
    friend Date operator-(Date lhs, int rhs);

    explicit operator std::string() const;

    bool isValid() const;
    static bool isValid(unsigned day, unsigned month, unsigned year);

    bool isLeapYear() const;
    static bool isLeapYear(unsigned year);

    unsigned numberDaysInMonth() const;
    static unsigned numberDaysInMonth(unsigned, unsigned);

    friend std::ostream& operator<<(std::ostream &os, const Date &date);

};

#endif //LABO_06_DATE_PERSON_DATE_H
