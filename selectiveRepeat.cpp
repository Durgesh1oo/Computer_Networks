#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
void transmission(int nf, int N, int m)
{
    srand(time(NULL));
    int i = 1, c = 0, d, e;
    while (i <= nf)
    {
        int x = 0;
        d = c;
        for (int j = i; j < i + N && j <= nf; j++)
        {
            cout << "____";
        }
        cout << endl;
        for (int j = i; j < i + N && j <= nf; j++)
        {
            cout << "| " << c;
            c++;
            if (c > m - 1)
                c = 0;
        }
        cout << " |" << endl;
        for (int j = i; j < i + N && j <= nf; j++)
        {
            cout << "____";
        }
        c = d;
        for (int j = i; j < i + N && j <= nf; j++)
        {

            int flag = rand() % 20;
            if (flag >= 0 && flag <= 10)
            {
                x++;
                e = c + 1;
                if (e > m - 1)
                    e = 0;
                cout << endl
                     << "\t\t\t\t\t\t\t\t\t\tAcknowledgment Send " << e << endl;
            }
            else if (flag >= 11 && flag <= 15)
            {
                cout << endl
                     << "\t\t\t\t ----------------";
                cout << endl
                     << "\t\t\t\t|  Frame " << c << " lost  |";
                cout << endl
                     << "\t\t\t\t ----------------";
                cout << endl
                     << "\t\t\t\t\t\t\t\t\t\tNAK Send " << c << endl;
                cout << endl
                     << "Resending Frame " << c << " ......";
            }
            else if (flag >= 16 && flag <= 20)
            {
                e = c + 1;
                if (e > m - 1)
                    e = 0;
                cout << endl
                     << "\t\t\t\t\t\t\t\t\t\tAcknowledgment Send " << e << endl;
                cout << endl
                     << "\t\t\t\t -----------------------------------";
                cout << endl
                     << "\t\t\t\t|  Acknowledgement of Frame " << e << " lost  |";
                cout << endl
                     << "\t\t\t\t -----------------------------------";
            }
            c++;
            if (c > m - 1)
                c = 0;
        }
        cout << endl;
        i += x;
    }
}
int main()
{
    int nf, N, n, m, sq;
    int no_tr = 0;

    cout << "Enter the number of frames : ";
    cin >> nf;
    cout << "Enter m : ";
    cin >> m;
    N = pow(2, m - 1);
    sq = pow(2, m);

    transmission(nf, N, sq);
    return 0;
}