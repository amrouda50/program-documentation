#include <iostream>
#include <vector>
using namespace std;

void greater_than_k(int temp[] , int K , vector<int>& result , int N);
void max_selection(int& start , int& last1 , vector<int> result );

int main()
{int N , K;
vector<int> result;
vector <int> last;

cin >> N >> K;
int temp [N];
for(int i = 0 ; i < N ; i++){
    cin >> temp[i];
}
int start = 0;
int last1 = 0;
greater_than_k(temp , K , result , N);
max_selection( start , last1 ,result);
if(last1 == 0){
    cout << "nincs";
}
else{
     cout << start << " "<< last1 << endl;
}
}
void greater_than_k(int temp[] , int K , vector<int>& result , int N){
for(int j = 0 ; j < N ; j++){
while(j < N && temp[j] > K){
    result.push_back(j+1);
    j++;
}
}

}

void max_selection(int& start , int& last1 , vector<int> result ){
int len = 1;
int maxlen = 1;
for( unsigned int i = 1 ; i < result.size() ; i++){

    if(result[i] == result[i-1] + 1) len++;
    else  len = 1;
    if(len > maxlen){
        last1 = result[i];
        maxlen = len;

    }
}
start = (last1 - maxlen) + 1;

}
