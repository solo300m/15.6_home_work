#include <iostream>
#include <vector>
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
            if (maxValue < vec[j])
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
    displyVector(vec);
}
void findPair(int marker, vector<int> &vec, int &fR, int &sR)
{
    int endIdx = 0;
    sortVector(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] >= marker)
        {
            if (i > 0)
            {
                endIdx = i;
                break;
            }
            else
            {
                cout << "В векторе нет пары значение, сумма которых равна " << marker << endl;
                break;
            }
        }
    }
    if (endIdx == 0)
        endIdx = vec.size() - 1;
    for (int i = 0; i < endIdx; i++)
    {
        for (int j = i + 1; j <= endIdx; j++)
        {
            if (vec[i] + vec[j] == marker)
            {
                fR = vec[i];
                sR = vec[j];
                break;
            }
        }
        if (fR != 0 && sR != 0)
            break;
    }
}
int main()
{
    vector<int> a{1};
    vector<int> &ptr = a;
    int marker = 0;
    int firstRez = 0;
    int &fR = firstRez;
    int secondRez = 0;
    int &sR = secondRez;
    initVector(ptr);
    cout << "Введенный вектор:" << endl;
    displyVector(ptr);
    cout << "Ввести значение контрольной суммы: ->";
    cin >> marker;
    findPair(marker, ptr, fR, sR);
    cout << fR << " + " << sR << " = " << marker;
    // sortVector(ptr);
    // displyVector(ptr);
}