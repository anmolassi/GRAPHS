#include <iostream>
using namespace std;
//first vertice is 1.
int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int direction[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            direction[i][j] = 0;
        }
    }
    cout << "Enter the number of directions : ";
    int x;
    cin >> x;
    int indegree[n + 1] = {0};
    for (int i = 0; i < x; i++)
    {
        int a, b;
        cin >> a >> b;
        direction[a][b] = 1;
        indegree[b]++;
    }
    int solution[n] = {0};
    int k = 0;
    int count = 1;
    while (count != n)
    {
        count = 1;
        for (int i = 1; i <= n; i++)
        {
            if(indegree[i]==INT_MAX)
            {
                count++;
                continue;
            }
            if (indegree[i] == 0)
            {
                indegree[i]=INT_MAX;
                for (int j = 1; j <= n; j++)
                {
                    if (direction[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }
                solution[k] = i;
                k++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << solution[i] << " ";
    }
}