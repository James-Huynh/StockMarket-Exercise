#pragma once

#include <iostream>
#include "User.h"
#include "Bot.h"
#include "Market.h"

using namespace std;

class App{
  private:
    int daysRemaining = 2;    // Time limit for the simulator
    User player;
    Bot bot;
    Market& market;
  public:
    //Print the menu for the user interactions
    App(Market &market);
    void printMenu();
    int getDaysRemaining();
    int getInput();
    void run(); //2nd main?
    void printFinalResult();
};
