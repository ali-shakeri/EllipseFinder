#include "defs.h"
#include "fit_ellipse.h"
#include "merge_images.h"
#include "mouse_handler.h"

extern bool callback;

int main(int argc, char* argv[])
{
    Mat frame;
    Mat blured_frame;
    Mat canny;
    Mat threshold_frame;
    
    const char* src_window = "Select ROI";
    namedWindow(src_window,CV_WINDOW_AUTOSIZE);
    
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " filename" << endl;
        cout << "\tfilename: Name of movie" << endl;
        return -1;
    }

    VideoCapture cap(argv[1]);         // read the video
    if(!cap.isOpened())
    {
        cout << "\nThere is no file with this name." << endl;
        return -1;
    }

    cap >> frame;
    namedWindow(src_window,CV_WINDOW_AUTOSIZE);
    imshow(src_window,frame);
    
    Rect pt, point1, point2;
    setMouseCallback(src_window,mouseHandler, (void*)&pt);
    
    while (!callback)
    {
        Mat temp = frame.clone();
        rectangle(temp, Point(pt.x, pt.y), Point(pt.x + pt.width, pt.y + pt.height), CV_RGB(255, 0, 0), 3, 8, 0);
        imshow(src_window, temp);
        waitKey(1);
    }
    destroyWindow(src_window);
    
    
    for(;;)
    {
        // read a frame and select a region of interest
        cap >> frame;
        Mat croped_frame(frame, pt);
        cvtColor(croped_frame, croped_frame, CV_BGR2GRAY);
        //cout << mean(croped_frame) << endl;

        // calculate the gaussian blur
        GaussianBlur(croped_frame, blured_frame, Size(7,7), 1.5, 1.5);

        // adaptive threshold
        threshold(blured_frame, threshold_frame, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

        // canny edge detector
        //Canny(threshold_frame, canny, 0, 50, 3);
        
        // draw an ellipse on the real ellipsoid
        Mat drawing = draw_ellipse(threshold_frame, croped_frame);

        Mat merged_frame = merge_images(croped_frame, blured_frame, threshold_frame, drawing);
        imshow("multi-view", merged_frame);

        if(waitKey(1) >= 0) break;
    }
    return 0;
}