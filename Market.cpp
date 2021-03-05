#include "Market.h"
#include "Security.h"
#include "Bond.h"
#include "Stock.h"

void Market::updateAllSecurities() {
  for(Security* c: vecSecurities){
      c->updateValue();
  }
}


void Market::printMarket() {
  cout << "****** Here are the securities available on the market ******" << endl << endl;
  for(Security* c: vecSecurities){
      c->printInfo();
  }
}

vector<Security*> Market::getMarketSecurities() {
  return vecSecurities;
}


void Market::initializeMarket() {
  Stock* MorganSecurity = new Stock();
  Stock* MthreeSecurity = new Stock();
  Stock* SoftGuildSecurity = new Stock();
  Bond* corpoSecurity = new Bond();
  Bond* fedSecurity = new Bond();

  MorganSecurity->setCompany("Morgan Stanley");
  MorganSecurity->setId("0");
  MorganSecurity->setValue(1000);
  MorganSecurity->setName("MS: Morgan Stanley Stock");

  MthreeSecurity->setCompany("Mthree");
  MthreeSecurity->setId("1");
  MthreeSecurity->setValue(800);
  MthreeSecurity->setName("MT: Mthree Stock");

  SoftGuildSecurity->setCompany("Software Guild");
  SoftGuildSecurity->setId("2");
  SoftGuildSecurity->setValue(600);
  SoftGuildSecurity->setName("SG: Software Guild Stock");
  
  corpoSecurity->setDuration(10);
  corpoSecurity->setId("3");
  corpoSecurity->setValue(700);
  corpoSecurity->setName("B Grade Corporate Bond");

  fedSecurity->setDuration(30);
  fedSecurity->setId("4");
  fedSecurity->setValue(500);
  fedSecurity->setName("A Grade Federal Bond");


  vecSecurities.push_back(MorganSecurity);
  vecSecurities.push_back(MthreeSecurity);
  vecSecurities.push_back(SoftGuildSecurity);
  vecSecurities.push_back(corpoSecurity);
  vecSecurities.push_back(fedSecurity);


}

// double Market::getFee() {
//   return TRANSACTION_FEE;
// }

// void Market::setFee(double fee) {
//   TRANSACTION_FEE = fee;
// }

