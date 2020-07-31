
#include <Windows.h>
//#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;
int main( )
{
cout<<"\t\t...FILEMAPPING SERVER or PARENT PROCESS.."<<endl;
HANDLE   hFileMap ;
BOOL     bResult ;
PCHAR    lpBuffer = NULL;



char c;
string s="";

FILE *pFile = fopen ( "sales.csv" , "r" );
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
    //s+='\0';

//cout<<s<<endl;
fseek (pFile , 0 , SEEK_END);
  long szBuffer = ftell (pFile);
  rewind (pFile);
  //cout<<szBuffer<<endl;
char Buffer[szBuffer+1];
strcpy(Buffer,s.c_str());
//cout<<Buffer<<endl;
hFileMap = CreateFileMapping(
                INVALID_HANDLE_VALUE,
                NULL,
                PAGE_READWRITE,
                0,
                szBuffer,
                "Local\\MyFileMap");

if (hFileMap == FALSE)
{
   cout<<"CreateFileMapping Failed "<<endl;
   cout<<"Error No - "<<GetLastError()<<endl;
}
 cout<<"CreateFileMapping Success"<<endl;


lpBuffer = (PCHAR)MapViewOfFile(
                hFileMap,
                FILE_MAP_ALL_ACCESS,
                0,
                0,
                szBuffer);
if (lpBuffer == NULL)
{
  cout<<"MapViewOfFile failed "<<endl;
  cout<<"Error No ->"<<GetLastError()<<endl;
}
cout<<"MapViewOfFile Success"<<endl;


CopyMemory(lpBuffer,Buffer,szBuffer);
cout<<lpBuffer;


bResult = UnmapViewOfFile(lpBuffer);
if (bResult == FALSE)
{
  cout<<"UnMapViewOfFIle Failed"<<endl;
  cout<<"Error No-> "<<GetLastError()<<endl;
}
cout<<"UnMapViewOfFIle Success"<<endl;

system("PAUSE");
return 0;
}

