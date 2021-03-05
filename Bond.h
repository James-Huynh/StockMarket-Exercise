#pragma once

#include "Security.h"

class Bond : public Security {
  private:
    int duration;   // Measured in days
    double interest;    // Percentage of daily return based on the value
    const int BOND_VARIATION = 100;   // the maximal amount that a bond can change in value

  public:
    // Mutators
    void setDuration(int durationIn);
    void setInterest(double percent);

    // Accessors 
    int getDuration();
    double getInterest();

    void updateValue();
    void printInfo();

    Bond* clone() const;
};