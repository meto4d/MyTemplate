//////////////////////////
//		2019/04/05		//
//////////////////////////
// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
// プロジェクトのプロパティで[C/C++]->[詳細]にある[必ずインクルード]
//　設定項目にstdafx.hを追加すると記入しなくてもこれが追加されているのとおなじになる
//
// $(SolutionDir)：.slnフォルダが置いてあるフォルダのフルパス
// 例：C:\somewhere\your_appli\
// $(ProjectDir)：プロジェクトのフォルダのフルパス
// 例：C:\somewhere\your_appli\some_project\
// $(TargetDir)：ビルドにより生成される.exeファイルが置かれるフォルダのフルパス
// 例：C:\somewhere\your_appli\Debug\
// $(Configuration)：プロジェクトのコンフィギュレーション
// 例：Debug か Releaseか
// $(Platform)：プラットフォーム。
// 例：Win32かx64か
// $(ProjectName)：プロジェクトの名前
// 例：some_project
//
// 参考:https://msdn.microsoft.com/ja-jp/library/c02as0cs.aspx
//
// #ifdef は #if defined
// #ifndef は #if !defined
// #else if ではなく #elif
// なので #elif defined
//
// _DEBUG
// _DLL
// _MSC_VER
//

//文字コードでの警告分を消去
// (UTF-8のOpenCVのエラー文など)
#pragma warning(disable: 4819)

#pragma once
#ifndef __STDAFX__
#define __STDAFX__

//VisualStudio用でしかサポートしてない明記
#ifndef _MSC_VER
#error It's_not_VisualStudio
#endif
////////////target.h///////////////
//過去のWinSDKのバージョンを指定するときなどに使用する
// 移植時に面倒なのでコメントアウト
//#include "targetver.h"

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//			パッケージフラグ		//
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
//			追加ヘッダー			//
//////////////////////////////////////

//基本的なヘッダ
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

// Windows ヘッダーから使用されていない部分を除外します。
#define WIN32_LEAN_AND_MEAN
// Windows ヘッダー ファイル:
#include <windows.h>

#include <time.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>	//std::setfillで0埋め
#include <conio.h>	//_kbhitでキー入力の取得
#include <future>
#include <string.h>
#include <algorithm>
#include <iterator>
#include <map>
#include <mmsystem.h>
#include <direct.h>
#include <filesystem>	// std::tr2::sys::path etcを使用するために必要

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <ws2tcpip.h>

#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

#include <ppl.h> //concurrency::parallel_for(size_t(0), size, size_t(1), [&](size_t i){for(){} });

//#include <objbase.h>

//////////////////////////////////////
//			追加ライブラリ			//
//////////////////////////////////////

//タイマ系の関数(timeGetTimeを使用するときに読み込むライブラリ windows.hとかmmsystem.hが必要だったり)
#pragma comment(lib, "Winmm.lib")
//ソケットっぽい関数(?)
#pragma comment(lib, "ws2_32.lib")
//ネット通信
#pragma comment(lib, "wsock32.lib")

//////////////////////////////////////
//			追加定義				//
//////////////////////////////////////

#define ARRAY_LENGTH(array) (sizeof(array)/sizeof(array[0]))


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//			CVやGLなどここから		//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

//////////////////////////////////////
//			OpenCVヘッダー			//
//////////////////////////////////////

#if OpenCV_flag

#define OpenCV_only_world_lib 1
#define OpenCV_contrib_flag 0

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

// OpenCV バージョン取得
#define CV_VERSION_STR CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

// ビルドモード
#ifdef _DEBUG
#define CV_EXT_STR "d.lib"
#else
#define CV_EXT_STR ".lib"
#endif

//version 2
#if CV_MAJOR_VERSION == 2
//OpenCV2系のライブラリ
#pragma comment(lib, "opencv_contrib"    CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_gpu"        CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_legacy"     CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_nonfree"    CV_VERSION_STR CV_EXT_STR)
#pragma comment(lib, "opencv_ocl"        CV_VERSION_STR CV_EXT_STR)
//テスト用モジュール。2系で読み込むとたまにエラー起こす(CVのver依存かOS等の環境依存か不明)
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
//staticlib全般
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

