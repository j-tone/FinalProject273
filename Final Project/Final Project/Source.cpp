

#include "EmergencyRoom.h"

using namespace std;

int main(){
	srand(time(NULL));
	/////////WELCOME
	int DR, NURSE, RATE, rate;
	cout << "How many doctors work in the ER?" << endl;
	cin >> DR;
	cout << "How many nurses work in the ER?" << endl;
	cin >> NURSE;
	cout << "What is the average hourly rate of patient arrival?" << endl;
	cin >> RATE;
	rate = 10000 * RATE / 60;

	EmergencyRoom ER;
	for (int i = 0; i < DR; i++){
		ER.AddDoctor();
	}
	for (int i = 0; i < NURSE; i++){
		ER.AddNurse();
	}
	for (int time = 0; time < 10080; time++){
		ER.resetWork();
		ER.EmployeesWork(time);
		ER.ReassignPatient();
		
	}
}