class Solution {
public:
    bool canMeasureWater(int a, int b, int target) {
        if(a + b < target)
            return false;
        
        if(a==target || b==target || a+b == target)
            return true;
        
        if(target % __gcd(a,b) == 0)
            return true;
        return false;
    }
};