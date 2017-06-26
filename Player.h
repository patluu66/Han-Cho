//
//  Player.h
//  HanCho
//
//  Created by Patrick Luu on 1/27/17.
//  Copyright © 2017 Patrick Luu. All rights reserved.
//

#ifndef Player_h
#define Player_h

class Player
{
private:
    string guess;
    int points;
    
public:
    Player(string playerName)
    {
        // Seed the random number generator.
        srand(time(0));
        
        name = playerName;
        guess = "";
        points = 0;
    }
    
    void makeGuess()
    {
        int guessNumber;
        
        cout << getName() << " enter your guess 0 or 1 (even or odd): " << endl;
        cin >> guessNumber;
        
        // Convert the random number to Cho or Han.
        if (guessNumber == 0)
            guess = "Cho (even)";
        else
            guess = "Han (odd)";
    }
    
    void addPoints(int newPoints)
    {
        points += newPoints;
    }
    
    string getName()
    {
        return name;
    }
    
    string getGuess()
    {
        return guess;
    }
    
    int getPoints()
    {
        return points;
    }
};

#endif /* Player_h */
