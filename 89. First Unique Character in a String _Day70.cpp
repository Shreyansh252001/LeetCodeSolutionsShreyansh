    int bit_shift = 0x10;
    int count_mask = 0x0000ffff;
    int index_mask = 0xffff0000;
    
    int get_count(const int &n) {
        return n & count_mask;
    } 
    
    void incr_count(int &n) {
        n = (n & index_mask) | (get_count(n) + 1);
    }

    int get_index(const int &n) {
         return (n & index_mask) >> bit_shift;
    }
    
    void set_index(int &n, int idx) {
        n = n & count_mask | (idx << bit_shift);
    }
    
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(0);
        int freq[256] = {};
        for (const auto &c : s) freq[c]++;
        for (int idx = 0; idx < s.size(); ++idx) {
          if (freq[s[idx]] == 1) return idx;
        }
        return -1;
    }
