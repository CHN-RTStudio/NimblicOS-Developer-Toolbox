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
- **示例**：
  ```c
  const char* version = app_get_kernel_version();
  app_draw_text(10, 10, version, 0xFFFFFF);
  ```

### app_get_system_time()

- **功能**：获取系统运行时间
- **原型**：`unsigned int app_get_system_time()`
- **参数**：无
- **返回值**：系统运行时间（毫秒）
- **说明**：该函数返回系统自启动以来的运行时间。
- **示例**：
  ```c
  unsigned int uptime = app_get_system_time();
  char time_str[50];
  // 格式化时间字符串
  app_draw_text(10, 30, time_str, 0xFFFFFF);
  ```

### app_get_system_info()

- **功能**：获取系统信息
- **原型**：`void app_get_system_info(char* info_buffer)`
- **参数**：`info_buffer` - 用于存储系统信息的缓冲区
- **返回值**：无
- **说明**：该函数将系统信息存储到提供的缓冲区中。
- **示例**：
  ```c
  char info[256];
  app_get_system_info(info);
  app_draw_text(10, 50, info, 0xFFFFFF);
  ```

### app_message_box()

- **功能**：显示消息框
- **原型**：`int app_message_box(const char* title, const char* message, int button_type)`
- **参数**：
  - `title` - 消息框标题
  - `message` - 消息内容
  - `button_type` - 按钮类型（1-确定，2-确定和取消，3-重试和取消，4-重试、忽略和取消，5-重试和忽略）
- **返回值**：用户按下的按钮序号（例如按钮类型4时，按下重试返回1，忽略返回2，取消返回3）
- **说明**：该函数显示一个消息框，等待用户按下按钮后返回按钮序号。
- **示例**：
  ```c
  int result = app_message_box("提示", "确定要删除文件吗？", 2);
  if (result == 1) {
      // 用户点击了确定
      app_delete_file("test.txt");
  }
  ```

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
- **示例**：
  ```c
  int window_id = app_create_window(100, 100, 400, 300, "我的应用");
  if (window_id >= 0) {
      app_show_window(window_id);
  }
  ```

### app_close_window()

- **功能**：关闭窗口
- **原型**：`void app_close_window(int window_id)`
- **参数**：`window_id` - 要关闭的窗口ID
- **返回值**：无
- **说明**：该函数关闭指定的窗口。
- **示例**：
  ```c
  // 关闭窗口
  app_close_window(window_id);
  ```

### app_show_window()

- **功能**：显示窗口
- **原型**：`void app_show_window(int window_id)`
- **参数**：`window_id` - 要显示的窗口ID
- **返回值**：无
- **说明**：该函数显示指定的窗口。
- **示例**：
  ```c
  // 创建窗口后显示它
  int window_id = app_create_window(100, 100, 400, 300, "我的应用");
  app_show_window(window_id);
  ```

### app_hide_window()

- **功能**：隐藏窗口
- **原型**：`void app_hide_window(int window_id)`
- **参数**：`window_id` - 要隐藏的窗口ID
- **返回值**：无
- **说明**：该函数隐藏指定的窗口。
- **示例**：
  ```c
  // 隐藏窗口
  app_hide_window(window_id);
  // 一段时间后重新显示
  app_show_window(window_id);
  ```

### app_set_window_title()

- **功能**：设置窗口标题
- **原型**：`void app_set_window_title(int window_id, const char* title)`
- **参数**：
  - `window_id` - 窗口ID
  - `title` - 新的窗口标题
- **返回值**：无
- **说明**：该函数设置指定窗口的标题。
- **示例**：
  ```c
  // 创建窗口
  int window_id = app_create_window(100, 100, 400, 300, "旧标题");
  // 更改窗口标题
  app_set_window_title(window_id, "新标题");
  ```

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
- **示例**：
  ```c
  // 绘制一个红色像素点
  app_draw_pixel(100, 100, 0xFF0000);
  ```

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
- **示例**：
  ```c
  // 绘制一条蓝色直线
  app_draw_line(50, 50, 150, 150, 0x0000FF);
  ```

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
- **示例**：
  ```c
  // 绘制一个绿色矩形边框
  app_draw_rect(100, 100, 200, 150, 0x00FF00);
  ```

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
- **示例**：
  ```c
  // 填充一个红色矩形
  app_fill_rect(100, 100, 200, 150, 0xFF0000);
  ```

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
- **示例**：
  ```c
  // 绘制一个蓝色圆形边框
  app_draw_circle(200, 200, 50, 0x0000FF);
  ```

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
- **示例**：
  ```c
  // 填充一个绿色圆形
  app_fill_circle(200, 200, 50, 0x00FF00);
  ```

### app_draw_text()

