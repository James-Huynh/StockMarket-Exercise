#include "App.h"


App::App(Market &marketIn) : market(marketIn) {}

void App::run() {
  int input;
  int quantity;
  string id;

  // Testing values
  player.setCash(10000.0);
  bot.setCash(5000.0);
  
  while(daysRemaining > 0){

    do{
      printMenu();
      input = getInput();

      switch(input) {
        case (1):
          cout << "Please write the security ID: ";
          cin >> id;
          cout << "Please specify a quantity: ";
          cin >> quantity;
          cout << endl;

          player.buySecurity(id, quantity, market.getMarketSecurities(), market.TRANSACTION_FEE);
          break;
          
        case (2):
          cout << "Please write the security ID: ";
          cin >> id;
          cout << "Please specify a quantity: ";
          cin >> quantity;
          cout << endl;

          player.sellSecurity(id, quantity, market.getMarketSecurities(), market.TRANSACTION_FEE);
          break;

        case (3):
          player.printMySecurities();
          break;

        case (4):
          market.printMarket();
          break;

        case (5):
          cout << "Your net worth is :" << player.calculateNetWorth() << endl << endl;
          break;

        case (6):
          cout << "Your cash is: " << player.getCash() << endl << endl;;
          break;

        case (7):
          bot.buyLowSellHigh(market.getMarketSecurities(), market.TRANSACTION_FEE);   // FIX ME
          market.updateAllSecurities();
          daysRemaining--;
          break;
        
        default:
          cout << "This is not a valid option" << endl;
          break;
      }

    

    } while(daysRemaining > 0);

  }
  // Simulator exits here
  printFinalResult();
}

void App::printFinalResult() {
  cout << "You ended up with a total net worth of " << player.calculateNetWorth() << endl << endl;;
  cout << "The cutting edge bot from Google ended with " << bot.calculateNetWorth() << endl;
}


void App::printMenu(){
  cout << "Menu: \n" << endl;
  cout << "1- Buy a security" << endl;
  cout << "2- Sell a security" << endl;
  cout << "3- Show securities owned" << endl;
  cout << "4- Show market" << endl;
  cout << "5- Show net worth (cash + value of all securities owned" << endl;
  cout << "6- Show cash available" << endl;
  cout << "7- Finish for today" << endl;
  cout << endl;
}

int App::getDaysRemaining() {
  return daysRemaining;
}


int App::getInput() {
  int input;

  cout << "Please choose an option: ";
  cin >> input;
  cout << endl;

  if (!(input >= 1 && input <= 7)) {
    input = -1;
  }

  return input;
}