#define _COMMANDLINE_H_
#ifndef COMMANDLINE_H
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "setup.h"
void calculate_factorization(void);  //计算因数分解
void calculate_log(void);   //计算自然对数的底e
void calculate_prime(void);  //计算素数
bool is_prime(int n);  //判断是否为素数
double exp(double x, int y); //计算x的y次方
void calculate_pi(void);  //计算圆周率
void endl(int n);
void _print(const char* str, int ms);  //打印字符串
int  welcome(void);  //欢迎界面
#endif