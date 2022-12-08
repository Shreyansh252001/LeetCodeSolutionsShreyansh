 static bool compareSizes(string &a,string &b)
    {
        return a.length()>b.length();
    }
    string frequencySort(string s)
    {
       vector<string> freq(100,"");
        
        for (char a : s)
            freq[a-'0'] += a;
        
        sort(freq.begin(), freq.end(), compareSizes);
        
        s = "";
        
        for (string str : freq)
            s += str;
        
        return s;
    }
