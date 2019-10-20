//============================================================================
// Name        : Exercise1.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 1 Lesson 3
//============================================================================
#include <iostream>
#include <vector>
#include <string>


class Wizard
{
public:
    Wizard(const char* name) : m_name(name) {} ;
    ~Wizard() {
        std::cout << "Destroying Wizard: " << m_name << "\n";
    }

    void speak()
    {
        std::cout << m_name << ": Abracadabara\n";
    }

    void act()
    {
        std::cout << m_name << ": Casts spell\n";
    }
    std::string m_name;
};

class Healer
{
public:
    Healer(const char* name) : m_name(name) {} ;
    ~Healer() {
        std::cout << "Destroying Healer: " << m_name << "\n";
    }

    void speak()
    {
        std::cout << m_name << ": Chill people\n";
    }

    void act()
    {
        std::cout << m_name << ": Applies soothing balm\n";
    }
    std::string m_name;
};


class Warrior
{
public:
    Warrior(const char* name) : m_name(name) {} ;
    ~Warrior() {
        std::cout << "Destroying Warrior: " << m_name << "\n";
    }

    void speak()
    {
        std::cout << m_name << ": Clobbering time\n";
    }

    void act()
    {
        std::cout << m_name << ": Hits the nearest bad guy\n";
    }
    std::string m_name;
};

int main(int argc, char**argv)
{
    std::cout << "\n------ Exercise 1 ------\n";
    Wizard wizard("Gandalf");
    Healer healer("Glenda");
    Warrior warrior("Ben Grimm");

    wizard.speak();
    healer.speak();
    warrior.speak();

    wizard.act();
    healer.act();
    warrior.act();

    std::cout << "Complete.\n";
    return 0;
}

