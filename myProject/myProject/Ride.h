#pragma once
#include"stdafx.h"

class Ride
{
public:
	Ride(int id);
	~Ride();
	int GetRidingTime() const;
	void GetName() const;
	int GetID() const;
	int GetWaitingTime(time_t time, class CXLEzAutomation file);
	const int Ride::GetWaitingTime(time_t time, class CXLEzAutomation file) const;
	double GetEfficiency() const;
	void SetEfficiency(time_t time, class CXLEzAutomation file, class Player you);

private:
	const int ridingTime = 5; // ���̱ⱸ ž�� �ð�: 5������ ��� ����
	double efficiency; // ���ð� ȿ����
	int id_number;	 // ���̱ⱸ ��ȣ: �ĺ���ȣ
	int waitingTime;
	CString name;

public:
	static void SetName(class std::vector<Ride>& rides, class CXLEzAutomation file);
	static int colAtCurr(time_t time, class CXLEzAutomation file);
	static void SetAllEfficiency(time_t time, class CXLEzAutomation file, class Player &you);
	static int distance[12][12];
};

