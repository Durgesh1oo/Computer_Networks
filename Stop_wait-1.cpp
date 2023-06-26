
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

class Stop_wait{
   int frames;
   public:
   void Transmission(int fr){
     int a =1;
     srand(time(0));
     while (a<=fr)
     {
        int timer =0;
        for(int i=a; i<1+a && i<=fr; i++){
            cout<<"Sending Frame: "<<i<<endl;
        }
        cout<<endl;       
   
        for(int i=a; i<1+a && i<=fr; i++){
            if(rand()%2){
                cout<<"Frame number: "<<i<<" sent\n";
                cout<<"Recieved Acknowledgememt for frame "<<i<<endl;
                timer++ ;
            }

            else{
                cout<<"Time out! Acknowledgement not Recieved for Frame no: "<<i<<endl;
                cout<<"Re-sending Frame\n"<<endl;
                break;
            }
        }  
     a = a+timer;
     }
   }
};

int main(){
    int frame;
    cout<<"Enter Number of frames you want to send: ";
    cin>>frame;

    Stop_wait s;
    s.Transmission(frame);
    return 0;
}
