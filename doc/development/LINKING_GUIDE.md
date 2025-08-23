# NimblicOS 应用程序链接指南

## 概述

本文档介绍如何将 NGP 和 NEP 应用程序链接到 NimblicOS 系统。NimblicOS 使用特定的链接过程来确保应用程序能够在系统上正确运行。

## 链接过程

NimblicOS 应用程序的链接过程与操作系统内核的链接过程不同。应用程序需要链接到系统提供的 API，而不是直接链接到硬件。

## NGP 应用程序链接

NGP (Nimblic Graphic Program) 应用程序是图形应用程序，需要访问图形界面 API。

### 链接命令

```bash
i686-elf-gcc -m32 -ffreestanding -fno-pie -nostdlib -nostartfiles \
  -I./include -I./include/api \
  -o myapp.ngp myapp.c
```

### 链接说明

1. 使用 `-I./include` 和 `-I./include/api` 包含必要的头文件
2. 使用 `-ffreestanding` 和 `-nostdlib` 确保应用程序不依赖标准库
3. 输出文件应具有 `.ngp` 扩展名

## NEP 应用程序链接

NEP (Nimblic Executable Program) 应用程序是终端应用程序，主要通过文本方式与用户交互。

### 链接命令

```bash
i686-elf-gcc -m32 -ffreestanding -fno-pie -nostdlib -nostartfiles \
  -I./include -I./include/api \
  -o myapp.nep myapp.c
```

### 链接说明

1. 使用 `-I./include` 和 `-I./include/api` 包含必要的头文件
2. 使用 `-ffreestanding` 和 `-nostdlib` 确保应用程序不依赖标准库
3. 输出文件应具有 `.nep` 扩展名

### Makefile 规则

```makefile
# 编译NGP应用程序
%.ngp: %.c
	$(CC) $(CFLAGS) -I./include -I./include/api -o $@ $<

# 编译NEP应用程序
%.nep: %.c
	$(CC) $(CFLAGS) -I./include -I./include/api -o $@ $<
```

## 链接时注意事项

1. 应用程序不能直接访问硬件资源
2. 所有系统资源访问必须通过提供的 API 进行
3. 应用程序在链接时不会包含操作系统内核代码
4. 应用程序将在运行时由操作系统加载和执行

## 调试链接问题

如果在链接应用程序时遇到问题，请检查以下几点：

1. 确保正确包含了 `appapi.h` 头文件
2. 检查函数调用是否与 API 参考文档中的声明匹配
3. 确认编译器标志是否正确设置
4. 验证输出文件扩展名是否正确（.ngp 或 .nep）
