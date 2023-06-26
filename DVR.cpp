#include<iostream>
#include<climits>
using namespace std;

class DVR {
    private:
    int nnodes;
    int source;
    int nneigh;
    int* neigh;
    int* stondelay;
    int** dvectors;
    int* distance;
    int* nextnode;

    public:
    void takeinput();
    void maketable();
    void display();
};

void DVR :: takeinput() {
    cout<<"Enter no of nodes in network : ";
    cin>>nnodes;
    cout<<"Enter node for which you want routing table : ";
    cin>>source;
    cout<<"Enter no of neighbour of above node : ";
    cin>>nneigh;
    cout<<"Enter neighbour nodes : ";
    neigh = new int[nneigh];
    for(int i=0 ; i<nneigh ; i++) {
        cin>>neigh[i];
    }
    cout<<"Enter delays from source to neighbour nodes respectively : ";
    stondelay = new int[nneigh];
    for(int i=0 ; i<nneigh ; i++) {
        cin>>stondelay[i];
    }
    dvectors = new int*[nneigh];
    for(int i=0 ; i<nneigh ; i++) {
        dvectors[i] = new int[nnodes];
        cout<<"Enter distance vector of node "<<neigh[i]<<" : ";
        for(int j=0 ; j<nnodes ; j++) {
            cin>>dvectors[i][j];
        }
    }
}

void DVR :: maketable() {
    distance = new int[nnodes];
    nextnode = new int[nnodes];
    for(int i=0 ; i<nnodes ; i++) {
        bool flag = false;
        int min = INT_MAX;
        int nxt;
        for(int j=0 ; j<nneigh ; j++) {
            int dist = dvectors[j][i] + stondelay[j];
            if(dist<min) {
                min = dist;
                nxt = neigh[j];
            }
        }
        for(int k=0 ; k<nneigh ; k++) {
            if(i==neigh[k]) {
                flag = true;
                min = stondelay[k];
                nxt = neigh[k];
                break;
            }
        }
        distance[i] = min;
        nextnode[i] = nxt;
    }
    distance[source] = 0;
    nextnode[source] = INT_MAX;
}

void DVR :: display() {
    cout<<"Routing table for node "<<source<<" : "<<endl;
    cout<<"Distance       Next"<<endl;
    for(int i=0 ; i<nnodes ; i++) {
        cout<<distance[i]<<"                "<<nextnode[i]<<endl;
    }
}


int main() {
    DVR que1;
    que1.takeinput();
    que1.maketable();
    que1.display();
}