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
    Date(unsigned day, unsigned month, unsigned year) : day(day), month(month), year(year){};
    Date(const Date& date) : day(date.day), month(date.month), year(date.year) {};

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

    friend bool operator<(const Date &lhs, const Date &rhs);
    friend bool operator>(const Date &lhs, const Date &rhs);
    friend bool operator<=(const Date &lhs, const Date &rhs);
    friend bool operator>=(const Date &lhs, const Date &rhs);
    friend bool operator==(const Date &lhs, const Date &rhs);
    friend bool operator!=(const Date &lhs, const Date &rhs);

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    Date& operator+=(int);
    Date& operator-=(int);

    friend Date operator+(Date lhs, int rhs);
    friend Date operator+(int lhs, const Date& rhs);
    friend Date operator-(Date lhs, int rhs);

    // TODO: check if this one is needed
    //Date& operator=(Date rhs) {};
    //Date& operator=(const Date &rhs) {}; <-- page 89 pdf
    // TODO: check how to do this one
    // usecase => d4 = {11, 03, 1978}        : 11-03-1978
    // Date& operator=(Date &lhs,unsigned day, unsigned month, unsigned year);
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
