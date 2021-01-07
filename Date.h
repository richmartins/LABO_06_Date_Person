/*-----------------------------------------------------------------------------------
Laboratoire    : 06 Class Date & Person
Nom de fichier : Date.h
Auteur(s)      : Tobie Praz & Richard V. M. Tenorio
Date création  : 02.01.21
Description    : Classe Date
Remarque(s)    : -
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
    bool correct = true;
public:

    /**
     * @section description
     * Constructeur par defaut
     *
     */
    Date() = default;

    /**
     * @section description
     * constructeur avec un string comme parametre
     *
     */
    explicit Date(const std::string &);

    /**
     * @section description
     * constructeur avec 3 parametres
     *
     * @param unsigned day
     * @param unsigned month
     * @param unsigned year
     */
    Date(unsigned day, unsigned month, unsigned year);

    /**
     * @section description
     * constructeur de copie
     *
     * @param Date date
     */
    Date(const Date &date);

    /**
     * @section description
     * setteur pour l'attribut day
     *
     */
    void setDay(unsigned);

    /**
     * @section description
     * setteur pour l'attribut month
     *
     */
    void setMonth(unsigned);

    /**
     * @section description
     * setteur pour l'attribut month avec Month comme parametre
     *
     */
    void setMonth(Month);

    /**
     * @section description
     * setteur pour l'attribut month avec un std::string comme parametre
     *
     */
    void setMonth(const std::string &);

    /**
     * @section description
     * setteur pour l'attribut year avec un unsigned
     *
     */
    void setYear(unsigned);

    /**
     * @section description
     * getteur pour l'attribut day
     *
     * @return unsigned
     */
    unsigned getDay() const;

    /**
     * @section description
     * getteur pour l'attribut day
     *
     * @return
     */
    unsigned getMonthNo() const;

    /**
     * @section description
     * getteur pour l'attribut month comme type Month
     *
     * @return Month
     */
    Month getMonthEnum() const;

    /**
     * @section description
     * getteur pour l'attribut month comme type std::string
     *
     * @return std::string
     */
    std::string getMonthString() const;

    /**
     * @section description
     * getteur pour l'attribut year
     *
     * @return unsigned
     */
    unsigned getYear() const;

    /**
     * @section description
     * surcharge de l'operateur "inferieur a"
     *
     * @param Date rhs
     * @return bool
     */
    bool operator<(const Date &rhs) const;

    /**
     * @section description
     * surcharge de l'operateur "superieur a"
     *
     * @param Date rhs
     * @return bool
     */
    bool operator>(const Date &rhs) const;

    /**
     * @section description
     * surcharge de l'operateur "inferieur ou egal a"
     *
     * @param Date rhs
     * @return bool
     */
    bool operator<=(const Date &rhs) const;

    /**
     * @section description
     * surcharge de l'operateur "superieur ou egal a"
     *
     *
     * @param rhs
     * @return
     */
    bool operator>=(const Date &rhs) const;

    /**
     * @section description
     * surcharge de l'operateur bien egalite
     *
     * @param Date rhs
     * @return bool
     */
    bool operator==(const Date &rhs) const;

    /**
     * @section description
     * surcharge de l'operateur inegalite
     *
     * @param Date rhs
     * @return bool
     */
    bool operator!=(const Date &rhs) const;

    /**
     * @section description
     * surchage de l'operateur increment prefix
     *
     * @return bool
     */
    Date &operator++();

    /**
     * @section description
     * surcharge de l'operateur increment postfix
     *
     * @return Date&
     */
    Date operator++(int);

    /**
     * @section description
     * surcharge de l'operateur decrement prefix
     *
     * @return Date&
     */
    Date &operator--();

    /**
     * @section description
     * surcharge de l'operateur decrement postfix
     *
     * @return Date
     */
    Date operator--(int);

    /**
     * @section description
     * surcharge de l'operateur plus egale
     *
     * @return Date&
     */
    Date &operator+=(int);

    /**
     * @section description
     * surcharge de l'operateur moins egale
     *
     * @return
     */
    Date &operator-=(int);

    /**
     * @section description
     * surcharge de l'operateur plus
     *
     * @param Date lhs
     * @param int rhs
     * @return Date
     */
    friend Date operator+(Date lhs, int rhs);

    /**
     * @section description
     * surcharge de l'operateur plus
     *
     * @param int lhs
     * @param Date rhs
     * @return Date
     */
    friend Date operator+(int lhs, const Date &rhs);

    /**
     * @section description
     * surcharge de l'operateur moins
     *
     * @param Date lhs
     * @param int rhs
     * @return Date
     */
    friend Date operator-(Date lhs, int rhs);

    /**
     * @section description
     * surcharge du cast par parenthese
     *
     * @return ???
     */
    explicit operator std::string() const;

    /**
     * @section description
     * methode membre qui determine si la dete est valide
     *
     * @return bool
     */
    bool isValid() const;

    /**
     * @section description
     * surcharge de la methode membre isValid avec 3 parametres
     *
     * @param unsigned day
     * @param unsigned month
     * @param unsigned year
     * @return bool
     */
    static bool isValid(unsigned day, unsigned month, unsigned year);

    /**
     * @section description
     * methode membre qui determine si c est une annee bissextile
     *
     * @return bool
     */
    bool isLeapYear() const;

    /**
     * @section surcharge de la fonction isLeapYear avec 1 parametres
     *
     * @param unsigned year
     * @return bool
     */
    static bool isLeapYear(unsigned year);

    /**
     * @section description
     * methode membre qui retourne le nombre dans un mois
     *
     * @return unsigned
     */
    unsigned numberDaysInMonth() const;

    /**
     * @section description
     * surcharge de la methode membre numberDaysInMonth
     *
     * @return static unsigned
     */
    static unsigned numberDaysInMonth(unsigned, unsigned);

    /**
     * @section description
     * surcharge de l operateur de decallage de bit a gauche
     *
     * @param ostream os flux
     * @param Date date
     * @return ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Date &date);

};

#endif //LABO_06_DATE_PERSON_DATE_H
