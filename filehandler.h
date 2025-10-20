#include<string>
using namespace std;

class filehandler{
public:
     static string readfile(const string filename);
     static void writefile(const string filename,const string content);
};
