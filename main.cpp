//
//  main.cpp
//  HanCho
//
//  Created by Patrick Luu on 1/26/17.
//  Copyright © 2017 Patrick Luu. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "Die.h"
#include "Dealer.h"
#include "Player.h"


void checkGuess(Player &player, Dealer &dealer)
{
    const int POINTS_TO_ADD = 1; // Points to award winner
    
    // Get the player's guess
    string guess = player.getGuess();
    
    // Get the result (Cho or Han).
    string choHanResult = dealer.getChoOrHan();
    
    // Display the player's guess.
    cout << "The player " << player.getName()
    << " guessed " << player.getGuess() << endl;
    
    // Award points if the player guessed correctly.
    if (guess == choHanResult)
    {
        player.addPoints(POINTS_TO_ADD);
        cout << "Congratulation, you won!" << endl;
        cout << "Awarding " << POINTS_TO_ADD
        << " point(s) to " << player.getName()
        << endl;
    } else {
        cout << "Sorry, you lose!\n";
    }
}

void roundResults(Dealer &dealer, Player &player1, Player &player2)
{
    // Show the dice values.
    cout << "The dealer rolled " << dealer.getDie1Value() << " and " << dealer.getDie2Value() << endl;
    
    // Show the result (Cho or Han).
    cout << "Result: " << dealer.getChoOrHan() << endl;
    
    // Check each player's guess and award points.
    checkGuess(player1, dealer);
    checkGuess(player2, dealer);
}

void displayGrandWinner(Player player1, Player player2)
{
    cout << "----------------------------\n";
    cout << "Game over. Here are the results:\n";
    
    cout << player1.getName() << ": " << player1.getPoints() << " points\n";
    // Display player #2's results.
    cout << player2.getName() << ": " << player2.getPoints() << " points\n";
    // Determine the grand winner.
    
    if (player1.getPoints() > player2.getPoints()) {
        cout << player1.getName() << " is the grand winner!\n";
    }
    else if (player2.getPoints() > player1.getPoints()) {
        cout << player2.getName() << " is the grand winner!\n";
    } else {
        cout << "Both players are tied!\n";
    }
}

int main()
{
    const int MAX_ROUNDS = 5; // Number of rounds
    string player1Name; // First player's name
    string player2Name; // Second player's name
    
    // Get the player's names.
    cout << "Enter the first player's name: ";
    cin >> player1Name;
    cout << "Enter the second player's name: ";
    cin >> player2Name;
    
    // Create the dealer.
    Dealer dealer;
    
    // Create the two players.
    Player player1(player1Name);
    Player player2(player2Name);
    
    // Play the rounds.
    for (int round = 0; round < MAX_ROUNDS; round++)
    {
        cout << "----------------------------\n";
        cout << "Now playing round " << (round + 1) << endl;
        
        // Roll the dice.
        dealer.rollDice();
        
        // The players make their guesses.
        player1.makeGuess();
        player2.makeGuess();
        
        // Determine the winner of this round.
        roundResults(dealer, player1, player2);
    }
    
    // Display the grand winner.
    displayGrandWinner(player1, player2);
    return 0;
}







































