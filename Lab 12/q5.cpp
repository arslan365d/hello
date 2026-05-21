#include <iostream>
#include <fstream>
using namespace std;

int countLines(){
  ifstream fin("story.txt");

  if(!fin){
    cout << "File cannot be opened"<<endl;
    return 0;
  }

  int count = 0;
  string sentence;

  while(getline(fin,sentence)){
    if(!sentence.empty() && sentence[0] != 'A'){
       cout << sentence <<endl;
       count++;
    }
  }

  return count;
}

int main() {
    int count = countLines();

    cout << "The Number of Lines Without A is "<<count<<endl;


    return 0;
}