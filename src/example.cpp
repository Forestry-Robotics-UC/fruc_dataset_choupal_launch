#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

ros::Publisher pub;

struct PointXYZIRT
{
    PCL_ADD_POINT4D
    PCL_ADD_INTENSITY;
    uint16_t ring;
    float time;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
} EIGEN_ALIGN16;

POINT_CLOUD_REGISTER_POINT_STRUCT (PointXYZIRT,
    (float, x, x) (float, y, y) (float, z, z) (float, intensity, intensity)
    (uint16_t, ring, ring) (float, time, time)
)

pcl::PointCloud<PointXYZIRT>::Ptr lio_sam_cloud_out(new pcl::PointCloud<PointXYZIRT>());
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);


void 
cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
  // Create a container for the data.
  sensor_msgs::PointCloud2 output;
  pcl::fromROSMsg (*input, *cloud);
  
  PointXYZIRT p;

  for (const auto& field : input->fields)
  {
    // Print the field name and type
    ROS_INFO("Field name: %s", field.name.c_str());
    ROS_INFO("Field type: %d", field.datatype);
  }


  //Fill point cloud
  //for (const pcl::PointXYZI& point : *cloud){
  //  p.x = point.x;
  //  p.y = point.y;
  //  p.z = point.z;
  //  p.intensity = point.intensity;
  //  p.ring = 0;
  //  lio_sam_cloud_out->push_back(p);
  //}

  //pcl::toROSMsg(*lio_sam_cloud_out, output);
  //output.header = input.header;


  // Publish the data.
  //pub.publish (output);
  //lio_sam_cloud_out->clear();
}

int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;
  ROS_WARN("Test this shit");

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/livox/lidar", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);

  // Spin
  ros::spin ();
}