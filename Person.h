/*-----------------------------------------------------------------------------------
Laboratoire    : 06 Class Date & Person
Nom de fichier : Person.h
Auteur(s)      : Tobie Praz & Richard V. M. Tenorio
Date création  : 02.01.21
Description    : <remplir>
Remarque(s)    : <remplir>
Compilateur    : gcc version 10.2.0 (Homebrew GCC 10.2.0) & Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/

#ifndef LABO_06_DATE_PERSON_PERSON_H
#define LABO_06_DATE_PERSON_PERSON_H
#include <string>
#include <utility>
#include "Date.h"

enum class PERSON {
    NO_ID,
    LASTNAME,
    FIRSTNAME,
    DATE
};

class Person {
private:
    static unsigned id;
    const std::string& lastName;
    const std::string& firstName;
    const Date        date;
    const unsigned    noId;

public:
    Person(const std::string &firstname, const std::string &lastname, const Date& date)
    : firstName(firstname), lastName(lastname), date(date), noId(id++) {};

    static unsigned nbrePerson(){};

    friend std::ostream& operator<<(std::ostream &os, const Person &rhs){};
    Person& operator=(const Person &rhs) {};
};

class SortBy{
private:
    PERSON by;
public:
    explicit SortBy(PERSON by) : by(by){};

    bool operator()(const Person &lhs, const Person &rhs){};
};


class FindBy{
private:
    PERSON by;
    const std::string& str;
public:
    FindBy(PERSON by, const std::string &str) : by(by), str(str) {};
    bool operator()(const Person &person){};
};


#endif //LABO_06_DATE_PERSON_PERSON_H
