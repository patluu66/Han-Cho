//
//  Die.h
//  HanCho
//
//  Created by Patrick Luu on 1/27/17.
//  Copyright © 2017 Patrick Luu. All rights reserved.
//

#ifndef Die_h
#define Die_h

class Die {
private:
    int side;
    
public:
    Die() { side = 6; }
    void roll() {
        side = (rand() % 6) + 1;
    }
    int getValue() {
        return side;
    }
};

#endif /* Die_h */
