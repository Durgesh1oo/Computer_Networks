#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class Hamming {
    private :
        string msg , tmsg , rmsg , cmsg;
        int m , r;
        string parstring(int power , string mesg);
        int check(string parity);
    public :
        Hamming(string m);
        void sender();
        void receiver();
};

string Hamming :: parstring(int power , string mesg) {
    string parity = "";
    for(int j=power ; j<=m+r ; j=j+(2*power)) {
        int  temp = power;
        int k = j-1;
        while(temp>0 && k<m+r) {
            parity+=(mesg[k++]);
            temp--;
        }
    } 
    return parity;
}

int Hamming :: check(string parity) {
    int num = 0;
    for(int l=0 ; l<parity.length() ; l++) {
        if(parity[l] == '1') {
            num++;
        }
    }
    return num;
}

Hamming :: Hamming(string ms) {
    msg = ms;
}

void Hamming :: sender() {
    m = msg.length();
    r = 0;
    while(pow(2,r) < m+r+1) {
        r++;
    }
    string temp(m+r , '0');
    tmsg = temp;
    int count = 0;
    for(int i=0 ; i<m+r ; i++) {
        int pos = i+1;
        if(!(floor(log2(pos)) == ceil(log2(pos)))) {
            tmsg[i] = msg[count];
            count++;
        }
    }
    for(int i=0 ; i<r ; i++) {
        int power = pow(2,i);
        string parity = parstring(power,tmsg); 
        int num = check(parity);
        if(num%2 == 0) {
            tmsg[power-1] = '1';
        }
        else {
            tmsg[power-1] = '0';
        }
    }
    cout<<"Transmitted message : "<<tmsg<<endl;
}

void Hamming :: receiver() {
    srand(time(0));
    int e = rand()%2;
    if(e == 0) {
        rmsg = tmsg;
        cout<<"No error induced"<<endl;
    }
    else {
        rmsg = tmsg;
        int pos = rand()%(m+r);
        if(rmsg[pos] == '0') {
                rmsg[pos] = '1';
        }
        else {
            rmsg[pos] = '0';
        }
        cout<<"Error induced "<<endl;
    }
    cout<<"Received message : "<<rmsg<<endl;

    if(e) {
        int epos = 0;
        for(int i=0 ; i<rmsg.length() ; i++) {
            int pos = i+1;
            if((floor(log2(pos)) == ceil(log2(pos)))) {
                string parity = parstring(pos,rmsg);
                int num = check(parity);
                if(num%2 == 0) {
                    epos+=pos;
                }
            }
        }
        cout<<"Error at position : "<<epos<<endl;
        cmsg = rmsg;
        if(cmsg[epos-1] == '1') {
            cmsg[epos-1] = '0';
        }
        else {
            cmsg[epos-1] = '1';
        }
        cout<<"Corrected message : "<<cmsg<<endl;
    }


}


int main() {
    string message;
    cout<<"Enter a message : ";
    getline(cin,message);

    Hamming h(message);
    h.sender();
    h.receiver();

    return 0;
}