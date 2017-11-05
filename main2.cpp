#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    Student(string firstName, string lastName, string patromynic, int first_score, int second_score, int third_score, int fourth_score, int fifth_score, int sixth_score) : scores(new int[6]), firstName(firstName), lastName(lastName), patronymic(patronymic){
        scores[0] = first_score;
        scores[1] = second_score;
        scores[2] = third_score;
        scores[3] = fourth_score;
        scores[4] = fifth_score;
        scores[5] = sixth_score;
    }

    ~Student(){
        delete [] scores;
    }

    int debts(){
        int count = 0;
        for (int i=0; i<6; ++i){
            if(scores[i] < 3) ++count;
        }
        return count;
    }

    bool withoutDebts(){
        for (int i=0; i < 6; ++i){
            if (scores[i]<3) return false;
        }
        return true;
    }

    double averageScore() const {
        double average = 0;
        for (int i=0; i<6; ++i){
            average += ((double) scores[i]/6);
        }
        return average;
    }

    bool isSchoolarship(){
        for (int i=0; i<6; ++i){
            if (scores[i] < 4) return false;
        }
        return true;
    }

private:
    int *scores;
    string firstName;
    string lastName;
    string patronymic;
};

float averageScore(Student students[], int n){
    if (n<5) return 0; // error
    int *temp = new int[n];
    for (int i=0; i<n; ++i){
        temp[i] = students[i].averageScore();
    }
    sort(temp, temp + n);
    int val=0;
    for (int i=2; i<n-2; ++i){
        val += temp[i];
    }
    delete[] temp;
    return val/(n-4);
}

int debtors(Student students[], int n){
    int count=0;
    for (int i=0; i<n; ++i){
        if(!students[i].withoutDebts()){
            ++count;
        }
    }
    return count;
}

int apprentices(Student students[], int n){
    int count = 0;
    for (int i=0; i<n; ++i){
        if (students[i].debts()>1){
            ++count;
        }
    }
    return count;
}

int fellowship(Student students[], int n){
    int count = 0;
    for (int i=0; i<n; ++i){
        if (students[i].isSchoolarship()){
            ++count;
        }
    }
    return count;
}

int main(){
    int n=6;
        Student students[] = {
        Student("Petr", "Abramov", "Sergeevich", 3,5,5,4,3,5),
        Student("Sergey", "Borisov", "Lvovich", 3,2,4,2,3,4),
        Student("Aleksey", "Golkhovoy", "Konstantinovich", 5,4,5,3,5,5),
        Student("Dmitri", "Ikrin", "Petrovich", 2,3,1,4,3,3),
        Student("Stepan", "Menshikov", "Aleksandrovich",5,4,5,5,3,5),
        Student("Vasili", "Yarovoy", "Ivanovich", 2,1,2,3,4,3)
    };

    cout << "Average Score: " << averageScore(students, n) << endl
         << "Debtors Count: " << debtors(students, n) << endl
         << "Apprenticies Count: " << apprentices(students, n) << endl
         << "Fellowship Count: " << fellowship(students, n) << endl;
    return 0;
}
