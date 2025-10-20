#include"filehandler.h"
#include<string>
#include<fstream>
#include<sstream>

    string filehandler::readfile(const string filename){
         ifstream file(filename);
         stringstream buffer;
         buffer<<file.rdbuf();
         return buffer.str();
  };
    void filehandler::writefile(const string filename,const string content){
        ofstream file(filename);
        file<<content;
        file.close();
  }
