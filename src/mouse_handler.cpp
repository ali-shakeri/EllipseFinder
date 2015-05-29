#include "defs.h"
//#include "mouse_handler.h"

bool callback = false;

void mouseHandler(int event, int x, int y, int flags, void* param)
{
    static Point point1, point2;
    static int drag = 0, select_flag = 0;
    if (event == CV_EVENT_LBUTTONDOWN && !drag && !select_flag)
    {
        /* left button clicked. ROI selection begins */
        point1 = point2 = Point(x, y);
        drag = 1;
    }

    if (event == CV_EVENT_MOUSEMOVE && drag && !select_flag)
    {
        /* mouse dragged. ROI being selected */
        point2 = Point(x, y);
    }

    if (event == CV_EVENT_LBUTTONUP && drag && !select_flag)
    {
        point2 = Point(x, y);
        drag = 0;
        select_flag = 1;
        callback = true;
    }
    
    // send region of interest to output
    Rect* rectptr = (Rect*)param;
    rectptr -> x = point1.x;
    rectptr -> y = point1.y;
    rectptr -> width  = point2.x - point1.x;
    rectptr -> height = point2.y - point1.y;
}