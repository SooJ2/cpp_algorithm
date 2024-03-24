#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
vector<string> split(string text, string delim){
    vector<string> result;
    long long pos;
    while((pos = text.find(delim)) != string::npos){
        string token = text.substr(0,pos);
        result.push_back(token);
        text.erase(0,pos+delim.length());
    }
    if (text.length())
        result.push_back(text);
        return result;
}
*/

vector<string> split(string text, string delimiter){
    vector<string> result;
    long long pos;
    while((pos=text.find(delimiter)) != string::npos){
        result.push_back(text.substr(0,pos));
        text.erase(0,pos+delimiter.length());
    }
    if (text.length() != 0)
        result.push_back(text);

    return result;
}


int main(){
    string text_sample = "hello world ! !";
    string delimiter = " ";
    vector<string> ret = split(text_sample,delimiter);
    for (string e: ret){
        cout << e << endl;
    }
}