//////////////////////////
//		2019/04/05		//
//////////////////////////
// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
// �v���W�F�N�g�̃v���p�e�B��[C/C++]->[�ڍ�]�ɂ���[�K���C���N���[�h]
//�@�ݒ荀�ڂ�stdafx.h��ǉ�����ƋL�����Ȃ��Ă����ꂪ�ǉ�����Ă���̂Ƃ��Ȃ��ɂȂ�
//
// $(SolutionDir)�F.sln�t�H���_���u���Ă���t�H���_�̃t���p�X
// ��FC:\somewhere\your_appli\
// $(ProjectDir)�F�v���W�F�N�g�̃t�H���_�̃t���p�X
// ��FC:\somewhere\your_appli\some_project\
// $(TargetDir)�F�r���h�ɂ�萶�������.exe�t�@�C�����u�����t�H���_�̃t���p�X
// ��FC:\somewhere\your_appli\Debug\
// $(Configuration)�F�v���W�F�N�g�̃R���t�B�M�����[�V����
// ��FDebug �� Release��
// $(Platform)�F�v���b�g�t�H�[���B
// ��FWin32��x64��
// $(ProjectName)�F�v���W�F�N�g�̖��O
// ��Fsome_project
//
// �Q�l:https://msdn.microsoft.com/ja-jp/library/c02as0cs.aspx
//
// #ifdef �� #if defined
// #ifndef �� #if !defined
// #else if �ł͂Ȃ� #elif
// �Ȃ̂� #elif defined
//
// _DEBUG
// _DLL
// _MSC_VER
//

//�����R�[�h�ł̌x����������
// (UTF-8��OpenCV�̃G���[���Ȃ�)
#pragma warning(disable: 4819)

#pragma once
#ifndef __STDAFX__
#define __STDAFX__

//VisualStudio�p�ł����T�|�[�g���ĂȂ����L
#ifndef _MSC_VER
#error It's_not_VisualStudio
#endif
////////////target.h///////////////
//�ߋ���WinSDK�̃o�[�W�������w�肷��Ƃ��ȂǂɎg�p����
// �ڐA���ɖʓ|�Ȃ̂ŃR�����g�A�E�g
//#include "targetver.h"

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//			�p�b�P�[�W�t���O		//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

// 0:false 1:true

//OpenCV
#define OpenCV_flag 0
//OpenGL
#define OpenGL_flag 0
//KinectSDKv2
#define KinectSDK_flag 0
//FlyCapture2
#define FlyCapture2_flag 0
//OculusVR
#define OculusVR_flag 0
//OpenNI
#define OpenNI_flag 0
//Dlib
#define Dlib_flag 0

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

//////////////////////////////////////
//			�ǉ��w�b�_�[			//
//////////////////////////////////////

//��{�I�ȃw�b�_
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

// Windows �w�b�_�[����g�p����Ă��Ȃ����������O���܂��B
#define WIN32_LEAN_AND_MEAN
// Windows �w�b�_�[ �t�@�C��:
#include <windows.h>

#include <time.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>	//std::setfill��0����
#include <conio.h>	//_kbhit�ŃL�[���͂̎擾
#include <future>
#include <string.h>
#include <algorithm>
#include <iterator>
#include <map>
#include <mmsystem.h>
#include <direct.h>
#include <filesystem>	// std::tr2::sys::path etc���g�p���邽�߂ɕK�v

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <ws2tcpip.h>

#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

#include <ppl.h> //concurrency::parallel_for(size_t(0), size, size_t(1), [&](size_t i){for(){} });

//#include <objbase.h>

//////////////////////////////////////
//			�ǉ����C�u����			//
//////////////////////////////////////

//�^�C�}�n�̊֐�(timeGetTime���g�p����Ƃ��ɓǂݍ��ރ��C�u���� windows.h�Ƃ�mmsystem.h���K�v��������)
#pragma comment(lib, "Winmm.lib")
//�\�P�b�g���ۂ��֐�(?)
#pragma comment(lib, "ws2_32.lib")
//�l�b�g�ʐM
#pragma comment(lib, "wsock32.lib")

//////////////////////////////////////
//			�ǉ���`				//
//////////////////////////////////////

#define ARRAY_LENGTH(array) (sizeof(array)/sizeof(array[0]))


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//			CV��GL�Ȃǂ�������		//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

//////////////////////////////////////
//			OpenCV�w�b�_�[			//
//////////////////////////////////////

#if OpenCV_flag

#define OpenCV_only_world_lib 1
#define OpenCV_contrib_flag 0

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

// OpenCV �o�[�W�����擾
#define CV_VERSION_STR CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

