#ifndef _WINSTRUMENT_H_
#define _WINSTRUMENT_H_

#include <string>
#include <random>

enum Type {wind, temperature, humidity};

// _serialNumber = -1, device no initialized
class WInstrument
{
  public:
    WInstrument(int serialNumber, std::string description, Type type);
    ~WInstrument();

    bool operator==(const WInstrument& rhs) const;
    bool operator!=(const WInstrument& rhs) const;

    double read() const;

    std::string getDescription() const;
    int getSerialNumber() const;
    Type getType() const;

  private:
    int _serialNumber = -1; 
    Type _type;
    std::string _description;

  private:
    std::uniform_real_distribution<double> *_dist;
};

#endif
