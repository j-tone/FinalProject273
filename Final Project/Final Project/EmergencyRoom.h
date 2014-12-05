#ifndef EMERGENCYROOM_H_
#define EMERGENCYROOM_H_

#include "Line.h"
#include "ERemployee.h"
#include <vector>

using namespace std;

class EmergencyRoom{
private:
	vector<Doctor*> Doctors;
	vector<Nurse*> Nurses;
	Line LowSeverity;
	Line HighSeverity;
	Records Record;
public:
	EmergencyRoom(){
	}
	void AddDoctor(){
		Doctors.push_back(new Doctor);
	}
	void AddNurse(){

		Nurses.push_back(new Nurse);
	}
	void ReassignPatient(){
			while(Available(Nurses) == true && HighSeverity.empty() == false && DoctorLowSev() == true){
				SwitchEmp(LowSevDoctor(), getAvailableNurse());
			}
	}
	Nurse* getAvailableNurse(){
		for (int i = 0; i < Nurses.size(); i++){
			if (!Nurses[i]->Busy()){
				return Nurses[i];
			}
		}
	}
	Doctor* LowSevDoctor(){
		for (int i = 0; i < Doctors.size(); i++){
			if (Doctors[i]->PatientSeverity() < 11){
				return Doctors[i];
			}
		}
	}
	template <class T>
	bool Available(vector<T*> X){
		for (int i = 0; i < X.size(); i++){
			if (!X[i]->Busy()){
				return true;
			}
		}
		return false;
	}
	bool DoctorLowSev(){
		for (int i = 0; i < Doctors.size(); i++){
			if (Doctors[i]->PatientSeverity() < 11){
				return true;
			}
		}
		return false;
	}
	void AssignDoctor(Doctor* x){
		if (!HighSeverity.empty()){
			x->start(HighSeverity.TopPriority());
			return;
		}
		else if (!LowSeverity.empty()){
			x->start(LowSeverity.TopPriority());
			return;
		}
		else return;
	}
	void AssignNurse(Nurse* x){
		if (!LowSeverity.empty()){
			x->start(LowSeverity.TopPriority());
			return;
		}
	}
	void AdmitPatient(string name, int time){
		int y;
		int x = rand() % 10;
		if (x < 7){
			y = (rand() % 10) + 1;
			LowSeverity.AddPatient(time, y, name);
		}
		else if (x < 9){
			y = (rand() % 5) + 11;
			HighSeverity.AddPatient(time, y, name);
		}
		else{
			y = (rand() % 5) + 16;
			HighSeverity.AddPatient(time, y, name);
		}
		
	}
	void SwitchEmp(Doctor *x, Nurse* y){
		y->start(x->GetPatient());
		y->InheritTime(x->getTimeRemaining());
		x->Relieve();
		AssignDoctor(x);
	}
	void resetWork(){
		for (int i = 0; i < Doctors.size(); i++){
			Doctors[i]->Reset();
		}
		for (int i = 0; i < Nurses.size(); i++){
			Nurses[i]->Reset();
		}
		return;
	}
	void EmployeesWork(int time){
		for (int i = 0; i < Doctors.size(); i++){
			if (Doctors[i]->Busy)
				Doctors[i]->work(Record, time);
		}
		for (int i = 0; i < Nurses.size(); i++){
			if (Nurses[i]->Busy)
				Nurses[i]->work(Record, time);
		}
		return;
	}
	void AssignEmployees(int time){
		while (Available(Nurses)){
			AssignNurse(getAvailableNurse());
		}
		while (Available(Doctors)){
			AssignNurse(getAvailableNurse());
		}
	}
};

#endif