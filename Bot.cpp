
#include <vector>

#include "Security.h"
#include "Market.h"
#include "Bot.h"

void Bot::buyLowSellHigh(vector <Security*> market, double marketFee){

  if (cash > 5000){
    buySecurity("1", 1, market, marketFee);
  }
  else{
    sellSecurity("1", 1, market, marketFee);
  }
}