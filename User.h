#pragma once

#include <vector>
#include "Security.h"
#include "Market.h"

class User{
  protected:
    double cash;    // In $
    vector <Security*> mySecurities;  // The securities owned by a certain user
    Market currMarket;

  public:
    //User(Market& currMarket);//*********************************************************
    //User();
    double getCash();
    void setCash (double cashIn);
    void setMarket(Market &marketIn);//**************************************************

    double calculateNetWorth();   // Computes the value of all of the user's asset combined
    void printMySecurities();     // Prints what securities the user owns
    void printCash();   // Display the current available cash
    bool sellSecurity(string ID, int quantity, vector <Security*> market, double marketFee);   //Sell security in a specific amount (quantity)
    bool buySecurity(string iD, int quantity, vector <Security*> market, double marketFee);    // Buy a security from the market
    bool checkID(string id);
};

