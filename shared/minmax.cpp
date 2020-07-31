#include <Windows.h>
//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<time.h>
using namespace std;
int main( )
{
clock_t t;
t = clock();
cout<<"\t\t..FILEMAPPING CLIENT or CHILD PROCESS.."<<endl;


HANDLE   hFileMap ;
BOOL     bResult ;
PCHAR    lpBuffer = NULL;

hFileMap = OpenFileMapping(
          FILE_MAP_ALL_ACCESS,
          FALSE,
          "Local\\MyFileMap");
if (hFileMap == NULL)
{
  cout<<"OpenFIleMap Failed"<<endl;
  cout<<"Error No-> "<<GetLastError()<<endl;
}
else cout<<"OpenFIleMap Success"<<endl;

lpBuffer = (PCHAR)MapViewOfFile(
             hFileMap,
             FILE_MAP_ALL_ACCESS,
             0,
             0,
             256 );
if( lpBuffer == NULL )
{
  cout<<"MapViewOfFile Failed "<<endl;
  cout<<"Error No - "<<GetLastError( )<<endl;
}
else cout<<"MapViewOfFile Success"<<endl;


cout<<"DATA READING FROM SERVER or PARENT PROCESS"<<endl;
//cout<<lpBuffer<<endl;
vector<vector<float> > v(101);
int i=0;
int col=0;
while(lpBuffer[i]!='\0' ){  
                        
       string s=""; 
       
       while(lpBuffer[i]!=',' && lpBuffer[i]!='\0' && lpBuffer[i]!='\n'){
           s+=lpBuffer[i];i++;
           
           
       }
      
       float temp = ::atof(s.c_str());
       //cout<<temp<<endl;
       v[col++].push_back(temp);
       if(lpBuffer[i]=='\n')
       {col=0;} 
       if(lpBuffer[i]!='\0')
       i++;    
}
clock_t tinside;
tinside = clock();
cout<<"min\t\tmax\n";
for(int i=0;i<3;i++){
  vector<int> a;
  float min=v[i][0];
  float max=v[i][0];
  for(int j=0;j<v[i].size();j++){
    if(v[i][j]<min) min=v[i][j];
    if(v[i][j]>max) max=v[i][j];
  }
  cout<<min<<"\t\t"<<max;

  cout<<endl;
}
tinside = clock() - tinside;
cout<<"(computational)It took me \n"<<tinside<<"clicks "<<(((float)tinside)/CLOCKS_PER_SEC)<<"(seconds)"<<endl;



bResult = UnmapViewOfFile( lpBuffer );
if( bResult == NULL)
{
 cout<<"Unmapping Failed = "<<GetLastError( )<<endl;
}
else cout<<"Unmapping Success"<<endl;


CloseHandle(hFileMap);
t = clock() - t;
cout<<"(process time)It took me\n"<<t<<" clicks "<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;
system("PAUSE");
return 0;
}
