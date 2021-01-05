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

array<string, 12> monthsNames = {
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
    //if(m >= Month::JANUARY && m <= Month::DECEMBER) {
        this->month = int(m);
    //}
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

std::string Date::getMonthString() {
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
    unsigned currentMonth = this->getMonthNo();
    unsigned nbrDaysInMonth = currentMonth <= 7 ? currentMonth % 2 ? 31 : 30 : currentMonth % 2 ? 30 : 31;

    if( this->getMonthEnum() == Month::FEBRUARY){
        nbrDaysInMonth = 28;
        if(this->isLeapYear()) {
            nbrDaysInMonth = 29;
        }
    }



    return *this;
}

Date Date::operator++(int) {}
Date& Date::operator--() {}
Date Date::operator--(int) {}
Date& Date::operator+=(int){}
Date& Date::operator-=(int){}

Date operator+(Date lhs, int rhs) {
    unsigned currentMonth = lhs.getMonthNo();
    unsigned nbrDaysInMonth = currentMonth <= 7 ? currentMonth % 2 ? 31 : 30 : currentMonth % 2 ? 30 : 31;

    if( lhs.getMonthEnum() == Month::FEBRUARY){
        nbrDaysInMonth = 28;
        if(lhs.isLeapYear()) {
            nbrDaysInMonth = 29;
        }
    }

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

Date operator-(Date lhs, int rhs) {}


bool Date::isValid(){}
bool Date::isValid(unsigned day, unsigned month, unsigned year){}

bool Date::isLeapYear(unsigned year){
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

bool Date::isLeapYear() const{
    return Date::isLeapYear(this->year);
}


