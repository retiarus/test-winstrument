#include "winstrument.h"

WInstrument::WInstrument(int serialNumber, std::string description, Type type):
  _serialNumber(serialNumber),
  _type(type),
  _description(description)
{
  switch(_type)
  {
    case wind:
      {
	_dist = new std::uniform_real_distribution<double>(0.0, 200.0);
	break;
      }
    case temperature:
      {
	_dist = new std::uniform_real_distribution<double>(-20.0, 100.0);
	break;
      }
    case humidity:
      {
	_dist = new std::uniform_real_distribution<double>(0.0, 100.0);
	break; 
      }
  }
}

WInstrument::~WInstrument()
{
  delete _dist;
}

bool WInstrument::operator==(const WInstrument& rhs) const
{
  if(this->_serialNumber == rhs._serialNumber)
    return true;
  else
    return false;
}

bool WInstrument::operator!=(const WInstrument& rhs) const
{
  return !(*this == rhs);
}

double WInstrument::read() const
{
  std::random_device rd;
  std::mt19937_64 gen(rd());
  return _dist->operator()(gen);
}

std::string WInstrument::getDescription() const
{
  return _description;
}

int WInstrument::getSerialNumber() const
{
  return _serialNumber;
}

Type WInstrument::getType() const
{
  return _type;
}
