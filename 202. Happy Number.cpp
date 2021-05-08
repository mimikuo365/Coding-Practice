class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> appeared;
        bool notVisited = true;
        while (notVisited) {
            int newN = 0;
            while (n != 0) {
                newN += (n % 10) * (n % 10);
                n = n / 10;
            }
            cout << newN << endl;
            n = newN;
            if (appeared.find(newN) != appeared.end())
                notVisited = false;
            appeared.insert(newN);
        }
        if (appeared.find(1) != appeared.end())
            return true;
        else return false;
    }
};
