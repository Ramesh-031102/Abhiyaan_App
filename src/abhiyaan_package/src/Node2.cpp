/* Subscriber Node
   Subscribes to the Topic: /team_abhiyaan
   Datatype: String */

#include "ros/ros.h"
#include"std_msgs/String.h"

void func(const std_msgs::String::ConstPtr& msg){
	ROS_INFO("The message that was recieved : %s",msg->data.c_str());
}
int main(int argc, char **argv){
	ros::init(argc, argv, "Node2");
	ros::NodeHandle n;
	ros::Subscriber topic_sub =  n.subscribe("team_abhiyaan",1000,func);
	ros::spin();
    return 0;
}