#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int sumMax = 0;
    int sumTmp = 0;
    int startRange = 0;
    int endRange = a.size() - 1;
    int startRez = 0;
    int endRez = a.size() - 1;

    for (int i = 0; i < a.size(); i++)
    {
        sumMax += a[i];
    }
    while (startRange != endRange)
    {
        for (int i = startRange; i <= endRange; i++)
        {
            sumTmp += a[i];
            if (sumMax < sumTmp)
            {
                sumMax = sumTmp;

                startRez = startRange;
                endRez = i;
            }
        }
        sumTmp = 0;
        startRange++;
    }

    cout << "Максимальная сумма: " << sumMax << endl;
    cout << "В диапазоне индексов [" << startRez << "][" << endRez << "]" << endl;
}