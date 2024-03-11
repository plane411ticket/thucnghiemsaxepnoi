#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
void quicksort(float *arr, int left, int right)
{
    int i = left;
    int j = right;
    int mid = left +(right - left)/2;
    while(i <= j)
    {
        while(arr[i]< arr[mid])
        {
            i++;
        }
        while(arr[j] > arr[mid])
        {
            j--;
        }
        if (i <=j)
        {
            float luu  = arr[i];
            arr[i] = arr[j];
            arr[j] = luu;
            i++;
            j--;
        }
    };
    if (left < j)
    {
        quicksort(arr, left, j);
    }
    if (i<right)
    {
        quicksort(arr, i, right);
    }
}
int main()
{
	float *arr = new float[1000000];
    freopen("dataset.txt","r",stdin);
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<1000000; j++)
        {
            cin >> arr[j];
        }
        auto bd = high_resolution_clock :: now();
        quicksort(arr,0, 1000000-1);
        auto kt = high_resolution_clock::now();
        auto timee = duration_cast<milliseconds>(kt - bd);
        cout << "Excution Time: "<< i << "\t" <<  timee.count() << "\t"<<"ms"<<"\n";
    }
    return 0;
}
