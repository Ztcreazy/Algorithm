#include "ros/ros.h"
#include "publish_subscribe/Person.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Introduction");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<publish_subscribe::Person>("Thesis",12);

    publish_subscribe::Person person;

    person.name = "Tong";
    person.age = 24;
    person.height = 175;

    ros::Rate rate(1); // frequency

    ros::Duration(2).sleep();

    while (ros::ok)
    {
        person.age += 1;
        pub.publish(person);
        ROS_INFO("Name: %s, Age: %d, Height: %.2f",person.name.c_str(),person.age,person.height);
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
