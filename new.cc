#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> my;
    list<int>::iterator it;
    my.push_back(100);
    my.push_back(200);
    my.push_back(300);
    it = my.begin();
    cout<<*(++it)<<endl;
    it++;
    cout<<*(++it)<<endl;
    cout<<*(++it)<<endl;
}