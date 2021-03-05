#include "User.h"
#include <iostream>

using namespace std;

/*
User::User() {
  Market& a;
  currMarket = a;
}*/

double User::getCash(){
  return cash;
}

void User::setCash (double cashIn){
  cash = cashIn;
}

/**********************************************************************
void setMarket(Market &marketIn){
  currMarket = marketIn;
}*/


double User::calculateNetWorth(){
  double totalFromSecurities = 0;
  for(Security* c: mySecurities){
      totalFromSecurities += c->getValue();
  }
  return cash + totalFromSecurities;
}

void User::printMySecurities(){
    for(Security* c: mySecurities){
      c->printInfo();
  }
}

void User::printCash(){
  cout << "Cash available: " << cash << endl;
}

bool User::sellSecurity(string ID, int quantity, vector <Security*> market, double marketFee){
  int quantityAvailable = 0;
  bool transactionPassed = false;
  double value;

  for(Security* c: mySecurities){
    if(c->getId() == ID){
      quantityAvailable++;
    }
  }

  if(quantityAvailable >= quantity){
    transactionPassed = true;
    for(Security* d: market){
      if(d->getId() == ID){
        value = d->getValue();
      }
    }

    for(int i = 0; i < mySecurities.size(); i++){
      if(mySecurities.at(i)->getId() == ID && quantityAvailable > 0){
        quantityAvailable--;
        cash += (value* (1 - marketFee));

        Security *secPtr = mySecurities.at(i);    // put a tmp pointer so that you can remove the object and delete it properly
        mySecurities.erase(mySecurities.begin() + i);
        delete secPtr; 
        
      } 
    }

  }
  return transactionPassed;
}

bool User::buySecurity(string iD, int quantity, vector <Security*> market, double marketFee) {
  
  if(quantity <= 0) {
  cout << "Please buy a positive quantity. FOOL" << endl << endl;
    return false;
  }

  bool transactionPassed = false;
  for(Security* c: market){
    if(c->getId() == iD){
      double totalCost = (c->getValue() * (1 + marketFee)) *  quantity;

      if (totalCost <= cash) {    // check to not go broke
        for(int i = 0; i < quantity; i++){
          Security* newSecurity = c->clone();  //using operator new in clone()
          mySecurities.push_back(newSecurity);
          cash -= (c->getValue() * (1 + marketFee));
        }
      }
      else{
        cout  << "YOU AINT GOT FUNDS FOOL" << endl << endl;
      }
    }
    bool transactionPassed = true;
    break;
  }
  return transactionPassed;
}



bool User::checkID(string iD) {
  vector<Security*> marketSecurities = currMarket.getMarketSecurities();

  for(Security* c: marketSecurities){
    if (c->getId() == iD) {
      return true;
    }
  }

  return false;
}