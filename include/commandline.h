#define _COMMANDLINE_H_
#ifndef COMMANDLINE_H
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "setup.h"
void calculate_factorization(void);  //���������ֽ�
void calculate_log(void);   //������Ȼ�����ĵ�e
void calculate_prime(void);  //��������
bool is_prime(int n);  //�ж��Ƿ�Ϊ����
double exp(double x, int y); //����x��y�η�
void calculate_pi(void);  //����Բ����
void endl(int n);
void _print(const char* str, int ms);  //��ӡ�ַ���
int  welcome(void);  //��ӭ����
#endif