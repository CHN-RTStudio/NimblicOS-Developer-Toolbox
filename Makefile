# 第三方程序编译Makefile

# 工具定义
GCC := i686-elf-gcc
LD := i686-elf-ld

# 编译选项
CFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I.
LDFLAGS := -T nep.ld -nostdlib

# 源文件和目标文件
SRCS := hello.c
OBJS := $(SRCS:.c=.o)
TARGET := hello.nep

# 默认目标
all: $(TARGET)

# 编译源文件
%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

# 链接成.NEP文件
$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

# 清理生成文件
clean:
	rm -rf $(OBJS) $(TARGET)

.PHONY: all clean