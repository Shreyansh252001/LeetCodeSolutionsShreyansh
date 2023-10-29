class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //https://www.youtube.com/watch?v=YQJLNxveyKg&t=69s
        
        int pigs=0,trails=(minutesToTest/minutesToDie)+1;// jitne chances hai usse ek zyaada row aap total check karke decesion de sakte ho ,this is in case of 1-d if the row and column is 2-d then trails*trails number of buckets you can judge if the number of buckets are more you need to arrange tem in 3-d trails*trails*trails ,here trails stand for (minutestest/minutesdie) + 1
        
        while(pow(trails,pigs)<buckets)
        {
            pigs++;
        }
        
        return pigs;
    }
};