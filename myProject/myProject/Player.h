#pragma once
#include"stdafx.h"

class Player
{
public:
	Player();
	~Player();
	void Insert_Player_Info();
	time_t getCurrentTime() const;
	time_t getExitTime() const;
	std::forward_list<Ride> getYourList() const;
	void SelectRide(class std::vector<Ride> rides);
	void ShowYourList() const;

private:
	time_t current_time;
	time_t exit_time;
	std::forward_list<Ride> yourList;

public:
	static void calLaterTime(time_t later_time, int& hours, int& minutes);
	static void OpenData(class CXLEzAutomation &file);
	static void ShowList(void);
	static void Tokenize(std::string& str, class std::vector<std::string>& tokens, const std::string delimiters = " ");
};

