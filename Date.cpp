/*-----------------------------------------------------------------------------------
Laboratoire    : 06 Class Date & Person
Nom de fichier : Date.cpp
Auteur(s)      : Tobie Praz & Richard V. M. Tenorio
Date création  : 02.01.21
Description    : <remplir>
Remarque(s)    : <remplir>
Compilateur    : gcc version 10.2.0 (Homebrew GCC 10.2.0) & Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/

#include <string>
#include <array>
#include <algorithm>
#include "Date.h"

using namespace std;

const size_t MONTHS = 12;
array<string, MONTHS> monthsNames = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
};

Date::Date(const std::string &date) {
    this->day = stoi(date.substr(0, 2));
    this->month = stoi(date.substr(3, 2));
    this->year = stoi(date.substr(6, 4));
}

Date::Date(unsigned day, unsigned month, unsigned year) : day(day), month(month), year(year) {}

Date::Date(const Date &date) : day(date.day), month(date.month), year(date.year) {}


//TODO: Set `Date::correct` in setters
void Date::setDay(unsigned d) {
    this->day = d;
}

void Date::setMonth(unsigned m) {
    this->month = m;
}

void Date::setMonth(Month m) {
    this->month = int(m);
}

void Date::setMonth(const std::string &m) {
    auto it = find(monthsNames.begin(), monthsNames.end(), m);

    if (it != monthsNames.end()) {
        this->month = (it - monthsNames.begin()) + 1;
    }
}

void Date::setYear(unsigned y) {
    this->year = y;
}


unsigned Date::getDay() const {
    return this->day;
}

unsigned Date::getMonthNo() const {
    return this->month;
}

Month Date::getMonthEnum() const {
    return Month(this->month);
}

std::string Date::getMonthString() const {
    return monthsNames.at(this->month - 1);
}

unsigned Date::getYear() const {
    return this->year;
}


bool Date::operator<(const Date &rhs) const {
    if(!(this->correct && rhs.correct)) return false;
    return this->year < rhs.year || this->month < rhs.month || this->day < rhs.day;
}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    if(!(this->correct && rhs.correct)) return false;
    return !(*this > rhs);
}

bool Date::operator>=(const Date &rhs) const {
    if(!(this->correct && rhs.correct)) return false;
    return !(*this < rhs);
}

bool Date::operator==(const Date &rhs) const {
    if(!(this->correct && rhs.correct)) return false;
    return this->year == rhs.year && this->month == rhs.month && this->day == rhs.day;
}

bool Date::operator!=(const Date &rhs) const {
    if(!(this->correct && rhs.correct)) return false;
    return !(*this == rhs);
}


unsigned Date::numberDaysInMonth(unsigned currentMonth, unsigned currentYear) {
    unsigned nbrDaysInMonth = currentMonth <= 7 ? currentMonth % 2 ? 31 : 30 : currentMonth % 2 ? 30 : 31;

    if (currentMonth == int(Month::FEBRUARY)) {
        nbrDaysInMonth = 28;
        if (Date::isLeapYear(currentYear)) {
            nbrDaysInMonth = 29;
        }
    }

    return nbrDaysInMonth;
}

unsigned Date::numberDaysInMonth() const {
    return numberDaysInMonth(this->month, this->year);
}


Date &Date::operator++() {
    return *this += 1;
}

Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

Date &Date::operator--() {
    return *this -= 1;
}

Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
}

Date &Date::operator+=(int rhs) {
    if (!this->correct) {
        return *this;
    }

    if (rhs < 0) {
        return *this -= -rhs;
    }

    unsigned nbrDaysInMonth = Date::numberDaysInMonth(this->getMonthNo(), this->getYear());

    while (this->day + rhs > nbrDaysInMonth) {
        rhs -= (nbrDaysInMonth - this->day) + 1;
        this->day = 1;
        if (this->month + 1 > 12) {
            ++this->year;
            this->month = 1;
        } else {
            ++this->month;
        }
        nbrDaysInMonth = Date::numberDaysInMonth(this->getMonthNo(), this->getYear());
    }
    this->day += rhs;

    return *this;
}

Date &Date::operator-=(int rhs) {
    if (!this->correct) {
        return *this;
    }

    if (rhs < 0) {
        return *this += -rhs;
    }

    while ((int) this->day - rhs < 1) {
        unsigned previousMonth = this->getMonthNo() - 1;
        unsigned nbrDaysInPreviousMonth = Date::numberDaysInMonth(previousMonth ? previousMonth : 12, this->getYear());
        rhs -= this->day;
        this->day = nbrDaysInPreviousMonth;
        if (this->month - 1 < 1) {
            --this->year;
            this->month = 12;
        } else {
            --this->month;
        }
    }
    this->day -= rhs;

    return *this;
}

Date operator+(Date lhs, int rhs) {
    return lhs += rhs;
}

Date operator+(int lhs, const Date &rhs) {
    return rhs + lhs;
}

Date operator-(Date lhs, int rhs) {
    return lhs -= rhs;
}

Date::operator std::string() const {
    return string(to_string(day) + '-' + to_string(month) + '-' + to_string(year));
}

bool Date::isValid() const {
    return Date::isValid(this->day, this->month, this->year);
}

bool Date::isValid(unsigned day, unsigned month, unsigned year) {
    return month >= (int) Month::JANUARY && month <= (int) Month::DECEMBER && day <= numberDaysInMonth(month, year);
}

bool Date::isLeapYear(unsigned year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

bool Date::isLeapYear() const {
    return Date::isLeapYear(this->year);
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    string res = date.isValid() ? string(date) : "Invalid date";
    os << res;
    return os;
}