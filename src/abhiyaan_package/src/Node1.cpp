/* Publisher Node
   Publishes to the Topic: /team_abhiyaan
   Datatype: String */
   
#include "ros/ros.h"
#include"std_msgs/String.h"

int main(int argc, char **argv){
	ros::init(argc, argv, "Node1");
	ros::NodeHandle n;
	ros::Publisher topic_pub =  n.advertise<std_msgs::String>("team_abhiyaan",1000);
	ros::Rate loop_rate(1);
    while(ros::ok()){
    	std_msgs::String msg;
    	msg.data = "Team Abhiyaan rocks:";
    	topic_pub.publish(msg);
    	ros::spinOnce();
    	loop_rate.sleep();
    }
    return 0;
}