// �r���h���[�h
#ifdef _DEBUG
#define CV_EXT_STR "d.lib"
#else
#define CV_EXT_STR ".lib"
#endif

//version 2
#if CV_MAJOR_VERSION == 2
//OpenCV2�n�̃��C�u����
#pragma comment(lib, "opencv_contrib"    CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_gpu"        CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_legacy"     CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_nonfree"    CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_ocl"        CV_VERSION_STR CV_EXT_STR)
//�e�X�g�p���W���[���B2�n�œǂݍ��ނƂ��܂ɃG���[�N����(CV��ver�ˑ���OS���̊��ˑ����s��)
//#pragma comment(lib, "opencv_ts"         CV_VERSION_STR CV_EXT_STR)
//version 3
#elif CV_MAJOR_VERSION == 3
//lib
#if OpenCV_only_world_lib
#pragma comment(lib, "opencv_world"      CV_VERSION_STR CV_EXT_STR)
#else
//#pragma comment(lib, "opencv_ts"         CV_VERSION_STR CV_EXT_STR)
//staticlib
#pragma comment(lib, "opencv_hal"        CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_imgcodecs"  CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_shape"      CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_videoio"    CV_VERSION_STR CV_EXT_STR)
#endif
//contrib
#if OpenCV_contrib_flag
#pragma comment(lib, "opencv_aruco"      CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_bgsegm"     CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_bioinspired" CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_ccalib"     CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_datasets"   CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_dnn"        CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_dpm"        CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_face"       CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_fuzzy"      CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_line_descriptor" CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_optflow"    CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_plot"       CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_reg"        CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_rgbd"       CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_saliency"   CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_stereo"     CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_structured_light" CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_surface_matching" CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_text"       CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_tracking"   CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_viz"        CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_xfeatures2d" CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_ximgproc"   CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_xobjdetect" CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_xphoto"     CV_VERSION_STR CV_EXT_STR)
#endif

#endif

#if !OpenCV_only_world_lib
//staticlib�S��
#pragma comment(lib, "opencv_calib3d"    CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_core"       CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_features2d" CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_flann"      CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_highgui"    CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_imgproc"    CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_ml"         CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_objdetect"  CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_photo"      CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_stitching"  CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_superres"   CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_video"      CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_videostab"  CV_VERSION_STR CV_EXT_STR)

#pragma comment(lib, "IlmImf"            CV_EXT_STR)
#pragma comment(lib, "libjasper"         CV_EXT_STR)
#pragma comment(lib, "libjpeg"           CV_EXT_STR)
#pragma comment(lib, "libpng"            CV_EXT_STR)
#pragma comment(lib, "libtiff"           CV_EXT_STR)
#pragma comment(lib, "zlib"              CV_EXT_STR)

#endif

//�Ȃɂ���?
#if CV_MAJOR_VERSION == 3
#if !OpenCV_only_world_lib
#ifndef _DEBUG
#pragma comment(lib, "ippicvmt"          CV_EXT_STR)
#endif
#endif
#endif

//////////////////////////////////////
//			OpenCV�ǉ��w�b�_�[		//
//////////////////////////////////////

#if CV_MAJOR_VERSION < 3

#include <opencv2/ocl/ocl.hpp>

#else

#include <opencv2/core/ocl.hpp>

#endif

//waitKey�p
// ���L�[
const int CV_WAITKEY_CURSORKEY_TOP = 2490368;
const int CV_WAITKEY_CURSORKEY_BOTTOM = 2621440;
const int CV_WAITKEY_CURSORKEY_RIGHT = 2555904;
const int CV_WAITKEY_CURSORKEY_LEFT = 2424832;
// �G���^�[�L�[�Ƃ�
const int CV_WAITKEY_ENTER = 13;
const int CV_WAITKEY_ESC = 27;
const int CV_WAITKEY_SPACE = 32;
const int CV_WAITKEY_TAB = 9;

#endif

//////////////////////////////////////
//			OpenGL�w�b�_�[			//
//////////////////////////////////////

#if OpenGL_flag

#pragma comment(lib, "opengl32.lib")

//GLext
//GL�֌W�F�Ȃɂ���cextended?
//#include <GL/glext.h>

