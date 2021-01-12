/*-----------------------------------------------------------------------------------
Laboratoire    : 06 Class Date & Person
Nom de fichier : Person.cpp
Auteur(s)      : Tobie Praz & Richard V. M. Tenorio
Date création  : 02.01.21
Description    : Définition de la classe Person
                 - Accesseurs
                 - Définition des foncteurs SortBy et FindBy
Remarque(s)    : -
Compilateur    : gcc version 10.2.0 (Homebrew GCC 10.2.0) & Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/

#include <string>
#include "Person.h"
#include <cassert>

unsigned Person::id      = 0;
unsigned Person::counter = 0;

Person::Person(std::string lastname, std::string firstname, const Date &date)
        : lastName(lastname), firstName(firstname), date(date), noId(++id) {
    ++counter;
}

Person::Person(const Person &person) : firstName(person.firstName), lastName(person.lastName),
                                       date(person.date), noId(person.noId) {
    ++counter;
}

Person::~Person() {
    --counter;
}

unsigned Person::nbrePerson() {
    return counter;
}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getLastName() const {
    return lastName;
}

unsigned Person::getIdNo() const {
    return noId;
}

std::string Person::getIdNoString() const {
    return std::to_string(noId);
}

std::string Person::getDateString() const {
    return std::string(date);
}

Date Person::getDate() const {
    return date;
}


std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    return os << rhs.getLastName() + " " + rhs.getFirstName()
                 + " " + rhs.getDateString()
                 + " (id=" + rhs.getIdNoString() + ")";
}

Person &Person::operator=(const Person &person) {
    if (this != &person) {
        (std::string &) lastName  = person.lastName;
        (std::string &) firstName = person.firstName;
        (Date &)             date = person.date;
        (unsigned &)         noId = person.noId;
    }
    return *this;
}


SortBy::SortBy(PERSON by) : by(by) {}

bool SortBy::operator()(const Person &lhs, const Person &rhs) {
    switch (by) {
        case PERSON::NO_ID : {
            return lhs.getIdNo() < rhs.getIdNo();
        }
        case PERSON::DATE : {
            return lhs.getDate() < rhs.getDate();
        }
        case PERSON::FIRSTNAME : {
            return lhs.getFirstName() < rhs.getFirstName();
        }
        case PERSON::LASTNAME : {
            return lhs.getLastName() < rhs.getLastName();
        }
        default : {
            assert(false);
        }
    }
}


FindBy::FindBy(PERSON by, const std::string &str) : by(by), str(str) {}

bool FindBy::operator()(const Person &person) {
    switch (by) {
        case PERSON::FIRSTNAME : {
            return person.getFirstName()  == str;
        }
        case PERSON::LASTNAME : {
            return person.getLastName()   == str;
        }
        case PERSON::NO_ID : {
            return person.getIdNoString() == str;
        }
        case PERSON::DATE : {
            return person.getDateString() == str;
        }
        default :
            return false;
    }
}