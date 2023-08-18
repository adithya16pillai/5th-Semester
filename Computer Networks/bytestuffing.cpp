#include <iostream>
using namespace std;
int main(){
    char a[20],b[20];
    int i,n,j;
    string flag,esc;
    cout << "Enter the size of the frame : ";
    cin >> n;
    n=n*1;
    cout << "Enter the characters in frame : " << endl;
    for(i=0;i<n;i++) {
        cin >> a[i];
    }
    cout << "Entered characters: \n" << endl;
    for(i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    j=0;
    for(i=0;i<n;i++) {
        if(a[i]=='flag') {
            b[j]='esc';
            j++;
            b[j]=a[i];
        } else if(a[i]=='esc') {
            b[j]='esc';
            j++;
            b[j]=a[i];
        } else {
            b[j]=a[i];
        }
        j++;
    }
    cout << "\nWhat the Sender recieves: " << endl;
    cout << "flag";
    for(i=0;i<j;i++){
        cout << endl;
        cout << b[i];
    }
    cout << "\nflag";
}