//GLEW(GLSL)
#include <GL/glew.h>
//����͂ȂɁH
//#include <GL/glxew.h>
#include <GL/wglew.h>
//MX�������\����Multiple Rendering Contexts���T�|�[�g���������ꍇ�ɗp����D
#if defined _DEBUG
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glew32s.lib")
#else
#if !defined _WIN64
//�uglew32s.lib�v�́ustatic�v�Ƃ����Ӗ��炵���uglew.dll�v���s�v�B
//�uglew32.lib�v�́uglew.dll�v���ďo���v���O�����ɃX�^�e�B�b�N�Ƀ����N����
#pragma comment(lib, "Release/Win32/" "glew32.lib")
#pragma comment(lib, "Release/Win32/" "glew32s.lib")
#pragma comment(lib, "Release MX/Win32/" "glew32mx.lib")
#pragma comment(lib, "Release MX/Win32/" "glew32mxs.lib")
#else
#pragma comment(lib, "Release/x64/" "glew32.lib")
#pragma comment(lib, "Release/x64/" "glew32s.lib")
#pragma comment(lib, "Release MX/x64/" "glew32mx.lib")
#pragma comment(lib, "Release MX/x64/" "glew32mxs.lib")
#endif
#endif

//GLUT
#include <GL/glut.h>
#include <gl/freeglut.h>
	#if !defined _WIN64
	#pragma comment(lib, "x86/freeglut.lib")
	#else
	#pragma comment(lib, "x64/freeglut.lib")
	#endif
#endif

//GLEW�̃��C�u����
#include <GL/glext.h>
//#pragma comment(lib, "C:\dev\glew\lib\Release\Win32\glew32.lib")
//#pragma comment(lib, "C:\dev\glew\lib\Release\Win32\glew32s.lib")

//GLFW
#include <GLFW/glfw3.h>
//#include <GLFW/glfw3native.h>
// �r���h���[�h
#ifdef _DEBUG
#pragma comment(lib, "Debug/glfw3.lib")
#else
#pragma comment(lib, "Release/glfw3.lib")
#endif

#endif

//////////////////////////////////////
//		KinectSDK v2�w�b�_�[		//
//////////////////////////////////////

#if KinectSDK_flag

#include <Kinect.h>

#if !defined _WIN64
#pragma comment(lib, "x86/Kinect20.lib")
#pragma comment(lib, "x86/Kinect20.Face.lib")
#pragma comment(lib, "x86/Kinect20.Fusion.lib")
#pragma comment(lib, "x86/Kinect20.VisualGestureBuilder.lib")
#else
#pragma comment(lib, "x64/Kinect20.lib")
#pragma comment(lib, "x64/Kinect20.Face.lib")
#pragma comment(lib, "x64/Kinect20.Fusion.lib")
#pragma comment(lib, "x64/Kinect20.VisualGestureBuilder.lib")
#endif

#endif

//////////////////////////////////////
//		FlyCapture2�w�b�_�[			//
//////////////////////////////////////

#if FlyCapture2_flag

#include <FlyCapture2.h>

#ifdef _DEBUG
#pragma comment(lib,"FlyCapture2d.lib")
#pragma comment(lib,"FlyCapture2GUId.lib")
#else _RELEASE
#pragma comment(lib,"FlyCapture2.lib")
#pragma comment(lib,"FlyCapture2GUI.lib")
#endif

#endif

//////////////////////////////////////
//			Oculus�w�b�_�[			//
//////////////////////////////////////

#if OculusVR_flag

#include <OVR_Kernel.h>
#include <OVR_Version.h>

#include <OVR_CAPI_GL.h>
#include <GL/CAPI_GLE.h>

#if OVR_PRODUCT_VERSION <1
	#if OVR_MAJOR_VERSION == 8
		#include <OVR_CAPI_0_8_0.h>
	#elif OVR_MAJOR_VERSION == 5
		#include <OVR_CAPI_0_5_0.h>
	#endif
#endif

// PlatformToolset
// ?VS2013
#ifdef PlatformToolset
#else
#define PlatformToolset "VS2013"
#endif


//OculusVR�̃��C�u����
#pragma comment(lib, PlatformToolset "/LibOVR.lib")

//OculusVR��Kernel���C�u����
#pragma comment(lib, PlatformToolset "/LibOVRKernel.lib")

#endif

//////////////////////////////////////
//		OpenNI+NITE�w�b�_�[			//
//////////////////////////////////////

#if OpenNI_flag

#include<XnCppWrapper.h>
#include<XnVSessionManager.h>

//OpenNI�̃��C�u����
#ifndef _WIN64
#pragma comment(lib, "OpenNI.lib")
#pragma comment(lib, "XnVNITE_1_5_2.lib")
#else
#pragma comment(lib, "OpenNI64.lib")
#pragma comment(lib, "XnVNITE64_1_5_2.lib")
#endif

const char* CONFIG_XML_PATH = "C:\Program Files\PrimeSense\NITE\Data\Sample-Tracking.xml";

