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

Person::~Person() {
    Person::id--;
}

unsigned Person::nbrePerson() {
    return Person::id;
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
