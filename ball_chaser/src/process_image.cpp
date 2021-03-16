#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request a service
ros::ServiceClient client;

void drive_robot(float lin_x, float ang_z)
{
    ROS_INFO_STREAM("Moving robot");

    // Request motor commands
    ball_chaser::DriveToTarget srv;

    srv.request.linear_x = (float)lin_x;
    srv.request.angular_z = (float)ang_z;

    // Call the command_robot service and pass the requested motor commands
    if (!client.call(srv))
        ROS_ERROR("Failed to call service command_robot");
}

// The callback function continuously executes and read the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int w_p =255; //white_pixel

    //assume ball not found at initial
    bool ball_found = false;

    int col = 0; //column_index
    
    for (int i=0; i < img.height * img.step; i =i+3)
    {   
        // RGB data
        if ((img.data[i] == w_p) && (img.data[i+1] == w_p) && (img.data[i+2] == w_p))
        {
            col = i % img.step;

            //turn left
            if (col < img.step/3)
                drive_robot(0.5, 0.5);

            //frwd
            else if (col < (img.step/3 * 2))
                drive_robot(0.7, 0); 

            //turn right
            else
                drive_robot(0.5, -0.5);

            ball_found = true;
            break;
         }
     }

     // if ball not found after scanning
     if (ball_found == false)
         drive_robot(0, 0);             
}
  

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subsribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
