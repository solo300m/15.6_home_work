#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void initVector(vector<int> &vec)
{
    int length = 0;
    cout << "Ввести размер вестора: -> ";
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        int tmp = 0;
        cout << "элемент [" << i << "] ->";
        cin >> tmp;
        if (i <= vec.size() - 1)
        {
            vec[i] = tmp;
        }
        else
        {
            vec.push_back(tmp);
        }
    }
}

void displyVector(vector<int> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i != vec.size() - 1)
        {
            cout << vec[i] << " ";
        }
        else
        {
            cout << vec[i] << "]";
        }
    }
    cout << endl;
}
void sortVector(vector<int> &vec)
{
    int maxIndex = 0;
    int maxValue = vec[0];
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (abs(maxValue) < abs(vec[j]))
            {
                maxValue = vec[j];
                maxIndex = j;
            }
        }
        int tmp = vec[i];
        vec[i] = maxValue;
        vec[maxIndex] = tmp;
        maxValue = vec[0];
        maxIndex = 0;
    }
    // displyVector(vec);
}

int main()
{
    vector<int> a{1};
    vector<int> &ptr = a;
    initVector(ptr);
    cout << "Введенный вектор:" << endl;
    displyVector(ptr);
    sortVector(ptr);
    cout << "Отсортированный вектор:" << endl;
    displyVector(ptr);
}