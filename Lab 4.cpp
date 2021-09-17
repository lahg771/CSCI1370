#include <iostream>
using namespace std;
#include <ctime>
#include <string>
#include <list>
#include <vector>
#include <locale>
#include <functional>

/*
introducing HiLo edition one!
by Blue A. Hurtado
please provide feedback in discord @blue#1974
*/



//put some functions here
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
bool isNumber(string str) {
    for (int i = 0; i < (str.length() - 1); i++)
      if (isdigit(str[i]) == false)
      return false;
      return true;
    }



int main() {
  //declare, saying that makes me feel like a lawyer
  string name;
  string ceil;
  string floor;
  vector<string> facts;
  vector<string> questiontracker;
  string placeholder;
  string guess;
  int ceiling;
  int flooring;
  int tries;
  int validGuess;

  //arrays will go here
  string questions[] = {"What's your favorite fruit?", "What's your favorite film?", "What's your favorite game?", "What's your favorite genre of music?", "What's your favorite animal?"};

  
  string fam[] = {"mother", "father", "sister", "brother", "cousin", "second cousin", "cousin twice removed", "mother-in-law", "father-in-law", "sister-in-law", "brother-in-law", "nephew", "niece", "grandmother", "grandfather", "uncle", "aunt", "crazy aunt kate", "grand uncle"};

  //this was in the instructions :)
  srand(time(0));

  //let's get to know each other !

   cout << "welcome to HiLo : the number guessing game! Edition 1!" << endl << "First, let's get your name!" << endl;
  getline(cin, name);

  //just something fun I guess numbers should be allowed
  if (isNumber(name) == true) {
    cout << endl << "Keeping secrets I see..." << endl << endl;
  }

  //family stuff
  int randomnumber1 = (rand() % 19);
  int randomnumber2 = (rand() % 19);
  int randomnumber3 = (rand() % 19);
  int randomnumber4 = (rand() % 19);
  string member1 = fam[randomnumber1];
  string member2 = fam[randomnumber2];
  string member3 = fam[randomnumber3];
  string member4 = fam[randomnumber4];


  //I want to randomize this lol
  //update: I did randomize it
  cout << endl << endl << name + ", was it? That's interesting! my " << member1 << "'s " << member2 << "'s " << member3 << "'s " << member4 << " has the same name!" << endl;


  //add more fact questions here
  cout << endl << endl << name + " okay time for some questions before we begin! (temporarily cannot promise you there won't be duplicate questions)" << endl;


  //let's randomize the questions!
  //IMPORTANT! FIGURE OUT A WAY TO AVOID DUPLICATES!
  int j = 0;
  while (j < 3) {
    randomnumber1 = (rand() % 6);
    if (randomnumber1 == 1) {
      cout << questions[0] << endl;
      getline(cin, placeholder);

      placeholder = removeSpaces(placeholder);
      
      facts.push_back(placeholder);
      questiontracker.push_back(questions[0]);
      j++;
    }
    else if (randomnumber1 == 2) {
      cout << questions[1] << endl;
      getline(cin, placeholder);
      
      placeholder = removeSpaces(placeholder);

      facts.push_back(placeholder);
      questiontracker.push_back(questions[1]);
      j++;
    }
    else if (randomnumber1 == 3) {
      cout << questions[2] << endl;
      getline(cin, placeholder);

      placeholder = removeSpaces(placeholder);
      
      facts.push_back(placeholder);
      questiontracker.push_back(questions[2]);
      j++;
    }
    else if (randomnumber1 == 4) {
      cout << questions[3] << endl;
      getline(cin, placeholder);

      placeholder = removeSpaces(placeholder);
     
      facts.push_back(placeholder);
      questiontracker.push_back(questions[3]);
      j++;
    }
    else if (randomnumber1 == 5) {
      cout << questions[4] << endl;
      getline(cin, placeholder);

      placeholder = removeSpaces(placeholder);

      facts.push_back(placeholder);
      questiontracker.push_back(questions[4]);
      j++;
    }
    }

  //actually getting to the hilo game part

  //ask for minimum
  cout << "Okay, " + name + " give us your minimum number: " << endl;
  cin >> floor;

  //check if it is a number
  if (isNumber(floor) == true) {
    flooring = stoi(floor);
  }
  else {
    cout << "that's no number!" << endl;
    return 0;
  }

  //ask for maximum
  cout << "Alright, give us your maximum number before we begin: " << endl;
  cin >> ceil;


  //check if it is a number
  if (isNumber(ceil) == true) {
    ceiling = stoi(ceil);
  }
  else {
    cout << "that's no number!" << endl;
    return 0;
  }

  //min cannot be bigger than max
  //fun fact write minimum in cursive without dotting your i's it's really satisfying
  if (flooring > ceiling) {
    cout << "your minimum cannot be bigger than your maximum" << endl;
    return 0;
  }


  //okay now take a guess
  cout << "Guess a number between " << flooring << " and " << ceiling << endl;

  //generate the random number
  int randomnumber = (rand() % ceiling) + flooring + 1;

  //sometimes it'll be just slightly higher i dunno why but oh well
  if (randomnumber > ceiling) {
    while (randomnumber > ceiling) {
      randomnumber -= 1;
    }
  }


  //get user's guess
  cin >> guess;


  //logic behind the responses here
  //start by checking if the guess is a number
  if (isNumber(guess) == true){
    validGuess = stoi(guess);
    //turn guess into an integer

    //use the integer to see if the guess is equal to the random number generated earlier
    while (validGuess != randomnumber) {
      //if it is higher
      if (validGuess > randomnumber) {
        cout << "too high!"<< endl << "Guess a number between " << flooring << " and " << ceiling << endl;

        //keeping track of the tries
        tries++;

        //taking the guess again and checking if it is a number (again)
        cin >> guess;
        if (isNumber(guess) == true) {
          validGuess = stoi(guess);
        }
        else {
          cout << "please enter a valid number" << endl;
          continue;
        }
      }

      //if it is lower
      else if (validGuess < randomnumber) {
        cout << "too low!" << endl << "Guess a number between " << flooring << " and " << ceiling << endl;

        //keeping track of the tries!
        tries++;

        //take the guess again and check to see if it is a number again!
        cin >> guess;
        if (isNumber(guess) == true) {
          validGuess = stoi(guess);
        }
        else {
          cout << "please enter a valid number" << endl;
          continue;
        }

        int randomquestnum = (rand() % tries + 1);
        int randomquestnum1 = (rand() % 4);
        if (randomquestnum == tries) {
          switch (randomquestnum) {
            case 1:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 2:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 3:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 4:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 5:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 6:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 7:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 8:
            cout << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 9:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 10:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 11:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 12:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 13:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 14:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
            case 15:
            cout << endl << facts[randomquestnum1] << " is one of your favorites!"<< endl << endl;
            break;
          }
          if (tries > 15) {
            cout << "just start again!" << endl;
            return 0;
          }
        }
      }
    }
  }

  //if the first guess is not a number game over I guess
  else if (isNumber(guess) != true){
    cout << "enter a valid number" << endl;
    return 0;
  }

  //while loop broken when the guess is equal to the random number


  //now to get to those end game responses!
    if (tries < 5) {
      cout << "you win! The number was " << randomnumber << " and it took you " << tries + 1 << " tries! That's some luck!" << endl;
    }
    else if (tries > 4 && tries < 7 ) {
      cout << "you win! The number was " << randomnumber << " and it took you " << tries + 1 << " tries! Not bad!" << endl;
    }
    else if (tries > 6 && tries < 9) {
      cout << "you win! The number was " << randomnumber << " and it took you " << tries + 1 << " tries! Not bad, not good...\naverage" << endl;
    }
    else if (tries > 8 && tries < 11) {
      cout << "you win! The number was " << randomnumber << " and it took you " << tries + 1 << " tries! Not the worst, but also not the best\nby far!" << endl;
    }
    else if (tries > 10) {
      cout << "That was an awful score. It hardly counts as a win! The number was " << randomnumber << " and it took you " << tries + 1 << " tries!" << endl;
    }
  }
