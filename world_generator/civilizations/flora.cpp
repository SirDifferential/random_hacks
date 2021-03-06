#include "flora.hpp"
#include "region.hpp"
#include <stdio.h>

Flora::Flora(long t)
{
    alive = true;
    birthTime = t;
    life = 100.0f;
    expectedLifeTime = 1000;
    lastReproduced = t;
    lastEaten = t;
}

Flora::~Flora()
{
}

void Flora::advanceTime(long t)
{
    if (region->getTemperature() < minTemperature || region->getTemperature() > maxTemperature
        || region->getHumidity() < minHumidity || region->getHumidity() > maxHumidity)
    {
        takeDamage(life/2);
    }
    if (t > birthTime + expectedLifeTime)
    {
        takeDamage(life);
    }

    if (t > lastReproduced + spreadRate)
    {
        lastReproduced = t;
        region->spreadFlora(this);
    }

    if (t > lastEaten + eatDelay)
    {
        lastEaten = t;

        // If there is no food, take damage and shorten food request time
        float receivedFood = region->givePlantFood(this);
        if (receivedFood < requiredSustenance)
        {
            takeDamage(5.0f);

            // How large % did we get?
            float percentage = receivedFood / requiredSustenance;

            // 100% == Next food time is as usual
            // 50% == Ask food when half of the usual time has passed
            lastEaten += (-1*eatDelay) + (eatDelay*percentage);
        }
    }
}

void Flora::takeDamage(float d)
{
    life -= d;
    if (life < 50)
        int b =5;
    if (life <= 1)
        die();
}

void Flora::die()
{
    fprintf(stderr, "Plant is dying\n");
    alive = false;
    region = NULL;
}

void Flora::setCoordX(int x)
{
    coord_x = x;
}

void Flora::setCoordY(int y)
{
    coord_y = y;
}

void Flora::setRegion(Region* r)
{
    region = r;
}

void Flora::setMass(float m)
{
    mass = m;
}

void Flora::setWidth(float w)
{
    width = w;
}

void Flora::setHeight(float h)
{
    height = h;
}

void Flora::setType(std::string t)
{
    type = t;
}

void Flora::setName(std::string n)
{
    name = n;
}

void Flora::setLastReproduced(long t)
{
    lastReproduced = t;
}

void Flora::setMinTemperature(float t)
{
    minTemperature = t;
}

void Flora::setMaxTemperature(float t)
{
    maxTemperature = t;
}

void Flora::setMinHumidity(float h)
{
    minHumidity = h;
}

void Flora::setMaxHumidity(float h)
{
    maxHumidity = h;
}

void Flora::setSpreadRate(float r)
{
    spreadRate = r;
}

int Flora::getCoordX()
{
    return coord_x;
}

int Flora::getCoordY()
{
    return coord_y;
}

Region* Flora::getRegion()
{
    return region;
}

float Flora::getWidth()
{
    return width;
}

float Flora::getHeight()
{
    return height;
}

float Flora::getMass()
{
    return mass;
}

std::string Flora::getType()
{
    return type;
}

long Flora::getLastReproduced()
{
    return lastReproduced;
}

std::string Flora::getName()
{
    return name;
}

float Flora::getMinTemperature()
{
    return minTemperature;
}

float Flora::getMaxTemperature()
{
    return maxTemperature;
}

float Flora::getMinHumidity()
{
    return minHumidity;
}

float Flora::getMaxHumidity()
{
    return maxHumidity;
}

float Flora::getSpreadRate()
{
    return spreadRate;
}

float Flora::getRequiredSustenance()
{
    return requiredSustenance;
}

void Flora::setRequiredSustenance(float r)
{
    requiredSustenance = r;
}

void Flora::setEatDelay(long t)
{
    eatDelay = t;
}

void Flora::setSpreadQuantity(int n)
{
    spreadQuantity = n;
}

void Flora::setLife(int n)
{
    life = n;
}

long Flora::getEatDelay()
{
    return eatDelay;
}

long Flora::getLastEaten()
{
    return lastEaten;
}

bool Flora::getAlive()
{
    return alive;
}

int Flora::getSpreadQuantity()
{
    return spreadQuantity;
}

int Flora::getLife()
{
    return life;
}

