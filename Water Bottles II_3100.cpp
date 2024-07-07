/*
You are given two integers numBottles and numExchange.

numBottles represents the number of full water bottles that you initially have. In one operation, you can perform one of the following operations:

Drink any number of full water bottles turning them into empty bottles.
Exchange numExchange empty bottles with one full water bottle. Then, increase numExchange by one.
Note that you cannot exchange multiple batches of empty bottles for the same value of numExchange. For example, if numBottles == 3 and numExchange == 1, you cannot exchange 3 empty water bottles for 3 full bottles.

Return the maximum number of water bottles you can drink.

 

Example 1:


Input: numBottles = 13, numExchange = 6
Output: 15
Explanation: The table above shows the number of full water bottles, empty water bottles, the value of numExchange, and the number of bottles drunk.
Example 2:


Input: numBottles = 10, numExchange = 3
Output: 13
Explanation: The table above shows the number of full water bottles, empty water bottles, the value of numExchange, and the number of bottles drunk.
 

Constraints:

1 <= numBottles <= 100 
1 <= numExchange <= 100
*/

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=numBottles;
        int full=0;
        while(true){
            if(empty+full<numExchange){
                break;
            }
            empty-=numExchange;
            numExchange++;
            full++;
            

        }
        return numBottles+full;
    }
};

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=numBottles;
        int ans=numBottles;
        while(empty>=numExchange){
            empty-=numExchange;
            empty++;
            numExchange++;
            ans++;
        }
        return ans;
    }
};