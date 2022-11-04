 
        if(b>a)
          return maximumScore(b,a,c);//makesure the 1st one is the largest one if b>a then swap and send to the recursive relation because now first consition will be true afrter swaping in recursive call and we will be checking whther c>b
        if(c>b)
          return maximumScore(a,c,b);//if c>b then second greater is c not b 1st has already been decided in previous condition so swap or do not swap if b>c now 
      //start substracting 1,1 from the largest of the 2 till there is a need for swapping with largest or second largest number
        return b==0?0:maximumScore(a-1,b-1,c)+1;
