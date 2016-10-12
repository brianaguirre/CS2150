#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp


//Middle Earth Class:
//Generates map and places random cities based on the list found in middleearth.cpp
class MiddleEarth {
private:

  int num_city_names, xsize, ysize; //Number of cities generated, Width, Height (The last two are the dimensions of the map)
  vector<float> xpos, ypos; //Vector that contains the x and y positions of the map - given in floats.
  vector<string> cities;  //Vector that contains all the cities within the map
  float *distances; //Distance within maps, shows the coordinates of the position
  map<string, int> indices; //Map for the game: has the name of the city and index for that city
  
public:
  //Constructor used to read from command line:
  //Takes in 4 parameters:
  //xsize -  width for the map
  //ysize - height for the map
  //num citites - number of cities within the map.
  //seed - random seed
  MiddleEarth (int xsize, int ysize, int numcities, int seed);

  //Destructor for all the allocated arrays for the map:
  ~MiddleEarth();

  //Prints out to user the things generated on the map.
  void print();

  //Prints out information on the cities - generally shows the distances
  //between points and randomized cities.
  void printTable();

  //Gets the specific distance between two citites. 
  //Not just the generic distance but rather computes the average
  //Based on the code under middleearth.cpp
  float getDistance (string city1, string city2);

  //Shows the complete list of the cities to travel.
  //Since we travel through the cities and then come back
  //Taking into account the traveling salesman, the first city is also 
  //The one we end up at.
  vector<string> getItinerary(unsigned int length);
};

#endif