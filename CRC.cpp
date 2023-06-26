  #include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class CRC {
    private:
        string msg , gmsg , tmsg , rmsg , rem;
        string divison(string divid , string divis);
        string Xor(string s1 , string s2);
    public:
        CRC(string m , string gm);
        void sender();
        void receiver();

};

string CRC :: Xor(string s1 , string s2) {
    string res = "";
    for(int i=0 ; i<s1.length() ; i++) {
        if((s1[i]=='0' && s2[i]=='0') || (s1[i]=='1' && s2[i]=='1')) {
            res+="0";
        }
        else {
            res+="1";
        }
    }
    return res;
}

string CRC :: divison(string divid , string divis) {
    int count = 0;
    string temp(divis.length() , '0');
    string result = temp;
    while(count < divid.length()) {
        int i = 0;
        while(i < divis.length()) {
            if(result[i] == '1') {
                break;
            }
            i++;
        }
        if(divid.length()-count<i) {
            result.erase(0,divid.length()-count);
            result.append(divid , count , divid.length()-count);
        }
        else {
            result.erase(0,i);
            result.append(divid , count , i);
        }
        count += i;
        if(result[0]=='1') {
            result = Xor(result , divis);
        }
        //if(result == temp) {
        //    break;
        //}
    }
    result.erase(0,1);
    return result;
}

CRC :: CRC(string m , string gm) {
    msg = m;
    gmsg = gm;
}

void CRC :: sender() {
    tmsg = msg;
    for(int i=1 ; i<gmsg.length() ; i++) {
        tmsg.append("0");
    }
    rem = divison(tmsg , gmsg);
    tmsg.replace(tmsg.length()-rem.length() , rem.length() , rem);
    cout<<"Remainder : "<<rem<<endl;
    cout<<"Transmitted message : "<<tmsg<<endl;
}

void CRC :: receiver() {
    srand(time(0));
    int r = rand()%(tmsg.length()+1);
    int* arr = new int[r];
    cout<<"Error induced in bits : ";
    for(int i=0 ; i<r ; i++) {
        int s = rand()%(tmsg.length());
        arr[i] = s;
        cout<<s<<" "; 
    }
    if(r == 0) {
        rmsg = tmsg;
    }
    else {
        rmsg = tmsg;
        for(int i=0 ; i<r ; i++) {
            if(rmsg[tmsg.length()-arr[i]-1] == '0') {
                rmsg[tmsg.length()-arr[i]-1] = '1';
            }
            else {
                rmsg[tmsg.length()-arr[i]-1] = '0';
            }
        }
    }
    cout<<endl<<"Recieved Message : "<<rmsg;
    string nrem = divison(rmsg , gmsg);
    bool flag = true;
    int j = 0;
    while(j<nrem.length()) {
        if(nrem[j] == '1') {
            flag = false;
            break;
        }
        j++;
    }
    cout<<endl<<"Remainder : "<<nrem;
    if(flag) {
        cout<<endl<<"Error not detected in received message";
    }
    else {
        cout<<endl<<"Error detected in received message";
    }

}

int main() {
    string message , gmessage;
    cout<<"Enter a message : ";
    getline(cin,message);
    cout<<"Enter generator message : ";
    getline(cin,gmessage);

    CRC que1(message , gmessage);
    que1.sender();
    que1.receiver();
}