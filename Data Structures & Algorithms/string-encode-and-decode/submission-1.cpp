class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        int len = strs.size();
        if(len == 0) return "";
        for(int i = 0; i < len; i++)
            encoded_string += to_string(strs[i].size()) + '#' + strs[i];
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i = 0;
        while(i < s.size())
        {
            int hash_pos = s.find('#', i);
            int str_len = stoi(s.substr(i, hash_pos - i));
            i = hash_pos + 1;
            decoded_strs.push_back(s.substr(i, str_len));
            i += str_len;
        }
        return decoded_strs;
    }
};
