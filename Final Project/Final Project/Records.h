#ifndef RECORDS_H_
#define RECORDS_H_

#include "Patient.h"
#include <queue>
using namespace std;

class Records{
private:
	queue <Patient> record;
public:
	Records(){
	}
	void Add(Patient x){
		record.push(x);
		return;
	}
	void Results(){
		int patients=record.size();
		int TOTALtimeAdmitted=0;
		int TOTALtimeSeen=0;
		int TOTALtimeReleased=0;
		int deaths=0;
		int TOTALdeathWaitTime = 0;
		do{
			if (record.front().CheckSurvive() == false){
				deaths++;
				TOTALdeathWaitTime += (record.front().gettimeReleased() - record.front().gettimeAdmitted());
				patients--;
			}
			else{
				TOTALtimeAdmitted += record.front().gettimeAdmitted();
				TOTALtimeSeen += record.front().gettimeSeen();
				TOTALtimeReleased += record.front().gettimeReleased();
			}
			record.pop();
		} while (record.size() != 0);

		cout << "Total number of patients seen: " << patients << endl;
		cout << "Average wait time: " << static_cast<double>((TOTALtimeSeen-TOTALtimeAdmitted)/patients) << " minutes"<<endl;
		cout << "Average length of visit: " << static_cast<double>((TOTALtimeReleased - TOTALtimeAdmitted) / patients) << " minutes" << endl;
		if (deaths!=0){
			cout << "Total deaths: " << deaths<<endl;
			cout << "Average wait time for patients who died (not included in Average wait time): " << static_cast<double>(TOTALdeathWaitTime / deaths) << endl;
			cout << "That is unacceptable!" << endl;
		}
	}
};

#endif