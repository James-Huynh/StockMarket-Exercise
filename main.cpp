/*
Authors: Hugo & James
*/

#include <iostream>
#include "App.h"
#include "Market.h"

using namespace std;

int main() {
  srand(time(0));
  Market market;
  market.initializeMarket();

  App myApp(market);

  myApp.run();
}