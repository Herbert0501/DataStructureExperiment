/***********************************
**版本：0.8
**作者：KaryWhite
***********************************/

#pragma once
#define _CRT_SECURE_NO_WARNINGS 1	/*防止不允许使用scnaf等不安全输入*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <conio.h> /*用了一个_getch函数,获取任意keyboard键*/
#include <assert.h>
#include "MMenu.h"


int main() {
	/*初始化与启动函数*/
	MInitial();

	return 0;
}