#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string sentence;

  cout << "Enter a Sentence: ";
  getline(cin, sentence);

  int len = sentence.length();
  cout << "Length of Sentence: " << len << endl;

  ofstream fout("data.txt");

  if (!fout)
  {
    cout << "File cannot be created" << endl;
    return 0;
  }

  fout << sentence;
  fout.close();
  cout << "Data Written Successfully" << endl;

  ifstream fin("data.txt");

  if (!fin)
  {
    cout << "File cannot be opened." << endl;
    return 0;
  }

  string data;

  cout << "Reading Data from File:" << endl;
  getline(fin, data);
  cout << data << endl;

  fin.close();

  return 0;
}