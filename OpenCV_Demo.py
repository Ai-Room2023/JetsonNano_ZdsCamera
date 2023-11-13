# -*- coding: utf-8 -*-

#Execute help(Camera) to view the corresponding help information
#functions such as dvpSet... and dvpGet... all appear in the form of attribute assignment in python
#For example functions such as dvpGetGamma and dvpSetGamma, corresponding to variable = camera.Gamma and camera.Gamma = 100


from dvp import *                                           #Put dvp.pyd into the lib directory or project directory
import numpy as np                                          #Install numpy library with pip command
import cv2                                                  #Install the opencv-python library with the pip command

#Convert the frame information into a numpy matrix object, which can be converted to a specific image format through opencv's cvtColor
def frame2mat(frameBuffer):
    frame, buffer = frameBuffer
    bits = np.uint8 if(frame.bits == Bits.BITS_8) else np.uint16
    shape = None
    convertType = None
    if(frame.format >= ImageFormat.FORMAT_MONO and frame.format <= ImageFormat.FORMAT_BAYER_RG):
        shape = 1
    elif(frame.format == ImageFormat.FORMAT_BGR24 or frame.format == ImageFormat.FORMAT_RGB24):
        shape = 3
    elif(frame.format == ImageFormat.FORMAT_BGR32 or frame.format == ImageFormat.FORMAT_RGB32):
        shape = 4
    else:
        return None

    mat = np.frombuffer(buffer, bits)
    mat = mat.reshape(frame.iHeight, frame.iWidth, shape)  
    return mat

##This function demonstrates the basic calling method of the camera function
def setCameraParams(camera):
    camera.Dialog();                                        #Displays the parameter adjustment dialog box

    roiDescr = camera.RoiDescr                              #Description of ROI
    roi = camera.Roi                                        #Get ROI
    roi.X = 0                                               #Horizontal and vertical coordinates
    roi.Y = 0
    roi.W = 400                                             #Width And Height
    roi.H = 400
    camera.Roi = roi                                        #set ROI

    camera.ResolutionModeSel = 0
    print("resolution mode 0")

    #fixed exposure mode
    camera.AeOperation = AeOperation.AE_OP_OFF              #turn off auto exposure
    camera.AntiFlick = AntiFlick.ANTIFLICK_DISABLE          
    expDescr = camera.ExposureDescr                         #Description of exposure time
    time = camera.Exposure                                  #get exposure time
    camera.Exposure = time                                  #set exposure time
    #automatic exposure mode
    camera.AntiFlick = AntiFlick.ANTIFLICK_50HZ             #Enable to eliminate strobe at 50HZ
    camera.AeTarget = camera.AeTarget + 1                   #Set the target brightness 
    camera.AeMode = AeMode.AE_MODE_AE_ONLY                  #adjust exposure time only
    camera.AeOperation = AeOperation.AE_OP_CONTINUOUS       #enable auto exposure

    
    #camera.GGain = 1
    #camera.RGain = 1
    #camera.BGain = 1
    
    #save parameters
    camera.SaveConfig("example.ini")


def main():
    cameraInfo = Refresh();                                 #Refresh and get camera list
    if(len(cameraInfo) == 0):                               #No device
        print(u"No device")
        return

    for k, v in enumerate(cameraInfo):                      #Print camera index and name
        print(k, "->", v.FriendlyName)

    while(True):                                            
        try:
            str = input("Please select the camera index number to be opened(0,1,2...):")
            index = (int)(str)                             
            camera = Camera(index)                          #Open the camera by index number
            #camera = Camera(cameraInfo[index].FriendlyName)#Open the camera by name
            print(camera);                                  #Print camera information
            break
        except dvpException as e:
            print(u"Open camera Failed:", e.Status)         
        except BaseException as e:
            print(u"Invalid index number:", str)                    
    
    try:
        camera.TriggerState = False                         #Switch from trigger mode to continuous  mode
        #camera.SetProperty("")
        #setCameraParams(camera)                            
        camera.Start()                                      #Start streaming
    except dvpException as e:
        print(u"Camera operation error:", e.Status)

    while (cv2.waitKey(1) != 27):                           #Press the ESC key to exit the loop
        try:
            print(camera.FrameCount)                        #Print frame information
            frame = camera.GetFrame(4000)                   #Acquire image data from the camera with a timeout of 4000 milliseconds
        except dvpException as e:
            print(u"Acquire image data Failed:", e.Status)
            if(e.Status == Status.DVP_STATUS_TIME_OUT):     
                continue                                    #If it's just a timeout error, continue
            break                                           #Abort on other errors                                                            

        mat = frame2mat(frame)                              #Convert to standard data format
        cv2.imshow(u"Preview (Press ESC exit)", mat)        #Display image data

    cv2.destroyAllWindows()                                 #Destroy window
    camera.Stop()                                           #Stop streaming
    camera.Close()                                          #Close Camera

#main function
main()


