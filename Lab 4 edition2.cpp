#include <iostream>
using namespace std;
#include <string>
#include <ctime>

/*
HiLo 2: Temperature Edition
brought to you by:
Leslie A. Hurtado
*/

bool isNumber(string str) {
    for (int i = 0; i < (str.length() - 1); i++) 
      if (isdigit(str[i]) == false)
      return false;
      return true;
    }

int main() {
  //random numbers
  srand(time(0));


  //declaring
  string userinput;
  string input2;
  int actualinput;
  int randomnumber;
  int tries;
  int adjustedGuess;
  string temperature;
  string temps[] = {"very hot", "hot", "warm", "cool", "cold", "very cold"};
  string hilo[] = {"higher", "lower"};


  //introduction
  cout << "Welcome to HiLo 2! : Temperature Edition" << endl << "This time around we'll have the computer guess your number instead!" << endl << endl << "Now think of any number from 0-100" << endl;


  //ask for a number
  getline(cin, userinput);
  if (isNumber(userinput) == true) {
    actualinput = stoi(userinput);
    cout << "Thank you" << endl;
  }
  else {
    cout << "Please input a number" << endl;
    return 0;
  }


  cout << endl << "For this to work we will implement a system!" << endl << "very hot" << endl << "hot" << endl << "warm" << endl << "cool" << endl << "cold" << endl << "very cold" << endl << "This is what you'll use to tell the computer how close the guess was to your actual number!" << endl << endl << "once the computer guesses your number correctly say 'That is my number'" << endl << endl << "Let's begin!" << endl;
  //computer will generate random numbers while the random number is not equal to the user number
  while (randomnumber != actualinput){
  randomnumber = (rand() % 100);
  //BUT after every number generated, ask user if it is too high or low?
  cout << randomnumber << " how close is this to your number?" << endl;
  getline(cin, temperature);
  start :
  if (temperature == temps[0]) {

    cout << "Is this higher or lower than your number?" << endl; 
    getline(cin, input2);
    if (input2 == hilo[0]) {
      randomnumber = randomnumber - 1;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
    else if (input2 == hilo[1]) {
      randomnumber = randomnumber + 1;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
  }
  else if (temperature == temps[1]) {

    cout << "Is this higher or lower than your number?" << endl; 
    getline(cin, input2);
    if (input2 == hilo[0]) {
      randomnumber = randomnumber - 2;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
    else if (input2 == hilo[1]) {
      randomnumber = randomnumber + 2;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
  }
  else if (temperature == temps[2]) {

    cout << "Is this higher or lower than your number?" << endl; 
    getline(cin, input2);
    if (input2 == hilo[0]) {
      randomnumber = randomnumber - 4;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
    else if (input2 == hilo[1]) {
      randomnumber = randomnumber + 4;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
  }
  else if (temperature == temps[3]) {
    
    cout << "Is this higher or lower than your number?" << endl; 
    getline(cin, input2);
    if (input2 == hilo[0]) {
      randomnumber = randomnumber - 5;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
    else if (input2 == hilo[1]) {
      randomnumber = randomnumber + 5;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
  }
  else if (temperature == temps[4]) {
    
    cout << "Is this higher or lower than your number?" << endl; 
    getline(cin, input2);
    if (input2 == hilo[0]) {
      randomnumber = randomnumber - 8;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
    else if (input2 == hilo[1]) {
      randomnumber = randomnumber + 8;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
  }
  else if (temperature == temps[5]) {
    
    cout << "Is this higher or lower than your number?" << endl; 
    getline(cin, input2);
    if (input2 == hilo[0]) {
      randomnumber = randomnumber - 20;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
    else if (input2 == hilo[1]) {
      randomnumber = randomnumber + 20;
      cout << randomnumber << " how close is this to your number?" << endl;
      getline(cin, temperature);
      tries++;
      goto start;
    }
  }
  else if (temperature == "that is my number" || temperature == "That is my number" || temperature == "this is my number" || temperature == "that's my number" || temperature == "That's my number" || temperature == "This is my number") {
    break;
  }
  else {
    cout << "please stick to the temperature system" << endl;
    goto start;
  }
  }
  cout << "the computer guessed " << randomnumber << " It took " << tries + 1 << " tries" << endl;
 }
