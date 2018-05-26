
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<string>

#include "config.h"
#include "Calibrate.h"
#include "PairAlign.h"

//extrinsic1 表示从1号设备到2号设备的空间变换矩阵1T2
CvMat extrinsic[12];//[0]:将1号点云移动到2号
//Eigen::Matrix4f Eigen_extrinsic[12];
CvMat translation;//设备上升方向
//Eigen::Matrix4f Eigen_translation;
int horizontalScanNum;//水平采集点云数（设备数）
int verticalScanNum;//竖直采集点云数（上升次数
float risingDistance;//每次移动的距离

void Get_ConfigArgv(){
	CvFileStorage *fs;
	fs = cvOpenFileStorage("./config/config.xml", 0, CV_STORAGE_READ);

	board_size.width = cvReadIntByName(fs, 0, "board_width", 0);
	board_size.height = cvReadIntByName(fs, 0, "board_height", 0);
	square_size.width = cvReadRealByName(fs, NULL, "board_width");
	square_size.height = cvReadRealByName(fs, NULL, "board_height");
	total_clude = cvReadIntByName(fs, 0, "cludenum", 0);
	Registration_flag = cvReadIntByName(fs, 0, "Registration_flag",0);
	HorizontalRegistrationModel = cvReadIntByName(fs, NULL, "HorizontalRegistrationModel");
	VerticalRegistrationModel = cvReadIntByName(fs, NULL, "VerticalRegistrationModel");

	Camera_ID == cvReadIntByName(fs, 0, "Camera_ID", 0);
	KSearchnum = cvReadIntByName(fs, 0, "KSearchnum", 0);
	MaxCorrespondenceDistance = cvReadRealByName(fs, NULL, "MaxCorrespondenceDistance"); //对应点之间的最大距离（0.1）, 在配准过程中，忽略大于该阈值的点
	LeafSize = cvReadRealByName(fs, NULL, "LeafSize");
	TransformationEpsilon = cvReadRealByName(fs, NULL, "TransformationEpsilon");//允许最大误差
	downsample_flag = cvReadIntByName(fs, NULL, "downsample_flag");
	Cali_Pic_Num = cvReadIntByName(fs, NULL, "Cali_Pic_Num");

	horizontalScanNum = cvReadIntByName(fs, NULL, "horizontalScanNum");
	verticalScanNum = cvReadIntByName(fs, NULL, "verticalScanNum");
	risingDistance = cvReadRealByName(fs, NULL, "risingDistance");

	cvReleaseFileStorage(&fs);
}

void Get_extrinsic(){
	CvFileStorage *fs;
	fs = cvOpenFileStorage("./config/extrinsic.xml", 0, CV_STORAGE_READ);

	translation = *(CvMat *)cvReadByName(fs, NULL, "translation");
	for (int i = 1; i <= 1;i++){
		std::string ex_mat = "extrinsic" + std::to_string(i);
		extrinsic[i-1] = *(CvMat *)cvReadByName(fs, NULL, ex_mat.c_str());
	}
	cvReleaseFileStorage(&fs);	
}




