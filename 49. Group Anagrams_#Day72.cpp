vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;  // map to store substrings for each anagram
        // add all strings in strs to map based on their anagram
        for(int i = 0; i < strs.size(); i++)
        {
            // add to map based on reordered char vector for string
            string tmp = strs[i];
            // sort tmp
            sort(tmp.begin(), tmp.end());
            // ex: bat -> abt, eat -> aet
            m[tmp].push_back(strs[i]);
        }
        // go through map and add all anagram substrings to ans
        for(auto i = m.begin(); i != m.end(); i++)
        {
            ans.push_back(i->second);
        }
        return ans;