//#include <iostream>
//#include <string>
//#include <ctime>
//#include <cstdlib>
//#include "Die.h"
//#include "Dealer.h"
//
//using namespace std;
//
//
////class Dealer
////{
////private:
////    Die die1;
////    Die die2;
////    int die1Value;
////    int die2Value;
////public:
////    Die dieA, dieB;
////    
////    Dealer()
////    {
////        die1Value = 0;
////        die2Value = 0;
////    }
////    void rollDice()
////    {
////        die1.roll();
////        die2.roll();
////        
////        // Save the dice values.
////        die1Value = die1.getValue();
////        die2Value = die2.getValue();
////    }
////    
////    string getChoOrHan()
////    {
////        string result; // To hold the result
////        
////        // Get the sum of the dice.
////        int sum = die1Value + die2Value;
////        
////        // Determine even or odd.
////        if (sum % 2 == 0) {
////            result = "Cho (even)";
////        }
////        else {
////            result = "Han (odd)";
////        }
////        
////        // Return the result.
////        return result;
////    }
////    
////    int getDie1Value() {
////        return die1Value;
////    }
////    
////    int getDie2Value() {
////        return die2Value;
////    }
////};
//
//class Player
//{
//private:
//    string name;
//    string guess;
//    int points;
//    
//public:
//    Player(string playerName)
//    {
//        // Seed the random number generator.
//        srand(time(0));
//        
//        name = playerName;
//        guess = "";
//        points = 0;
//    }
//
//    void makeGuess()
//    {
//        int guessNumber;
//        
//        cout << getName() << " enter your guess 0 or 1 (even or odd): " << endl;
//        cin >> guessNumber;
//        
//        // Convert the random number to Cho or Han.
//        if (guessNumber == 0)
//            guess = "Cho (even)";
//        else
//            guess = "Han (odd)";
//    }
//    
//    void addPoints(int newPoints)
//    {
//        points += newPoints;
//    }
//    
//    string getName()
//    {
//        return name;
//    }
//    
//    string getGuess()
//    {
//        return guess;
//    }
//    
//    int getPoints()
//    {
//        return points;
//    }
//};
//
////***************************************************
//// The checkGuess function checks a player's guess *
//// against the dealer's result. *
////***************************************************
//void checkGuess(Player &player, Dealer &dealer)
//{
//    const int POINTS_TO_ADD = 1; // Points to award winner
//    
//    // Get the player's guess
//    string guess = player.getGuess();
//    
//    // Get the result (Cho or Han).
//    string choHanResult = dealer.getChoOrHan();
//    
//    // Display the player's guess.
//    cout << "The player " << player.getName()
//    << " guessed " << player.getGuess() << endl;
//    
//    // Award points if the player guessed correctly.
//    if (guess == choHanResult)
//    {
//        player.addPoints(POINTS_TO_ADD);
//        cout << "Congratulation, you won!" << endl;
//        cout << "Awarding " << POINTS_TO_ADD
//        << " point(s) to " << player.getName()
//        << endl;
//    } else {
//        cout << "Sorry, you lose!\n";
//    }
//}
//
//void roundResults(Dealer &dealer, Player &player1, Player &player2)
//{
//     // Show the dice values.
//    cout << "The dealer rolled " << dealer.getDie1Value() << " and " << dealer.getDie2Value() << endl;
//    
//      // Show the result (Cho or Han).
//    cout << "Result: " << dealer.getChoOrHan() << endl;
//
//    // Check each player's guess and award points.
//    checkGuess(player1, dealer);
//    checkGuess(player2, dealer);
//}
//
//void displayGrandWinner(Player player1, Player player2)
//{
//    cout << "----------------------------\n";
//    cout << "Game over. Here are the results:\n";
//
//    cout << player1.getName() << ": " << player1.getPoints() << " points\n";
//    // Display player #2's results.
//    cout << player2.getName() << ": " << player2.getPoints() << " points\n";
//    // Determine the grand winner.
//    
//    if (player1.getPoints() > player2.getPoints()) {
//        cout << player1.getName() << " is the grand winner!\n";
//    }
//    else if (player2.getPoints() > player1.getPoints()) {
//        cout << player2.getName() << " is the grand winner!\n";
//    } else {
//        cout << "Both players are tied!\n";
//    }
//}
//
//int main()
//{
//    const int MAX_ROUNDS = 5; // Number of rounds
//    string player1Name; // First player's name
//    string player2Name; // Second player's name
//    
//     // Get the player's names.
//    cout << "Enter the first player's name: ";
//    cin >> player1Name;
//    cout << "Enter the second player's name: ";
//    cin >> player2Name;
//    
//     // Create the dealer.
//    Dealer dealer;
//    
//     // Create the two players.
//    Player player1(player1Name);
//    Player player2(player2Name);
//    
//     // Play the rounds.
//    for (int round = 0; round < MAX_ROUNDS; round++)
//    {
//        cout << "----------------------------\n";
//        cout << "Now playing round " << (round + 1) << endl;
//            
//         // Roll the dice.
//        dealer.rollDice();
//        
//         // The players make their guesses.
//        player1.makeGuess();
//        player2.makeGuess();
//        
//         // Determine the winner of this round.
//        roundResults(dealer, player1, player2);
//    }
//        
//         // Display the grand winner.
//        displayGrandWinner(player1, player2);
//        return 0;
//}




































































//int main(int argc, const char * argv[]) {
//    srand(time(0));
//    
//    cout << "Welcome to HanCho Dice Game!\n";
//    cout << "------------------------------\n";
//    
//    Dealer firstDealer;
//    
//    firstDealer.rollDice();
//    cout << firstDealer.getDie1Value() << " " << firstDealer.getDie2Value() << endl;
//    cout << "Is Cho or Han: " << firstDealer.getChoOrHan() << endl;
//    
//    return 0;
//}





































