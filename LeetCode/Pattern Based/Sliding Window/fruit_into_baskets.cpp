/*  Dynamic Sliding Window

https://leetcode.com/problems/fruit-into-baskets/

The code is by iterting the whole list, and keeping the fruit counter as a map to keep the data related to the number and type of fruits in 
the fruit. Also remove the fruit if the size of the fruit map is greater than 2. 


Core concept : Dynamically add and remove the input elements also by keeping track of the largest contiguos 2 fruit length in the 
input array.

Time complexity : O(N) 

Space Complexity: O(N) {Because the size of the hashmap increase linearly with the input array size}


*/


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> fruitCounter;
        
        int windowStart = 0, maxFruits = 0;
        
        int nFruits = fruits.size();
        
        for(int i = 0; i < nFruits; i++){
            fruitCounter[fruits[i]] += 1;
            
            while(fruitCounter.size() > 2){
                int leftFruit = fruits[windowStart];
                fruitCounter[leftFruit]--;
                if(fruitCounter[leftFruit]  == 0){
                    fruitCounter.erase(leftFruit);
                }
                windowStart += 1;
            }
        maxFruits = max(maxFruits, i - windowStart + 1);
        }
        
        return maxFruits;
    
    }
};