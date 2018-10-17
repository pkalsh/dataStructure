#include "stdafx.h"

Player::Player()
{
	system_clock::time_point temp = system_clock::now();
	current_time = system_clock::to_time_t(temp);
}


Player::~Player() 
{
}


void Player::Insert_Player_Info()
{
	long exit_minutes;
	int hours, minutes;

	while (1) {
		cout << "�� �е��� �̿��Ͻ� �����Դϱ�?   "; cin >> exit_minutes;
		time_t later = current_time + exit_minutes * 60;
		calLaterTime(later, hours, minutes);

		tm *ct = localtime(&current_time);

		if (hours >= 21 || hours<10) {
			cout << "�� 9�� ���Ŀ� ��� ���̱ⱸ �̿��� ����˴ϴ�.." << endl;
			cout << "�ٽ� �������ּ���." << endl; continue;
		}

		cout << ct->tm_hour << ":" << ct->tm_min << " ~ "
			<< hours << ":" << minutes << endl;


		cout << "�Է��Ͻ� �ð��� �´ٸ� y��, �ƴϸ� �ƹ�Ű�� �Է��ϼ���." << endl;
		

		char adjustment;
		cin >> adjustment; cout << endl;
		if (adjustment == 'y') {
			exit_time = later;
			break;
		}
	}
}


time_t Player::getCurrentTime() const
{
	return current_time;
}

time_t Player::getExitTime() const
{
	return exit_time;
}

std::forward_list<Ride> Player:: getYourList() const
{
	return yourList;
}

void Player::calLaterTime(time_t later_time, int& hours, int& minutes)
{
	int currentSeconds = later_time % 60;
	time_t totalMinutes = later_time / 60;
	minutes = totalMinutes % 60;
	time_t totalHours = totalMinutes / 60;
	hours = totalHours % 24 + 9;
}

