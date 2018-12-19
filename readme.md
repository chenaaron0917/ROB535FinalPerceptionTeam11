## Fall2018 ROB535 Final Project Perception Team 11
#### System Requirements:
Ubuntu 16.04 LTS;
CUDA 10.0;
CUDNN 7.0;
OPENCV 3.4.1;
RTX2080Ti Intel i7-9700k;
gcc 5.4.0;
python 2.7;
GPU;
OpenCV;

#### Configuration
1. 'cfg/yolov3.cfg' to set up neural networks and image dimensions
2. 'examples/darknet.c' is the main
3. 'examples/detector.c' test_detector to read image and run prediction 
4. 'src/image.c' draw_detections_my to write prediction result
#### Task 1
1. Go to current folder directory
2. Download pre-trained weight: https://pjreddie.com/media/files/yolov3.weights
3. (In terminal) compile: make
4. (In terminal) run: ./darknet detect cfg/yolov3.cfg yolov3.weights DIR_TO_TEST
5. Post processing - run 'post.py' in 'posprocessing' folder


