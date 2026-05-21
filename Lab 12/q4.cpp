#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

class Participant {
private:
    string name;
    int id, score;

public:

    Participant(int id, string name, int score) {
        this->id = id;
        this->name = name;
        this->score = score;
    }

    Participant() {}

    void input() {
        ofstream fout("participant.dat", ios::app);
         if(!fout){
          cout << "File cannot be created"<<endl;
          return;
        }

        fout << id << " " << name << " " << score << endl;

        fout.close();

        cout << "Participant Data Stored Successfully" << endl;
    }

    void output(int reqid) {
        ifstream fin("participant.dat");

         if(!fin){
          cout << "File cannot be opened"<<endl;
          return;
        }

        int id;
        string name;
        int score;

        bool found = false;

        while (fin >> id >> name >> score) {
            if (id == reqid) {
                cout << "ID: " << id << endl;
                cout << "Name: " << name << endl;
                cout << "Score: " << score << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Record not found!" << endl;
        }

        fin.close();
    }


    void maxScore() {
        ifstream fin("participant.dat");

        if(!fin){
          cout << "File cannot be opened"<<endl;
          return;
        }

        int id, score;
        string name;

        int maxScore = INT_MIN;

        while (fin >> id >> name >> score) {
            if (score > maxScore) {
                maxScore = score;
            }
        }

        fin.close();

        cout << "Maximum Score: " << maxScore << endl;
    }
};

int main() {

    Participant p1(11, "Arslan", 18);
    Participant p2(12, "Ali", 25);
    Participant p3(13, "Ahmed", 20);

    p1.input();
    p2.input();
    p3.input();

    cout << "\nSearch Result:\n";
    p1.output(12);

    p1.maxScore();

    return 0;
}