#! /usr/bin/env python

import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("Publisher_py")

    pub = rospy.Publisher("Vehicle",String,queue_size = 10)

    message = String()

    rate = rospy.Rate(1)

    count = 0;

    rospy.sleep(5)

    while not rospy.is_shutdown():
        count += 4
        message.data = "Aston Martin ---> " + str(count)
        pub.publish(message)
        rospy.loginfo("%s", message.data)
        rate.sleep()
