#include "Stock.h"
#include <iostream>
 
using namespace std;

Stock* Stock::clone() const {
  return new Stock(*this);
}

string Stock::getCompany() {
  return company;
}

void Stock::setCompany(string companyName) {
  company = companyName;
}

void Stock::updateValue() {
  int posOrNeg;
  double variation;

  while (posOrNeg == 0) {
    posOrNeg = (rand() % 3) - 1;
  }
  variation = rand() % STOCK_VARIATION;

  setValue(this->getValue() + variation*posOrNeg);
  //setValue(this->getValue() - 10);
}

void Stock::printInfo(){
  Security::printInfo();
  cout << "Company name: " << company << endl;
  cout << endl;
}