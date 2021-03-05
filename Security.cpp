#include "Security.h"
#include <ctime>
#include <iomanip>

Security::~Security(){
  cout << "Detructing our securities" << endl;
}

double Security::getValue(){
  return value;
}
string Security::getName(){
  return name;
}
string Security::getId(){
  return id;
}
void Security::setValue(double valueIn){
  value = valueIn;
}
void Security::setName(string nameIn){
  name = nameIn;
}
void Security::setId(string idIn){
  id = idIn;
}

void Security::printInfo() {
  cout << "Name: " << name << endl;
  cout << "Id: " << id << endl;
  cout << "Value: " << fixed << setprecision(0) << value << endl;
}
