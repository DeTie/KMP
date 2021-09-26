#include <iostream>
#include <cmath>
#include "pmt.cpp"
using namespace std;

int kmp (string origString, string targString){

    if(targString.length() > origString.length()){
        return -1;
    }
    else if (targString.length() == origString.length()){
        for(int i = 0; i < origString.length(); i ++){
            if (targString[i] != origString[i]){
                return -1;
            }
        }
        return 0;
    }
    //primary check

    int * pmtDex = pmt(targString);
    //targetString to PMT index
    int result = -1;
    int i = 0;
    int j = 0;
    do{
        if(j == targString.length()){
            return i-j;
        }
        else if (j == 0 || origString[i] == targString[j]){
            i ++;
            j ++;
        }
        else{
            j = pmtDex[j - 1];
            //it means the first pmt[j-1] chars of target string is repeated
        }
    }while(i <= origString.length());
    
    return result;
}

int main (){
    string origString,targString;
    cout << "input the original string:" << endl;
    getline(cin,origString);
    cout << "input the target string for search:" << endl;
    getline(cin,targString);
    cout << kmp(origString,targString)<<endl;
    system("pause");
    return 0;
}