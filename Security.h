#pragma once

#include <string>
#include <iostream>
#include <cmath>

using namespace std;


class Security{
  protected:
    double value;   // in $
    string name;    // informal name
    string id;    // unique to all securities

  public:
    virtual ~Security();
    //virtual Security();
    virtual Security* clone()  const = 0;   // Uses the copy constructor
    double getValue();
    string getName();
    string getId();
    void setValue(double valueIn);
    void setName(string nameIn);
    void setId(string idIn);
    virtual void updateValue() = 0;
    virtual void printInfo(); 

};