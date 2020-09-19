#include "RoverSensors.hh"

SamplePercept::SamplePercept(char *line) {
  // ok, this is a bit bad; doesn't do any error checking
  
  myPercept=atoi(line);
}

VisionPercept::VisionPercept(char *line) {
  myPercept=(strcasecmp(line,"clear")==0);
}


RoverSampleSensor::RoverSampleSensor(char *filename) {
  lastPercept=nullptr;

  myFile=fopen(filename,"r");
  if (myFile==nullptr) {
    fprintf(stderr,"Error opening file %s, exiting\n",filename);
    exit(1);
  }
}

RoverSampleSensor::RoverSampleSensor() {
  lastPercept=nullptr;

  myFile=stdin;
}

RoverSampleSensor::~RoverSampleSensor() {
  if (myFile!=nullptr) {
    fclose(myFile);
  }
  if (lastPercept!=nullptr) {
    delete lastPercept;
  }
}
    

SamplePercept *RoverSampleSensor::getSamplePercept() {
  char buf[1024];

  if (fgets(buf,1023,myFile)) {
    if (lastPercept!=nullptr)
      delete lastPercept;
    return (lastPercept=new SamplePercept(buf));
  }
  return nullptr;
}

MovingRoverSensors::MovingRoverSensors() {
  initialize(stdin);
}


MovingRoverSensors::MovingRoverSensors(char *filename) {
  FILE *myFile;

  myFile=fopen(filename,"r");
  if (myFile==nullptr) {
    fprintf(stderr,"Error opening file %s, exiting\n",filename);
    exit(1);
  }
  initialize(myFile);
  fclose(myFile);
}

void MovingRoverSensors::initialize(FILE *myFile) {
  char buf[1024];
  int counter=0;

  // OK, we should really do dynamic allocation here, but I'm going to
  // guarantee that we don't get more than a 100x2 grid.
#define MAXLINES 100

  samps=new SamplePercept**[2];
  vis=new VisionPercept**[2];
  samps[0]=new SamplePercept*[MAXLINES];
  samps[1]=new SamplePercept*[MAXLINES];
  vis[0]=new VisionPercept*[MAXLINES];
  vis[1]=new VisionPercept*[MAXLINES];

  for(counter=0;counter<MAXLINES;counter++) {
    samps[0][counter]=nullptr;
    samps[1][counter]=nullptr;
    vis[0][counter]=nullptr;
    vis[1][counter]=nullptr;
  }

  counter=0;

  while(fgets(buf,1023,myFile)) {
    int i;
    counter++;
    if (counter>2) {
      fprintf(stderr,"Ooops!  Too many input lines in file.\n");
      exit(1);
    }
    char *s=strtok(buf,",");
    // check to see if we have the right line number
    if(atoi(s)!=counter) {
      fprintf(stderr,"Oops!  Error in file formatting.\n");
      exit(1);
    }

    i=0;
    int done=0;
    while (!done) {
      // first get a vision percept
      s=strtok(NULL,",");
      if (s==nullptr) {
	done=1;
	continue;
      }
      vis[counter-1][i]=new VisionPercept(s);

      // then get a sample percept
      s=strtok(NULL,",");
      samps[counter-1][i]=new SamplePercept(s);

      i++;
    }
    ncols=i;
  }

  nrows=counter;
}

MovingRoverSensors::~MovingRoverSensors() {
  int i;

  for (i=0;i<MAXLINES;i++) {
    if (samps[0][i]!=nullptr) delete samps[0][i];
    if (vis[0][i]!=nullptr) delete vis[0][i];
    if (samps[1][i]!=nullptr) delete samps[1][i];
    if (vis[1][i]!=nullptr) delete vis[1][i];
  }
  delete[] samps[0];
  delete[] samps[1];
  delete[] samps;

  delete[] vis[0];
  delete[] vis[1];
  delete[] vis;
}

SamplePercept *MovingRoverSensors::getSamplePercept(int x, int y) {
  if (x<=0 || x>ncols || y<=0 || y>=3) {
    return nullptr;
  } else {
    return samps[y-1][x-1];
  }
}

VisionPercept *MovingRoverSensors::getVisionPercept(int x, int y) {
  if (x<=0 || x>ncols || y<=0 || y>=3) {
    return nullptr;
  } else {
    return vis[y-1][x-1];
  }
}

  
