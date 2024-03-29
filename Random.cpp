#include <bits/stdc++.h>
using namespace std;
int main()
{
  ofstream xuatfile("dataset.txt");
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> real_dis(-1000000.0, 1000000.0);
  vector<double> randomnumberlist;
  for (int i = 0; i < 10; ++i)
  {
    for (int j = 0; j < 1000000; ++j)
    {
      double randomnumberreal= real_dis(gen);
      randomnumberlist.push_back(randomnumberreal);
    }
    if (i == 0)
    {
      sort(randomnumberlist.begin(), randomnumberlist.end());
    }
    else if (i == 1)
    {
      sort(randomnumberlist.begin(), randomnumberlist.end(), greater<double>());
    }
    for (double randomnumber : randomnumberlist)
    {
      xuatfile << randomnumber << " ";
    }
    xuatfile << endl;
    randomnumberlist.clear();
  }
  xuatfile.close();
  return 0;
}
