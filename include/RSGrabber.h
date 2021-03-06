// RSGrabber.cpp: 定义 DLL 应用程序的导出函数。
//

#include <pcl/point_cloud.h>  
#include <pcl/point_types.h>
#include <thread>


//类型定义
namespace RSGRABBER
{
	typedef pcl::PointXYZRGBA              PointXYZRGBA;
	typedef pcl::PointXYZRGB              PointXYZRGB;
	typedef pcl::PointCloud<PointXYZRGBA>  CloudXYZRGBA;
	typedef pcl::PointCloud<PointXYZRGB>  CloudXYZRGB;
	typedef CloudXYZRGBA::Ptr              CloudXYZRGBAPtr;
	typedef CloudXYZRGB::Ptr              CloudXYZRGBPtr;
	typedef CloudXYZRGBA::ConstPtr         CloudXYZRGBAConstPtr;
	typedef void(*PCLDataCallBack)(const CloudXYZRGBAConstPtr& cloud_in, void *user);
}

namespace RSGRABBER {
	class __declspec(dllexport) RealsenseGrabber
	{
	public:
		RealsenseGrabber():mIsStop(false){}
		~RealsenseGrabber(){}
		void start(PCLDataCallBack cb, void* user);
		void stop();
	private:
		//std::tuple<int, int, int> RGB_Texture(rs2::video_frame texture, rs2::texture_coordinate Texture_XY);
		//CloudXYZRGBAPtr rs_to_pcl_color(const rs2::points& points, rs2::video_frame& color);
		bool mIsStop;
	};
}