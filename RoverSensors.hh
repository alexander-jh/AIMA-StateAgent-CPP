extern "C" {
  #include <stdio.h>
  #include <stdlib.h>
  #include <strings.h>
}
#include <cstring>

/*
  SamplePercept: the object holding a soil sample perception
  
  Constructor: SamplePercept(char *text) converts text into integer percept
    representation of "text" should be ASCII
  value(): returns integer representation of percept

*/
class SamplePercept {
private:
  int myPercept;

public:
  SamplePercept(char *text);
  inline int value() { return myPercept;} ;
};




/*
  VisionPercept: the object holding vision perceptions (whether a
  square is clear or not)

  Constructor: VisionPercept(char *text) converts text into boolean percept
     value of line should either be "CLEAR" or "BOULDER"
  isClear(): returns char; value is 1 if percept is clear, 0 otherwise

*/

class VisionPercept {
private:
  // myPercept is true if the square is clear
  char myPercept;

public: 
  VisionPercept(char *line);
  inline char isClear() { return myPercept; }
};

/*
  RoverSampleSensor: a sensor object used in part 1 to parse the
  datafile and return observations.

  Constructor: RoverSampleSensor(char *filename): builds a sensor
    object from the file "filename"

  Constructor: RoverSampleSensor(): builds a sensor object from 
    the standard input

  getSamplePercept(): returns a pointer to the next SamplePercept
    MEMORY HANDLING: the memory is "owned" by RoverSampleSensor so you
      (the caller) don't have to delete it.
*/

class RoverSampleSensor {
private:
  FILE *myFile;
  SamplePercept *lastPercept;
  
public:
  RoverSampleSensor(char *filename);
  RoverSampleSensor();
  ~RoverSampleSensor();
  SamplePercept *getSamplePercept();
};



/*
  MovingRoverSensors: a group of sensors that will give observations
  for a particular square


  Constructor: MovingRoverSensors(char *filename): builds a sensor
    object from the file "filename"

  Constructor: MovingRoverSensors(): builds a sensor object from 
    the standard input

  getSamplePercept(int x, int y): returns a pointer to the SamplePercept
    found by sampling <x,y>
    MEMORY HANDLING: the memory is "owned" by MovingRoverSensors so you
      (the caller) don't have to delete it.

  getVisionPercept(int x, int y): returns a pointer to the VisionPercept
    found by examining <x,y>
    MEMORY HANDLING: the memory is "owned" by MovingRoverSensors so you
      (the caller) don't have to delete it.

*/
  
class MovingRoverSensors {
private:
  SamplePercept ***samps;
  VisionPercept ***vis;
  int nrows;
  int ncols;
  void initialize(FILE *fp);

public:
  MovingRoverSensors(char *filename);
  MovingRoverSensors();
  ~MovingRoverSensors();
  SamplePercept *getSamplePercept(int x, int y);
  VisionPercept *getVisionPercept(int x, int y);
};

    


  