//#include <iostream>
//#include <string>
//#include <ctime>
//#include <cstdlib>
//
//using namespace std;
//
//class Die {
//    friend class Dealer;
//private:
//    int side;
//    
//public:
//    Die() { side = 6; }
//    void roll() {
//        side = (rand() % 6) + 1;
//    }
//    int getValue() {
//        return side;
//    }
//};
//
//class Dealer
//{
//private:
//    Die die1;
//    Die die2;
//    int die1Value;
//    int die2Value;
//public:
//    Die dieA, dieB;
//    
//    Dealer()
//    {
//        die1Value = 0;
//        die2Value = 0;
//    }
//    void rollDice()
//    {
//        die1.roll();
//        die2.roll();
//        
//        // Save the dice values.
//        die1Value = die1.getValue();
//        die2Value = die2.getValue();
//    }
//    
//    string getChoOrHan()
//    {
//        string result; // To hold the result
//        
//        // Get the sum of the dice.
//        int sum = die1Value + die2Value;
//        
//        // Determine even or odd.
//        if (sum % 2 == 0) {
//            result = "Cho (even)";
//        }
//        else {
//            result = "Han (odd)";
//        }
//        
//        // Return the result.
//        return result;
//    }
//    
//    int getDie1Value() {
//        return die1Value;
//    }
//    
//    int getDie2Value() {
//        return die2Value;
//    }
//};
//
//class Player
//{
//private:
//    string name;
//    string guess;
//    int points;
//    
//public:
//    Player(string);
//    void makeGuess();
//    void addPoints(int);
//    string getName();
//    string getGuess();
//    int getPoints();
//};
//
//Player::Player(string playerName)
//{
//    // Seed the random number generator.
//    srand(time(0));
//    
//    name = playerName;
//    guess = "";
//    points = 0;
//}
//
//void Player::makeGuess()
//{
//     const int MIN_VALUE = 0;
//     const int MAX_VALUE = 1;
//
//     int guessNumber; // For the user's guess 32
//     // Get a random number, either 0 or 1.
//     guessNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
//
//     // Convert the random number to Cho or Han.
//     if (guessNumber == 0)
//         guess = "Cho (even)";
//     else
//     guess = "Han (odd)";
// }
//
// //**********************************************
// // The addPoints member function adds a *
// // specified number of points to the player's *
// // current balance. *
// //**********************************************
//void Player::addPoints(int newPoints)
//{
//    points += newPoints;
//}
//
// //**********************************************
// // The getName member function returns a *
// // player's name. *
// //**********************************************
//string Player::getName()
//{
//    return name;
//}
//
//string Player::getGuess()
//{
//    return guess;
//}
//
// //**********************************************
// // The getPoints member function returns a *
// // player's points. *
// //**********************************************
//int Player::getPoints()
//{
//    return points;
//}
//
//
//int main(int argc, const char * argv[]) {
//    srand(time(0));
//    
//    cout << "Welcome to HanCho Dice Game!\n";
//    cout << "------------------------------\n";
//    
//    Dealer firstDealer;
//    
//    firstDealer.rollDice();
//    cout << firstDealer.getDie1Value() << " " << firstDealer.getDie2Value() << endl;
//    cout << "Is Cho or Han: " << firstDealer.getChoOrHan() << endl;
//    
//    return 0;
//}





































