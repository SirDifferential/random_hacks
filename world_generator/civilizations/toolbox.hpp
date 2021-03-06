#ifndef _TOOLBOX_HPP_
#define _TOOLBOX_HPP_

// This class contains various collected tools and utilies
// It has spanners, drills, hammers... you name it

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "creature.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#ifdef WIN32
#include <windows.h>
#endif

class Toolbox
{
private:
public:
    Toolbox();
    ~Toolbox();
    
    int timesRandomized;
    
    int giveRandomInt();
    int giveRandomInt(int min, int max);
    
    bool fileExists(std::string path);
    SDL_Color getRandomColor();
    SDL_Color getBWColor(SDL_Color in);
    
    std::string searchFile(int range, std::string path);
    
    std::string appendToStringNTimes(std::string in, int numOfTimes);
    std::string charToString(char c);
    std::string intToString(int i);
    std::string resolutionToString(int sizeX, int sizeY);
    int boolToInt(bool b);
    std::vector<int> doubleVectorToIntVector(std::vector<double> in);
    std::string stripString(std::string source, int quantity, std::string mode);
    std::string relativePathToAbsolute(std::string path);
    std::string reverseString(std::string toReverse);
    std::string combineStringAndInt(std::string in1, int in2);
    std::string combineStringAndInts(std::string in1, int in2, int in3);

    template <class T>
    typename std::vector<T>::const_iterator searchElementFromVector(const std::vector<T>& v, const T& toFind);

    float** giveFloatArray2D(int sizeX, int sizeY);
    float*** giveFloatArray3D(int sizeX, int sizeY, int sizeZ);
    void clearFloatArray2D(float** arr, int sizeX, int sizeY);
    void deleteFloatArray2D(float** arr, int sizeX);
    void clearFloatArray3D(float*** arr, int sizeX, int sizeY, int sizeZ);
    void deleteFloatArray3D(float*** arr, int sizeX, int sizeY);
};


// Performs a std::find for a vector of generic type
// Returns an iterator pointing to the element if found, else the end of the vector
template <class T>
typename std::vector<T>::const_iterator Toolbox::searchElementFromVector(const std::vector<T>& v, const T& toFind)
{
    return std::find(v.begin(), v.end(), toFind);
}

extern Toolbox tbox;

#endif
