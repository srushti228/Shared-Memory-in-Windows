#include<windows.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<cmath>
#include<sstream>
#include <fstream>
#include<time.h>

using namespace std;
int main()
{ clock_t t;
 t=clock();
    string s="";

      char c;
  
    ifstream in("sales.csv");
    if (!in) {
        cout << "File Does not Exist";

        return 0;
    }
    cout << "\n\n";

    while (in.eof() == 0) {
        in.get(c);
        s+=c;

    }
  
//cout<<s<<endl;
vector<vector<float> > v(101);

int i=0;
int col=0;  


int k=0;   

  
while(s[i]!='\0' ){  
                        
       string str=""; 
       
       while(s[i]!=',' && s[i]!='\0' && s[i]!='\n'){
           str+=s[i];i++;
           
           
       }
      // cout<<str<<endl;
      
       float temp = ::atof(str.c_str());
       //cout<<temp<<endl;
       v[col].push_back(log(temp));
       if(s[i]=='\n')
       {col++;} 
       if(s[i]!='\0')
       i++;    
}
clock_t tinside;
tinside = clock();

/*for(int i=0;i<100;i++){
  for(int j=0;j<3;j++){
      cout<<v[i][j]<<",";
  }
  cout<<endl;
}*/
  ofstream ins("sales.csv");
string res;
for(int i=0;i<100;i++){
  for(int j=0;j<3;j++){
     std::ostringstream strs;
     strs << v[i][j];
     std::string stri = strs.str();
      res+=stri;
      res+=',';
  }
  res+='\n';
}
//cout<<res<<endl;

ins<< res << endl; // to save string into file*/
in >> res;
cout<<res<<endl;
ins.close();
  in.close();
tinside = clock() - tinside;
t=clock()-t;


cout<<"(computational)It took me \n"<<tinside<<"clicks "<<(((float)tinside)/CLOCKS_PER_SEC)<<"(seconds)"<<endl;
cout<<"(process time)It took me\n"<<t<<" clicks "<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;

}