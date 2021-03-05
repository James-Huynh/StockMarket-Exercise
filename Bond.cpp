#include "Bond.h"

void Bond::setDuration(int durationIn){
  duration = durationIn;
}

void Bond::setInterest(double percent) {
  interest = percent;
}

int Bond::getDuration(){
  return duration;
}

double Bond::getInterest() {
  return interest;
}

void Bond::updateValue(){
  int posOrNeg = 0;
  double variation;

  while (posOrNeg == 0) {
    posOrNeg = (rand() % 3) - 1;
  }
  
  variation = rand() % BOND_VARIATION;

  setValue(this->getValue() + variation*posOrNeg);
  //setValue(this->getValue() - 10);
}

void Bond::printInfo(){
  Security::printInfo();
  cout << "Bond duration: " << duration << " days" << endl;
  cout << "Bond interest: " << interest << endl;
  cout << endl;
}

Bond* Bond::clone() const{
   return new Bond(*this); 
}

