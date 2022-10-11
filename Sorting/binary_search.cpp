#include <iostream>
#include <cmath>
using namespace std;
const int m = 5;
void set_w_value(int w[][m], int *p, int *q, int n, int count)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; i < n; j++)
        {
            if (i != j && (abs(j - i) == count))
            {
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                break;
            }
        }
    }
}
void set_c_value(int w[][m],int c[][m] int *p, int *q, int n, int count)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; i < n; j++)
        {
            if (i != j && (abs(j - i) == count))
            {
              c[i][j] = min(c[i][k -1] + )
                break;
            }
        }
    }
}
int main()
{
    //***************************************************************************
    cout << "How many keys are there(n) n is default 4 ?  ";
    int n;
    cin >> n;
    //***************************************************************************
    cout << "Enter Keys :" << endl;
    int keys[n];
    for (int i = 0; i < n; i++)
    {
        cin >> keys[i];
    }
    cout << endl;
    //***************************************************************************
    cout << "Enter p(i) value :" << endl;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << endl;
    
    cout << "Enter q(i) value :" << endl;
    int q[n];
    for (int i = 0; i <= n; i++)
    {
        cin >> q[i];
    }
    cout << endl;

 
    cout << "Keys :  ";
    for (int i = 0; i < n; i++)
    {
        cout << keys[i] << " ";
    }
    cout << endl;

    cout << "p(i) :  ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    cout << "q(i) :";
    for (int i = 0; i <= n; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;

    int w[5][5] = {0};
    int c[5][5] = {0};
    int r[5][5] = {0};
    int i, j;
    for (i = 0, j = 0; j <= n, i <= n; i++, j++)
    {

        if (i == j)
        {
            w[i][j] = q[i];
            c[i][j] = 0;
            r[i][j] = 0;
        }
    }

    int count = 1; // count is j - i value

    for (int i = 0; i < n; i++)
    {
        set_w_value(w, p, q, n, count);
        count++;
    }
    count = 1;
    for (int i = 0; i < n; i++)
    {
        set_c_value(w, c, p, q, n, count);
        count++;
    }

    return 0;
}
