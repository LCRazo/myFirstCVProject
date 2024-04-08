#  Face Detection and Color Tracking with OpenCV

## Project Description
Developed two distinct computer vision applications leveraging OpenCV library for face detection and color tracking. Implemented real-time video processing algorithms for face detection and color isolation

1) Developed a real-time face detection application using OpenCV and Haar cascades for detecting frontal faces in a live video stream.
2) Created a color tracking application using OpenCV to isolate objects of interest based on specified HSV color ranges in a live camera feed.


## Table of Contents

- [Installation](#installation)
- [Features](#Features)
- [Technologies](#technologies)
- [Credits](#credits)
- [License](#license)

## Installation


## Features
1) Utilized the VideoCapture class to access the camera feed and capture frames. Implemented face detection using the CascadeClassifier class with the pre-trained Haar cascade model. Displayed detected faces as rectangles overlaid on the video feed.

2) Used trackbars to dynamically adjust the HSV color range parameters for real-time color tracking. Converted the input BGR image to the HSV color space using cvtColor() function. Applied color filtering using inRange() function to create a binary mask highlighting the specified color range.

## Technologies
C++, OpenCV


## Credits





