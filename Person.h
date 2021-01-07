/*-----------------------------------------------------------------------------------
Laboratoire    : 06 Class Date & Person
Nom de fichier : Person.h
Auteur(s)      : Tobie Praz & Richard V. M. Tenorio
Date création  : 02.01.21
Description    : Classe Person
Remarque(s)    : -
Compilateur    : gcc version 10.2.0 (Homebrew GCC 10.2.0) & Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/

#ifndef LABO_06_DATE_PERSON_PERSON_H
#define LABO_06_DATE_PERSON_PERSON_H

#include <string>
#include <vector>
#include "Date.h"

enum class PERSON {
    NO_ID,
    LASTNAME,
    FIRSTNAME,
    DATE
};

class Person {
private:
    static unsigned    id;
    static unsigned    counter;
    const unsigned     noId;
    const std::string  lastName;
    const std::string  firstName;
    const Date         date;

public:

    /**
     * @section description
     * Constructeur a trois 3 parametres
     *
     * @param std::string firstname
     * @param std::string lastname
     * @param Date date
     */
    Person(std::string firstname, std::string lastname, const Date &date);

    /**
     * @section description
     * constructeur par copie
     *
     * @param Person person
     */
    Person(const Person& person);

    /**
     * @section descritption
     * desctructeur
     */
    ~Person();

    /**
     * @section description
     * getteur pour l'attribut id_no
     *
     * @return unsigned
     */
    unsigned getIdNo() const;

    /**
     * @section description
     * getteur pour l'attribut id_no en string
     *
     * @return std::string
     */
    std::string getIdNoString() const;

    /**
     * @section description
     * getteur pour l'attribut date en string
     *
     * @return std::string
     */
    std::string getDateString() const;

    /**
     * @section description
     * getteur pour l'attribut date
     *
     * @return Date
     */
    Date getDate() const;

    /**
     * @section description
     * getteur pour l'attribut firstname
     *
     * @return std::string
     */
    std::string getFirstName() const;

    /**
     * @section description
     * getteur pour l'attribut lastname
     *
     * @return std::string
     */
    std::string getLastName() const;

    /**
     * @section description
     * methode qui retourne le nombre de personne instancier
     *
     * @return unsigned
     */
    static unsigned nbrePerson();
    /**
     * @section description
     * surcharge de l'operateur d'affectation
     *
     * @param const Person
     * @return Person&
     */
    Person& operator=(const Person &person);

    /**
     * @section description
     * surcharge de l'operateur decalage de bit a gauche
     *
     * @param std::ostream os flux
     * @param const Person rhs
     * @return std::ostream
     */
    friend std::ostream& operator<<(std::ostream &os, const Person &rhs);

};

class SortBy{
private:
    PERSON by;
public:
    /**
     * @section description
     * Constructeur de foncteur
     *
     * @param PERSON by
     */
    explicit SortBy(PERSON by);
    /**
     * @section description
     *
     * surchage de l'operateur parenthese
     *
     * @param lhs
     * @param rhs
     * @return
     */
    bool operator()(const Person &lhs, const Person &rhs);
};


class FindBy{
private:
    PERSON by;
    const std::string& str;
public:

    /**
     * @section description
     * constructeur de foncteur
     *
     * @param PERSON by
     * @param std::string str
     */
    FindBy(PERSON by, const std::string &str);

    /**
     * @section description
     * surchage de l'operateur parenthese
     *
     * @param person
     * @return bool
     */
    bool operator()(const Person &person);
};

#endif //LABO_06_DATE_PERSON_PERSON_H
