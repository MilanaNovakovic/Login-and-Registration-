#include<iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
void program();
void registration();
void login();
void forgot();

int main(){
    program();
    return 0;
}

void program(){
cout<<"__________________________________________________________"<<"\n";
cout<<"\t\t Welcome to the login page"<<"\n";
cout<<"__________________________________________________________"<<"\n";

cout<<"Press 1 to LOGIN\n";
cout<<"Press 2 to REGISTRATION\n";
cout<<"Press 3 if you forgot you PASSWORD\n";
cout<<"Press 4 to EXIT\n";
int c;
cin>>c;
switch (c)
{
case 1:
    system("cls");
    login();
    break;
case 2:
    system("cls");
    registration();
    break;
case 3:
    system("cls");
    forgot();
    break;
case 4:
    cout<<"Thank you\n";
    break;        
default:
system("cls");
program();
    break;
}



}

void registration(){
    cout<<"username: ";
    string id;
    cin>>id;
    cout<< "password: ";
    string pass;
    cin>>pass;
    ifstream input("registration.txt");
    string pid, ppass;
    bool found=false;
    while(input>>pid>>ppass){
        if(id==pid){
            found=true;
            break;
        }

    }
    input.close();
    if(found){
        cout<<"Username already exist\n";
        program();
    }else{
    ofstream  f1("registration.txt", ios::app);
    f1<<id<<" "<<pass<<"\n";
    f1.close();
    cout<<"Registration done\n";
    }
   
}

void login(){
    cout<<"username: ";
    string id;
    cin>>id;
    cout<< "password: ";
    string pass;
    cin>>pass;

    ifstream input("registration.txt");
    string pid, ppass;
    bool found=false;
    while(input>>pid>>ppass){
        if(pid==id && ppass==pass){
            found=true;
            break;
        }
    }
    if(found){
        cout<<"Successful login\n";
        
    }else{
        system("cls");
        cout<<"Error in username or password\n";
        program();

    }
    


}

void forgot(){
    cout<<"We will found your password by your username\n";
    cout<<"username: ";
    string id;
    cin>>id;
    ifstream input("registration.txt");
    string pid, pass;
    bool found=false;
    while(input>>pid>>pass){
        if(pid==id){
            found=true;
            break;

        }
    }
    input.close();
    if(found){
        cout<<"Your password is: "<<pass<<endl;
    }else{
        system("cls");
        cout<<"Password not found\n";
        program();

    }
    
}