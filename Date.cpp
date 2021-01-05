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

Date::Date(const std::string &date){
    this->day = stoi(date.substr(0,1));
    this->month = stoi(date.substr(3,4));
    this->day = stoi(date.substr(6,9));
}

void Date::setDay(unsigned d) {
    this->day = d;
}


void Date::setMonth(unsigned m) {
    this->month = m;
}

void Date::setMonth(Month m){
    this->month = int(m);
}


void Date::setYear(unsigned y){
    this->year = y;
}


void Date::setMonth(const std::string &m){
    auto it = find(monthsNames.begin(), monthsNames.end(), m);

    if(it != monthsNames.end()){
        this->month = (it - monthsNames.begin()) +1;
    }
}

unsigned Date::getDay() const{
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

bool operator<(const Date &lhs, const Date &rhs){
    return lhs.year < rhs.year || lhs.month < rhs.month ||  lhs.day < rhs.day;
}

bool operator>(const Date &lhs, const Date &rhs){
    return rhs < lhs;
}

bool operator<=(const Date &lhs, const Date &rhs){
    return !(lhs > rhs);
}

bool operator>=(const Date &lhs, const Date &rhs){
    return !(lhs < rhs);
}

bool operator==(const Date &lhs, const Date &rhs){
    return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}

bool operator!=(const Date &lhs, const Date &rhs){
    return !(lhs == rhs);
}

Date& Date::operator++() {
    return *(this + 1);
}

Date Date::operator++(int) {
    Date temp = *(this + 1);
    return temp;
}
Date& Date::operator--() {
    return *(this - 1);
}
Date Date::operator--(int) {
    Date temp = *(this + 1);
    return temp;
}
Date& Date::operator+=(int){}
Date& Date::operator-=(int){}

unsigned Date::numberDaysInMonth(unsigned currentMonth, unsigned currentYear) {
    unsigned nbrDaysInMonth = currentMonth <= 7 ? currentMonth % 2 ? 31 : 30 : currentMonth % 2 ? 30 : 31;

    if(currentMonth == int(Month::FEBRUARY)){
        nbrDaysInMonth = 28;
        if(Date::isLeapYear(currentYear)) {
            nbrDaysInMonth = 29;
        }
    }

    return nbrDaysInMonth;
}


unsigned Date::numberDaysInMonth() const{
    return numberDaysInMonth(this->month, this->day);
}

Date operator+(Date lhs, int rhs) {
    unsigned nbrDaysInMonth =  Date::numberDaysInMonth(lhs.getMonthNo(), lhs.getYear());

    if(lhs.day + rhs > nbrDaysInMonth){
        lhs.day = 1;
        if(lhs.month + 1 > 12){
            lhs.year += 1;
            lhs.month = 1;
        } else {
            lhs.month += 1;
        }
    } else {
        lhs.day += rhs;
    }

    return lhs;
}
Date operator+(int lhs, const Date& rhs) {
    return rhs + lhs;
}

Date operator-(Date lhs, int rhs) {
    unsigned nbrDaysInPreviousMonth = Date::numberDaysInMonth((lhs.getMonthNo() - 1), lhs.getYear());

    if(lhs.day - rhs < 1){
        if(lhs.month - 1 < 1){
            lhs.year -= 1;
            lhs.month = 12;
            lhs.day = 31;
        } else {
            lhs.day = nbrDaysInPreviousMonth;
        }
    } else {
        lhs.day -= rhs;
    }

    return lhs;
}

Date::operator std::string() const {
    return string(to_string(day) + '-' + to_string(month) + '-' + to_string(year));
}

bool Date::isValid() const{
    return Date::isValid(this->day, this->month, this->year);
}
bool Date::isValid(unsigned day, unsigned month, unsigned year){
    return day < numberDaysInMonth(month, year);
}

bool Date::isLeapYear(unsigned year){
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

bool Date::isLeapYear() const{
    return Date::isLeapYear(this->year);
}

std::ostream& operator<<(std::ostream &os, const Date &date) {
    string res = date.isValid() ? string(date) : "Invalid date";
    os << res;
    return os;
}