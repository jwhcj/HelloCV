#include"crypto.h"
#include<cctype>
#include<string>
using namespace std;
 string crypto:: ceasarencrypto(const string text,int key){
       string result="";
       for(char c:text){
          if(isalpha(c)){
            char base=isupper(c)? 'A':'a';
            c=(c-base+key)%26+base;
          }  
            result=result+c;
       }
       return result;
};
 string crypto:: ceasardecrypto(const string text,int key){
       string result="";
       for(char c:text){
          if(isalpha(c)){
            char base=isupper(c)? 'A':'a';
            c=(c-base+(26-key%26))%26+base;
          }  
            result=result+c;
       }
       return result;
};
