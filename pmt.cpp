#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int * pmt(string inputString){
    int len = inputString.length();
    static int * result = new int[len];
    result[0] = 0;
    int counter = 0;
    //initialize the first position
    for(int i = 1; i < len; i ++ ){
        //start from the second position
        if(inputString[counter] != inputString[i]){
            counter = 0;
        }
        else{
            counter ++;
        }
        result[i] =counter;
        //for the last "i ++" and '\0', the index length would be input.length+2
    }
    return result;
}

// int main(){
//     string target = "deaeadeae";
//     int* de = pmt(target);
//     cout << sizeof(de) <<endl;
//     for(int i = 0; i < target.length(); i++){
//         cout << de[i] <<endl;
//     }
//     system("pause");
//     return 0;
// }