void Player::OpenData(CXLEzAutomation &file)
{
	CString strPath = L"C:\tdata\dataSet.xlsx";
	wchar_t chThisPath[_MAX_PATH];
	GetCurrentDirectory(_MAX_PATH, chThisPath);
	// ���������� �ִ� ��� ����
	if (file.OpenExcelFile(strPath))
	{
		cout << "SUCCESS" << endl;
	}
	//���������� �о������ ���ϸ� ���� ������ ���ο� Sheet ���
	else {
		file.SetCellValue(1, 2, L"ȸ����");
		file.SetCellValue(1, 3, L"ȸ���ٱ���");
		file.SetCellValue(1, 4, L"ȸ���׳�");
		file.SetCellValue(1, 5, L"���̷ν���");
		file.SetCellValue(1, 6, L"���̾�Ʈ����");
		file.SetCellValue(1, 7, L"�������");
		file.SetCellValue(1, 8, L"�ķ�ġ�������");
		file.SetCellValue(1, 9, L"��Ʋ��Ƽ��");
		file.SetCellValue(1, 10, L"���̷ν���");
		file.SetCellValue(1, 11, L"����ŷ");
		file.SetCellValue(1, 12, L"����ī");
		file.SetCellValue(1, 13, L"���̷ε��");
		file.SetCellValue(2, 1, "10:00");
		file.SetCellValue(3, 1, "10:20");
		file.SetCellValue(4, 1, "10:40");
		file.SetCellValue(5, 1, "11:00");
		file.SetCellValue(6, 1, "11:20");
		file.SetCellValue(7, 1, "11:40");
		file.SetCellValue(8, 1, "12:00");
		file.SetCellValue(9, 1, "12:20");
		file.SetCellValue(10, 1, "12:40");
		file.SetCellValue(11, 1, "13:00");
		file.SetCellValue(12, 1, "13:20");
		file.SetCellValue(13, 1, "13:40");
		file.SetCellValue(14, 1, "14:00");
		file.SetCellValue(15, 1, "14:20");
		file.SetCellValue(16, 1, "14:40");
		file.SetCellValue(17, 1, "15:00");
		file.SetCellValue(18, 1, "15:20");
		file.SetCellValue(19, 1, "15:40");
		file.SetCellValue(20, 1, "16:00");
		file.SetCellValue(21, 1, "16:20");
		file.SetCellValue(22, 1, "16:40");
		file.SetCellValue(23, 1, "17:00");
		file.SetCellValue(24, 1, "17:20");
		file.SetCellValue(25, 1, "17:40");
		file.SetCellValue(26, 1, "18:00");
		file.SetCellValue(27, 1, "18:20");
		file.SetCellValue(28, 1, "18:40");
		file.SetCellValue(29, 1, "19:00");
		file.SetCellValue(30, 1, "19:20");
		file.SetCellValue(31, 1, "19:40");
		file.SetCellValue(32, 1, "20:00");
		file.SetCellValue(2, 2, "10");
		file.SetCellValue(3, 2, "10");
		file.SetCellValue(4, 2, "10");
		file.SetCellValue(5, 2, "10");
		file.SetCellValue(6, 2, "10");
		file.SetCellValue(7, 2, "10");
		file.SetCellValue(8, 2, "10");
		file.SetCellValue(9, 2, "10");
		file.SetCellValue(10, 2, "10");
		file.SetCellValue(11, 2, "10");
		file.SetCellValue(12, 2, "10");
		file.SetCellValue(13, 2, "10");
		file.SetCellValue(14, 2, "10");
		file.SetCellValue(15, 2, "10");
		file.SetCellValue(16, 2, "10");
		file.SetCellValue(17, 2, "10");
		file.SetCellValue(18, 2, "10");
		file.SetCellValue(19, 2, "10");
		file.SetCellValue(20, 2, "10");
		file.SetCellValue(21, 2, "10");
		file.SetCellValue(22, 2, "10");
		file.SetCellValue(23, 2, "10");
		file.SetCellValue(24, 2, "10");
		file.SetCellValue(25, 2, "10");
		file.SetCellValue(26, 2, "10");
		file.SetCellValue(27, 2, "10");
		file.SetCellValue(28, 2, "10");
		file.SetCellValue(29, 2, "10");
		file.SetCellValue(30, 2, "10");
		file.SetCellValue(31, 2, "10");
		file.SetCellValue(32, 2, "10");
		file.SetCellValue(2, 3, "5");
		file.SetCellValue(3, 3, "5");
		file.SetCellValue(4, 3, "5");
		file.SetCellValue(5, 3, "5");
		file.SetCellValue(6, 3, "5");
		file.SetCellValue(7, 3, "5");
		file.SetCellValue(8, 3, "5");
		file.SetCellValue(9, 3, "5");
		file.SetCellValue(10, 3, "5");
		file.SetCellValue(11, 3, "10");
		file.SetCellValue(12, 3, "10");
		file.SetCellValue(13, 3, "10");
		file.SetCellValue(14, 3, "10");
		file.SetCellValue(15, 3, "10");
		file.SetCellValue(16, 3, "10");
		file.SetCellValue(17, 3, "10");
		file.SetCellValue(18, 3, "10");
		file.SetCellValue(19, 3, "10");
		file.SetCellValue(20, 3, "10");
		file.SetCellValue(21, 3, "10");
		file.SetCellValue(22, 3, "10");
		file.SetCellValue(23, 3, "10");
		file.SetCellValue(24, 3, "10");
		file.SetCellValue(25, 3, "10");
		file.SetCellValue(26, 3, "10");
		file.SetCellValue(27, 3, "10");
		file.SetCellValue(28, 3, "10");
		file.SetCellValue(29, 3, "10");
		file.SetCellValue(30, 3, "10");
		file.SetCellValue(31, 3, "10");
		file.SetCellValue(32, 3, "10");
		file.SetCellValue(2, 4, "5");
		file.SetCellValue(3, 4, "5");
		file.SetCellValue(4, 4, "5");
		file.SetCellValue(5, 4, "5");
		file.SetCellValue(6, 4, "25");
		file.SetCellValue(7, 4, "25");
		file.SetCellValue(8, 4, "25");
		file.SetCellValue(9, 4, "25");
		file.SetCellValue(10, 4, "25");
		file.SetCellValue(11, 4, "25");
		file.SetCellValue(12, 4, "25");
		file.SetCellValue(13, 4, "25");
		file.SetCellValue(14, 4, "25");
		file.SetCellValue(15, 4, "25");
		file.SetCellValue(16, 4, "25");
		file.SetCellValue(17, 4, "25");
		file.SetCellValue(18, 4, "25");
		file.SetCellValue(19, 4, "25");
		file.SetCellValue(20, 4, "25");
		file.SetCellValue(21, 4, "25");
		file.SetCellValue(22, 4, "25");
		file.SetCellValue(23, 4, "25");
		file.SetCellValue(24, 4, "25");
		file.SetCellValue(25, 4, "25");
		file.SetCellValue(26, 4, "25");
		file.SetCellValue(27, 4, "25");
		file.SetCellValue(28, 4, "25");
		file.SetCellValue(29, 4, "25");
		file.SetCellValue(30, 4, "25");
		file.SetCellValue(31, 4, "25");
		file.SetCellValue(32, 4, "25");
		file.SetCellValue(2, 5, "20");
		file.SetCellValue(3, 5, "10");
		file.SetCellValue(4, 5, "10");
		file.SetCellValue(5, 5, "20");
		file.SetCellValue(6, 5, "30");
		file.SetCellValue(7, 5, "30");
		file.SetCellValue(8, 5, "30");
		file.SetCellValue(9, 5, "30");
		file.SetCellValue(10, 5, "30");
		file.SetCellValue(11, 5, "30");
		file.SetCellValue(12, 5, "30");
		file.SetCellValue(13, 5, "30");
		file.SetCellValue(14, 5, "30");
		file.SetCellValue(15, 5, "30");
		file.SetCellValue(16, 5, "30");
		file.SetCellValue(17, 5, "40");
		file.SetCellValue(18, 5, "40");
		file.SetCellValue(19, 5, "50");
		file.SetCellValue(20, 5, "50");
		file.SetCellValue(21, 5, "50");
		file.SetCellValue(22, 5, "70");
		file.SetCellValue(23, 5, "70");
		file.SetCellValue(24, 5, "70");
		file.SetCellValue(25, 5, "70");
		file.SetCellValue(26, 5, "70");
		file.SetCellValue(27, 5, "70");
		file.SetCellValue(28, 5, "70");
		file.SetCellValue(29, 5, "70");
		file.SetCellValue(30, 5, "70");
		file.SetCellValue(31, 5, "70");
		file.SetCellValue(32, 5, "70");
		file.SetCellValue(2, 6, "10");
		file.SetCellValue(3, 6, "10");
		file.SetCellValue(4, 6, "10");
		file.SetCellValue(5, 6, "10");
		file.SetCellValue(6, 6, "20");
		file.SetCellValue(7, 6, "20");
		file.SetCellValue(8, 6, "20");
		file.SetCellValue(9, 6, "40");
		file.SetCellValue(10, 6, "40");
		file.SetCellValue(11, 6, "40");
		file.SetCellValue(12, 6, "40");
		file.SetCellValue(13, 6, "40");
		file.SetCellValue(14, 6, "40");
		file.SetCellValue(15, 6, "40");
		file.SetCellValue(16, 6, "40");
		file.SetCellValue(17, 6, "40");
		file.SetCellValue(18, 6, "40");
		file.SetCellValue(19, 6, "40");
		file.SetCellValue(20, 6, "40");
		file.SetCellValue(21, 6, "40");
		file.SetCellValue(22, 6, "40");
		file.SetCellValue(23, 6, "40");
		file.SetCellValue(24, 6, "40");
		file.SetCellValue(25, 6, "40");
		file.SetCellValue(26, 6, "40");
		file.SetCellValue(27, 6, "40");
		file.SetCellValue(28, 6, "40");
		file.SetCellValue(29, 6, "40");
		file.SetCellValue(30, 6, "40");
		file.SetCellValue(31, 6, "40");
		file.SetCellValue(32, 6, "40");
		file.SetCellValue(2, 7, "5");
		file.SetCellValue(3, 7, "5");
		file.SetCellValue(4, 7, "5");
		file.SetCellValue(5, 7, "5");
		file.SetCellValue(6, 7, "25");
		file.SetCellValue(7, 7, "25");
		file.SetCellValue(8, 7, "25");
		file.SetCellValue(9, 7, "25");
		file.SetCellValue(10, 7, "25");
		file.SetCellValue(11, 7, "25");
		file.SetCellValue(12, 7, "25");
		file.SetCellValue(13, 7, "25");
		file.SetCellValue(14, 7, "25");
		file.SetCellValue(15, 7, "25");
		file.SetCellValue(16, 7, "25");
		file.SetCellValue(17, 7, "25");
		file.SetCellValue(18, 7, "25");
		file.SetCellValue(19, 7, "25");
		file.SetCellValue(20, 7, "25");
		file.SetCellValue(21, 7, "25");
		file.SetCellValue(22, 7, "25");
		file.SetCellValue(23, 7, "25");
		file.SetCellValue(24, 7, "25");
		file.SetCellValue(25, 7, "25");
		file.SetCellValue(26, 7, "25");
		file.SetCellValue(27, 7, "25");
		file.SetCellValue(28, 7, "25");
		file.SetCellValue(29, 7, "25");
		file.SetCellValue(30, 7, "25");
		file.SetCellValue(31, 7, "25");
		file.SetCellValue(32, 7, "25");
		file.SetCellValue(2, 8, "40");
		file.SetCellValue(3, 8, "40");
		file.SetCellValue(4, 8, "40");
		file.SetCellValue(5, 8, "50");
		file.SetCellValue(6, 8, "50");
		file.SetCellValue(7, 8, "50");
		file.SetCellValue(8, 8, "60");
		file.SetCellValue(9, 8, "60");
		file.SetCellValue(10, 8, "60");
		file.SetCellValue(11, 8, "60");
		file.SetCellValue(12, 8, "70");
		file.SetCellValue(13, 8, "70");
		file.SetCellValue(14, 8, "70");
		file.SetCellValue(15, 8, "70");
		file.SetCellValue(16 ,8, "70");
		file.SetCellValue(17, 8, "70");
		file.SetCellValue(18, 8, "70");
		file.SetCellValue(19, 8, "70");
		file.SetCellValue(20, 8, "70");
		file.SetCellValue(21, 8, "100");
		file.SetCellValue(22, 8, "100");
		file.SetCellValue(23, 8, "100");
		file.SetCellValue(24, 8, "100");
		file.SetCellValue(25, 8, "100");
		file.SetCellValue(26, 8, "100");
		file.SetCellValue(27, 8, "100");
		file.SetCellValue(28, 8, "100");
		file.SetCellValue(29, 8, "100");
		file.SetCellValue(30, 8, "100");
		file.SetCellValue(31, 8, "100");
		file.SetCellValue(32, 8, "100");
		file.SetCellValue(2, 9, "40");
		file.SetCellValue(3, 9, "40");
		file.SetCellValue(4, 9, "40");
		file.SetCellValue(5, 9, "40");
		file.SetCellValue(6, 9, "60");
		file.SetCellValue(7, 9, "60");
		file.SetCellValue(8, 9, "60");
		file.SetCellValue(9, 9, "60");
		file.SetCellValue(10, 9, "60");
		file.SetCellValue(11, 9, "80");
		file.SetCellValue(12, 9, "80");
		file.SetCellValue(13, 9, "80");
		file.SetCellValue(14, 9, "80");
		file.SetCellValue(15, 9, "80");
		file.SetCellValue(16, 9, "60");
		file.SetCellValue(17, 9, "60");
		file.SetCellValue(18, 9, "80");
		file.SetCellValue(19, 9, "80");
		file.SetCellValue(20, 9, "80");
		file.SetCellValue(21, 9, "80");
		file.SetCellValue(22, 9, "80");
		file.SetCellValue(23, 9, "80");
		file.SetCellValue(24, 9, "100");
		file.SetCellValue(25, 9, "100");
		file.SetCellValue(26, 9, "100");
		file.SetCellValue(27, 9, "100");
		file.SetCellValue(28, 9, "100");
		file.SetCellValue(29, 9, "100");
		file.SetCellValue(30, 9, "100");
		file.SetCellValue(31, 9, "-1");
		file.SetCellValue(32, 9, "-1");
		file.SetCellValue(2, 10, "10");
		file.SetCellValue(3, 10, "10");
		file.SetCellValue(4, 10, "10");
		file.SetCellValue(5, 10, "10");
		file.SetCellValue(6, 10, "35");
		file.SetCellValue(7, 10, "35");
		file.SetCellValue(8, 10, "35");
		file.SetCellValue(9, 10, "35");
		file.SetCellValue(10, 10, "35");
		file.SetCellValue(11, 10, "35");
		file.SetCellValue(12, 10, "35");
		file.SetCellValue(13, 10, "35");
		file.SetCellValue(14, 10, "35");
		file.SetCellValue(15, 10, "35");
		file.SetCellValue(16, 10, "35");
		file.SetCellValue(17, 10, "35");
		file.SetCellValue(18, 10, "35");
		file.SetCellValue(19, 10, "35");
		file.SetCellValue(20, 10, "35");
		file.SetCellValue(21, 10, "35");
		file.SetCellValue(22, 10, "35");
		file.SetCellValue(23, 10, "35");
		file.SetCellValue(24, 10, "35");
		file.SetCellValue(25, 10, "35");
		file.SetCellValue(26, 10, "35");
		file.SetCellValue(27, 10, "35");
		file.SetCellValue(28, 10, "35");
		file.SetCellValue(29, 10, "35");
		file.SetCellValue(30, 10, "35");
		file.SetCellValue(31, 10, "35");
		file.SetCellValue(32, 10, "35");
		file.SetCellValue(2, 11, "5");
		file.SetCellValue(3 ,11, "10");
		file.SetCellValue(4, 11, "15");
		file.SetCellValue(5, 11, "15");
		file.SetCellValue(6, 11, "20");
		file.SetCellValue(7, 11, "20");
		file.SetCellValue(8, 11, "20");
		file.SetCellValue(9, 11, "20");
		file.SetCellValue(10, 11, "20");
		file.SetCellValue(11, 11, "25");
		file.SetCellValue(12, 11, "20");
		file.SetCellValue(13, 11, "40");
		file.SetCellValue(14, 11, "40");
		file.SetCellValue(15, 11, "40");
		file.SetCellValue(16, 11, "50");
		file.SetCellValue(17, 11, "40");
		file.SetCellValue(18, 11, "40");
		file.SetCellValue(19, 11, "40");
		file.SetCellValue(20, 11, "50");
		file.SetCellValue(21, 11, "45");
		file.SetCellValue(22, 11, "45");
		file.SetCellValue(23, 11, "45");
		file.SetCellValue(24, 11, "50");
		file.SetCellValue(25, 11, "45");
		file.SetCellValue(26, 11, "45");
		file.SetCellValue(27, 11, "20");
		file.SetCellValue(28, 11, "-1");
		file.SetCellValue(29, 11, "-1");
		file.SetCellValue(30, 11, "-1");
		file.SetCellValue(31, 11, "20");
		file.SetCellValue(32, 11, "25");
		file.SetCellValue(2, 12, "10");
		file.SetCellValue(3, 12, "10");
		file.SetCellValue(4, 12, "10");
		file.SetCellValue(5, 12, "10");
		file.SetCellValue(6, 12, "20");
		file.SetCellValue(7, 12, "30");
		file.SetCellValue(8, 12, "30");
		file.SetCellValue(9, 12, "40");
		file.SetCellValue(10, 12, "40");
		file.SetCellValue(11, 12, "40");
		file.SetCellValue(12, 12, "40");
		file.SetCellValue(13, 12, "40");
		file.SetCellValue(14, 12, "40");
		file.SetCellValue(15, 12, "40");
		file.SetCellValue(16, 12, "40");
		file.SetCellValue(17, 12, "40");
		file.SetCellValue(18, 12, "40");
		file.SetCellValue(19, 12, "40");
		file.SetCellValue(20, 12, "40");
		file.SetCellValue(21, 12, "40");
		file.SetCellValue(22, 12, "40");
		file.SetCellValue(23, 12, "40");
		file.SetCellValue(24, 12, "40");
		file.SetCellValue(25, 12, "40");
		file.SetCellValue(26, 12, "40");
		file.SetCellValue(27, 12, "40");
		file.SetCellValue(28, 12, "40");
		file.SetCellValue(29, 12, "40");
		file.SetCellValue(30, 12, "40");
		file.SetCellValue(31, 12, "40");
		file.SetCellValue(32, 12, "40");
		file.SetCellValue(2, 13,"10");
		file.SetCellValue(3, 13, "10");
		file.SetCellValue(4, 13, "10");
		file.SetCellValue(5, 13, "10");
		file.SetCellValue(6, 13, "15");
		file.SetCellValue(7, 13, "15");
		file.SetCellValue(8, 13, "15");
		file.SetCellValue(9, 13, "15");
		file.SetCellValue(10, 13, "15");
		file.SetCellValue(11, 13, "15");
		file.SetCellValue(12, 13, "15");
		file.SetCellValue(13, 13, "15");
		file.SetCellValue(14, 13, "15");
		file.SetCellValue(15, 13, "15");
		file.SetCellValue(16, 13, "15");
		file.SetCellValue(17, 13, "15");
		file.SetCellValue(18, 13, "15");
		file.SetCellValue(19, 13, "15");
		file.SetCellValue(20, 13, "15");
		file.SetCellValue(21, 13, "15");
		file.SetCellValue(22, 13, "15");
		file.SetCellValue(23, 13, "15");
		file.SetCellValue(24, 13, "15");
		file.SetCellValue(25, 13, "40");
		file.SetCellValue(26, 13, "60");
		file.SetCellValue(27, 13, "60");
		file.SetCellValue(28, 13, "60");
		file.SetCellValue(29, 13, "60");
		file.SetCellValue(30, 13, "-1");
		file.SetCellValue(31, 13, "-1");
		file.SetCellValue(32, 13, "-1");
	}
	
	file.SaveFileAs(L"C:\tdata\tdata.xlsx");
}

