#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.0001
double cp = 1.03;

double norm(vector<double>&v)
{
    int n = v.size();
    double res = 0;
    for(int i = 0; i < n; i++)
    {
         res += v[i]*v[i];
    }
    return sqrt(res);
}
double dist(vector<double>v1, vector<double>v2)
{
    int n = v1.size();
    for(int i = 0; i < n; i++)
    {
        v1[i] = v1[i] - v2[i];
    }
    return norm(v1);
}
double func1(vector<double>x)
{
	return 331 + 45.6*x[1] - 4.03*x[1]*x[1] - x[0];
}
double func2(vector<double>x)
{
    return x[1]*cp*(x[2]-25) - 1020 - 3.83*0.1*x[0] + 5.13*0.001*x[0]*x[0]; 
}
double func3(vector<double>x)
{
    return x[1]*cp*(x[3]-x[2]) - 8000;
}
double func4(vector<double>x)
{
    return x[4] - x[5]-x[6];
}
double func5(vector<double>x)
{
    return 8.5019 + 2.332*0.01*x[0]+4.8*0.00001*x[0]*x[0] - 2.644*0.01*x[3]+
            1.849*0.00001*x[3]*x[3] + 1.21*0.0001*x[0]*x[1]-2.736*0.0000001*x[0]*x[0]*x[3] - 1.137*0.0000001*x[0]*x[3]*x[3]*x[3] + 2.124*pow(0.1,10)*x[0]*x[0]*x[3]*x[3]*x[3];
}

int main()
{
    // Taking the initial guess to be 1 for every parameter
    vector<double>x(7, 1);
    double corr = 0.3;
    vector<double>prev(7,0);
    while(dist(x, prev) < EPSILON)
    {
           vector<vector<double>>J(7, vector<double>(7, 0));
           for(int i = 0; i < 7; i++)
               x[i] = x[i] - corr;
    }
    for(auto it: x)
    cout << it << " ";
}