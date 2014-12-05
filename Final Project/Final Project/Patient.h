#include <iostream>
#include <string>

using namespace std;

class Patient{
private:
	int timeAdmitted;
	int timeSeen;
	int timeReleased;
	string name;
	int ENTEREDseverity;
	bool survived;
public:
	Patient(int timeAdmitted, string name, int severity){
		this->timeAdmitted = timeAdmitted;
		this->name = name;
		this->ENTEREDseverity = severity;
		survived = false;
	}
	void See(int timeSeen){
		this->timeSeen = timeSeen;
		return;
	}
	int gettimeAdmitted(){
		return timeAdmitted;
	}
	int gettimeSeen(){
		return timeSeen;
	}
	int gettimeReleased(){
		return timeReleased;
	}
	int getENTEREDseverity(){
		return ENTEREDseverity;
	}
	void Survived(){
		survived = true;
		return;
	}
	bool CheckSurvive(){
		return survived;
	}
	void Release(int timeReleased){
		this->timeReleased = timeReleased;
		return;
	}
};