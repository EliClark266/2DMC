#pragma once



#include <cmath>
#include <time.h>
#include <graphics.h>
#include <conio.h>



constexpr auto PI = 3.14159265;						// 圆周率
constexpr auto WIN_WIDTH = 1000;					// 窗口宽
constexpr auto WIN_HEIGHT = 640;					// 窗口高
constexpr auto TITLE_HEIGHT = 100;					// 标题高
constexpr auto BUTTON_HEIGHT = 25;					// 按钮高
constexpr auto BUTTON_SPACING = 60;					// 按钮之间间距
constexpr auto BUTTON_SPACING_WIDTH = 25;			// 按钮中文字周围宽间距
constexpr auto BUTTON_SPACING_HEIGHT = 5;			// 按钮中文字周围高间距
constexpr auto TITLE_ADDR = L"Pictrue\\Title.png";	// 标题图片地址
constexpr auto CLOUD_ADDR = L"Pictrue\\Cloud.png";	// 云图片地址
constexpr auto CREATE_WORLD = L"新建世界";			// 新建世界按钮文字
constexpr auto OPEN_WORLD = L"打开世界";			// 打开世界按钮文字
constexpr auto EXIT_GAME = L"退出游戏";				// 退出游戏按钮文字
constexpr auto GAME_HELP = L"游戏资讯";				// 游戏资讯按钮文字
constexpr auto VERSION_INFO = L"Version 1.0";		// 版本信息