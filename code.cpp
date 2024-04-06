#include <cstdint>
#include <vector>
#include <opencv2/opencv.hpp>

struct Point {
    int32_t x;
    int32_t y;
};

std::vector<Point> detectLane(const cv::Mat& image) {
    std::vector<Point> points;
    
    return points;
}

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        std::vector<Point> points = detectLane(gray);

        cv::imshow("Frame", frame);
        if (cv::waitKey(1) >= 0) {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
