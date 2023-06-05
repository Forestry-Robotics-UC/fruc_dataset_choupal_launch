#include <ros/ros.h>
#include <tf/transform_broadcaster.h> //tf
#include <nav_msgs/Odometry.h>	// odom

tf::TransformBroadcaster *tb;

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg){
    
    //ROS_INFO("Odom received. Publish TF.");

    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = msg->header.stamp;
    odom_trans.header.frame_id = msg->header.frame_id;
    odom_trans.child_frame_id = msg->child_frame_id;
    odom_trans.transform.translation.x = msg->pose.pose.position.x;
    odom_trans.transform.translation.y = msg->pose.pose.position.y;
    odom_trans.transform.translation.z = msg->pose.pose.position.z;
    odom_trans.transform.rotation.x = msg->pose.pose.orientation.x;
    odom_trans.transform.rotation.y = msg->pose.pose.orientation.y;
    odom_trans.transform.rotation.z = msg->pose.pose.orientation.z;
    odom_trans.transform.rotation.w = msg->pose.pose.orientation.w;
    tb->sendTransform(odom_trans);    
}


int main(int argc, char** argv){
    
	ros::init(argc, argv, "subscribe_odom_publish_tf");
        
	ros::NodeHandle n;
        
        tb = new tf::TransformBroadcaster();
        ros::Subscriber odom_sub = n.subscribe<nav_msgs::Odometry>("odom", 100, &odomCallback); 

        ros::spin();   
        
        return 0;
};