//�T���v��xml�t�@�C�����擾����
//DWORD dwResult;
//TCHAR tchrEnvVariable[256];
//dwResult = GetEnvironmentVariable(_T("XN_NITE_INSTALL_PATH"), tchrEnvVariable, sizeof(tchrEnvVariable));
//if (dwResult == 0){
//	std::cout << "GetEnvironmentVariable�Ɏ��s���܂���" << std::endl;
//}
//char chrEnvVariable[100];
//WideCharToMultiByte(CP_ACP, 0, tchrEnvVariable, -1, chrEnvVariable, sizeof(chrEnvVariable), NULL, NULL);
//lstrcpy(tchrEnvVariable, TEXT("\Data\Sample-Tracking.xml"));
//char* CONFIG_XML_PATH = chrEnvVariable;

#endif

//////////////////////////
//		Dlib			//
//////////////////////////

#if Dlib_flag

#include <dlib/revision.h>

#define DLIB_STR_EXP(__A)	#__A
#define DLIB_STR(__A)		DLIB_STR_EXP(__A)
#define DLIB_VERSION DLIB_STR(DLIB_MAJOR_VERSION) "." DLIB_STR(DLIB_MINOR_VERSION) "." DLIB_STR(DLIB_PATCH_VERSION)

#ifdef _DEBUG
#define DLIB_EXT_STR "_debug_"
#else
#define DLIB_EXT_STR "_release_"
#endif

#ifdef _WIN64
#define DLIB_BIT_STR "64bit_"
#else
#define DLIB_BIT_STR "32bit_"
#endif

#define DLIB_MSVC "msvc" DLIB_STR(_MSC_VER) ".lib"

#pragma comment(lib, "dlib" DLIB_VERSION DLIB_EXT_STR DLIB_BIT_STR DLIB_MSVC)

#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <dlib/image_transforms.h>
#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>

#if OpenCV_flag
#include <dlib/opencv.h>
#endif

#endif

////// template //////
/*
////// time //////
	timeBeginPeriod(1);
	DWORD start = timeGetTime();
	timeEndPeriod(1);

////// color : stdout //////
	HANDLE hStdout;
	WORD wAttributes;
	CONSOLE_SCREEN_BUFFER_INFO csbi;//�\���̂ł�

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//hStdout�̃R���\�[���X�N���[���o�b�t�@����csbi�Ɏ擾
	GetConsoleScreenBufferInfo(hStdout, &csbi);
	//�ΐF&������
	wAttributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(hStdout, wAttributes);
	printf("�ΐF\n");
	//���̃e�L�X�g��Ԃɖ߂�
	SetConsoleTextAttribute(hStdout, csbi.wAttributes);
	printf("���̏��\n");
	
////// ostringstream //////

	std::ostringstream pic_name[2];

	pic_name[0] << "HeloWarld!";

	std::cout << pic_name[0].str() << std::endl;

	//�֗��ϐ��g���������
	for (int key = 0; key < ARRAY_LENGTH(pic_name); key++)
	{
		//�֗��ϐ��̃o�b�t�@���N���A
		pic_name[key].str("");
		//�֗��ϐ��̃X�g���[���̏�Ԃ��N���A
		pic_name[key].clear(std::stringstream::goodbit);
	}
	pic_name[0] << "test";

	std::cout << pic_name[0].str() << std::endl;

////// quicksort //////
quicksort(int a[], int l, int r)
{
	int v, i, j, t;
	if (r > l) {
		v = a[r]; i = l-1; j = r;
		for (;;) {
			while (a[++i] < v) ;
			while (a[--j] > v) ;
			if (i >= j) break;
			t = a[i]; a[i] = a[j]; a[j] = t;
		}
		t = a[i]; a[i] = a[r]; a[r] = t;
		quicksort(a, l, i-1);
		quicksort(a, i+1, r);
	}
}

// 2
quicksort(int a[], int l, int r)
{
	int i;
	if (r < l) {
		i = partition(l, r);
		quicksort(a, l, i-1);
		quicksort(a, i+1, r);
	}
}

////// quickselect //////

k = (N-1)/2;
select(a, 0, N-1, k);
median = a[k];
	
select(int a[], int l, int r, int k)
{
	int i;
	if (r > l) {
		i = partition(l, r);
		if (i > l+k-1) select(a, l, i-1, k);
		if (i < l+k-1) select(a, i+1, r, k-i);
	}
}

////// wait key as while loop //////

while(_kbhit() == 0)
{
	printf_s("wait key \r");
}
int c = _getch();
printf_s("press key %d \n", c);


////// string <-> wstring //////

//! �V���O���o�C�g�A�}���`�o�C�g�����񉻊֐�
std::string TWStringToString(const std::wstring& arg_wstr)
{
	// ������
	size_t length = arg_wstr.size();
	// �ϊ��㕶����
	size_t convLength;
	// ���̎󂯎M��p�Ӂi�������~2�����\���ł��傤�j
	char *c = new char[length * 2];
	// �ϊ�
	wcstombs_s(&convLength, c, sizeof(char) * length * 2, arg_wstr.c_str(), length * 2);
	// �Ԃ�l�֕ۑ�
	std::string result(c);
	// ���̎󂯎M��j��
	delete c;

	return result;
}

//! ���C�h�����񉻊֐�
std::wstring TStringToWString(const std::string& arg_str)
{
	// ������
	size_t length = arg_str.size();
	// �ϊ��㕶����
	size_t convLength;
	// ���̎󂯎M��p��
	wchar_t *wc = new wchar_t[length + 2];
	// �ϊ�
	mbstowcs_s(&convLength, wc, length + 1, arg_str.c_str(), _TRUNCATE);
	// �Ԃ�l�֕ۑ�
	std::wstring str(wc);
	// ���̎󂯎M��j��
	delete wc;

	return str;
}



*/


