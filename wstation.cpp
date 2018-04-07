#include "wstation.h"

WStation::WStation(double lat, double log, std::string name):
  _latitude(lat),
  _logintude(log),
  _name(name){}

WStation::~WStation()
{
  _instruments.clear();
}

const WInstrument& WStation::operator[](const int& i) const
{
  return _instruments[i];
}

void WStation::insertInstrument(const WInstrument& instrument)
{
  _instruments.push_back(instrument);
}

void WStation::removeInstrument(const WInstrument& instrument)
{
  auto it = _instruments.begin();
  auto ite = _instruments.end();
  while(it != ite)
  {
    if(*it == instrument)
    {
      _instruments.erase(it);
      break;
    }
    ++it;
  }
}

int WStation::size() const
{
  return _instruments.size();
}

double WStation::getLatitude() const
{
  return _latitude;
}

double WStation::getLongitude() const
{
  return _logintude;
}

std::string WStation::getName() const
{
  return _name;
}
