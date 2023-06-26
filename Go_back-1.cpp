#include <iostream>
using namespace std;

class Go_back_n
{
    int frame;
    int Window_size;

public:
    void Transmission(int fr, int win_size)
    {
        int a = 1;
        while (a <= fr)
        {
            int timer = 0;
            for (int i = a; i < win_size + a && i <= fr; i++)
            {
                cout << "Sending Frame: " << i << endl;
            }
            cout << endl;

            for (int i = a; i < win_size + a && i <= fr; i++)
            {
                if (rand() % 2)
                {
                    cout << "Frame number: " << i << " sent\n";
                    cout << "Recieved Acknowledgememt for frame " << i << endl;
                    timer++;

                    if (a + win_size > fr)
                    {
                        continue;
                    }
                }

                else
                {
                    cout << "Time out! Acknowledgement not Recieved for Frame no: " << i << endl;
                    cout << "Re-sending Frame\n"
                         << endl;
                    break;
                }
            }
            a = a + timer;
        }
    }
};

int main()
{
    int frame, window_size;
    cout << "Enter Number of frames you want to send: ";
    cin >> frame;

    cout << "Enter Window Size: ";
    cin >> window_size;
    Go_back_n g;
    g.Transmission(frame, window_size);
    return 0;
}