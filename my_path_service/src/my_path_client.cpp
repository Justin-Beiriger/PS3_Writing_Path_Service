//path_client:
// illustrates how to send a request to the path_service service

#include <ros/ros.h>
#include <example_ros_service/PathSrv.h> // this message type is defined in the current package
#include <iostream>
#include <string>
#include <nav_msgs/Path.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
using namespace std;

geometry_msgs::Quaternion convertPlanarPhi2Quaternion(double phi) {
    geometry_msgs::Quaternion quaternion;
    quaternion.x = 0.0;
    quaternion.y = 0.0;
    quaternion.z = sin(phi / 2.0);
    quaternion.w = cos(phi / 2.0);
    return quaternion;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "path_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<example_ros_service::PathSrv>("path_service");
    geometry_msgs::Quaternion quat;
    
    while (!client.exists()) {
      ROS_INFO("waiting for service...");
      ros::Duration(1.0).sleep();
    }
    ROS_INFO("connected client to service");
    example_ros_service::PathSrv path_srv;
    
    //create some path points...this should be done by some intelligent algorithm, but we'll hard-code it here
    geometry_msgs::PoseStamped pose_stamped;
    geometry_msgs::Pose pose;
    pose.position.x = 3.0; // first desired x-coord is 3
    pose.position.y = 0.0;
    pose.position.z = 0.0; // let's hope so!
    quat = convertPlanarPhi2Quaternion(1.571);
    pose_stamped.pose.orientation = quat;
    pose_stamped.pose = pose;
    path_srv.request.nav_path.poses.push_back(pose_stamped);
    
    // some more poses...
    quat = convertPlanarPhi2Quaternion(0); // get a quaternion corresponding to this heading
    pose_stamped.pose.orientation = quat;
    pose_stamped.pose.position.y = 3.0; // desired y-coord is 3.0
    path_srv.request.nav_path.poses.push_back(pose_stamped);
    
    quat = convertPlanarPhi2Quaternion(1.571);
    pose_stamped.pose.orientation = quat;
    pose_stamped.pose.position.x = 6.5; // desired x-coord is 6.5
    path_srv.request.nav_path.poses.push_back(pose_stamped);
    
    quat = convertPlanarPhi2Quaternion(3.14159);
    pose_stamped.pose.orientation = quat;
    pose_stamped.pose.position.y = 5.2; // desired x-coord is 6.5
    path_srv.request.nav_path.poses.push_back(pose_stamped);
    
    quat = convertPlanarPhi2Quaternion(1.571);
    pose_stamped.pose.orientation = quat;
    pose_stamped.pose.position.x = 3.0; // desired x-coord is 6.5
    path_srv.request.nav_path.poses.push_back(pose_stamped);
    
    quat = convertPlanarPhi2Quaternion(3.14159);
    pose_stamped.pose.orientation = quat;
    pose_stamped.pose.position.y = 12.0; // desired x-coord is 6.5
    path_srv.request.nav_path.poses.push_back(pose_stamped);
    
    quat = convertPlanarPhi2Quaternion(3.14159);
    pose_stamped.pose.orientation = quat;
    pose_stamped.pose.position.x = 0; // desired x-coord is 6.5
    path_srv.request.nav_path.poses.push_back(pose_stamped);
    client.call(path_srv);
    
    return 0;
}
