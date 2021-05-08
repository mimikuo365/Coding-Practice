class Solution {
private:
    void popMax(stack<char> &mystack, int &ctr, int k)
    {
        if (ctr == k)
            return;
        else 
        {
            
            char top = mystack.top();
            mystack.pop();
            if (mystack.empty() || top > mystack.top())
            {
                ctr = ctr + 1;
                return;
            }
            else
            {
                popMax(mystack, ctr, k);
                mystack.push(top);
                return;
            }
        }
    }
public:
    string removeKdigits(string num, int k) 
    {
        stack<char> mystack;
        
        for (int i = num.size()-1; i >= 0; i--)
            mystack.push(num[i]);

        int ctr = 0; 
        while (ctr != k)
            popMax(mystack, ctr, k);

        string min = "0"; 

        if (!mystack.empty())
        {
            min = "";
            
            for (int i = 0; !mystack.empty(); i++)
            {
                char cur = mystack.top();
                mystack.pop(); 
                if (mystack.empty() || cur != '0')
                    min += cur;
                else
                {
                    if (cur != '0' || min != "") 
                        min += cur;
                }
            }
        }
        return min;
    }
};
