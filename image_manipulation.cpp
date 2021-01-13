#include "opencv4/opencv2/opencv.hpp"
#include "iostream"
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    char file[512];
    cout << "Enter filename along with path: ";
    cin >> file;
    Mat inputImage = imread( file, 1 );
    if(inputImage.empty())
    {
        cout << "Unable to load image.!";
        return -1;
    }
    //show the original image
    const char* windowTitle = "Original Image";
    namedWindow( windowTitle );
    imshow( windowTitle, inputImage );
    const char* windowTitleRotated = "Rotated Image";
    namedWindow( windowTitleRotated );
    int iAngle = 180;
    createTrackbar("Angle", windowTitleRotated, &iAngle, 360); // to input angle for rotating image
    // to get center point of input image
    int height = inputImage.rows / 2;
    int width = inputImage.cols / 2;
    while (true)
    {
        Mat matRotation = getRotationMatrix2D( Point(width, height), (iAngle - 180), 1 ); 
        // Rotate the image
        Mat imgRotated;
        warpAffine( inputImage, imgRotated, matRotation, inputImage.size() ); 
        imshow( windowTitleRotated, imgRotated );
        waitKey(30);
    }
    return 0;
}