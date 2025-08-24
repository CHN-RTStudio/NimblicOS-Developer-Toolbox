# NimblicOS 完整应用程序开发指南

## 概述

本文档整合了 NimblicOS NGP 和 NEP 应用程序的开发教程以及 API 参考，为开发者提供完整的应用程序开发指导。

## 应用程序类型

NimblicOS 支持两种类型的应用程序：

1. **NEP (Nimblic Executable Program)** - 终端应用程序
2. **NGP (Nimblic Graphic Program)** - 图形应用程序

## 开发环境设置

要开发 NimblicOS 应用程序，您需要：

1. 包含 `appapi.h` 头文件
2. 使用支持的编译器（详情请参考构建系统文档）

## 开发 NEP 应用程序

NEP 应用程序是终端应用程序，主要通过文本方式与用户交互。

### 特点

- 基于文本的用户界面
- 通过标准输入输出与用户交互
- 可以访问文件系统 API
- 可以获取系统信息和时间
- 可以创建和管理进程

### 示例

```c
#include "include/api/appapi.h"

int main() {
    // 获取系统信息
    char info[256];
    app_get_system_info(info);
    printf("System: %s\n", info);
    
    // 文件操作
    int fd = app_open_file("example.txt", "w");
    if (fd >= 0) {
        const char* message = "Hello from NEP!";
        app_write_file(fd, message, strlen(message));
        app_close_file(fd);
    }
    
    return 0;
}
```

## 开发 NGP 应用程序

NGP 应用程序是图形应用程序，可以创建窗口并使用图形API进行绘制。

### 特点

- 可以创建和管理多个窗口
- 可以使用图形 API 绘制图形和文本
- 可以处理鼠标和键盘输入
- 通过消息循环机制处理用户交互

### 示例

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

## 编译和链接

### 链接命令

NGP 应用程序链接命令：
```bash
i686-elf-gcc -m32 -ffreestanding -fno-pie -nostdlib -nostartfiles \
  -I./include -I./include/api \
  -o myapp.ngp myapp.c
```

NEP 应用程序链接命令：
```bash
i686-elf-gcc -m32 -ffreestanding -fno-pie -nostdlib -nostartfiles \
  -I./include -I./include/api \
  -o myapp.nep myapp.c
```

### 构建系统集成

NimblicOS 的 Makefile 已经配置为自动处理 NGP 和 NEP 应用程序的编译和链接。

## 安全注意事项

为了保护系统安全，NimblicOS 采取了以下措施：

1. 应用程序只能通过提供的 API 接口访问系统功能
2. 应用程序无法直接访问系统内存
3. 应用程序无法直接调用系统中断
4. 所有文件操作都受到系统监控

请遵循安全指南，不要尝试绕过这些保护机制。