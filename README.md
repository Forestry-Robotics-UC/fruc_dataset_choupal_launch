FRUC Datasets (Forest environment dataset)

This dataset was collected as part of the work conducted by the [Forestry Robotics @ University](https://www.youtube.com/@forestryroboticsuc) of Coimbra team 
part of the [Institute of Systems and Robotics](https://www.isr.uc.pt/)
within the scope of the [Safety, Exploration and Maintenance of Forests with Ecological Robotics (SEMFIRE, ref. CENTRO-01-0247-FEDER-03269)](http://semfire.ingeniarius.pt/) 
and the Semi-Autonomous Robotic System for Forest Cleaning and Fire Prevention (SafeForest, CENTRO-01-0247-FEDER-045931) research projects. 
Its purpose is to allow researchers in forestry robotics to have an in-depth analysis of a florests environment; obtain an a priori map for robot 
operations (e.g. path plannning, landscaping, etc…) and to train segmentation algorithms;


The dataset in question includes data from multiple sensors and absolute, map-referenced localization which can be used to 
register the sensor data to a fixed coordinate system. It was collected at the Choupal National Woods, Coimbra, Portugal (40◦13′13.3′′N;8◦26′38.1′′W). 
The dataset was collected during a partly clouded day in a forest environment by performing two circular loop laps amounting to a total distance of 
approximately 800m, with a total duration of 24 minutes and 26 seconds. The scenario is rich in features relevant to forestry robotics applications, 
including trees, bushes, tree trunks, etc. To better handle the multimodal nature of the acquired data, the dataset is bundled into rosbags, a file 
format used by the ROS (Robot Operating System) to record and play back data.


More specifically, the datasets include:

- RGB Images from an Intel Realsense D435i
- Aligned Depth Images from an Intel Realsense D435i
- Point Clouds from a Livox Mid-70 LiDAR
- Unfiltered acceleration, gyroscopic and magnetic data from a Xsens MTi IMU
- Unfiltered acceleration, gyroscopic data from an Intel Realsense D435i

Description of files:

- The dataset was split into three rosbags (choupal_0.bag, choupal_1.bag, choupal_2.bag).
- The rosbag_info_[x].txt contains the information of each rosbag;
- The sensor_box.urdf contains all the required transforms;
- The sensor_box.stl contains the 3D model of the apparatus;
- The choupal.launch publishes the sensor transforms and plays the dataset;
- The **localization.bag** contains the final graph of poses extracted with RTAB-Map republished as nav_msgs/odom at 5Hz.
- The **localization_[x]Hz.bag** contains the final graph of poses extracted with RTAB-Map at a higher frequency, but the poses are interpolated. If you don't require a high frame rate, please use the localization.bag instead.

Usage:

1. Extract the fruc_dataset_choupal_launch.zip into a catkin workspace
2. Copy the rosbags into the fruc_dataset_choupal_launch/rosbag/
3. Edit the fruc_dataset_choupal_launch/launch/choupal.launch file to your use case:
    - Change the file_path argument if the rosbags are not in the default location;
    - Set enable_localization to true in order to use the provided localization bags.
4. Compile the package and source the environment:

```
catkin_make [/your_catkin_workspace/]
source [/your_catkin_workspace/devel/setup.bash]
```
5. Launch the files:
`roslaunch fruc_dataset_choupal_launch choupal.launch`
