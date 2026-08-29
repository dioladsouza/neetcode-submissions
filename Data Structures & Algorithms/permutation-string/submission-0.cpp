class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();

        if(len1 > len2) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        for(char c : s1)
            freq1[c - 'a']++;

        int l = 0;
        for(int r = 0; r < len2; r++)
        {   
            freq2[s2[r] - 'a']++;
            if(r - l + 1 > len1)
            {
                freq2[s2[l] - 'a']--;
                l++;
            }
            if(freq1 == freq2)
                return true;
        }
        return false;
    }
};
