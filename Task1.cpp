#include <bits/stdc++.h>
using namespace std;

bool findElement(vector<char> queue, char target)
{
    int start = 0;
    int end = queue.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (mid <= target)
            end = mid;
        else
            start = mid - 1;
    }

    if (queue[end] == target)
        return true;
    else
        return false;
}

int findNewCurrentNumber(vector<char> &oldQueue, vector<char> &newQueue, int currentNumber)
{
    int d = -1;
    int count = 0;
    char temp;

    while (currentNumber <= oldQueue.size())
    {
        if (findElement(newQueue, oldQueue[currentNumber - 1]))
        {
            d = currentNumber;
            break;
        }
        currentNumber++;
    }
    temp = oldQueue[currentNumber - 1];

    for (int i = 0; i < currentNumber; i++)
    {
        if (oldQueue[i] == temp)
        {
            count++;
        }
    }
    for (int i = 0; i < newQueue.size(); i++)
    {
        if (newQueue[i] == temp)
        {
            count--;
        }
        if (count == 0)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    int currentNumber;
    cin >> n >> m >> currentNumber;
    vector<char> newQueue;
    vector<char> oldQueue;
    char k;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        oldQueue.push_back(k);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        newQueue.push_back(k);
    }

    cout << findNewCurrentNumber(oldQueue, newQueue, currentNumber);

    return 0;
}