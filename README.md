# Single Camera Bee Recorder

### Setup

Download and install Raspberry OS for RPi4

Install following dependences:

```
sudo apt install vim git wget libopencv-dev cmake -y
```

Prepare data storage folder
```
mkdir ~/Data/
```

Clone this repo and run the install.sh script

```
sudo chmod +x install.sh
sudo ./install.sh
```

Reboot RPi, and it will automatically record data into the ~/Data/ forlder.