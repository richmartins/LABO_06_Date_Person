/*-----------------------------------------------------------------------------------
Laboratoire    : 06 Class Date & Person
Nom de fichier : Person.cpp
Auteur(s)      : Tobie Praz & Richard V. M. Tenorio
Date création  : 02.01.21
Description    : <remplir>
Remarque(s)    : <remplir>
Compilateur    : gcc version 10.2.0 (Homebrew GCC 10.2.0) & Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/

#include <string>
#include "Person.h"

unsigned Person::id = 0;
unsigned Person::counter = 0;

Person::Person(const std::string &lastname, const std::string &firstname, const Date& date)
        : lastName(lastname), firstName(firstname), date(date), noId(++id) {
    ++counter;
}

Person::Person(const Person &person) : firstName(person.firstName), lastName(person.lastName), date(person.date), noId(person.noId) {
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


std::ostream& operator<<(std::ostream &os, const Person &rhs) {
    return os << rhs.getFirstName() + " "     + rhs.getLastName()
                                    + " "     + rhs.getDateString()
                                    + " (id=" + rhs.getIdNoString() + ")";
}

Person& Person::operator=(const Person &rhs) {
    return const_cast<Person &>(rhs);
}

SortBy::SortBy(PERSON by) : by(by) {}

bool SortBy::operator()(const Person &lhs, const Person &rhs) {
    switch (by) {
        case PERSON::FIRSTNAME : {
            return lhs.getFirstName().compare(rhs.getFirstName()) <= 0;
        }
        case PERSON::LASTNAME : {
            return lhs.getLastName().compare(rhs.getLastName()) <= 0;
        }
        case PERSON::NO_ID : {
            return lhs.getIdNo() < rhs.getIdNo();
        }
        case PERSON::DATE : {
            return lhs.getDate() < rhs.getDate();
        }
        default : {
            return false;
        }
    }
}


FindBy::FindBy(PERSON by, const std::string &str) : by(by), str(str) {}

bool FindBy::operator()(const Person &person) {
    switch (by) {
        case PERSON::FIRSTNAME : {
            return person.getFirstName() == str;
        }
        case PERSON::LASTNAME : {
            return person.getLastName() == str;
        }
        case PERSON::NO_ID : {
            return person.getIdNoString() == str;
        }
        case PERSON::DATE : {
            return person.getDateString() == str;
        }
        default : return false;
    }
}