#endif

//////////////////////
//	release note	//
//////////////////////
//
//19/04/05
//freeglut300�ɑΉ��w�b�_��������
//
//18/12/21
//Dlib�w�b�_�ǉ�
//
//18/05/13
//�e���v���[�g�ǉ�
// std::string <--> std::wstring
//
//
//17/11/07
//GLFW��vs2017�֌W
//
//17/05/28
//�������`
//
//17/04/17
//VisualStudio�p�ł����T�|�[�g���ĂȂ��Ɩ��L
//MinGW�p�Ƃ���p�ӂ��Ă�������
//
//16/12/02
//Socket�n�̃C���N���[�h��lib
//
//16/10/17
//OpenCV�w�b�_�[world.lib�������g���t���O�ǉ�
//
//16/07/27
//conio.h��ǉ�
// _kbhit()�ŃL�[���͂ɂ��while���[�v�Ƃ��g����悤��
// �e���v�����ǉ�
//
//16/07/13
//�C���N���[�h�K�[�h�ǉ�
// ifndef�ŕϐ�"__STDAFX__"��p����
//fstream�w�b�_�[�̒ǉ�
// fopen�Ƃ��Ƃ�
//direct.h��filesystem�w�b�_�[�̒ǉ�
// mkdir�Ƃ��ł���
// std::tr2::sys::path etc���g�p���邽�߂ɕK�v
//gl/freeglut.h�w�b�_�[�̒ǉ�(GL)
//
//16/07/12
//OpenGL glew�̓ǂݍ��ރ��C�u�����w���DEBUG���̎w�肪�Ԉ���Ă����̂��C��
//
//16/07/01
//�����R�[�h�̌x��������������#pragma warning(disable: 4819)��ǉ�
// �����R�[�h�x�������������Ƃɂ�鑼�̌x�����ɒ���
//�e���v���[�g���ǉ�
// ���Ԍv������e���v���[�g
// �R���\�[����ɕ\�����镶���F�Ȃǂ�ς�����̂̃e���v���[�g�ǉ�
//
//16/06/22
//Kinect v2 Library�̒ǉ�
//
//16/06/04
//dll�����ł���悤��
//ppl.h��ǉ�
// parallel_for�ȂǕ���
//
//16/04/28
//KinectSDKv2��ǉ�
//
//16/03/14
//�����Ȃǂ�����ǉ�
// ���e�͕ύX�Ȃ�
//
//16/02/25
//opencv lib��staticlib�Ő���
// CV2��CV3�Ŗ��m�ɓǂݍ���lib�����
// CV2�ł�staticlib��lib�̑傫�ȋ�ʂȂ�
//windows.h��ǉ�
// QueryPerformanceCounter()�Ńi�m�b���擾���邽�߂�
//
//16/02/23
//opencv contrib�Ȃǂ̑��̃��C�u�����ǉ�
//lib��K���ɒǉ����������Ȃ̂Œʏ��lib��contrib����lib�����݂��Ă���̂Ō�Œ��ߕK�v
//opengl GLEW��lib(Release����32/64bit�̎w��)���Ԉ���Ă����̂ŏC��
//glxew.h���ׂ����ǁA����ς�Ȃɂ��킩��Ȃ�����...
//
//16/02/16
//#include <sstream>�ǉ�
//release note�ǉ�
//
//////////
// VS2010:vc10 VS2012:vc11 VS2013:vc12 VS2015:vc14 VS2017:vc15(vc14.1)
//