//なにこれ?
#if CV_MAJOR_VERSION == 3
#if !OpenCV_only_world_lib
#ifndef _DEBUG
#pragma comment(lib, "ippicvmt"          CV_EXT_STR)
#endif
#endif
#endif

//////////////////////////////////////
//			OpenCV追加ヘッダー		//
//////////////////////////////////////

#if CV_MAJOR_VERSION < 3

#include <opencv2/ocl/ocl.hpp>

#else

#include <opencv2/core/ocl.hpp>

#endif

//waitKey用
// 矢印キー
const int CV_WAITKEY_CURSORKEY_TOP = 2490368;
const int CV_WAITKEY_CURSORKEY_BOTTOM = 2621440;
const int CV_WAITKEY_CURSORKEY_RIGHT = 2555904;
const int CV_WAITKEY_CURSORKEY_LEFT = 2424832;
// エンターキーとか
const int CV_WAITKEY_ENTER = 13;
const int CV_WAITKEY_ESC = 27;
const int CV_WAITKEY_SPACE = 32;
const int CV_WAITKEY_TAB = 9;

#endif

//////////////////////////////////////
//			OpenGLヘッダー			//
//////////////////////////////////////

#if OpenGL_flag

#pragma comment(lib, "opengl32.lib")

//GLext
//GL関係：なにこれ…extended?
//#include <GL/glext.h>

//GLEW(GLSL)
#include <GL/glew.h>
//これはなに？
//#include <GL/glxew.h>
#include <GL/wglew.h>
//MXがついた構成はMultiple Rendering Contextsをサポートさせたい場合に用いる．
#if defined _DEBUG
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glew32s.lib")
#else
#if !defined _WIN64
//「glew32s.lib」は「static」という意味らしく「glew.dll」が不要。
//「glew32.lib」は「glew.dll」を呼出すプログラムにスタティックにリンクする
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

//GLEWのライブラリ
#include <GL/glext.h>
//#pragma comment(lib, "C:\dev\glew\lib\Release\Win32\glew32.lib")
//#pragma comment(lib, "C:\dev\glew\lib\Release\Win32\glew32s.lib")

//GLFW
#include <GLFW/glfw3.h>
//#include <GLFW/glfw3native.h>
// ビルドモード
#ifdef _DEBUG
#pragma comment(lib, "Debug/glfw3.lib")
#else
#pragma comment(lib, "Release/glfw3.lib")
#endif

#endif

//////////////////////////////////////
//		KinectSDK v2ヘッダー		//
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
//		FlyCapture2ヘッダー			//
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
//			Oculusヘッダー			//
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


//OculusVRのライブラリ
#pragma comment(lib, PlatformToolset "/LibOVR.lib")

//OculusVRのKernelライブラリ
#pragma comment(lib, PlatformToolset "/LibOVRKernel.lib")

#endif

//////////////////////////////////////
//		OpenNI+NITEヘッダー			//
//////////////////////////////////////

#if OpenNI_flag

#include<XnCppWrapper.h>
#include<XnVSessionManager.h>

//OpenNIのライブラリ
#ifndef _WIN64
#pragma comment(lib, "OpenNI.lib")
#pragma comment(lib, "XnVNITE_1_5_2.lib")
#else
#pragma comment(lib, "OpenNI64.lib")
#pragma comment(lib, "XnVNITE64_1_5_2.lib")
#endif

const char* CONFIG_XML_PATH = "C:\Program Files\PrimeSense\NITE\Data\Sample-Tracking.xml";

//サンプルxmlファイルを取得する
//DWORD dwResult;
//TCHAR tchrEnvVariable[256];
//dwResult = GetEnvironmentVariable(_T("XN_NITE_INSTALL_PATH"), tchrEnvVariable, sizeof(tchrEnvVariable));
//if (dwResult == 0){
//	std::cout << "GetEnvironmentVariableに失敗しました" << std::endl;
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
	CONSOLE_SCREEN_BUFFER_INFO csbi;//構造体です

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//hStdoutのコンソールスクリーンバッファ情報をcsbiに取得
	GetConsoleScreenBufferInfo(hStdout, &csbi);
	//緑色&太文字
	wAttributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(hStdout, wAttributes);
	printf("緑色\n");
	//元のテキスト状態に戻す
	SetConsoleTextAttribute(hStdout, csbi.wAttributes);
	printf("元の状態\n");
	
