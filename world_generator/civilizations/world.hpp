#ifndef __WORLD_HPP_
#define __WORLD_HPP_

#include <memory>
#include <vector>


class Civilization;
class Region;

class World
{
private:
    int width;  // Multiple of 8 (km) (0, 8, 16, 24, 32...)
    int height; // Multiple of 8 (km)
    
    std::vector<std::shared_ptr<Region> > regions;
    std::vector<std::shared_ptr<Civilization> > civilizations;
    unsigned long currentCreatures;
    unsigned long pastCreatures;
    bool alive;
    long world_time;
public:
    World();
    ~World();
    
    void addRegion(int x, int y, int t, int h);
    void live();
    void die();
    void advanceTime();
    long getTime();
    void setTime(long t);
    std::vector<std::shared_ptr<Civilization> > getCivilizations();
    unsigned long getCurrentCreatures();
    unsigned long getPastCreatures();
};

#endif
