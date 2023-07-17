#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  // 遍历所有摄像头
  cv::VideoCapture cap;
  for (int cameraIndex = 0; cameraIndex < 10; cameraIndex++) {
    cap.open(cameraIndex);
    if (cap.isOpened()) {
      if (cap.get(cv::CAP_PROP_FRAME_WIDTH) == 640 &&
          cap.get(cv::CAP_PROP_FRAME_HEIGHT) == 400) {
        break;
      } else {
        cap.release(); // Release the camera to free resources.
      }
    } 
  }

  // 获取摄像头的分辨率
  int frameWidth = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
  int frameHeight = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));

  // 创建一个窗口用于显示摄像头图像
  cv::namedWindow("Camera Feed", cv::WINDOW_NORMAL);
  cv::resizeWindow("Camera Feed", frameWidth, frameHeight);

  while (true) {
    cv::Mat frame;
    // 从摄像头读取一帧图像
    cap.read(frame);

    // 检查是否成功读取图像
    if (frame.empty()) {
        std::cout << "Error: Failed to capture frame." << std::endl;
        break;
    }

    // 在窗口中显示图像
    cv::imshow("Camera Feed", frame);

    // 等待一段时间（以毫秒为单位）后继续下一次循环
    // 这里使用 waitKey() 来显示图像并等待按键输入
    // 如果需要显示图像的更高帧率，可以适当减小等待时间
    char key = cv::waitKey(1);
    if (key == 27 || key== 'q') {
        // 如果按下了 Esc 键（ASCII码为27），退出循环
        break;
    }
    if (cv::getWindowProperty("Camera Feed", 0) == -1)
        break;
  }

  // 释放摄像头和关闭显示窗口
  cap.release();
  cv::destroyAllWindows();

  return 0;

}