# include "defs.h"
# include "fit_ellipse.h"
# include "merge_images.h"

int main(int argc, char* argv[])
{
	if (argc != 2){
		cout << "Usage: " << argv[0] << " filename\n\tfilename: Name of movie" << endl;
		return -1;
	}

    VideoCapture cap(argv[1]);         // read the video
    //VideoCapture cap("../ellipsoid_2.mpg");         // read the video
    if(!cap.isOpened())
        return -1;

    Mat frame;
    Mat blured_frame;
    Mat canny;
    Mat threshold_frame;
    
    for(;;)
    {
        // read a frame and select a region of interest
        cap >> frame;
        Rect croped_area = Rect(250, 250, 300, 300);
        Mat croped_frame(frame, croped_area);
        cvtColor(croped_frame, croped_frame, CV_BGR2GRAY);

        // calculate the gaussian blur
        GaussianBlur(croped_frame, blured_frame, Size(7,7), 1.5, 1.5);

        // adaptive threshold
        threshold(blured_frame, threshold_frame, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

        // canny edge detector
        //Canny(threshold_frame, canny, 0, 50, 3);
        
        // draw an ellipse on the real ellipsoid
        Mat drawing = draw_ellipse(threshold_frame, croped_frame);

        Mat merged_frame = merge_images(croped_frame, blured_frame, threshold_frame, drawing);
        //Mat merged_frame = merge_images(croped_frame, drawing, "Original Video", "Fited Ellipse");
        //Mat merged_frame = merge_images(croped_frame, threshold_frame_1, drawing, "Original Video", "", "Fited Ellipse");
        imshow("multi-view", merged_frame);

        if(waitKey(30) >= 0) break;
    }
    return 0;
}
