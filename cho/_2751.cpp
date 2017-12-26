#include <iostream>
using namespace std;

void mergeSort(int* record, int recordLength) {

}

int main(){
  int temp = 0;
  cin >> temp;
  int* record = new int[temp];

  for(int i = 0; i < temp; i++){
    cin >> record[i];
  }

  //sorting
  mergeSort(record, temp);

  for(int i = 0; i < temp; i++){
    cout << record[i] << endl;
  }
  
  return 0;
}
