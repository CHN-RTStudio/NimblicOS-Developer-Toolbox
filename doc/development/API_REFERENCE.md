# NimblicOS API 参考文档

## 概述

本文档详细介绍了 NimblicOS 提供的所有 API 接口，供应用程序开发者使用。

## 系统信息相关API

### app_get_kernel_version()

- **功能**：获取内核版本信息
- **原型**：`const char* app_get_kernel_version()`
- **参数**：无
- **返回值**：指向内核版本字符串的指针，格式为"Kai系统内核版本"例如"Kai0.4.0"
- **说明**：该函数返回当前 NimblicOS 系统的内核版本信息。

### app_get_system_time()

- **功能**：获取系统运行时间
- **原型**：`unsigned int app_get_system_time()`
- **参数**：无
- **返回值**：系统运行时间（毫秒）
- **说明**：该函数返回系统自启动以来的运行时间。

### app_get_system_info()

- **功能**：获取系统信息
- **原型**：`void app_get_system_info(char* info_buffer)`
- **参数**：`info_buffer` - 用于存储系统信息的缓冲区
- **返回值**：无
- **说明**：该函数将系统信息存储到提供的缓冲区中。

## 窗口管理相关API

### app_create_window()

- **功能**：创建窗口
- **原型**：`int app_create_window(int x, int y, int width, int height, const char* title)`
- **参数**：
  - `x` - 窗口左上角X坐标
  - `y` - 窗口左上角Y坐标
  - `width` - 窗口宽度
  - `height` - 窗口高度
  - `title` - 窗口标题
- **返回值**：窗口ID，如果创建失败则返回负数
- **说明**：该函数创建一个新的窗口并返回其ID。

### app_close_window()

- **功能**：关闭窗口
- **原型**：`void app_close_window(int window_id)`
- **参数**：`window_id` - 要关闭的窗口ID
- **返回值**：无
- **说明**：该函数关闭指定的窗口。

### app_show_window()

- **功能**：显示窗口
- **原型**：`void app_show_window(int window_id)`
- **参数**：`window_id` - 要显示的窗口ID
- **返回值**：无
- **说明**：该函数显示指定的窗口。

### app_hide_window()

- **功能**：隐藏窗口
- **原型**：`void app_hide_window(int window_id)`
- **参数**：`window_id` - 要隐藏的窗口ID
- **返回值**：无
- **说明**：该函数隐藏指定的窗口。

### app_set_window_title()

- **功能**：设置窗口标题
- **原型**：`void app_set_window_title(int window_id, const char* title)`
- **参数**：
  - `window_id` - 窗口ID
  - `title` - 新的窗口标题
- **返回值**：无
- **说明**：该函数设置指定窗口的标题。

## 图形界面相关API

### app_draw_pixel()

- **功能**：绘制像素
- **原型**：`void app_draw_pixel(int x, int y, unsigned int color)`
- **参数**：
  - `x` - 像素X坐标
  - `y` - 像素Y坐标
  - `color` - 像素颜色（RGB格式）
- **返回值**：无
- **说明**：该函数在指定位置绘制一个像素。

### app_draw_line()

- **功能**：绘制直线
- **原型**：`void app_draw_line(int x1, int y1, int x2, int y2, unsigned int color)`
- **参数**：
  - `x1` - 起点X坐标
  - `y1` - 起点Y坐标
  - `x2` - 终点X坐标
  - `y2` - 终点Y坐标
  - `color` - 直线颜色（RGB格式）
- **返回值**：无
- **说明**：该函数绘制一条直线。

### app_draw_rect()

- **功能**：绘制矩形边框
- **原型**：`void app_draw_rect(int x, int y, int width, int height, unsigned int color)`
- **参数**：
  - `x` - 矩形左上角X坐标
  - `y` - 矩形左上角Y坐标
  - `width` - 矩形宽度
  - `height` - 矩形高度
  - `color` - 矩形边框颜色（RGB格式）
- **返回值**：无
- **说明**：该函数绘制一个矩形的边框。

### app_fill_rect()

- **功能**：填充矩形
- **原型**：`void app_fill_rect(int x, int y, int width, int height, unsigned int color)`
- **参数**：
  - `x` - 矩形左上角X坐标
  - `y` - 矩形左上角Y坐标
  - `width` - 矩形宽度
  - `height` - 矩形高度
  - `color` - 填充颜色（RGB格式）
- **返回值**：无
- **说明**：该函数填充一个矩形区域。

### app_draw_circle()

- **功能**：绘制圆形边框
- **原型**：`void app_draw_circle(int x, int y, int radius, unsigned int color)`
- **参数**：
  - `x` - 圆心X坐标
  - `y` - 圆心Y坐标
  - `radius` - 圆半径
  - `color` - 圆形边框颜色（RGB格式）
