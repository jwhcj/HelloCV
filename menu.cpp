#include<iostream>
#include<string>
#include"crypto.h"
#include"filehandler.h"
#include"menu.h"
#include<limits>
using namespace std; 

void menu::mainmenu(){
     cout<<"1.文本加密\n";
     cout<<"2.文本解密\n";
     cout<<"3.文件加密\n";
     cout<<"4.文件解密\n";
     cout<<"5.退出程序\n";
     cout<<"请选择功能：\n";
     int choice;
     cin>>choice;
     switch(choice){
       case 1:
         menu::encrytxtmenu();
         break;
       case 2:
         menu::decrytxtmenu();
         break;
       case 3:
         menu::encryfilemenu();
         break;
       case 4:
         menu::decryfilemenu();
         break;
       case 5:
         return;
     }
}
void menu::encrytxtmenu(){
     string text;int key;
     cout<<"请输入要加密的文本：";
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     getline(cin,text);
     cout<<"请输入密钥：";
     cin>>key;
     string encrypto=crypto::ceasarencrypto(text,key);
     cout<<"加密结果："<<encrypto<<endl;  
}

void menu::decrytxtmenu(){
     string text;int key;
     cout<<"请输入要解密的文本：";
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     getline(cin,text);
     cout<<"请输入密钥：";
     cin>>key;
     string decrypto=crypto::ceasardecrypto(text,key);
     cout<<"解密结果："<<decrypto<<endl;
}

void menu::encryfilemenu(){
     string inputfile,outputfile;
     cout<<"请输入要加密的文件路径：";
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     getline(cin,inputfile);
     cout<<"请输入密钥：";
     int key;
     cin>>key;
     string content=filehandler::readfile(inputfile);
     string encrycontent=crypto::ceasarencrypto(content,key);
     outputfile="encrypted.txt";
     filehandler::writefile(outputfile,encrycontent);
       cout<<"加密结果已保存到："<<outputfile<<endl;    
}

void menu::decryfilemenu(){
     string inputfile,outputfile;
     cout<<"请输入要解密的文件路径：";
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     getline(cin,inputfile);
     cout<<"请输入密钥：";
     int key;
     cin>>key;
     string content=filehandler::readfile(inputfile);
     string encrycontent=crypto::ceasardecrypto(content,key);
     outputfile="decrypted.txt";
     filehandler::writefile(outputfile,encrycontent);
     cout<<encrycontent;
       cout<<"解密结果已保存到："<<outputfile<<endl;    
}
