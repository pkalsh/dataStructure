#include "stdafx.h"
#include "Player.h"
#include "Ride.h"

#define NUMOFRIDES 12

int _tmain(int argc, _TCHAR* argv[])
{
	Player you;

	vector<Ride> allRides;
	you.Insert_Player_Info();
	for (int i = 0;i < NUMOFRIDES;i++)
		allRides.push_back(i);

	//데이터 파일 열기	
	CXLEzAutomation dataFile(FALSE);
	Player::OpenData(dataFile);

	Ride::SetName(allRides, dataFile);

	Player::ShowList();
	you.SelectRide(allRides);
	Ride::SetAllEfficiency(you.getCurrentTime(), dataFile, you);
	you.ShowYourList();
	
	dataFile.ReleaseExcel(); // 엑셀 파일 해제
	
	return 0;
}