- **返回值**：无
- **说明**：该函数绘制一个圆形的边框。

### app_fill_circle()

- **功能**：填充圆形
- **原型**：`void app_fill_circle(int x, int y, int radius, unsigned int color)`
- **参数**：
  - `x` - 圆心X坐标
  - `y` - 圆心Y坐标
  - `radius` - 圆半径
  - `color` - 填充颜色（RGB格式）
- **返回值**：无
- **说明**：该函数填充一个圆形区域。

### app_draw_text()

- **功能**：绘制文本
- **原型**：`void app_draw_text(int x, int y, const char* text, unsigned int color)`
- **参数**：
  - `x` - 文本起始X坐标
  - `y` - 文本起始Y坐标
  - `text` - 要绘制的文本
  - `color` - 文本颜色（RGB格式）
- **返回值**：无
- **说明**：该函数在指定位置绘制文本。

## 输入处理相关API

### app_is_mouse_clicked()

- **功能**：检查鼠标是否被点击
- **原型**：`int app_is_mouse_clicked()`
- **参数**：无
- **返回值**：如果鼠标被点击则返回1，否则返回0
- **说明**：该函数检查鼠标是否被点击。

### app_get_mouse_x()

- **功能**：获取鼠标X坐标
- **原型**：`int app_get_mouse_x()`
- **参数**：无
- **返回值**：鼠标当前X坐标
- **说明**：该函数返回鼠标当前的X坐标。

### app_get_mouse_y()

- **功能**：获取鼠标Y坐标
- **原型**：`int app_get_mouse_y()`
- **参数**：无
- **返回值**：鼠标当前Y坐标
- **说明**：该函数返回鼠标当前的Y坐标。

### app_is_key_pressed()

- **功能**：检查是否有按键被按下
- **原型**：`int app_is_key_pressed()`
- **参数**：无
- **返回值**：如果有按键被按下则返回1，否则返回0
- **说明**：该函数检查是否有按键被按下。

### app_get_pressed_key()

- **功能**：获取被按下的键值
- **原型**：`char app_get_pressed_key()`
- **参数**：无
- **返回值**：被按下的键值
- **说明**：该函数返回被按下的键值。

## 文件系统相关API

### app_open_file()

- **功能**：打开文件
- **原型**：`int app_open_file(const char* filename, const char* mode)`
- **参数**：
  - `filename` - 文件名
  - `mode` - 打开模式（"r"读取，"w"写入，"a"追加）
- **返回值**：文件描述符，如果打开失败则返回负数
- **说明**：该函数打开指定的文件并返回文件描述符。

### app_close_file()

- **功能**：关闭文件
- **原型**：`int app_close_file(int file_id)`
- **参数**：`file_id` - 文件描述符
- **返回值**：如果成功关闭则返回0，否则返回负数
- **说明**：该函数关闭指定的文件。

### app_read_file()

- **功能**：读取文件
- **原型**：`int app_read_file(int file_id, void* buffer, int size)`
- **参数**：
  - `file_id` - 文件描述符
  - `buffer` - 用于存储读取数据的缓冲区
  - `size` - 要读取的字节数
- **返回值**：实际读取的字节数，如果读取失败则返回负数
- **说明**：该函数从指定文件中读取数据。

### app_write_file()

- **功能**：写入文件
- **原型**：`int app_write_file(int file_id, const void* buffer, int size)`
- **参数**：
  - `file_id` - 文件描述符
  - `buffer` - 要写入的数据缓冲区
  - `size` - 要写入的字节数
- **返回值**：实际写入的字节数，如果写入失败则返回负数
- **说明**：该函数向指定文件中写入数据。

### app_delete_file()

- **功能**：删除文件
- **原型**：`int app_delete_file(const char* filename)`
- **参数**：`filename` - 要删除的文件名
- **返回值**：如果成功删除则返回0，否则返回负数
- **说明**：该函数删除指定的文件。

## 进程管理相关API

### app_create_process()

- **功能**：创建进程
- **原型**：`int app_create_process(void (*entry_point)())`
- **参数**：`entry_point` - 进程入口函数指针
- **返回值**：进程ID，如果创建失败则返回负数
- **说明**：该函数创建一个新的进程并返回其ID。

### app_exit_process()

- **功能**：退出进程
- **原型**：`void app_exit_process()`
- **参数**：无
- **返回值**：无
- **说明**：该函数退出当前进程。

### app_yield()

- **功能**：让出CPU控制权
- **原型**：`void app_yield()`
- **参数**：无
- **返回值**：无
- **说明**：该函数让出CPU控制权，以便其他进程可以运行。