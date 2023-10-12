/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bs(MountainArray& m,int low,int high,int target,bool reversed)
    {
      /*  while(l<r)
        {
            int mid=(l+r)>>1;
            int num=m.get(mid);
            //not reverse
            if(reverse)
            {
                
                if(num>target)
                {
                  l=mid+1;   
                }
                else
                {
                    r=mid;
                }
            }
            else
            {
                if(num>target)
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        
        
        return l;*/
        
           while (low != high) {
            int mid = low + (high - low) / 2;
            if (reversed) {
                if (m.get(mid) > target)
                    low = mid + 1; // Move to the right side for a decreasing slope.
                else
                    high = mid; // Move to the left side for an increasing slope.
            } else {
                if (m.get(mid) < target)
                    low = mid + 1; // Move to the right side for an increasing slope.
                else
                    high = mid; // Move to the left side for a decreasing slope.
            }
        }
        return low; // Return the index where the target should be or would be inserted.
    }
    
    int findInMountainArray(int target, MountainArray &m) 
    {
        int l=0,r=m.length()-1,mid;
        // we do not need to break out of while loop if we have directly found the number in array because may be before this on index the same number may be existing
        
        
        while(l<r)
        {
            mid=(l+r)>>1;
            
            if(m.get(mid)<m.get(mid+1))
            {
                l=mid+1;
            }
            else
                r=mid;
        }
        // we do not need to return if we have directly found the number in array because may be before this index the same number may be existing
        // if(m.get(mid)==target)
        //     return mid;
        
        cout<<l<<" "<<r<<" "<<mid<<"\n";
        
        
        int foundinleft=bs(m,0,mid,target,false);//all increasing
        
              
        if(m.get(foundinleft)==target)
            return foundinleft;
        
        cout<<"done"<<"\n";
        
        int foundinright=bs(m,mid+1,m.length()-1,target,true);//all decreasing
        
        if(m.get(foundinright)==target)
            return foundinright;
        
        return -1;
    }
};