#ifndef _WSTATION_H_
#define _WSTATION_H_

#include <iostream>
#include <vector>

#include "winstrument.h"

class WStation
{
  public:
    WStation(double lat, double log, std::string name);
    ~WStation();

    const WInstrument& operator[](const int& i) const;
    
    void insertInstrument(const WInstrument& instrument);
    void removeInstrument(const WInstrument& instrument);
    int size() const;

    double getLatitude() const;
    double getLongitude() const;
    std::string getName() const;

  private:
    double _latitude;
    double _logintude;
    std::string _name;
    std::vector<WInstrument> _instruments;
};

#endif // _WSTAION_H_
