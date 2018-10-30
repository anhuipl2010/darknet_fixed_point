make clean
make -j32
rm conv_weights.txt
./darknet detector test cfg/coco.data cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights data/bus.jpg -thresh 0.1 -ext_output

