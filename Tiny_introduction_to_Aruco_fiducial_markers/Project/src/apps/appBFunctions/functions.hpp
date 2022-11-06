#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/ovis.hpp>

/**
 * @brief processedInformation
 *      - Struct used to ease the managing of the returned information
 *        by the function processFrome()
 */
struct processedInformation{
    cv::Mat rvec, tvec;
    bool estimatedPose;
};

/**
 * @brief Function created in order to aislate the processing of each frame
 * 
 * @param frame Input/Output frame to be processed
 * @param K Camera parameter K
 * @param D Camera parameter D
 * @param mask mask
 * @param drawingType Drawing configuration
 *              - 0: No drawing
 *              - 1: Aruco default detection drawing
 *              - 2: Customized detection drawing
 */
processedInformation processFrame(cv::Mat &frame, cv::Mat K, cv::Mat D, cv::Mat mask, int drawingType = 0);




/**
*   @brief Initialize the Ovis window
*
*   @param win object WindowScene to initialize
*   @param windowname required window name
*   @param imsize_aux required size
*   @param CamParam camera params path
*   @param customObjectFile custom object file to use
*/
void initializeOvisWindow(cv::Ptr<cv::ovis::WindowScene>& win, std::string windowname, cv::Size imsize_aux, std::string CamParam, std::string customObjectFile);


#endif