#ifndef LINE_H_
#define LINE_H_

#include "Records.h"
#include <map>
using namespace std;

class Line{
private:
	map<double, Patient*> LINE;
public:
	bool empty(){
		return LINE.empty();
	}
	Patient* TopPriority(){
		Patient* x=LINE.begin()->second;
		LINE.erase(LINE.begin()->first);
		return x;
	}
	void AddPatient(int time, int severity, string name){
		double x = 21 - (severity + ((500 - time % 500) / 500));
		LINE.insert(pair<double, Patient*>(x, new Patient(time, name, severity)));
		return;
	}
};

#endif