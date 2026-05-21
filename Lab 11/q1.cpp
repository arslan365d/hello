#include <iostream>
using namespace std;

class PasswordLengthException{
    public:
    const char* what(){
      return "Password cannot have less then 6 characters";
    }
};

class PasswordDigitException{
    public:
    const char* what(){
      return "Password must contain at least one digit";
    }
};

int main() {
   string userName,password;
   cout<<"Enter your User name: ";
   cin>> userName ;
   cout<<"Enter your Password: ";
   try{
     cin>> password;
     if(password.length()<6){
        PasswordLengthException e;
        throw e;
     }

     int found = -1;
     for(int i=0;i<password.length();i++){
          if(password[i] >= 48 && password[i]<=57){
             found =1;
             break;
          }
     }
     if(found ==-1){
      PasswordDigitException e;
      throw e;
     }
     
   cout << "Login Successfull!!!!"<<endl;
    cout << "Username: "<<userName <<endl << "Password: "<<password<<endl;

   }catch(PasswordLengthException &e){
      cout << e.what();
   }
   catch(PasswordDigitException &e){
      cout << e.what();
   }

   


    return 0;
}