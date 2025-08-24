#ifndef APPIAPI_H
#define APPIAPI_H

// NimblicOS 应用程序开发API头文件
// 本文件为应用程序开发者提供必要的API接口
// 注意：本系统闭源，仅公开开发app需要的文件

// 图形界面相关API
void app_draw_pixel(int x, int y, unsigned int color);
void app_draw_line(int x1, int y1, int x2, int y2, unsigned int color);
void app_draw_rect(int x, int y, int width, int height, unsigned int color);
void app_fill_rect(int x, int y, int width, int height, unsigned int color);
void app_draw_circle(int x, int y, int radius, unsigned int color);
void app_fill_circle(int x, int y, int radius, unsigned int color);
void app_draw_text(int x, int y, const char* text, unsigned int color);

// 窗口管理相关API
int app_create_window(int x, int y, int width, int height, const char* title);
void app_close_window(int window_id);
void app_show_window(int window_id);
void app_hide_window(int window_id);
void app_set_window_title(int window_id, const char* title);

// 输入处理相关API
int app_is_mouse_clicked();
int app_get_mouse_x();
int app_get_mouse_y();
int app_is_key_pressed();
char app_get_pressed_key();

// 文件系统相关API
int app_open_file(const char* filename, const char* mode);
int app_close_file(int file_id);
int app_read_file(int file_id, void* buffer, int size);
int app_write_file(int file_id, const void* buffer, int size);
int app_delete_file(const char* filename);

// 系统信息相关API
unsigned int app_get_system_time();
void app_get_system_info(char* info_buffer);
const char* app_get_kernel_version();

// 消息框API
int app_message_box(const char* title, const char* message, int button_type);

// 控件相关API
void app_draw_button(int window_id, int x, int y, int width, int height, const char* text);
void app_draw_label(int window_id, int x, int y, const char* text);
void app_draw_editbox(int window_id, int x, int y, int width, int height);
void app_draw_progressbar(int window_id, int x, int y, int width, int height, int progress);

// 进程管理相关API
int app_create_process(void (*entry_point)());
void app_exit_process();
void app_yield();

#endif
