#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class Parity {
    private :
        string msg;
        string tmsg;
        string rmsg;
        int size;
    public :
        Parity(string m);
        void sender();
        void receiver();

};

Parity :: Parity(string m) {
    msg = m;
}

void Parity :: sender() {
    int count = 0;
    size = msg.length();
    for(int i=0 ; i<size ; i++) {
        if(msg[i] == '1') {
            count++;
        }
    }
    if(count%2 == 0) {
        tmsg = msg + "1";
    }
    else {
        tmsg = msg + "0";
    }
    cout<<"Transmitted Message : "<<tmsg<<endl;
}

void Parity :: receiver() {
    srand(time(0));
    int r = rand()%(size+2);   //generate randno from 0-(value of r=6)
    int* arr = new int[r];
    cout<<"Error induced in bits : ";
    for(int i=0 ; i<r ; i++) {     //genrate "r" no. of randno
        int s = rand()%(size+1);
        arr[i] = s;
        cout<<s<<" "; 
    }
    if(r == 0) {
        rmsg = tmsg;
    }
    else {
        rmsg = tmsg;
        for(int i=0 ; i<r ; i++) {
            if(rmsg[size-arr[i]] == '0') {    //inverted those bits
                rmsg[size-arr[i]] = '1';
            }
            else {
                rmsg[size-arr[i]] = '0';
            }
        }
    }
    cout<<endl<<"Recieved Message : "<<rmsg;
    int count = 0;
    for(int i=0 ; i<size+1 ; i++) {
        if(rmsg[i] == '1') {
            count++;
        }
    }
    if(count%2 == 0) {
        cout<<endl<<"Error detected in received message";
    }
    else {
        cout<<endl<<"No Error detected in received message";
    }
}

int main() {
    string message;
    cout<<"Enter a message : ";
    getline(cin,message);

    Parity p(message);
    p.sender();
    p.receiver();
}