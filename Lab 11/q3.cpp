#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

void mySort(vector<int> &nums, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - 1-i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int main(){
    vector<int> numbers;
    vector<int> numbers2;
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
        numbers2.push_back(num);
    }

    cout << "Sorting using Custom sort function: "<<endl;
    auto start = chrono::high_resolution_clock::now(); // start time
    mySort(numbers, n);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    cout << "Elements:-" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }


     cout << "\nSorting using sort in built Function: "<<endl;
    auto start2 = chrono::high_resolution_clock::now(); // start time
    sort(numbers2.begin(),numbers2.end());
    auto end2 = chrono::high_resolution_clock::now();

    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

    cout << "Time taken: " << duration2.count() << " microseconds" << endl;

    cout << "Elements:-" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << numbers2[i] << " ";
    }

    return 0;
}