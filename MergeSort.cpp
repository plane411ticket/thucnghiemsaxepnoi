#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
void tron(float *arr, int const trai, int const giua,int const phai)
{
	int const d1 = giua- trai + 1;
	int const d2 = phai - giua;
	float *dt= new float [d1];
	float *dp= new float [d2];
	for (int i = 0; i < d1; i++)
    {
        dt[i] = arr[trai + i];
    }
	for (int j = 0; j < d2; j++)
    {
        dp[j] = arr[giua+ 1 + j];
    }
	int vt1 = 0,vt2 = 0;
	int vt= trai;
	while (vt1 < d1 && vt2 < d2)
    {
		if (dt[vt1]<= dp[vt2])
		{
			arr[vt]= dt[vt1];
			vt1++;
		}
		else
		{
			arr[vt] = dp[vt2];
			vt2++;
		}
		vt++;
	}

	while (vt1< d1)
    {
		arr[vt]= dt[vt1];
		vt1++;
		vt++;
	}
	while (vt2 < d2)
	{
		arr[vt] = dp[vt2];
		vt2++;
		vt++;
	}
	delete[] dt;
	delete[] dp;
}
void mergesort(float *arr, int const bd, int const kt)
{
	if (bd >= kt)
    {
        return;
    }
	int giua = bd + (kt - bd) / 2;
	mergesort(arr, bd, giua);
	mergesort(arr, giua + 1, kt);
	tron(arr, bd, giua, kt);
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
        mergesort(arr, 0,1000000);
        auto kt = high_resolution_clock::now();
        auto timee = duration_cast<milliseconds>(kt - bd);
        cout << "Excution Time: "<< i << "\t" <<  timee.count() << "\t"<<"ms"<<"\n";
    }
    return 0;
}

