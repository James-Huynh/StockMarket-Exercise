#pragma once

#include "Security.h"
#include <string>

using namespace std;

class Stock : public Security {
  private:
    string company;   // The name of the company that the stock comes from
    const int STOCK_VARIATION = 200;   // the maximal amount that a stock can change in value

  public:
    Stock* clone() const;

    string getCompany();
    void setCompany(string companyName);
    
    void updateValue();
    void printInfo();
};