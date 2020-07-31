#include <Windows.h>
//#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<cmath>
#include<sstream>
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

vector<vector<float> > v(101);

int i=0;
int col=0;  


int k=0;   
//cout<<lpBuffer; 
clock_t tinside;
tinside = clock();  
while(lpBuffer[i]!='\0' ){  
                        
       string s=""; 
       
       while(lpBuffer[i]!=',' && lpBuffer[i]!='\0' && lpBuffer[i]!='\n'){
           s+=lpBuffer[i];i++;
           
           
       }
      
       float temp = ::atof(s.c_str());
       //cout<<temp<<endl;
       v[col].push_back(log(temp));
       if(lpBuffer[i]=='\n')
       {col++;} 
       if(lpBuffer[i]!='\0')
       i++;    
}
tinside = clock() - tinside;


// std::ostringstream strs;
// strs << v[i][j];
// std::string str = strs.str();
//cout<<"hey";


string res;
for(int i=0;i<100;i++){
  for(int j=0;j<3;j++){
     std::ostringstream strs;
     strs << v[i][j];
     std::string str = strs.str();
      res+=str;
      res+=',';
  }
  res+='\n';
}
char Buf[res.length()+1];
strcpy(Buf,res.c_str());

CopyMemory(lpBuffer,Buf,res.length());
cout<<lpBuffer;


bResult = UnmapViewOfFile( lpBuffer );
if( bResult == NULL)
{
 cout<<"Unmapping Failed = "<<GetLastError( )<<endl;
}
else cout<<"Unmapping Success"<<endl;


CloseHandle(hFileMap);
t = clock() - t;
cout<<"(computational)It took me \n"<<tinside<<"clicks "<<(((float)tinside)/CLOCKS_PER_SEC)<<"(seconds)"<<endl;
cout<<"(process time)It took me\n"<<t<<" clicks "<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;

system("PAUSE");
return 0;
}
