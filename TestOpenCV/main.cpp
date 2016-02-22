//
//  main.cpp
//  TestOpenCV
//
//  Created by takujifunao on 2016/02/17.
//  Copyright © 2016年 takujifunao. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cv.h>
#include <highgui.h>

int main(int, char**) {
    cv::VideoCapture vcap;
    cv::Mat image;
    
    // This works on a D-Link CDS-932L
    vcap.set(CV_CAP_PROP_FOURCC, CV_FOURCC('H', '2', '6', '4'));
    
    const std::string videoStreamAddress = "http://192.168.100.103:9000/?action=stream";
    //open the video stream and make sure it's opened
    if(!vcap.open(videoStreamAddress)) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }
    
    for(;;) {
        if(!vcap.read(image)) {
            std::cout << "No frame" << std::endl;
            cv::waitKey();
        }
        cv::imshow("Output Window", image);
        
        if(cv::waitKey(1) >= 0) break;
    }   
    
}