#include<bits/stdc++.h> 
using namespace std; 

string crc(string input,string key){
	int key_len=key.length();
	int n=input.length();
	for(int i=0;i<n-key_len+1;i++){
		for(int j=0;j<key_len;j++){
			input[i+j]=input[i+j]==key[j]?'0':'1';
		}
		for(;i<n&&input[i]!='1';i++);
		if(input[i]=='1')
			i--;
	}
	return input.substr(n-key_len+1);
}
 
int main() {
	string data,x;
	cout << "Enter data: ";
	cin >> data;
	cout << "Enter key: ";
	cin >> x;
	string temp = data;
	for(int i = 0; i < x.length()-1; i++)
	temp+='0';
	string checksum;
	checksum = crc(temp,x);
	cout << "Encoded data: ";
	cout << data+checksum;
	cout << "\nCheck sum: ";
	cout << checksum;
	cout << endl;
	cout << "          Reciever Side          "<<endl;
	cout << "Enter data recieved: ";
	string msg;
	cin >> msg;
	if(msg.length() != data.length()) {
		cout << "Error in data";
		return 0;
	}
	string remainder;
	remainder = crc(msg,x);
	for(auto x:remainder)
		if(x!='0') {
			cout << "Error in data";
			return 0;
		}
	cout << "No error!\n";
}
