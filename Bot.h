#pragma once

#include "User.h"

class Bot : public User {
  private:

  public:
    void buyLowSellHigh(vector <Security*> market, double marketFee);

};