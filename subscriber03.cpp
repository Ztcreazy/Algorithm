#include "ros/ros.h"
#include "publish_subscribe/Person.h"

void Implement(const publish_subscribe::Person::ConstPtr &person){
    ROS_INFO("Name: %s, Age: %d, Height: %.2f",person->name.c_str(),person->age,person->height);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Background");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe<publish_subscribe::Person>("Thesis",12,Implement);

    ros::spin();

    return 0;
}
