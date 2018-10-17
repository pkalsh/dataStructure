#include "stdafx.h"


Ride::Ride(int id)
	:efficiency(0)
	, waitingTime(-1),id_number(id)
{	
}

Ride::~Ride()
{
}

int Ride::GetRidingTime() const
{
	return Ride::ridingTime;
}

 void Ride::SetName(class vector<Ride>& rides, class CXLEzAutomation file)
 {
	 for (int i = 0;i < 12;i++) {
		 rides[i].name = file.GetCellValue(1, i + 2);
	 }
 }

 int Ride::GetID() const {
	 return id_number;
 }

 void Ride::GetName() const{
	 cout << name;
 }

 int Ride::colAtCurr(time_t time, class CXLEzAutomation file)
 {
	 int currentSeconds = time % 60;
	 time_t totalMinutes = time / 60;
	 int minutes = totalMinutes % 60;
	 time_t totalHours = totalMinutes / 60;
	 int hours = totalHours % 24 + 9;
	 int hTmins = hours * 60 + minutes;

	 for (int i = 2;i <= 32;i++)
	 {
		 int xhour = _ttoi(file.GetCellValue(i, 1).Left(2));
		 int xmin = _ttoi(file.GetCellValue(i, 1).Right(2));
		 int xhTmins = xhour * 60 + xmin;

		 if (hTmins >= xhTmins || hTmins < (xhTmins + 20))return i;
	 }
	 return -1;
 }

 int Ride::GetWaitingTime(time_t time, class CXLEzAutomation file)
 {
	 waitingTime = _ttoi(file.GetCellValue(colAtCurr(time, file), id_number));
	 return waitingTime;
 }

 //상수 반복자를 위한 메서드
const int Ride::GetWaitingTime(time_t time, class CXLEzAutomation file) const
 {
	const_cast<int&>( waitingTime) = _ttoi(file.GetCellValue(colAtCurr(time, file), id_number));
	return waitingTime;
 }

 //효율성 계산
 void Ride::SetEfficiency(time_t time, class CXLEzAutomation file, class Player you)
 {
	vector<int> Wcur_to_exit;
	int curWT = _ttoi(file.GetCellValue(colAtCurr(time, file), id_number));

	while (_ttoi(file.GetCellValue(colAtCurr(time, file), id_number))
		 < _ttoi(file.GetCellValue(colAtCurr(you.getExitTime(), file), id_number))) {
		 
		Wcur_to_exit.push_back(_ttoi(file.GetCellValue(colAtCurr(time, file), id_number)));
		time += 60 * 20;
	}

	int maxWT = 0;
	for (int i = 0;i < Wcur_to_exit.size();i++)
		if (Wcur_to_exit[i] > maxWT)
			maxWT = Wcur_to_exit[i];

	efficiency = log(maxWT / curWT);
 }

 double Ride::GetEfficiency() const
 {
	 return efficiency;
 }
 
 //리스트를 의미있는 리스트로 전환
 void Ride::SetAllEfficiency(time_t time, class CXLEzAutomation file, class Player& you)
 {
	 forward_list<Ride> list = you.getYourList();
	 forward_list<Ride> new_list;
	 
	 while (!list.empty()) {
		  for (auto iter = list.cbegin(); iter != list.cend();iter++)
		 {
			 Ride temp = (*iter);
			 temp.SetEfficiency(time, file, you);
		 }
		 auto maxIter = list.cbegin();
		 double maxEF = -1.0;
		 for (auto iter = list.cbegin(); iter != list.cend();iter++) {
			 if ((*iter).GetEfficiency() > maxEF) {
				 maxEF = (*iter).GetEfficiency();
				 maxIter = iter;
			 }
			 if ((*iter).GetEfficiency() == maxEF) {
				 int number = 0; int maxDistVal = 0; int EquDistVal = 0;
				 for (auto s_iter = list.cbegin();s_iter != list.cend();s_iter++)
				 {
					 EquDistVal += distance[(*iter).id_number][(*s_iter).id_number];
					 maxDistVal += distance[(*maxIter).id_number][(*s_iter).id_number];
					 number++;
				 }
				 double aveMax = (double)maxDistVal / number;
				 double aveEqu = (double)EquDistVal / number;
				 if (aveMax > aveEqu) maxEF = (*iter).GetEfficiency();
			 }
		 }
		 if ((*maxIter).GetWaitingTime(time,file) < 0) {
			 (*maxIter).GetName(); cout << "은(는) 운행이 종료되었습니다." << endl
				 << "리스트에서 제외합니다." << endl;
			 list.remove(*maxIter);
			 continue;
		 }
		 if (new_list.empty()) {
			 time += ((*maxIter).GetWaitingTime(time, file) + (*maxIter).ridingTime
				 + distance[(*maxIter).GetID()][(*maxIter).GetID()]) * 60;
		 }
		 else {
			 time += ((*maxIter).GetWaitingTime(time, file) + (*maxIter).ridingTime
				 + distance[(*new_list.cbegin()).GetID()][(*maxIter).GetID()]) * 60;
		 }
		 auto earIter = ++maxIter; list.reverse();
		 new_list.push_front(*maxIter);
		 list.erase_after(earIter);
	 }
	 swap(list, new_list);
 }

 int Ride::distance[12][12] = {
	 //거리: 분 단위로 기입
	 0,2,8,8,2,7,2,7,8,3,2,9,
	 2,0,6,6,1,5,4,5,6,1,3,7,
	 8,6,0,2,6,1,7,2,1,4,7,1,
	 8,6,2,0,6,2,7,2,2,4,7,2,
	 2,1,6,6,0,5,3,5,6,2,3,7,
	 7,5,1,2,5,0,7,7,1,4,7,2,
	 2,4,7,1,3,7,0,7,8,4,2,9,
	 7,5,2,2,5,7,7,0,3,4,7,3,
	 8,6,1,2,6,1,8,3,0,5,8,1,
	 3,2,4,4,2,4,4,4,5,0,4,6,
	 2,3,7,7,3,7,2,7,8,4,0,9,
	 9,7,1,2,7,2,9,3,1,6,9,0
 };