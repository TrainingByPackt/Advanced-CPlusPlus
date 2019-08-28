//============================================================================
// Name        : exercise4.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 4 Lesson 3
//============================================================================
#include <memory>
#include <iostream>
#include <type_traits>
#include "sensors.hpp"

#define  EXERCISE4_STEP     1

template<typename SP>
void printSharedPointer(SP sp, const char* message)
{
        std::cout << std::boolalpha;
        std::cout << message << "\n";
        std::cout << "    SharedP: Empty=" << !(bool)sp << ", # owners=" << sp.use_count() << "\n";
}

template<typename SP>
void printUniquePointer(SP& sp, const char* message)
{
    std::cout << std::boolalpha;
    std::cout << message << "\n";
    std::cout << "    UniqP: Empty=" << !(bool)sp << "\n";
}

enum class SensorType
{
    Light,
    Temperature,
    Pressure
};

std::unique_ptr<ISensor>
createSensor(SensorType type)
{
    std::unique_ptr<ISensor> sensor;

    if (type == SensorType::Light)
    {
        sensor.reset(new LightSensor);
    }
    else if (type == SensorType::Temperature)
    {
        sensor.reset(new TemperatureSensor);
    }
    else if (type == SensorType::Pressure)
    {
        sensor.reset(new PressureSensor);
    }
    return sensor;
}

using SensorSPtr=std::shared_ptr<ISensor>;

void testSensors()
{
    auto light = createSensor(SensorType::Light);
    auto pressure = createSensor(SensorType::Pressure);
    auto temperature = createSensor(SensorType::Temperature);

    std::cout << "Light reading is " << light->read() << "\n";
    printUniquePointer(light, "light sensor");


#if EXERCISE4_STEP >= 5
    SensorSPtr light2 = light;
    printUniquePointer(light, "After move");
    std::cout << "Light2 reading is " << light2->read() << "\n";
    printSharedPointer(light2, "Light 2");
#endif

#if EXERCISE4_STEP >= 12

    light = createSensor(SensorType::Light);
    printUniquePointer(light, "Second light");

    SensorSPtr light3(std::move(light));
    printSharedPointer(light3, "Light 3");
    light3 = light2;
    printSharedPointer(light3, "Light 3");
#endif
}

void testArrays()
{
    std::unique_ptr<int []> board = std::make_unique<int []>(8*8);

    for(int i=0  ; i<8 ; i++)
        for(int j=0 ; j<8 ; j++)
            board[i*8+j] = 10*(i+1)+j+1;

    for(int i=0  ; i<8 ; i++)
    {
        char sep{' '};
        for(int j=0 ; j<8 ; j++)
            std::cout << board[i*8+j] << sep;
        std::cout << "\n";
    }
}

int main()
{
    std::cout << "\n\n------ Exercise 4 ------\n";
#if EXERCISE4_STEP >= 15
    testArrays();
#else
    testSensors();
#endif
    std::cout << "------ Complete. -------\n";
}



