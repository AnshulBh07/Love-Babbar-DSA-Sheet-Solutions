#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getCommon(vector<int> &A, vector<int> &B, vector<int> &C, int n1, int n2, int n3)
{

    vector<int> ans;
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            ans.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
        {

            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    vector<int> newans;

    for (int i = 0; i < ans.size(); i++)
    {
        while (ans[i] == ans[i + 1])
        {
            i++;
        }
        newans.push_back(ans[i]);
    }

    return newans;
}

int main()
{
    vector<int> A{1, 5, 10, 20, 40, 80};
    vector<int> B{};
    vector<int> C{};
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    vector<int> ans = getCommon(A, B, C, n1, n2, n3);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}