//
//  main.cpp
//  LRU Cache
//
//  Created by Jayant Mehra on 9/13/18.
//  Copyright © 2018 Jayant Mehra. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Cache.h"

int main() {
    Cache cache(2);
    
    assert(cache.setKeyValue(1, "1"));
    assert(cache.setKeyValue(2, "2"));
    assert(cache.getValue(1) == "1");
    assert(cache.setKeyValue(3, "3"));
    assert(cache.getValue(2) == "");
    assert(cache.setKeyValue(4, "4"));
    assert(cache.getValue(1) == "");
    assert(cache.getValue(3) == "3");
    assert(cache.getValue(4) == "4");
    
    cout << "All tests passed" << endl;
    return 0;
}
