# include "defs.h"

// fit ellipse around contours
Mat draw_ellipse(Mat threshold_frame, Mat croped_frame){
    Mat temp;
    threshold_frame.copyTo(temp);
    
    // find contours
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(temp, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    
    // fit ellipse
    vector<RotatedRect> minEllipse(contours.size());
    vector<RotatedRect> minRect(contours.size());
    for( int i = 0; i < contours.size(); i++ ){
        minRect[i] = minAreaRect(Mat(contours[i]));
        if(contours[i].size() > 5) minEllipse[i] = fitEllipse(Mat(contours[i]));
    }
    
    // draw ellipse
    Mat drawing;
    croped_frame.copyTo(drawing);
    
    static Scalar color;
    static Scalar mean_img = mean(drawing);
    if (mean_img[0] < 100) color = Scalar(255);
    else color = Scalar(0);
    
    for( int i = 0; i< contours.size(); i++ ){
        ellipse(drawing, minEllipse[i], color, 1, 1);
    }
    
    return drawing;
}