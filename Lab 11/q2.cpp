#include <iostream>
#include <vector>
using namespace std;

class DynamicStack{
private:
    vector<char> arr;

 public:
  void push(const char ch){
      arr.push_back(ch);
  }

  char pop(){
    if(arr.empty()){
      return '\0';
    }
    char ch = arr.back();
    arr.pop_back();
    return ch;
  }

   char peek() {
        if (arr.empty()) {
            return '\0';
        }

        return arr.back();
    }

     bool isEmpty() {
        return arr.empty();
    }

    string reverse(string sentence) {
        string result = "";

        for (int i = 0; i < sentence.length(); i++) {

            if (sentence[i] != ' ') {
                push(sentence[i]);
            }

            else {
                while (!isEmpty()) {
                    result += pop();
                }

                result += ' ';
            }
        }

        while (!isEmpty()) {
            result += pop();
        }

        return result;
    }


};

int main() {
    
  DynamicStack s;
  string sentence;

  cout << "Enter a Sentence: ";
  getline(cin,sentence);

  string reverseSentence = s.reverse(sentence);


  cout << "Actual Sentence: "<<sentence <<endl <<"Rversed Sentence: "<<reverseSentence<<endl;

    return 0;
}