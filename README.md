# KinectV2_SDK_Basic
Templete Project for KinectV2 SDK

## PATH
Need PATH for Kinect SDK's libs and headers.
In my case, 
Define MACRO as "KINECTSDK20_DIR"
And set path like this "C:\Program Files\Microsoft SDKs\Kinect\v2.0_1409"

In Solution setting, Include search path and library search path is like below.
* include path: $(KINECTSDK20_DIR)\inc
* lib search path: $(KINECTSDK20_DIR)\Lib\x64

This setting is my own. So you need to set for your env.
