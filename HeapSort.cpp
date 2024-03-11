#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
void xaydungheap(float *arr, int n, int i)
{
	int ln = i;
	int trai = 2 * i + 1;
	int phai = 2 * i + 2;
	if (trai <n && arr[trai] > arr[ln])
    {
        ln = trai;
    }
	if (phai < n && arr[phai] > arr[ln])
    {
        ln = phai;
    }
	if (ln != i)
    {
		float luu = arr[i];
		arr[i] = arr[ln];
		arr[ln]= luu;
		xaydungheap(arr, n, ln);
	}
}
void heapsort(float *arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
    {
        xaydungheap(arr, n, i);
    }
	for (int i = n - 1; i > 0; i--)
    {
		float luu = arr[i];
		arr[i] = arr[0];
		arr[0]= luu;
		xaydungheap(arr, i, 0);
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
        heapsort(arr, 1000000);
        auto kt = high_resolution_clock::now();
        auto timee = duration_cast<milliseconds>(kt - bd);
        cout << "Excution Time: "<< i << "\t" <<  timee.count() << "\t"<<"ms"<<"\n";
    }
    return 0;
}
