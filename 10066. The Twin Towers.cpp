#include <vector>
#include <iostream>
using namespace std;

int visited[101][101] = {0};
int dp[101][101] = {0};


int dynamicRecurrent(int x, int y)
{
    if (x <= 0 || y <= 0)
        return 0;
    if (visited[x][y] == 1)
        return dp[x][y];
    int diagonal = dynamicRecurrent(x-1, y-1) + 1;    
    int left = dynamicRecurrent(x, y-1);
    int up = dynamicRecurrent(x-1, y);
    if (dp[x][0] == dp[0][y])
        dp[x][y] = diagonal;
    else
        dp[x][y] = max(left, up);
    visited[x][y] = 1;
    return dp[x][y];
}

int main()
{
    vector<int> TwinTowerNum;
    vector<int> maxMatchVector;
    int curTwinTowerNum = 1;
    int len1 = 0;
    int len2 = 0;
    while (cin >> len1 >> len2)
    {
        for (int i = 0; i <= len1; i++)
            for (int j = 0; j <= len2; j++)
            {
                visited[i][j] = 0;
                dp[i][j] = 0;
            }
        if (len1 != 0 && len2 != 0)
        {
            for (int i = 0; i < len1; i++)
                cin >> dp[i+1][0];
            for (int i = 0; i < len2; i++)
                cin >> dp[0][i+1];
            int maxMatch = dynamicRecurrent(len1, len2);
            TwinTowerNum.push_back(curTwinTowerNum);
            curTwinTowerNum = curTwinTowerNum + 1;
            maxMatchVector.push_back(maxMatch);
        }
        else
            break;
    }
    for (int i = 0; i < TwinTowerNum.size(); i++)
    {
        cout << "Twin Towers #" << TwinTowerNum[i] << endl;
        cout << "Number of Tiles : " << maxMatchVector[i] << endl;
        cout << endl;
    }
    return 0;
}