////// ostringstream //////

	std::ostringstream pic_name[2];

	pic_name[0] << "HeloWarld!";

	std::cout << pic_name[0].str() << std::endl;

	//便利変数使ったら消す
	for (int key = 0; key < ARRAY_LENGTH(pic_name); key++)
	{
		//便利変数のバッファをクリア
		pic_name[key].str("");
		//便利変数のストリームの状態をクリア
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

//! シングルバイト、マルチバイト文字列化関数
std::string TWStringToString(const std::wstring& arg_wstr)
{
	// 文字数
	size_t length = arg_wstr.size();
	// 変換後文字数
	size_t convLength;
	// 仮の受け皿を用意（文字数×2ありゃ十分でしょう）
	char *c = new char[length * 2];
	// 変換
	wcstombs_s(&convLength, c, sizeof(char) * length * 2, arg_wstr.c_str(), length * 2);
	// 返り値へ保存
	std::string result(c);
	// 仮の受け皿を破棄
	delete c;

	return result;
}

//! ワイド文字列化関数
std::wstring TStringToWString(const std::string& arg_str)
{
	// 文字数
	size_t length = arg_str.size();
	// 変換後文字数
	size_t convLength;
	// 仮の受け皿を用意
	wchar_t *wc = new wchar_t[length + 2];
	// 変換
	mbstowcs_s(&convLength, wc, length + 1, arg_str.c_str(), _TRUNCATE);
	// 返り値へ保存
	std::wstring str(wc);
	// 仮の受け皿を破棄
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
//freeglut300に対応ヘッダ書き換え
//
//18/12/21
//Dlibヘッダ追加
//
//18/05/13
//テンプレート追加
// std::string <--> std::wstring
//
//
//17/11/07
//GLFWやvs2017関係
//
//17/05/28
//少し整形
//
//17/04/17
//VisualStudio用でしかサポートしてないと明記
//MinGW用とかを用意していきたい
//
//16/12/02
//Socket系のインクルードとlib
//
//16/10/17
//OpenCVヘッダーworld.libだけを使うフラグ追加
//
//16/07/27
//conio.hを追加
// _kbhit()でキー入力によるwhileループとか使えるように
// テンプレも追加
//
//16/07/13
//インクルードガード追加
// ifndefで変数"__STDAFX__"を用いる
//fstreamヘッダーの追加
// fopenとかとか
//direct.hやfilesystemヘッダーの追加
// mkdirとかできる
// std::tr2::sys::path etcを使用するために必要
//gl/freeglut.hヘッダーの追加(GL)
//
//16/07/12
//OpenGL glewの読み込むライブラリ指定でDEBUG時の指定が間違っていたのを修正
//
//16/07/01
//文字コードの警告文を消去する#pragma warning(disable: 4819)を追加
// 文字コード警告を消したことによる他の警告文に注意
//テンプレート文追加
// 時間計測するテンプレート
// コンソール上に表示する文字色などを変えるもののテンプレート追加
//
//16/06/22
//Kinect v2 Libraryの追加
//
//16/06/04
//dll化もできるように
//ppl.hを追加
// parallel_forなど並列化
//
//16/04/28
//KinectSDKv2を追加
//
//16/03/14
//説明などを幾つか追加
// 内容は変更なし
//
//16/02/25
//opencv libとstaticlibで整理
// CV2とCV3で明確に読み込むlibを区別
// CV2ではstaticlibとlibの大きな区別なし
//windows.hを追加
// QueryPerformanceCounter()でナノ秒を取得するために
//
//16/02/23
//opencv contribなどの他のライブラリ追加
//libを適当に追加しただけなので通常のlibとcontrib分のlibも混在しているので後で調節必要
//opengl GLEWのlib(Release時の32/64bitの指定)が間違っていたので修正
//glxew.h調べたけど、やっぱりなにかわからなかった...
//
//16/02/16
//#include <sstream>追加
//release note追加
//
//////////
// VS2010:vc10 VS2012:vc11 VS2013:vc12 VS2015:vc14 VS2017:vc15(vc14.1)
//
