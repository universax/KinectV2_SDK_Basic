#pragma once
#include "KinectManager.h"

class App
{
public:
	App();
	~App();

	HRESULT init();
	void run();

private:
	//Event
	bool mRunning;

	//Kinect
	KinectManager &mKinect = KinectManager::GetInstance();
};

