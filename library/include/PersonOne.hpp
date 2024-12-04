#ifndef PERSONONE_HPP
#define PERSONONE_HPP

#include <iostream>
#include <string>

class abstract
{
    virtual void showDetails() const = 0;
};

// BasePerson class definition
template <typename T, typename S, typename K>
class BasePerson : abstract
{
private:
    T age;
    S name;
    K occupation;

public:
    BasePerson(const T &age, const S &name, const K &occupation); // Constructor should take by value, not by reference
    BasePerson<T, S, K> getObject();
    T getage() const;
    S getname() const;
    K getoccupation() const;

    void showDetails() const override;

    virtual ~BasePerson() = default; // Virtual destructor for polymorphism
};

// ExtendedBasePerson class definition (derived from BasePerson)
template <typename T, typename S, typename K, typename J>
class ExtendedBasePerson : public BasePerson<T, S, K>
{
private:
    J gender;

public:
    ExtendedBasePerson(const T &age, const S &name, const K &occupation, const J &gender); // Constructor should take by value, not by reference
    void showDetails() const override;

    J getGender() const;
};

// PersonOne class definition (derived from ExtendedBasePerson)
template <typename T, typename S, typename K, typename J, typename L>
class PersonOne : public ExtendedBasePerson<T, S, K, J>
{
private:
    L affair;

public:
    PersonOne(const T &age, const S &name, const K &occupation, const J &gender, const L &affair); // Constructor should take by value, not by reference
    void showDetails() const override;

    L getaffair() const;
};

template class BasePerson<int, std::string, std::string>;
template class ExtendedBasePerson<int, std::string, std::string, std::string>;
template class PersonOne<int, std::string, std::string, std::string, std::string>;

#endif // PERSONONE_HPP
