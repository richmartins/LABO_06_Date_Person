/*-----------------------------------------------------------------------------------
Laboratoire    : 05 Class Date & Person
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
#include "Date.h"

class Person {
private:
    const std::string lastName;
    const std::string firstName;
    const Date        date;
    const unsigned    noId;

};


#endif //LABO_06_DATE_PERSON_PERSON_H