- **功能**：绘制文本
- **原型**：`void app_draw_text(int x, int y, const char* text, unsigned int color)`
- **参数**：
  - `x` - 文本起始X坐标
  - `y` - 文本起始Y坐标
  - `text` - 要绘制的文本字符串
  - `color` - 文本颜色（RGB格式）
- **返回值**：无
- **说明**：该函数在指定位置绘制文本。
- **示例**：
  ```c
  // 在位置(100, 100)绘制白色文本
  app_draw_text(100, 100, "Hello, World!", 0xFFFFFF);
  ```

### app_draw_button()

- **功能**：绘制按钮控件
- **原型**：`void app_draw_button(int window_id, int x, int y, int width, int height, const char* text)`
- **参数**：
  - `window_id` - 窗口ID
  - `x` - 按钮左上角X坐标
  - `y` - 按钮左上角Y坐标
  - `width` - 按钮宽度
  - `height` - 按钮高度
  - `text` - 按钮上显示的文本
- **返回值**：无
- **说明**：该函数在指定窗口中绘制一个按钮控件。
- **示例**：
  ```c
  // 在窗口中绘制一个按钮
  app_draw_button(window_id, 50, 50, 100, 30, "点击我");
  ```

### app_draw_label()

- **功能**：绘制标签控件
- **原型**：`void app_draw_label(int window_id, int x, int y, const char* text)`
- **参数**：
  - `window_id` - 窗口ID
  - `x` - 标签起始X坐标
  - `y` - 标签起始Y坐标
  - `text` - 标签文本
- **返回值**：无
- **说明**：该函数在指定窗口中绘制一个标签控件。
- **示例**：
  ```c
  // 在窗口中绘制一个标签
  app_draw_label(window_id, 50, 100, "这是一个标签");
  ```

### app_draw_editbox()

- **功能**：绘制编辑框控件
- **原型**：`void app_draw_editbox(int window_id, int x, int y, int width, int height, const char* text)`
- **参数**：
  - `window_id` - 窗口ID
  - `x` - 编辑框左上角X坐标
  - `y` - 编辑框左上角Y坐标
  - `width` - 编辑框宽度
  - `height` - 编辑框高度
  - `text` - 编辑框中显示的文本
- **返回值**：无
- **说明**：该函数在指定窗口中绘制一个编辑框控件。
- **示例**：
  ```c
  // 在窗口中绘制一个编辑框
  app_draw_editbox(window_id, 50, 150, 200, 30, "请输入文本");
  ```

### app_draw_progressbar()

- **功能**：绘制进度条控件
- **原型**：`void app_draw_progressbar(int window_id, int x, int y, int width, int height, int progress)`
- **参数**：
  - `window_id` - 窗口ID
  - `x` - 进度条左上角X坐标
  - `y` - 进度条左上角Y坐标
  - `width` - 进度条宽度
  - `height` - 进度条高度
  - `progress` - 进度值（0-100）
- **返回值**：无
- **说明**：该函数在指定窗口中绘制一个进度条控件。
- **示例**：
  ```c
  // 在窗口中绘制一个进度条，进度为50%
  app_draw_progressbar(window_id, 50, 200, 200, 20, 50);
  ```

## 输入处理相关API

### app_is_mouse_clicked()

- **功能**：检查鼠标是否被点击
- **原型**：`int app_is_mouse_clicked()`
- **参数**：无
- **返回值**：如果鼠标被点击则返回1，否则返回0
- **说明**：该函数检查鼠标是否被点击。
- **示例**：
  ```c
  // 检查鼠标是否被点击
  if (app_is_mouse_clicked()) {
      // 处理鼠标点击事件
  }
  ```

### app_get_mouse_x()

- **功能**：获取鼠标X坐标
- **原型**：`int app_get_mouse_x()`
- **参数**：无
- **返回值**：鼠标当前X坐标
- **说明**：该函数返回鼠标当前的X坐标。
- **示例**：
  ```c
  // 获取鼠标X坐标
  int mouse_x = app_get_mouse_x();
  ```

### app_get_mouse_y()

- **功能**：获取鼠标Y坐标
- **原型**：`int app_get_mouse_y()`
- **参数**：无
- **返回值**：鼠标当前Y坐标
- **说明**：该函数返回鼠标当前的Y坐标。
- **示例**：
  ```c
  // 获取鼠标Y坐标
  int mouse_y = app_get_mouse_y();
  ```

### app_is_key_pressed()

- **功能**：检查键盘按键是否被按下
- **原型**：`int app_is_key_pressed(int key_code)`
- **参数**：
  - `key_code` - 按键码
- **返回值**：如果指定按键被按下返回1，否则返回0
- **说明**：该函数用于检测指定的键盘按键是否被按下。
- **示例**：
  ```c
  // 检查空格键是否被按下
  if (app_is_key_pressed(32)) {
      // 处理空格键按下事件
  }
  ```

