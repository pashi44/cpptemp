#include "PersonOne.hpp"
// BasePerson class implementation
template <typename T, typename S, typename K>
BasePerson<T, S, K>::BasePerson(const T &age, const S &name, const K &occupation)
    : age(age), name(name), occupation(occupation) {} // Using initializer list
template <typename T, typename S, typename K>
BasePerson<T, S, K> BasePerson<T, S, K>::getObject()
{
    return *this;
}
template <typename T, typename S, typename K>
T BasePerson<T, S, K>::getage() const
{
    return age;
}
template <typename T, typename S, typename K>
S BasePerson<T, S, K>::getname() const
{
    return name;
}
template <typename T, typename S, typename K>
K BasePerson<T, S, K>::getoccupation() const
{
    return occupation;
}
template <typename T, typename S, typename K>
void BasePerson<T, S, K>::showDetails() const
{
    std::cout << "BasePerson: Age: " << age << ", Name: " << name << ", Occupation: " << occupation << std::endl;
    // std::cin;
}
// ExtendedBasePerson class implementation
template <typename T, typename S, typename K, typename J>
ExtendedBasePerson<T, S, K, J>::ExtendedBasePerson(const T &age, const S &name, const K &occupation, const J &gender)
    : BasePerson<T, S, K>(age, name, occupation), gender(gender)
{
} // Using initializer list
template <typename T, typename S, typename K, typename J>
J ExtendedBasePerson<T, S, K, J>::getGender() const
{
    return gender;
}
// ExtendedBasePerson
template <typename T, typename S, typename K, typename J>
void ExtendedBasePerson<T, S, K, J>::showDetails() const
{
    // Calling the base class's showDetails
    BasePerson<T, S, K>::showDetails();
    std::cout << "Gender: " << gender << std::endl;
}
// PersonOne class implementation
template <typename T, typename S, typename K, typename J, typename L>
PersonOne<T, S, K, J, L>::PersonOne(const T &age, const S &name, const K &occupation, const J &gender, const L &affair)
    : ExtendedBasePerson<T, S, K, J>(age, name, occupation, gender), affair(affair)
{
} // Using initializer list
template <typename T, typename S, typename K, typename J, typename L>
L PersonOne<T, S, K, J, L>::getaffair() const
{
    return affair;
}
template <typename T, typename S, typename K, typename J, typename L>
void PersonOne<T, S, K, J, L>::showDetails() const
{
    // Calling the base class's showDetails
    ExtendedBasePerson<T, S, K, J>::showDetails();
    std::cout << "Gender: " << (*this).affair << std::endl;
}
