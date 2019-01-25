#include "pch.h"
#include "App.h"


App::App()
{
}


App::~App()
{
}

HRESULT App::init()
{
	HRESULT hr = S_FALSE;
	mRunning = false;

	//Kinect Setting
	hr = mKinect.init();

	if (SUCCEEDED(hr))
	{
		mRunning = true;
	}

	return hr;
}

void App::run()
{
	while (mRunning)
	{
		// Kinect
		mKinect.update();
		if (mKinect.getIsFrameNew())
		{
			//-----------------------------------
			//kinect
			//-----------------------------------
			//depthŽæ“¾
			vector<UINT16> depthBuf;
			mKinect.getDepthBuf(depthBuf);
			if (depthBuf.empty())
			{
				continue;
			}
		}
		// Sleep
		Sleep(1);
	}
}