//#include <iostream>
//#include <string>
//#include <ctime>
//#include <cstdlib>
//
//using namespace std;
//
//class Die {
//    friend class Dealer;
//private:
//    int side;
//    
//public:
//    Die() { side = 6; }
//    void roll() {
//        side = (rand() % 6) + 1;
//    }
//    int getValue() {
//        return side;
//    }
//};
//
//class Dealer
//{
//private:
//    Die die1;
//    Die die2;
//    int die1Value;
//    int die2Value;
//public:
//    Die dieA, dieB;
//    
//    Dealer()
//    {
//        die1Value = 0;
//        die2Value = 0;
//    }
//    void rollDice()
//    {
//        die1.roll();
//        die2.roll();
//        
//        // Save the dice values.
//        die1Value = die1.getValue();
//        die2Value = die2.getValue();
//    }
//    
//    string getChoOrHan()
//    {
//        string result; // To hold the result
//        
//         // Get the sum of the dice.
//        int sum = die1Value + die2Value;
//        
//         // Determine even or odd.
//        if (sum % 2 == 0) {
//             result = "Cho (even)";
//        }
//        else {
//             result = "Han (odd)";
//        }
//        
//         // Return the result.
//        return result;
//    }
//    
//    int getDie1Value() {
//        return die1Value;
//    }
//    
//    int getDie2Value() {
//        return die2Value;
//    }
//};
//
//class Player
//{
//private:
//    string name;
//    string guess;
//    int points;
//    
//public:
//    Player(string);
//    void makeGuess();
//    void addPoints(int);
//    string getName();
//    string getGuess();
//    int getPoints();
//};
//
//Player::Player(string playerName)
//{
//     // Seed the random number generator.
//    srand(time(0));
//    
//    name = playerName;
//    guess = "";
//    points = 0;
//}
//
////void Player::makeGuess()
//// {
////     const int MIN_VALUE = 0;
////     const int MAX_VALUE = 1;
////    
////     int guessNumber; // For the user's guess 32
////     // Get a random number, either 0 or 1.
////     guessNumber = (rand() % (MAX_VALUE − MIN_VALUE + 1)) + MIN_VALUE;
////    
////     // Convert the random number to Cho or Han.
////     if (guessNumber == 0)
////         guess = "Cho (even)";
////    else
////     guess = "Han (odd)";
////        }
////
//// //**********************************************
//// // The addPoints member function adds a *
//// // specified number of points to the player's *
//// // current balance. *
//// //**********************************************
//// void Player::addPoints(int newPoints)
////{
////    points += newPoints;
////}
////
//// //**********************************************
//// // The getName member function returns a *
//// // player's name. *
//// //**********************************************
////string Player::getName()
////{
////     return name;
////}
//
//
//
//
//int main(int argc, const char * argv[]) {
//    srand(time(0));
//    
//    cout << "Welcome to HanCho Dice Game!\n";
//    cout << "------------------------------\n";
//    
//    Dealer firstDealer;
//    
//    firstDealer.rollDice();
//    cout << firstDealer.getDie1Value() << " " << firstDealer.getDie2Value() << endl;
//    cout << "Is Cho or Han: " << firstDealer.getChoOrHan() << endl;
//    
//    return 0;
//}
























//// friend functions
//#include <iostream>
//using namespace std;
//
//class Rectangle {
//    int width, height;
//public:
//    Rectangle() {}
//    Rectangle (int x, int y) : width(x), height(y) {}
//    int area() {return width * height;}
//    friend Rectangle duplicate (const Rectangle&);
//};
//
//class Rectangle duplicate (const Rectangle& param)
//{
//    Rectangle res;
//    res.width = param.width*2;
//    res.height = param.height*2;
//    return res;
//}
//
//int main () {
//    Rectangle foo;
//    Rectangle bar (2,3);
//    foo = duplicate (bar);
//    cout << foo.area() << '\n';
//    return 0;
//}






















//#include <iostream>
//
//using namespace std;
//
//class Die {
//private:
//    int side;
//public:
//    Die() { side = 6; }
//    void roll() {
//        side = (rand() % 6) + 1;
//    }
//    int getValue() {
//        return side;
//    }
//
//    friend Dealer(Die &a);
//
//};
//
//
//class Dealer(Die &a)
//{
//private:
//    Die die1;
//    Die die2;
//    int die1Value;
//    int die2Value;
//public:
//    Dealer()
//    {
//        die1Value = 0;
//        die2Value = 0;
//    }
//    void rollDice()
//    {
//        //        Die die1, die2;
//        die1.roll();
//        die2.roll();
//
//        // Save the dice values.
//        die1Value = die1.getValue();
//        die2Value = die2.getValue();
//
//    }
//
//    void getValue(Die &a);
//
//    string getChoOrHan();
//    int getDie1Value();
//    int getDie2Value();
//};
//
//
////Dealer::Dealer()
////{
////     die1Value = 0;
////     die2Value = 0;
////}
//
////void Dealer::rollDice()
////{
////    Die die1, die2;
////    die1.roll();
////    die2.roll();
////
////     // Save the dice values.
////    die1Value = die1.getValue();
////    die2Value = die2.getValue();
////}
//
//
//int main(int argc, const char * argv[]) {
//    srand(time(0));
//
//    cout << "Welcome to HanCho Dice Game!\n";
//    cout << "------------------------------\n";
//
//    Dealer dealer1;
//
//    dealer1.rollDice();
//    cout << dealer1.getDie1Value() << endl;
//
//
//    return 0;
//}



























