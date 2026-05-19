/* 001_greed_is_good solution.cpp
 * Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it, is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point

Each of 5 dice can only be counted once in each roll. For example, a given "5" can only count as part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)
 * */

#include <array>
#include <map>

int score(const std::array<unsigned, 5>& dice) {
    
    // Create a map to store: Key -> value
    std::map<int, int> frequency;

    // Loop to count frequency
    for(int n: dice) {
        frequency[n]++;
    }

    int sum = 0;

    // Cheking frequency out
    for(const auto& pair : frequency){
        if(pair.second >= 3) {
            if(pair.first == 1) {
                sum += 1000;
            } else if (pair.first == 2) {
                sum += 200;
            } else if (pair.first == 3) {
                sum += 300;
            } else if (pair.first == 4) {
                sum += 400;
            } else if (pair.first == 5) {
                sum += 500;
            } else if (pair.first == 6) {
                sum += 600;
            };

            int diff = pair.second - 3;

            if(diff == 1) {
                if(pair.first == 1) {sum += 100;}
                else if(pair.first == 5) {sum += 50;}
            } else if(diff == 2) {
                if(pair.first == 1) {sum += 200;}
                else if(pair.first == 5) {sum += 100;}
            }

        } else if(pair.second == 1) {
            if(pair.first == 1) {
                sum += 100;
            } else if (pair.first == 5) {
                sum += 50;
            }
        } else if(pair.second == 2) {
            if(pair.first == 1) {
                sum += 200;
            } else if(pair.first == 5) {
                sum += 100;
            }
        }
    }    

    return sum;
}