void Player::ShowList(void)
{
	cout << endl << endl;
	cout << "*****************�ⱸ ����*****************" << endl;
	cout << "0. ȸ����" << endl;
	cout << "1.ȸ���ٱ���" << endl;
	cout << "2.ȸ���׳�" << endl;
	cout << "3.���̷ν���" << endl;
	cout << "4.���̾�Ʈ����" << endl;
	cout << "5.�������" << endl;
	cout << "6.�ķ�ġ�������" << endl;
	cout << "7.��Ʋ��Ƽ��" << endl;
	cout << "8.���̷ν���" << endl;
	cout << "9.����ŷ" << endl;
	cout << "10. ����ī" << endl;
	cout << "11. ���̷ε��" << endl;
	cout << "********************************************" << endl;
}

void Player::Tokenize(std::string& str, class vector<std::string>& tokens, const std::string delimiters)
{
	// �� ù ���ڰ� �������� ��� ����
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// �����ڰ� �ƴ� ù ���ڸ� ã�´�
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token�� ã������ vector�� �߰��Ѵ�
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// �����ڸ� �پ�Ѵ´�.  "not_of"�� �����϶�
		lastPos = str.find_first_not_of(delimiters, pos);
		// ���� �����ڰ� �ƴ� ���ڸ� ã�´�
		pos = str.find_first_of(delimiters, lastPos);
	}
}


void Player::SelectRide(class vector<Ride> rides)
{
	vector<string> tokens;
	forward_list<Ride> list;
	char chselect[100];

	while (1) {
		cout << "�Է�  ex) 1,2,8,9 " << endl << ">> "; cin >> chselect;

		string select;

		select.copy(chselect, MAXCHAR);
		Tokenize(select, tokens, ",");

		copy(tokens.begin(), tokens.end(), ostream_iterator<string>(cout, ", "));

		cout << "�Է��Ͻ� ������ ������ y��, �ƴϸ� �ƹ�Ű�� �Է��ϼ���." << endl;

		char adjustment;
		cin >> adjustment; cout << endl;
		if (adjustment == 'y')	break;
	}
	for (int i = 0;i < tokens.size();i++)
	{
		int num = rides.at(stoi(tokens.at(i))).GetID();
		list.push_front(num);
	}
	yourList = list;
}

void Player::ShowYourList() const
{
	for (auto iter = yourList.cbegin();iter != yourList.cend();iter++)
	{
		(*iter).GetName(); cout << " -> ";
	}
	cout << "��" << endl << endl;
}