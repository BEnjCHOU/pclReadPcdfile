#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

void readPcd(std::string filename, int counting, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
    // absolute path
    std::string absolute_path = "/Your/absolute/Path/";
    std::string readPcd = Path + filename + "-" + std::to_string(counting) + ".pcd";
    if (pcl::io::loadPCDFile<pcl::PointXYZ> (readPcd, *cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    }
}

int main()
{
    const int NUMBER_OF_FILE = 10;
    // point cloud statement to save point cloud
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    // read multiple file
    std::string filename = "raw_cloud";
    for(int i = 0 ; i < NUMBER_OF_FILE ; ++i)
    {
        readPcd(filename, i, cloud)
        cloud->clear();
    }
        
}
