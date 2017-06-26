//
//  Dealer.h
//  HanCho
//
//  Created by Patrick Luu on 1/27/17.
//  Copyright © 2017 Patrick Luu. All rights reserved.
//

#ifndef Dealer_h
#define Dealer_h

class Dealer
{
private:
    Die die1;
    Die die2;
    int die1Value;
    int die2Value;
public:
    Die dieA, dieB;
    
    Dealer()
    {
        die1Value = 0;
        die2Value = 0;
    }
    void rollDice()
    {
        die1.roll();
        die2.roll();
        
        // Save the dice values.
        die1Value = die1.getValue();
        die2Value = die2.getValue();
    }
    
    string getChoOrHan()
    {
        string result; // To hold the result
        
        // Get the sum of the dice.
        int sum = die1Value + die2Value;
        
        // Determine even or odd.
        if (sum % 2 == 0) {
            result = "Cho (even)";
        }
        else {
            result = "Han (odd)";
        }
        
        // Return the result.
        return result;
    }
    
    int getDie1Value() {
        return die1Value;
    }
    
    int getDie2Value() {
        return die2Value;
    }
};

#endif /* Dealer_h */
