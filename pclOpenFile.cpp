#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

int main (int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    
    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("../cluster_data/cloud_cluster-1249.pcd", *cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }
//    std::cout << "Loaded "
//    << cloud->width * cloud->height
//    << " data points from test_pcd.pcd with the following fields: "
//    << std::endl;
//    for (size_t i = 0; i < cloud->points.size (); ++i)
//        std::cout << "    " << cloud->points[i].x
//        << " "    << cloud->points[i].y
//        << " "    << cloud->points[i].z << std::endl;
    //vis statements
    pcl::visualization::PCLVisualizer vis("3D View");
    // visualization statements
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> blue(cloud,0,0,255);
    vis.addPointCloud(cloud,blue,"cloud",0);
    vis.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud");
    // visualize
    while(!vis.wasStopped())
    {
        // remove point cloud
        //vis.removeAllPointClouds();
        
        vis.spinOnce();
    }
    return (0);
}
