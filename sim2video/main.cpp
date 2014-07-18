//
//  main.cpp
//  sim2video
//
//  Created by Chong Shao on 7/16/14.
//  Copyright (c) 2014 Chong Shao. All rights reserved.
//

#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cvaux.h>

#include <opencv2/core/core.hpp>


using namespace std;
using namespace cv;
int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    // should sepecify the video info by passing command line arguemnts...
    
    
    
    
    // currently using the default values
    // video size
    int h = 484;
    int w = 648;
    
    // bead info
    int bead_radius = 3;
    int n_of_beads = 10;
    
    // video info
    int n_of_frames = 1800;
    
    ifstream file ( "file.csv" );
    string value;
    

    while (file.good() ) {
        getline(file, value, ',');
        cout << string(value, 1, value.length()-2);
    }
    
    // sim should also be a Mat.
    Mat sim;
    
    
    // read from CSV that contains beads data
    Mat img;
    
    int rows = img.rows;
    double bead_x, bead_y;
    
    
    
    cout << rows << endl;
    cout << "foo" << endl;
    for (int i = 0; i < n_of_frames; i++) {
        img = Mat(h,w,CV_64F,double(0));
        for (int k = 0; k < n_of_beads; k++) {
            const double* curr_row = sim.ptr<double>(i+k*n_of_frames);
            bead_x = static_cast<int>(curr_row[3]);
            bead_y = static_cast<int>(curr_row[4]);
            int x,y;
            // manipulate the current img:
            for (y = bead_y - bead_radius; y< bead_y + bead_radius; y++)
            {
                if ( y < h ){
                    for ( x = bead_x - bead_radius; x < bead_x + bead_radius; x++) {
                        img.at<double>(y,x) = 1.0;
                        
                    }
                }
            }
        
        }
        
    
    
    }
    
    
    return 0;

    
    
}

