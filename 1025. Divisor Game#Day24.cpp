   return !(n&1);


/*
REMEMBER EACH ONE PLAYS OPTIMALLY

5->4(A)->3(B)->2(A)->1(B) bob wins
or
5->4(A)->2(B)->1(A) alice wins

but thing to observe here is till 4 there is no divisible number between 0<x<5 so 1 is the only option with A
now b can choose between -2 or -1 but bob needs to win so he will choose -1
after that between 0<x<2 -2 is there and bob's win is confirmed with one decision of bob
Similar will happen in every odd number case

but is the number is even the control is with alice so 
6->5(a)->4(b)->3(a)->2(b)->1(a) alice wins    as alice gives one option of -1 to bob in each and every step alice wins
         4(b)->2(a)->1(b)   bob wins        otherwise if alice does the mistake of substracting -2 from 4 bob wins so it is better ti follow above line 

6->4(a)->3(b)->2(a)->1(b) bob wins     but alice will not choose to subtract 2 from 6 as once chance is with bob he substracts 1 from 4 and wins the game as
    4(a)->2(b)->1(a) alice wins                                                                   bob will never loose the chance and substract 2 from 4
    
6->3(a)->2(b)->1(a) alice wins             alice wins but after substracting odd from even number but this will not work everyhere suppose we take 9
9->6(a)->5(b)->4(a)->3(b)->2(a)->1(b)      bob wins
               4(a)->2(b)->1(a)             alice wins //bob will never do -2 to allow alice to wins
    6(a)->4(b)->3(a)->2(b)->1(a)          bob wins
          4(b)->2(a)->1(b)                  alice wins //bob will nevr to -2 from 6 to allow alice to win
    6(a)->3(b)->2(a)->1(b)                alice wins   //bob will nevrr do -3 from 6 to allow alice to win  so best option for alice is to always substract -1 from
                                                         if the number is odd
*/
