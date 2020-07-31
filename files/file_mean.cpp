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
{clock_t t;
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
vector<vector<float> > v(101);
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
cout<<"mean\t\tstandard deviation\n";  
for(int i=0;i<3;i++){
  float sum=0;
  float sqsum=0;
  int m=v[i].size();
  for(int j=0;j<100;j++){
    sum=sum+v[i][j]; 
  }
  float mean=sum/100;
  for(int k=0;k<100;k++){
      sqsum=sqsum+((v[i][k]-mean)*(v[i][k]-mean));
  }
  cout<<mean<<"\t\t"<<sqrt(sqsum/100);

  cout<<endl;
}
tinside = clock() - tinside;
t=clock()-t;
cout<<"(computational)It took me "<<tinside<<"clicks "<<(((float)tinside)/CLOCKS_PER_SEC)<<"(seconds)"<<endl;
cout<<"(process time)It took me\n"<<t<<" clicks "<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;



}