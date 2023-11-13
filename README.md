# JetsonNano_ZdsCamera
setting up zds gige camera with jetson nano board

## 1. wiring

![photo7743702569](https://github.com/Ai-Room2023/JetsonNano_ZdsCamera/assets/140303548/57ad0b3b-b112-4e4c-9f87-3ceadfcafd2a)
![photo7743702420](https://github.com/Ai-Room2023/JetsonNano_ZdsCamera/assets/140303548/f7b384f2-36d6-41ca-97a2-39ccb372d640)


## 2. convert the files into executable format

enter command:
```
sudo chmod a+wx install.sh
```
then in filter directory:
```
sudo chmod a+wx dsfilter.sh &
sudo chmod a+wx install_driver.sh &
sudo chmod a+wx dsfilter.sh 
```


## 3. install
connect the camera --> enter blew command 
```
sudo ./install.sh
```
			
		
## 4. sdk introduction:

-- democam2                    DVP2 demo
-- Demo_arm64                    simple demo executalbe program，no UI
-- OpenCV_Demo.py             Python Demo
-- libdvp.so&libhzd.so         Sdk api library
-- dvp.so                      python3.10 library
-- *.dscam.so                  device driver library


NOTE:
*.so  must be placed in the same directory





###Enable jumbo Ethernet frames

If your network card, GigE Vision device, and switch support it, we recommend enabling jumbo Ethernet frames when using GigE Vision devices.

Execute the following command as root:

```

/Sbin/ifconfig<network_ Interface_ ID>mtu SIZE

```
For example:
```
sudo /sbin/ifconfig eth0 mtu 9000
```

Among them, network_ Interface_ ID is the name of the network interface card (NIC)

SIZE=Required frame size

For example:

```

Sudo ifconfig enp0s25 mtu 8000

Tip: To view the names of NICs in the system, execute the following command as root: lshw - c network - businfo

```



Check if the reverse filtering function is enabled

```

Sysctl - a 2>/dev/null | grep '. rp_ Filter '

```

When the output value in the terminal is 1, it indicates that the reverse filtering function is enabled. Use the following command to turn off the reverse filtering function

```

Sudo sysctl net.ipv4.conf.all.rp_ Filter=0

Sudo sysctl net.ipv4.conf.th0.rp_ Filter=0

```




Permanently disable reverse filtering function

```

/Modify in etc/sysctl. conf

Net.ipv4.conf.all.rp_ Filter=0

Net. ipv4. conf. eth0. rp_ Filter=0
```

## 4. Using with python3.10

python code need cv2 and numpy library
after installation use blew command:
```
sudo python3.10 OpenCV_Demo.py
```
