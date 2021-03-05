#pragma once

#include "Security.h"
#include <vector>
/*
For now, the market will contain;
  Stocks: Mthree, Morgan Stanley, SoftwareGuild
  Bonds: corporate, federal 
*/
class Market {
  private:
    vector<Security*> vecSecurities;

  public:
    double const TRANSACTION_FEE = 0.10;

    // Updates the value of all securities today with a pseudo-random formula
    void updateAllSecurities();

    // Prints the value of all securites on the market for the day
    void printMarket();

    // Create the initial market conditions: genereates the securites available to be traded
    void initializeMarket();

    vector<Security*> getMarketSecurities();

    

};