class Solution {
public:
    int minFlips(int a, int b, int c) {
       /* int count=0;
            
        for(int i=0;i<=31;i++)
        {
            if((a>>i || b>>i)!=c>>i)
            {
                if((c>>i)&1 == 1 && (a>>i)&1==0 && (b>>i)&1==0)
                    count++;
                else if((c>>i)&1==0)
                {
                    count+=((a>>i)&1+(b>>i)&1);
                }
            }
        }
        
        return count;*/
         int answer = 0;
        while (a != 0 | b != 0 | c != 0) {
            if ((c & 1) == 1) {
                if ((a & 1) == 0 && (b & 1) == 0) {
                    answer++;
                }
            } else {
                answer += (a & 1) + (b & 1);
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return answer;
    }
};