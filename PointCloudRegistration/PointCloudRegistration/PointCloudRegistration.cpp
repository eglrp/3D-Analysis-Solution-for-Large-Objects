// �������̨Ӧ�ó������ڵ㡣
//�ص���Microsoft���ŵ�����
//
// Created by �쿭 on 17/4/4.
//
#include "stdafx.h"

#include "PairAlign.h"
#include "config.h"

#include <pcl/visualization/cloud_viewer.h>  
#include <iostream>  
#include <pcl/io/io.h>  
#include <pcl/io/pcd_io.h>  

#include <cv.h>
#include <highgui.h>


int _tmain(int argc, char** argv)
{
	char *str1 = "1_point_cloud.ply";
	argv[1] = str1;
	char *str2 = "2_point_cloud.ply";
	argv[2] = str2;
	char *str3 = "3_point_cloud.ply";
	argv[3] = str3;
	char *str4 = "4_point_cloud.ply";
	argv[4] = str4;
	char *str5 = "5_point_cloud.ply";
	argv[5] = str5;
	char *str6 = "6_point_cloud.ply";
	argv[6] = str6;
	char *str7 = "7_point_cloud.ply";
	argv[7] = str7 ;
	char *str8 = "8_point_cloud.ply";
	argv[8] = str8;
	char *str9 = "9_point_cloud.ply";
	argv[9] = str7;
	Get_extrinsic();
	Get_ConfigArgv();

	argc = total_clude+1;
	//��ȡ����
	/*<horizontalScanNum>12</horizontalScanNum>
	  <verticalScanNum>3</verticalScanNum>
*/
	std::vector<PCD, Eigen::aligned_allocator<PCD> > data; //ģ��
	loadData(argc, argv, data); //��ȡpcd�ļ����ݣ����������	
	HorizontalAccurateRegistration(data);
	VerticalAccurateRegistration(data);
	//AccurateRegistration2(data);//��ϸƴ��

	return 0;
}
