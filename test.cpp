#include <iostream>

#include "winstrument.h"
#include "wstation.h"

int main()
{

  WInstrument instrumentA(10, "instrumento 01", wind);
  WInstrument instrumentB(11, "instrumento 02", humidity);
  WInstrument instrumentC(12, "instrumento 03", temperature);

  WStation stationA(12.6, 14.9, "saojose");
  stationA.insertInstrument(instrumentA);
  stationA.insertInstrument(instrumentB);
  stationA.insertInstrument(instrumentC);

  for(int i=0; i < stationA.size(); ++i)
  {
  std::cout << stationA[i].getSerialNumber() 
    << "\t" << stationA[i].getDescription() 
    << "\t" << stationA[i].getType()
    << "\t" << stationA[i].read() << std::endl;
  }

  stationA.removeInstrument(instrumentB);

  std::cout << std::endl;
  
  for(int i=0; i < stationA.size(); ++i)
  {
  std::cout << stationA[i].getSerialNumber() 
    << "\t" << stationA[i].getDescription() 
    << "\t" << stationA[i].getType()
    << "\t" << stationA[i].read() << std::endl;
  }
  return 0;
}
