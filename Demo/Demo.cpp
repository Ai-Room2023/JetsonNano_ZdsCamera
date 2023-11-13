/*****************************************************************************
* @FileName:Demo.cpp
* @CreatTime: 2021/04/28 10:58
* @Descriptions: Simple demo
* @Version: ver 1.0
*****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <pthread.h> 
#include <iostream>
#include "DVPCamera.h"		/* DVP API header */

using namespace std;
//#define TEST_TRIG		/* Trigger switch */
//#define SOFT_TRIG		/* Software trigger */
#define GRABCOUNT 20		/* grab count */

void* test(void *p)
{
	dvpStatus status;
	dvpHandle h;
	bool trigMode = false;
	char *name = (char*)p;

	printf("test start,camera is %s\r\n", name);
	do 
	{
		/* open camera */
		status = dvpOpenByName(name, OPEN_NORMAL, &h);
		if (status != DVP_STATUS_OK)
		{
			printf("dvpOpenByName failed with err:%d\r\n", status);
			break;
		}

		dvpRegion region;
		double exp;
		float gain;

#ifdef TEST_TRIG
		/* set trigger mode*/
		status = dvpSetTriggerState(h, true);
		if (status == DVP_STATUS_OK)
		{
			dvpSetTriggerSource(h, TRIGGER_SOURCE_SOFTWARE);
			dvpSetTriggerInputType(h, TRIGGER_POS_EDGE);
			dvpSetInputIoFunction(h, INPUT_IO_1, INPUT_FUNCTION_TRIGGER);
			trigMode = true;
		}
		else
		{
			printf("dvpSetTriggerState failed with err:%d\r\n", status);
			break;
		}
#endif
		/* get roi information*/
		status = dvpGetRoi(h, &region);
		if (status != DVP_STATUS_OK)
		{
			printf("dvpGetRoi failed with err:%d\r\n", status);
			break;
		}
		printf("%s, region: x:%d, y:%d, w:%d, h:%d\r\n", name, region.X, region.Y, region.W, region.H);

		/* get exposure value*/
		status = dvpGetExposure(h, &exp);
		if (status != DVP_STATUS_OK)
		{
			printf("dvpGetExposure failed with err:%d\r\n", status);
			break;
		}

		status = dvpGetAnalogGain(h, &gain);
		if (status != DVP_STATUS_OK)
		{
			printf("dvpGetAnalogGain failed with err:%d\r\n", status);
			break;
		}

		printf("%s, exposure: %lf, gain: %f\r\n", name, exp, gain);


		uint32_t v;
		/* frame information*/
		dvpFrame frame;
		/* image data memory address，users do not need to release memory */
		void *p;

		/* start video stream */
		status = dvpStart(h);
		if (status != DVP_STATUS_OK)
		{
			break;
		}

		/* grab frame */
		for (int j = 0; j < GRABCOUNT; j++)
		{
#ifdef SOFT_TRIG
			if (trigMode)
			{
				// trigger a frame
				status = dvpTriggerFire(h);
				if (status != DVP_STATUS_OK)
				{
					printf("Fail to trig a frame\r\n");           
				}
			}
#endif
			/* get frame info and image data */
			status = dvpGetFrame(h, &frame, &p, 3000);
			if (status != DVP_STATUS_OK)
			{
				if (trigMode)
					continue;
				else
					break;
			}
			
			/* display framecount and frame rate*/
			dvpFrameCount framecount;
			status = dvpGetFrameCount(h, &framecount);
			if(status != DVP_STATUS_OK)
			{
				printf("get framecount failed\n");
			}
			printf("framecount: %d, framerate: %f\n", framecount.uFrameCount, framecount.fFrameRate);

			/* display frame info */
			printf("%s, frame:%lu, timestamp:%lu, %d*%d, %dbytes, format:%d\r\n", 
				name,
				frame.uFrameID,
				frame.uTimestamp,
				frame.iWidth,
				frame.iHeight,
				frame.uBytes,
				frame.format);

			/* save image data */
			// char PicName[64];
			// 
			// 				sprintf(PicName, "%s_pic_%d.jpg",name, k);
			// 				status = dvpSavePicture(&frame, p, PicName, 90);
			// 				if (status == DVP_STATUS_OK)
			// 				{
			// 					printf("Save to %s OK\r\n", PicName);
			// 				}
		}        

		/* stop video stream */
		status = dvpStop(h);
		if (status != DVP_STATUS_OK)
		{
			break;
		}
	}while(0);

	dvpClose(h);

	printf("test quit, %s, status:%d\r\n", name, status);
}


int main(int argc, char *argv[])
{
	printf("start...\r\n");

	dvpUint32 count = 0;
  dvpInt32 num = -1;
	dvpCameraInfo info[8];
	   
	dvpStatus status;
  std::string strInput;


	/* enum camera */
	dvpRefresh(&count);
	if (count > 8)
		count = 8;

	for (int i = 0; i < count; i++)
	{    
		if(dvpEnum(i, &info[i]) == DVP_STATUS_OK)    
		{        
			printf("[%d]-Camera FriendlyName : %s\r\n", i, info[i].FriendlyName);
		}
	}

	/* not find camera */
	if (count == 0)
		return 0;


	printf("Please enter a valid number of the camera you want to open:\r\n");
  cin.clear();
  cin >> strInput;
    
  try
  {
    num = std::stoi(strInput);
    printf("num:[%d]\r\n", num);
  }
  catch(...)
  {
    printf("the number[%s] of the camera is invalid\r\n", strInput.c_str());
  }    
   
  if(num < 0 || num >= count)
  {
    printf("the number of the camera is invalid num=%d \r\n", num);
    return 0;
	} 

	pthread_t tidp;
	int r = pthread_create(&tidp, NULL, test, (void*)info[num].FriendlyName); 
	pthread_join(tidp, NULL);

	return 0;
}
