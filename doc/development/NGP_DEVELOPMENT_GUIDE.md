# NimblicOS NGP (Nimblic Graphic Program) 开发指南

## 概述

本文档专门介绍如何为 NimblicOS 开发 NGP (Nimblic Graphic Program) 图形应用程序。NGP 应用程序是具有图形用户界面的应用程序，可以创建窗口并使用图形 API 进行绘制。

## 开发环境设置

要开发 NimblicOS NGP 应用程序，您需要：

1. 包含 `appapi.h` 头文件
2. 使用支持的编译器（详情请参考构建系统文档）

## NGP 应用程序特点

- 可以创建和管理多个窗口
- 可以使用图形 API 绘制图形和文本
- 可以处理鼠标和键盘输入
- 通过消息循环机制处理用户交互

## 核心 API

NGP 应用程序主要使用以下 API 类别：

### 窗口管理 API

- `int app_create_window(int x, int y, int width, int height, const char* title)` - 创建窗口
- `void app_close_window(int window_id)` - 关闭窗口
- `void app_show_window(int window_id)` - 显示窗口
- `void app_hide_window(int window_id)` - 隐藏窗口
- `void app_set_window_title(int window_id, const char* title)` - 设置窗口标题

### 图形界面 API

- `void app_draw_pixel(int x, int y, unsigned int color)` - 绘制像素
- `void app_draw_line(int x1, int y1, int x2, int y2, unsigned int color)` - 绘制直线
- `void app_draw_rect(int x, int y, int width, int height, unsigned int color)` - 绘制矩形边框
- `void app_fill_rect(int x, int y, int width, int height, unsigned int color)` - 填充矩形
- `void app_draw_circle(int x, int y, int radius, unsigned int color)` - 绘制圆形边框
- `void app_fill_circle(int x, int y, int radius, unsigned int color)` - 填充圆形
- `void app_draw_text(int x, int y, const char* text, unsigned int color)` - 绘制文本

### 输入处理 API

- `int app_is_mouse_clicked()` - 检查鼠标是否被点击
- `int app_get_mouse_x()` - 获取鼠标X坐标
- `int app_get_mouse_y()` - 获取鼠标Y坐标
- `int app_is_key_pressed()` - 检查是否有按键被按下
- `char app_get_pressed_key()` - 获取被按下的键值

## NGP 应用程序结构

NGP 应用程序通常具有以下结构：

1. 创建一个或多个窗口
2. 在窗口中绘制用户界面元素
3. 进入消息循环处理用户输入
4. 根据用户输入更新界面

## 开发示例

以下是一个简单的 NGP 应用程序示例：

```c
#include "include/api/appapi.h"

void draw_ui() {
    // 绘制背景
    app_fill_rect(0, 0, 400, 300, 0xCCCCCC);
    
    // 绘制按钮
    app_fill_rect(50, 50, 100, 30, 0x007ACC);
    app_draw_text(60, 60, "Click Me", 0xFFFFFF);
}

int main() {
    // 创建窗口
    int window = app_create_window(100, 100, 400, 300, "My NGP App");
    app_show_window(window);
    
    // 主循环
    while (1) {
        // 绘制界面
        draw_ui();
        
        // 处理输入
        if (app_is_mouse_clicked()) {
            int x = app_get_mouse_x();
            int y = app_get_mouse_y();
            
            // 检查按钮点击
            if (x >= 50 && x <= 150 && y >= 50 && y <= 80) {
                printf("Button clicked!\n");
            }
        }
        
        // 让出CPU
        app_yield();
    }
    
    return 0;
}
```

## 最佳实践

1. 在主循环中使用 `app_yield()` 让出 CPU 控制权，以便其他进程可以运行
2. 合理组织代码结构，将界面绘制和逻辑处理分离
3. 正确处理窗口关闭事件
4. 注意内存管理，及时释放不再使用的资源
