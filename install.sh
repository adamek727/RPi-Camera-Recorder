echo "Clearing"
rm -r build/
rm /usr/bin/SingleCamera
rm /lib/systemd/system/single_camera.service

echo "Building"
mkdir build && cd build && cmake .. && make -j2 && cd ..

echo "Installation"
cp build/SingleCamera /usr/bin/SingleCamera
cp single_camera.service /lib/systemd/system/single_camera.service
chmod 644 /lib/systemd/system/single_camera.service

echo "Service Enabling"
systemctl daemon-reload
systemctl enable single_camera.service