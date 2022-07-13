#include "utility.h"
#include <cstddef>
#include <string>
using namespace std;

int suitToValue(char suit){
    int suitValue;
    if (suit == 'c'){
        suitValue = 100;
    }
    else if (suit == 'd') {
        suitValue = 200;
    }
    else if (suit == 's') {
        suitValue = 300;
    }
    else if (suit == 'h') {
        suitValue = 400;
    }
    else{
        return -1;
    }
    return suitValue;
}

int valueToInt(string value){
    if (value == "j"){ 
        return 11;
    }
    else if (value == "q"){ 
        return 12;
    }
    else if (value == "k"){
        return 13;
    }
    else if (value == "a"){
        return 1;
    }
    else{
        return stoi(value);
    }
}
string valueToLetter(int value) {
  if(value == 1) {
    return "a";
  } 
  if(value == 11) {
    return "j";
  }
  if(value == 12) {
    return "q";
  }
  if(value == 13) { 
    return "k";
  }
  return to_string(value);
}
string NodetoString(char suit, int value){
    string s1(1, suit);
    string s2 = valueToLetter(value);
    string space = " ";
    return s1 + space + s2;
}