// KinectV2_SDK_Basic.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include "App.h"

int main()
{
	try {
		App app;
		app.init();
		app.run();
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		return -1;
	}
	return 0;
}