#include <iostream>
#include <cmath>
using namespace std;

double Distance(double *pos1,double *pos2 ){
    double d1;
    return d1=sqrt(pow((pos1[0]-pos2[0]),2)+pow((pos1[1]-pos2[1]),2));
}

int Distance(int *pos1,int *pos2){
    int d2;
    return d2=sqrt(pow((pos1[0]-pos2[0]),2)+pow((pos1[1]-pos2[1]),2));
}
int main(){
    double pos1[2],pos2[2]={};
    double d1;
    int d2;
    cout << "Enter the first coordinate: "<<endl; 
    cin >> pos1[0] >> pos1[1];
    cout << "if you want to enter the second coordinate press 1, if you want to use the defult coordinate press 0: "<<endl;
    int choice;
    cin >> choice;
    if (choice==1){
        cout << "Enter the second coordinate: ";
        cin >> pos2[0] >> pos2[1];
    }
    else
        cout << "You have chosen the defult coordinate (0,0)"<<endl;
    
    int pos3[2]={pos1[0],pos1[1]},pos4[2]={pos2[0],pos2[1]};
    d1=Distance(pos1,pos2);
    d2=Distance(pos3,pos4);
    cout << "The double distance between the two points is: "<<d1<<endl;
    cout << "The int distance between the two points is: "<<d2<<endl;
    return 0;
}