//// friend functions
//#include <iostream>
//using namespace std;
//
//class Rectangle {
//    int width, height;
//public:
//    Rectangle() {}
//    Rectangle (int x, int y) : width(x), height(y) {}
//    int area() {return width * height;}
//    friend Rectangle duplicate (const Rectangle&);
//};
//
//class Rectangle duplicate (const Rectangle& param)
//{
//    Rectangle res;
//    res.width = param.width*2;
//    res.height = param.height*2;
//    return res;
//}
//
//int main () {
//    Rectangle foo;
//    Rectangle bar (2,3);
//    foo = duplicate (bar);
//    cout << foo.area() << '\n';
//    return 0;
//}

























//#include <iostream>
//
//using namespace std;
//
//class Dealer;
//
//class Die {
//private:
//    int side;
//public:
//    Die() { side = 6; }
//    void roll() {
//        side = (rand() % 6) + 1;
//    }
//    int getValue() {
//        return side;
//    }
//    
//    int Dealer::getValue(Die &a);
//    
//};
//
//
//class Dealer
//{
//private:
//    Die die1;
//    Die die2;
//    int die1Value;
//    int die2Value;
//public:
//    Dealer()
//    {
//        die1Value = 0;
//        die2Value = 0;
//    }
//    void rollDice()
//    {
//        //        Die die1, die2;
//        die1.roll();
//        die2.roll();
//        
//        // Save the dice values.
//        die1Value = die1.getValue();
//        die2Value = die2.getValue();
//
//    }
//    
//    void getValue(Die &a);
//    
//    string getChoOrHan();
//    int getDie1Value();
//    int getDie2Value();
//};
//
//
////Dealer::Dealer()
////{
////     die1Value = 0;
////     die2Value = 0;
////}
//
////void Dealer::rollDice()
////{
////    Die die1, die2;
////    die1.roll();
////    die2.roll();
////
////     // Save the dice values.
////    die1Value = die1.getValue();
////    die2Value = die2.getValue();
////}
//
//
//int main(int argc, const char * argv[]) {
//    srand(time(0));
//    
//    cout << "Welcome to HanCho Dice Game!\n";
//    cout << "------------------------------\n";
//    
//    Dealer dealer1;
//    
//    dealer1.rollDice();
//    cout << dealer1.getDie1Value() << endl;
//    
//    
//    return 0;
//}




































//#include <iostream>
//
//using namespace std;
//
//class Die {
//    friend class Dealer;
//private:
//    int side;
//public:
//    Die() { side = 6; }
//    void roll() {
//        side = (rand() % 6) + 1;
//    }
//    int getValue() {
//        return side;
//    }
//    
//    
//};
//
//
//class Dealer
//{
//private:
//    Die die1;
//    Die die2;
//    int die1Value;
//    int die2Value;
//public:
//    Die dieA, dieB;
//    
//    Dealer()
//    {
//        die1Value = 0;
//        die2Value = 0;
//    }
//    void rollDice()
//    {
////        Die die1, die2;
//        dieA.roll();
//        dieB.roll();
//        
//        // Save the dice values.
////        die1Value = dieA.getValue();
////        die2Value = dieB.getValue();
//        die1Value = dieA.side;
//        die2Value = dieB.side;
//    }
//    
//    string getChoOrHan();
//    int getDie1Value();
//    int getDie2Value();
//};
//
////Dealer::Dealer()
////{
////     die1Value = 0;
////     die2Value = 0;
////}
//
////void Dealer::rollDice()
////{
////    Die die1, die2;
////    die1.roll();
////    die2.roll();
////    
////     // Save the dice values.
////    die1Value = die1.getValue();
////    die2Value = die2.getValue();
////}
//
//
//int main(int argc, const char * argv[]) {
//    srand(time(0));
//    
//    cout << "Welcome to HanCho Dice Game!\n";
//    cout << "------------------------------\n";
//
//    Dealer dealer1;
//    
//    dealer1.rollDice();
//    cout << dealer1.getDie1Value() << endl;
//    
//    
//    return 0;
//}



















//int main(int argc, const char * argv[]) {
//    srand(time(0));
//    
//    cout << "Welcome to HanCho Dice Game!\n";
//    cout << "------------------------------\n";
//    Die die1, die2;
//    die1.roll();
//    cout << die1.getDie() << endl;
//    
//    die1.roll();
//    cout << die1.getDie() << endl;
//    
//    return 0;
//}
















