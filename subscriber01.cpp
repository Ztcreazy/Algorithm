#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void Implement(const std_msgs::String::ConstPtr &msg){
    ROS_INFO("Subscriber is subscribing: %s", msg->data.c_str());
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Subscriber");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("Publishing",12,Implement);

    /* spin */
    ros::spin();

    return 0;
}
