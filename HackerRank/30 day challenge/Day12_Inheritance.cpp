#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
};

class Student : public Person{
	private:
		vector<int> testScores;  
	public:
		Student(string _firstName,string _lastName,int _id,vector<int> scores):	Person(_firstName,_lastName,_id),
		testScores(scores)
		{	
		}
		char calculate()
		{
			double average;
			for (auto& n: testScores)
				average += n;
			
			average = average/testScores.size();
			char grade = '?';
			
			if(average >= 90)
				grade = 'O';
			else if(average >= 80)
				grade = 'E';
			else if(average >= 70)
				grade = 'A';
			else if(average >= 55)
				grade = 'P';
			else if(average >= 40)
				grade = 'D';
			else
				grade = 'T';
			
		return grade;
		}
    
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}
