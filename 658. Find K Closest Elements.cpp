class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::vector<int>::iterator low, up;        
        low = lower_bound(arr.begin(), arr.end(), x); 
        if (low == arr.end())
            low = arr.end() - 1;
        else if (*low != x)
            low--;
        up = low+1;
        while (k > 0) {
            if (low >= arr.begin() && up < arr.end()) {
                // cout << '1' << endl;
                // cout << *low << " " << *up << endl;
                if (abs(x - *low) <= abs(*up - x))
                    low--;
                else
                    up++;
            }
            else if (low < arr.begin()) {
			    up++;
                // cout << '2' << endl;                
            }
            else if (up >= arr.end()) {
                low--;
                // cout << '3' << endl;                
            }
		    k--;
        }
        return vector<int>(low + 1, up);
    }
};
        
