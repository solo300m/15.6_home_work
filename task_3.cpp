#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    vector<int> a{1};
    vector<int> &ptr = a;
    int i = 0;
    while (true)
    {
        int tmp = 0;
        cout << "элемент ->";
        cin >> tmp;
        if (tmp != -1 && tmp != -2)
        {
            if (i <= ptr.size() - 1)
            {
                ptr[i] = tmp;
                i++;
            }
            else
            {
                ptr.push_back(tmp);
                i++;
            }
        }
        else if (tmp == -1)
        {
            displyVector(ptr);
            sortVector(ptr);
            if (ptr.size() >= 5)
            {
                cout << "Вывод -> " << ptr[4] << endl;
            }
            else
            {
                cout << "Размер массива " << ptr.size() << ". Для вывода 5 элемента не хватает данных." << endl;
            }
        }
        else if (tmp == -2)
        {
            break;
        }
    }
}