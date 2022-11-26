 int prevElement = nums[0];
        int count = 1;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != prevElement)
            {
                nums[count++] = nums[i];
                prevElement = nums[i];
                // count
            
            }
        }

        return count;
