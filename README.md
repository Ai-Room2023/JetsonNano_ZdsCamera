# JetsonNano_ZdsCamera
setting up zds gige camera with jetson nano board

## 1. convert the files into executable format:
in filter directory:
```
sudo chmod a+wx dsfilter.sh &
sudo chmod a+wx install_driver.sh &
sudo chmod a+wx dsfilter.sh
```

## 2. install: 
connect the camera --> enter blew command 
```
sudo ./install.sh
```
			
		
## 3. sdk introduction:

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
