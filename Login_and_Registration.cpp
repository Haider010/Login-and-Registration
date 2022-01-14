#include<bits\stdc++.h>
#include<conio.h>
using namespace std;
class SYSTEM{
    string user_id;
    string password;
    public:
    void login();
    void registration();
    void forgot_password();
};
void SYSTEM::registration(){
    cout<<"\n-----REGISTRATION-----"<<endl;
    fstream reg;
    reg.open("system.txt",ios::out|ios::binary);
    cout<<"\nENTER USERNAME : ";cin>>user_id;
    cout<<"ENTER PASSWORD : ";cin>>password;
    reg.write((char*)this,sizeof(*this));
    reg.close();
}
void SYSTEM::login(){
    string username,passward;
    cout<<"\n-----LOGIN-----"<<endl;
    fstream log;
    log.open("system.txt",ios::in|ios::binary);
    if(!log){
        cout<<"\nNO ACCOUNT IS REGISTERED"<<endl;
        return;
    }
    cout<<"\nENTER USER NAME : ";cin>>username;
    log.read((char*)this,sizeof(*this));
    while (!log.eof())
    {
        if(username==user_id){
        cout<<"ENTER PASSWORD : ";cin>>passward;
        if(passward==password){
            cout<<"\nLOGIN SUCESSFULLY"<<endl;
            exit(0);
        }
        else{
            cout<<"\nPASSWORD IS INCORRECT....TRY AGAIN"<<endl;
            return;
        }
        }  
        else{
            cout<<"\nUSER NAME IS INCORRCT.....TRY AGAIN"<<endl;
            return;
        }        
        log.read((char*)this,sizeof(*this));
    }
}
int main(){
    SYSTEM user;
    int choice;
    fh:
    cout<<"\n---------LOGIN AND RESGISTRATION SYSTEM----------"<<endl;
    cout<<"\n1 => LOGIN"<<endl;
    cout<<"2 => REGISTRATION"<<endl;
    cout<<"3 => EXIT"<<endl;
    cout<<"\nENTER YOUR CHOICE : ";cin>>choice;
    switch (choice)
    {
    case 1:
    user.login();
    goto fh;
        break;
    case 2:
    user.registration();
    goto fh;
        break;
    case 3: 
        exit(0);
    default:
        cout<<"\nINVALID CHOICE.....TRY AGAIN"<<endl;
        goto fh;
    }
    return 0;
    goto fh;
}