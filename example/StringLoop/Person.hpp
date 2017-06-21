#ifndef NATIVE_EXAMPLE_PERSON_HPP
#define NATIVE_EXAMPLE_PERSON_HPP

#include <native/library.hpp>

class Person {
private:
    String fullname;
    Integer age;

public:

    /**
     * Person Constructor
     */
    Person() {
        this->fullname = "";
        this->age = 0;
    }

    /**
     * Person constructor with param `fullname' and `age'
     *
     * @param fullname
     * @param age
     */
    Person(String fullname, int age) {
        this->fullname = fullname;
        this->age = age;
    }

    /**
     * Person destructor
     */
    ~Person() {

    }

    /**
     * Set name for object Person
     *
     * @param fullname
     * @return *this
     */
    Person &setName(String fullname) {
        this->fullname = fullname;
        return *this;
    }

    /**
     * Set age for object Person
     *
     * @param age
     * @return *this
     */
    Person &setAge(int age) {
        this->age = age;
        return *this;
    }

    /**
     * Get name of object Person
     *
     * @return String
     */
    String getName() {
        return this->fullname;
    }

    /**
     * Get age of object Person
     *
     * @return Integer
     */
    Integer getAge() {
        return this->age;
    }

    /**
     * Override method output of Object Person
     *
     * @param os
     * @param target
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Person &target) {
        std::cout << "Full name: " << target.fullname.toString() << std::endl;
        std::cout << "Age: " << target.age.toString() << std::endl;
        return os;
    }
};

#endif //NATIVE_EXAMPLE_PERSON_HPP
