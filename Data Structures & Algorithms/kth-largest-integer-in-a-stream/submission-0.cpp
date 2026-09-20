class KthLargest {
public:
    int k;
    vector<int> arr;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->arr = nums;
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(arr.begin(), arr.end());
        return arr[arr.size() - k];
    }
};
