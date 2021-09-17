#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
/* lab 3 by Leslie A. Hurtado */

bool checkHours(string str) {
    for (int i = 0; i < (str.length() - 1); i++)
      if (isdigit(str[i]) == false)
      return false;
      return true;
    }

//just learned you have to declare functions outside the main ??? I did tons of research and this was the only solution I could actually wrap my head around, so I included it


int main() {
  //I do declare!
  string phoneHours;
  int pckgPlan;
  double totalBill;



  //we need your feedback :) *customer service voice*
  cout << "Please enter your package plan : " << endl << "Basic package - enter 1," << endl << "Gold package - enter 2," << endl <<  "Platinum package - enter 3" << endl;

  cin >> pckgPlan;



//this makes the program run real slow but oh well
  if (pckgPlan > 3 || pckgPlan < 1) {
    //i'll give you the benefit of the doubt if you somehow end with this message but please dont
    cout << "Please run program again and enter a valid package" << endl;
    return 0;
  }

//it was getting annoying to keep having to enter two numbers during test runs so
  if (pckgPlan == 3) {
    //this is the platinum plan which has unlimited access for 19.95 a month
    totalBill = 19.95;
    cout << "Your total phone bill this month is : " << totalBill << fixed << showpoint << setprecision(2) << endl;
    return 0;
  }


  //dont want to deal with strings thank you
  cout << "Thank you. Please enter the amount of hours used this month :" << endl;

  cin >> phoneHours;
  
  //error catching extreme deluxe
  if (checkHours(phoneHours) == true) {
    double phoneHours1 = stod (phoneHours);


    //these are the infinite if/else statements now

    if (pckgPlan == 1) {
    //this is the basic plan which has 10 hours for 9.95 and anything after is 2 per hour
    if (phoneHours1 <= 10) {
      totalBill = 9.95;
      cout << "Your total phone bill this month is : " << totalBill << fixed << showpoint << setprecision(2) << endl;
      return 0;
    }
    else {
      totalBill = 9.95 + ((phoneHours1 - 10) * 2);
      cout << "Your total phone bill this month is : " << totalBill << fixed << showpoint << setprecision(2) << endl;
      return 0;
    }
  }


  else if (pckgPlan == 2) {
    //this is the gold plan which has 20 hours for 14.95 and everything after is 1 per hour
    if (phoneHours1 <= 20) {
      totalBill = 14.95;
      cout << "Your total phone bill this month is : " << totalBill << fixed << showpoint << setprecision(2) << endl;
      return 0;
    }
    else {
      totalBill = 14.95 + (phoneHours1 - 20);
      cout << "Your total phone bill this month is : " << totalBill << fixed << showpoint << setprecision(2) << endl;
      return 0;
    }
  }
  }
  else {
    cout << "never do that again" << endl;
  }
}
