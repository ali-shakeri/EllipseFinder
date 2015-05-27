# include "defs.h"

// Merge two images
Mat merge_images(Mat img1, Mat img2,
                 String str1 = "1.Original Video",
                 String str2 = "2.Fit Ellipse")
{
    int height = img1.rows;           //number of rows of img1
    int width = img1.cols;           //number of cols of img1
    
    Mat merged_frame = Mat(Size(width*2, height), CV_8U);
    Mat roi;
    Point org(5,25);
    putText(img1, str1, org,  FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255), 1);
    putText(img2, str2, org,  FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255), 1);
    roi = Mat(merged_frame, Rect(0, 0, width, height));
    img1.copyTo(roi);
    roi = Mat(merged_frame, Rect(width, 0, width, height));
    img2.copyTo(roi);
    
    return merged_frame;
}


// Merge three images
Mat merge_images(Mat img1, Mat img2, Mat img3,
                 String str1 = "1.Original Video",
                 String str2 = "2.Fit Ellipse",
                 String str3 = "3.Title 3")
{
    int height = img1.rows;           //number of rows of img1
    int width = img1.cols;           //number of cols of img1
    
    Mat merged_frame = Mat(Size(width*3, height), CV_8U);
    Mat roi;
    Point org(5,25);
    putText(img1, str1, org,  FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255), 1);
    putText(img2, str2, org,  FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255), 1);
    putText(img3, str3, org,  FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255), 1);
    roi = Mat(merged_frame, Rect(0, 0, width, height));
    img1.copyTo(roi);
    roi = Mat(merged_frame, Rect(width, 0, width, height));
    img2.copyTo(roi);
    roi = Mat(merged_frame, Rect(2*width, 0, width, height));
    img3.copyTo(roi);
    
    return merged_frame;
}


// Merge four images
Mat merge_images(Mat img1, Mat img2, Mat img3, Mat img4,
                 String str1 = "1.Original Video",
                 String str2 = "2.Gaussian Blur",
                 String str3 = "3.Binary After Blur",
                 String str4 = "4.Fit Ellipse")
{
    int height = img1.rows;           //number of rows of img1
    int width = img1.cols;           //number of cols of img1
    
    Mat merged_frame = Mat(Size(width*2, height*2), CV_8U);
    Mat roi;
    Point org(5,25);
    putText(img1, str1, org,  FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255), 1);
    putText(img2, str2, org,  FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255), 1);
    putText(img3, str3, org,  FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255), 1);
    putText(img4, str4, org,  FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255), 1);
    roi = Mat(merged_frame, Rect(0, 0, width, height));
    img1.copyTo(roi);
    roi = Mat(merged_frame, Rect(width, 0, width, height));
    img2.copyTo(roi);
    roi = Mat(merged_frame, Rect(0, height, width, height));
    img3.copyTo(roi);
    roi = Mat(merged_frame, Rect(width, height, width, height));
    img4.copyTo(roi);
    
    return merged_frame;
}