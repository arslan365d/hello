#include <iostream>
#include <fstream>
using namespace std;

int main()
{

  ifstream fin("src.txt");
  ofstream fout("dest.txt");

  if (!fin)
  {
    cout << "Source file cannot be opened" << endl;
    return 0;
  }

  if (!fout)
  {
    cout << "Destination file cannot be created" << endl;
    return 0;
  }

  string line;

  while (getline(fin, line))
  {
    fout << line << endl;
  }
  fin.close();
  fout.close();

  cout << "File Copied Successfuly" << endl;

  return 0;
}