### app_get_pressed_key()

- **功能**：获取被按下的按键
- **原型**：`int app_get_pressed_key()`
- **参数**：无
- **返回值**：被按下的按键码，如果没有按键被按下则返回0
- **说明**：该函数返回当前被按下的按键码。
- **示例**：
  ```c
  // 获取被按下的按键
  int key = app_get_pressed_key();
  if (key != 0) {
      // 处理按键事件
  }
  ```

## 文件系统相关API

### app_open_file()

- **功能**：打开文件
- **原型**：`int app_open_file(const char* filename, const char* mode)`
- **参数**：
  - `filename` - 文件名
  - `mode` - 打开模式（"r"读取，"w"写入，"a"追加）
- **返回值**：文件描述符，如果打开失败则返回负数
- **说明**：该函数打开指定的文件并返回文件描述符。
- **示例**：
  ```c
  // 以只读模式打开文件
  int fd = app_open_file("example.txt", "r");
  if (fd >= 0) {
      // 文件打开成功，可以进行读取操作
  } else {
      // 文件打开失败
  }
  ```

### app_close_file()

- **功能**：关闭文件
- **原型**：`int app_close_file(int file_id)`
- **参数**：`file_id` - 文件描述符
- **返回值**：如果成功关闭则返回0，否则返回负数
- **说明**：该函数关闭指定的文件。
- **示例**：
  ```c
  // 关闭文件
  int result = app_close_file(fd);
  if (result == 0) {
      // 文件关闭成功
  } else {
      // 文件关闭失败
  }
  ```

### app_read_file()

- **功能**：读取文件
- **原型**：`int app_read_file(int file_id, void* buffer, int size)`
- **参数**：
  - `file_id` - 文件描述符
  - `buffer` - 用于存储读取数据的缓冲区
  - `size` - 要读取的字节数
- **返回值**：实际读取的字节数，如果读取失败则返回负数
- **说明**：该函数从指定文件中读取数据。
- **示例**：
  ```c
  // 读取文件内容
  char buffer[256];
  int bytes_read = app_read_file(fd, buffer, sizeof(buffer) - 1);
  if (bytes_read > 0) {
      // 成功读取数据
      buffer[bytes_read] = '\0';  // 添加字符串结束符
  } else {
      // 读取失败
  }
  ```

### app_write_file()

- **功能**：写入文件
- **原型**：`int app_write_file(int file_id, const void* buffer, int size)`
- **参数**：
  - `file_id` - 文件描述符
  - `buffer` - 要写入的数据缓冲区
  - `size` - 要写入的字节数
- **返回值**：实际写入的字节数，如果写入失败则返回负数
- **说明**：该函数向指定文件中写入数据。
- **示例**：
  ```c
  // 写入文件内容
  const char* text = "Hello, World!";
  int bytes_written = app_write_file(fd, text, strlen(text));
  if (bytes_written > 0) {
      // 成功写入数据
  } else {
      // 写入失败
  }
  ```

### app_delete_file()

- **功能**：删除文件
- **原型**：`int app_delete_file(const char* filename)`
- **参数**：`filename` - 要删除的文件名
- **返回值**：如果成功删除则返回0，否则返回负数
- **说明**：该函数删除指定的文件。
- **示例**：
  ```c
  // 删除文件
  int result = app_delete_file("example.txt");
  if (result == 0) {
      // 文件删除成功
  } else {
      // 文件删除失败
  }
  ```

## 进程管理相关API

### app_create_process()

- **功能**：创建新进程
- **原型**：`int app_create_process(const char* command)`
- **参数**：
  - `command` - 要执行的命令
- **返回值**：进程ID，如果创建失败则返回-1
- **说明**：该函数用于创建并启动一个新的进程。
- **示例**：
  ```c
  // 创建新进程
  int pid = app_create_process("notepad");
  if (pid != -1) {
      // 进程创建成功
  } else {
      // 进程创建失败
  }
  ```

### app_exit_process()

- **功能**：退出当前进程
- **原型**：`void app_exit_process()`
- **参数**：无
- **返回值**：无
- **说明**：该函数用于退出当前进程。
- **示例**：
  ```c
  // 退出当前进程
  app_exit_process();
  ```

### app_yield()

- **功能**：让出CPU时间片
- **原型**：`void app_yield()`
- **参数**：无
- **返回值**：无
- **说明**：该函数用于让出当前进程的CPU时间片，允许其他进程运行。
- **示例**：
  ```c
  // 在循环中让出CPU时间片
  while (1) {
      // 执行一些操作
      app_yield();  // 让出CPU时间片
  }
  ```
