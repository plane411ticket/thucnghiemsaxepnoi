#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
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
        sort(arr,  arr+1000000);
        auto kt = high_resolution_clock::now();
        auto timee = duration_cast<milliseconds>(kt - bd);
        cout << "Excution Time: "<< i << "\t" <<  timee.count() << "\t"<<"ms"<<"\n";
    }
    return 0;
}
