# NimblicOS 第三方程序开发指南

## 什么是.NEP文件?

.NEP文件是NimblicOS系统中的第三方程序文件格式，可以通过系统API与操作系统交互。这些程序可以使用系统提供的各种功能，如文件操作、屏幕输出、键盘输入等。

## 开发环境要求

1. NimblicOS 0.3 或更高版本
2. i686-elf-gcc 工具链
3. 文本编辑器

## 编写第三方程序

### 示例程序

下面是一个简单的.NEP程序示例 `hello.c`：

```c
/* NimblicOS 第三方程序示例 - hello.nep */

#include "kernel/sysapi.h"

// 程序入口点
int main(int argc, char **argv) {
    // 清屏
    sys_clear_screen();

    // 显示欢迎信息
    sys_print_string("Hello, NimblicOS!\n\n");
    sys_print_string("This is a third-party program (.NEP)\n");
    sys_print_string("Using system API:\n");

    // 显示系统版本
    char version[128];
    sys_get_version(version, sizeof(version));
    sys_print_string("System version: ");
    sys_print_string(version);
    sys_print_string("\n");

    // 获取当前时间
    uint32_t time = sys_get_time();
    sys_print_string("Current system time: ");
    char time_str[20];
    // 简单整数转字符串
    int i = 0;
    uint32_t temp = time;
    do {
        time_str[i++] = '0' + (temp % 10);
        temp /= 10;
    } while (temp > 0);
    time_str[i] = '\0';
    // 反转字符串
    for (int j = 0; j < i / 2; j++) {
        char c = time_str[j];
        time_str[j] = time_str[i - j - 1];
        time_str[i - j - 1] = c;
    }
    sys_print_string(time_str);
    sys_print_string("\n\n");

    sys_print_string("Press any key to exit...\n");
    sys_read_char();

    return 0;
}

// 程序入口点包装器
int nep_main(int argc, char **argv) {
    return main(argc, argv);
}
```

### 系统API参考

系统提供以下几类API：

1. **文件操作API**：
   - `sys_open`: 打开文件
   - `sys_read`: 读取文件
   - `sys_write`: 写入文件
   - `sys_close`: 关闭文件
   - `sys_mkdir`: 创建目录
   - `sys_cd`: 切换目录
   - `sys_ls`: 列出目录内容

2. **屏幕输出API**：
   - `sys_clear_screen`: 清屏
   - `sys_print_string`: 打印字符串
   - `sys_set_cursor`: 设置光标位置

3. **键盘输入API**：
   - `sys_read_char`: 读取字符
   - `sys_read_string`: 读取字符串

4. **内存管理API**：
   - `sys_malloc`: 分配内存
   - `sys_free`: 释放内存

5. **系统信息API**：
   - `sys_get_version`: 获取系统版本
   - `sys_get_time`: 获取当前时间
   - `sys_exec_nep`: 执行.NEP文件

## 编译第三方程序

使用提供的 `Makefile.nep` 和 `nep.ld` 文件编译你的程序：

```bash
make -f Makefile.nep
```

这将生成一个 `.nep` 文件，例如 `hello.nep`。

## 运行第三方程序

在NimblicOS的shell中，只需输入.NEP文件的名称（不带扩展名）即可运行：

```
NimblicOS> hello
```

系统将尝试执行 `hello.nep` 文件。

## 注意事项

1. .NEP程序的入口点必须是 `nep_main` 函数
2. 程序运行完毕后会自动释放内存
3. 当前系统限制.NEP文件大小最大为64KB
4. 编写程序时请包含 `kernel/sysapi.h` 头文件

## 示例程序编译和运行流程

1. 编写 `hello.c` 程序
2. 使用 `make -f Makefile.nep` 编译程序
3. 在NimblicOS shell中输入 `hello` 运行程序

## 高级功能

未来版本将支持更多高级功能，如多线程、图形界面、网络通信等。

## 故障排除

1. 如果程序无法运行，检查是否正确包含了 `kernel/sysapi.h` 头文件
2. 确保.NEP文件位于当前工作目录
3. 检查文件权限和大小限制
4. 确认使用了正确的编译工具链

希望这个指南能帮助你开发NimblicOS的第三方程序！如果你有任何问题或建议，请联系我们。
rtstudio@zohomail.cn