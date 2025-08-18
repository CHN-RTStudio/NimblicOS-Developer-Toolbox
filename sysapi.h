/* NimblicOS 3.0 系统API头文件 */

#ifndef SYSAPI_H
#define SYSAPI_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// 文件操作相关API
#define FILE_READ   0x01
#define FILE_WRITE  0x02
#define FILE_APPEND 0x04

// 打开文件
int sys_open(const char *filename, uint8_t mode);

// 读取文件
int sys_read(int file_handle, void *buffer, size_t size);

// 写入文件
int sys_write(int file_handle, const void *buffer, size_t size);

// 关闭文件
int sys_close(int file_handle);

// 创建目录
int sys_mkdir(const char *dir_name);

// 切换目录
int sys_cd(const char *dir_name);

// 列出目录内容
int sys_ls(const char *dir_name, char *buffer, size_t buffer_size);

// 屏幕输出相关API
// 清屏
void sys_clear_screen(void);

// 打印字符串
void sys_print_string(const char *str);

// 设置光标位置
void sys_set_cursor(uint8_t x, uint8_t y);

// 键盘输入相关API
// 读取字符
char sys_read_char(void);

// 读取字符串
int sys_read_string(char *buffer, size_t max_length);

// 内存管理相关API
// 分配内存
void *sys_malloc(size_t size);

// 释放内存
void sys_free(void *ptr);

// 系统信息相关API
// 获取系统版本
void sys_get_version(char *buffer, size_t buffer_size);

// 获取当前时间
uint32_t sys_get_time(void);

// 执行.NEP文件
int sys_exec_nep(const char *filename, char **args);

// 第三方程序入口点定义
typedef int (*nep_entry_point)(int argc, char **argv);

#endif // SYSAPI_H