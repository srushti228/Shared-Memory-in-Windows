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
{  clock_t t;
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
cout<<s;
vector<vector<float> > v(100);
int i=0;
int col=0;
while(s[i]!='\0' ){  
                        
       string str=""; 
       
       while(s[i]!=',' && s[i]!='\0' && s[i]!='\n'){
           str+=s[i];i++;
           
           
       }
      
       float temp = ::atof(str.c_str());
       //cout<<temp<<endl;
       v[col++].push_back(temp);
       if(s[i]=='\n')
       {col=0;} 
       if(s[i]!='\0')
       i++;    
}


clock_t tinside;
tinside = clock();
cout<<"min\t\tmax\n";
for(int i=0;i<3;i++){

  float min=v[i][0];
 
  float max=v[i][0];
  for(int j=0;j<100;j++){
    if(v[i][j]<min){min=v[i][j];}
    if(v[i][j]>max) max=v[i][j];
  }

  cout<<min<<"\t\t"<<max;

  cout<<endl;
}
tinside = clock() - tinside;
t=clock()-t;
cout<<"(computational)It took me \n"<<tinside<<"clicks "<<(((float)tinside)/CLOCKS_PER_SEC)<<"(seconds)"<<endl;


cout<<"(process time)It took me\n"<<t<<" clicks "<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;

}