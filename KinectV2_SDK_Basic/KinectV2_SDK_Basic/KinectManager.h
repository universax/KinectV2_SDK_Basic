#pragma once
#include "Singleton.h"

using namespace std;
class KinectManager: public Singleton < KinectManager >
{
public:
	HRESULT init();
	void update();
	inline bool getIsFrameNew() { return isFrameNew; }
	void getDepthBuf(vector<UINT16> &output);
	void getColorBuf(vector<BYTE> &output);
	void getInfraredBuf(vector<UINT16> &output);
	void getBodyIndexFrameBuf(vector<BYTE> &output);
	
	CComPtr<ICoordinateMapper> pCoordinateMapper;
	
private:
	friend class Singleton < KinectManager > ;
	KinectManager(){};
	~KinectManager(){};

	//------------------------------------------------------------
	//KinectŽü‚è‚ÌŠî–{‹@”\
	//------------------------------
	//Kinect
	CComPtr<IKinectSensor> kinect;
	bool isFrameNew;

	//------------------------------
	//Color
	CComPtr<IColorFrameReader> colorFrameReader;
	int colorWidth;
	int colorHeight;
	unsigned int colorBytesPerPixel;
	vector<BYTE>colorBuffer;
	bool updateColorFrame();
	
	//------------------------------
	//Depth
	CComPtr<IDepthFrameReader> pDepthReader;
	vector<UINT16> depthBuffer;
	
	unsigned int bufferSize = 512 * 424;
	bool updateDepthFrame();

	//------------------------------
	//IR
	CComPtr<IInfraredFrameReader> infraredFrameReader;
	int infraredFrameWidth, infraredFrameHeight;
	vector<UINT16> infraredBuffer;
	bool updateInfraredFrame();
	
	//------------------------------
	//Body Index
	CComPtr<IBodyIndexFrameReader> pBodyIndexFrameReader;
	vector<BYTE>bodyIndexBuffer;
	bool updateBodyIndexFrame();
};

