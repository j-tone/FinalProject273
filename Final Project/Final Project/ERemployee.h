#include "Patient.h"
#include <ctime>
#include <cstdlib>

using namespace std;

class ERemployee{
protected:
	bool busy;
	bool worked;
	Patient* tendingTo;
	int timeRemaining;
public:
	ERemployee(){
		busy = false;
	}
	void work(Records y, int time){
		timeRemaining--;
		worked = true;
		if (timeRemaining == 0){
			DoneTreating(y, time);
		}
		return;
	}
	virtual void start(Patient *x){}
	void DoneTreating(Records y, int time){
		tendingTo->gettimeReleased = time;
		y.Add(*tendingTo);
		busy = false;
		return;
	}
	int PatientSeverity(){
		return tendingTo->getENTEREDseverity();
	}
	void Reset(){
		worked = false;
		return;
	}
	bool Busy(){
		return busy;
	}
	Patient* GetPatient(){
		return tendingTo;
	}
};

class Doctor: public ERemployee{
public:
	Doctor() :ERemployee(){}
	void start(Patient *x){
		busy = true;
		tendingTo = x;
		timeRemaining = (rand() % 20) + 1;
	}
	int getTimeRemaining(){
		return timeRemaining;
	}
	void Relieve(){
		busy = false;
	}
};

class Nurse : public ERemployee{
public:
	Nurse() :ERemployee(){}
	void start(Patient *x){
		busy = true;
		tendingTo = x;
		timeRemaining = (rand() % 10) + 1;
	}
	void InheritTime(int timeR1){
		if (timeR1 < 10){
			timeRemaining = timeR1;
		}
		else{
			timeRemaining = 10;
		}
	}
};