//============================================================================
// Name        : sensors.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 4 Lesson 3
//============================================================================

#include <iostream>

struct ISensor
{
    virtual float read() const = 0;
    virtual ~ISensor() = default;
};

struct LightSensor : ISensor
{
    LightSensor() 
    {
        std::cout << "+++Create Light Sensor\n";
    }
    ~LightSensor() 
    {
        std::cout << "---Destroy Light Sensor\n";
    }

    float read() const override
    {
        return 11.0F;
    }
};

struct TemperatureSensor : ISensor
{
    TemperatureSensor() 
    {
        std::cout << "+++Create Temperature Sensor\n";
    }
    ~TemperatureSensor() 
    {
        std::cout << "---Destroy Temperature Sensor\n";
    }

    float read() const override
    {
        return 32.0F;
    }
};

struct PressureSensor : ISensor
{
    PressureSensor() 
    {
        std::cout << "+++Create Pressure Sensor\n";
    }
    ~PressureSensor() 
    {
        std::cout << "---Destroy Pressure Sensor\n";
    }

    float read() const override
    {
        return 56.0F;
    }
};
