#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Publisher");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("Publishing",12);

    std_msgs::String message;

    ros::Rate rate(10); // frequency

    ros::Duration(2).sleep();

    int count = 0;

    while (ros::ok)
    {
        count++;
        // message.data = "Publisher is Publishing";
        std::stringstream ss;
        ss << "Publisher is Publishing ---> " << count;
        message.data = ss.str();
        pub.publish(message);
        ROS_INFO("%s", ss.str().c_str());
        rate.sleep();
        // ros::spinOnce();
    }
    
    return 0;
}
