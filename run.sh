make -j32
./darknet detector test cfg/coco.data cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights data/bus.jpg

