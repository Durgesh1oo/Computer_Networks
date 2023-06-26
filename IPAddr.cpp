#include<iostream>
#include<climits>
#include<string>
using namespace std;

class IP {
    private:
        string ipaddr;
        int ipsplit[4];
    public:
        IP(string addr) {ipaddr = addr;}
        void checkrange();
};

void IP :: checkrange() {
    int count = 0;
    for(int i=0 ; i<ipaddr.size() ; i++) {
        if(!isdigit(ipaddr[i]) && ipaddr[i]!='.') {
            cout<<"This is not a valid ipv4 address"<<endl;
            return ;
        }
        if(ipaddr[i]=='.') {
            count++;
        }
    }
    if(count>3) {
        cout<<"This is not a valid ipv4 address"<<endl;
        return ;
    }

    string temp = "";
    int j = 0;
    for(int i=0 ; i<ipaddr.size() ; i++) {
        if(ipaddr[i] != '.') {
            temp+=ipaddr[i];
        }
        else {
            ipsplit[j] = stoi(temp);
            temp = "";
            j++;
        }
    }
    ipsplit[3] = stoi(temp);//this statement puts last number of ip in array as it is left in above loop

    bool flag = true;
    for(int i=0 ; i<4 ; i++) {
        if(0>ipsplit[i] || ipsplit[i]>255) {
            flag = false;
        }
    }
    if(flag) {
        if(0<=ipsplit[0] && ipsplit[0]<=127) {
            cout<<"This ip address belongs to class A"<<endl;
        }
        else if(128<=ipsplit[0] && ipsplit[0]<=191) {
            cout<<"This ip address belongs to class B"<<endl;
        }
        else if(192<=ipsplit[0] && ipsplit[0]<=223) {
            cout<<"This ip address belongs to class C"<<endl;
        }
        else if(224<=ipsplit[0] && ipsplit[0]<=239) {
            cout<<"This ip address belongs to class D"<<endl;
        }
        else {
            cout<<"This ip address belongs to class E"<<endl;
        }
    }
    else {
       cout<<"This is not a valid ip address"<<endl;
    }
}

int main() {
    string ip;
    cout<<"Enter ipv4 address : ";
    cin>>ip;
    IP ip1(ip);
    ip1.checkrange();

}
