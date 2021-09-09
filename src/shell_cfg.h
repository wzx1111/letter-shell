/**
 * @file shell_cfg.h
 * @author Letter (nevermindzzt@gmail.com)
 * @brief shell config
 * @version 3.0.0
 * @date 2019-12-31
 *
 * @copyright (c) 2019 Letter
 *
 */

#ifndef __SHELL_CFG_H__
#define __SHELL_CFG_H__

#include "shell_port.h"

/**
 * @brief 是否使用默认shell任务while循环，使能宏`SHELL_USING_TASK`后此宏有意义
 *        使能此宏，则`shellTask()`函数会一直循环读取输入，一般使用操作系统建立shell
 *        任务时使能此宏，关闭此宏的情况下，一般适用于无操作系统，在主循环中调用`shellTask()`
 */
#ifndef SHELL_TASK_WHILE
#define SHELL_TASK_WHILE 1
#endif

/**
 * @brief 是否使用命令导出方式
 *        使能此宏后，可以使用`SHELL_EXPORT_CMD()`等导出命令
 *        定义shell命令，关闭此宏的情况下，需要使用命令表的方式
 */
#ifndef SHELL_USING_CMD_EXPORT
#define SHELL_USING_CMD_EXPORT 1
#endif
/**
 * @brief 是否使用shell伴生对象
 *        一些扩展的组件(文件系统支持，日志工具等)需要使用伴生对象
 */
#ifndef SHELL_USING_COMPANION
#define SHELL_USING_COMPANION 0
#endif

/**
 * @brief 支持shell尾行模式
 */
#ifndef SHELL_SUPPORT_END_LINE
#define SHELL_SUPPORT_END_LINE 0
#endif

/**
 * @brief 是否在输出命令列表中列出用户
 */
#ifndef SHELL_HELP_LIST_USER
#define SHELL_HELP_LIST_USER 0
#endif

/**
 * @brief 是否在输出命令列表中列出变量
 */
#ifndef SHELL_HELP_LIST_VAR
#define SHELL_HELP_LIST_VAR 0
#endif

/**
 * @brief 是否在输出命令列表中列出按键
 */
#ifndef SHELL_HELP_LIST_KEY
#define SHELL_HELP_LIST_KEY 0
#endif

/**
 * @brief 是否在输出命令列表中展示命令权限
 */
#ifndef SHELL_HELP_SHOW_PERMISSION
#define SHELL_HELP_SHOW_PERMISSION 1
#endif

/**
 * @brief 使用LF作为命令行回车触发
 *        可以和SHELL_ENTER_CR同时开启
 */
#ifndef SHELL_ENTER_LF
#define SHELL_ENTER_LF 1
#endif

/**
 * @brief 使用CR作为命令行回车触发
 *        可以和SHELL_ENTER_LF同时开启
 */
#ifndef SHELL_ENTER_CR
#define SHELL_ENTER_CR 1
#endif

/**
 * @brief 使用CRLF作为命令行回车触发
 *        不可以和SHELL_ENTER_LF或SHELL_ENTER_CR同时开启
 */
#ifndef SHELL_ENTER_CRLF
#define SHELL_ENTER_CRLF 0
#endif

/**
 * @brief 使用执行未导出函数的功能
 *        启用后，可以通过`exec [addr] [args]`直接执行对应地址的函数
 * @attention 如果地址错误，可能会直接引起程序崩溃
 */
#ifndef SHELL_EXEC_UNDEF_FUNC
#define SHELL_EXEC_UNDEF_FUNC 0
#endif

/**
 * @brief shell命令参数最大数量
 *        包含命令名在内，超过16个参数并且使用了参数自动转换的情况下，需要修改源码
 */
#ifndef SHELL_PARAMETER_MAX_NUMBER
#define SHELL_PARAMETER_MAX_NUMBER 8
#endif

/**
 * @brief 历史命令记录数量
 */
#ifndef SHELL_HISTORY_MAX_NUMBER
#define SHELL_HISTORY_MAX_NUMBER 5
#endif

/**
 * @brief 双击间隔(ms)
 *        使能宏`SHELL_LONG_HELP`后此宏生效，定义双击tab补全help的时间间隔
 */
#ifndef SHELL_DOUBLE_CLICK_TIME
#define SHELL_DOUBLE_CLICK_TIME 200
#endif

/**
 * @brief 快速帮助
 *        作用于双击tab的场景，当使能此宏时，双击tab不会对命令进行help补全，而是直接显示对应命令的帮助信息
 */
#ifndef SHELL_QUICK_HELP
#define SHELL_QUICK_HELP 1
#endif

/**
 * @brief 管理的最大shell数量
 */
#ifndef SHELL_MAX_NUMBER
#define SHELL_MAX_NUMBER 5
#endif

/**
 * @brief shell格式化输出的缓冲大小
 *        为0时不使用shell格式化输出
 */
#ifndef SHELL_PRINT_BUFFER
#define SHELL_PRINT_BUFFER 128
#endif

/**
 * @brief shell格式化输入的缓冲大小
 *        为0时不使用shell格式化输入
 * @note shell格式化输入会阻塞shellTask, 仅适用于在有操作系统的情况下使用
 */
#ifndef SHELL_SCAN_BUFFER
#define SHELL_SCAN_BUFFER 0
#endif

/**
 * @brief 获取系统时间(ms)
 *        定义此宏为获取系统Tick，如`HAL_GetTick()`
 * @note 此宏不定义时无法使用双击tab补全命令help，无法使用shell超时锁定
 */
#ifndef SHELL_GET_TICK()
#define SHELL_GET_TICK() 0
#endif

/**
 * @brief 使用锁
 * @note 使用shell锁时，需要对加锁和解锁进行实现
 */
#ifndef SHELL_USING_LOCK
#define SHELL_USING_LOCK 0
#endif

/**
 * @brief shell内存分配
 *        shell本身不需要此接口，若使用shell伴生对象，需要进行定义
 */
#ifndef SHELL_MALLOC
#define SHELL_MALLOC(size) 0
#endif

/**
 * @brief shell内存释放
 *        shell本身不需要此接口，若使用shell伴生对象，需要进行定义
 */
#ifndef SHELL_FREE
#define SHELL_FREE(obj) 0
#endif

/**
 * @brief 是否显示shell信息
 */
#ifndef SHELL_SHOW_INFO
#define SHELL_SHOW_INFO 1
#endif

/**
 * @brief 是否在登录后清除命令行
 */
#ifndef SHELL_CLS_WHEN_LOGIN
#define SHELL_CLS_WHEN_LOGIN 1
#endif

/**
 * @brief shell默认用户
 */
#ifndef SHELL_DEFAULT_USER
#define SHELL_DEFAULT_USER "letter"
#endif

/**
 * @brief shell默认用户密码
 *        若默认用户不需要密码，设为""
 */
#ifndef SHELL_DEFAULT_USER_PASSWORD
#define SHELL_DEFAULT_USER_PASSWORD ""
#endif

/**
 * @brief shell自动锁定超时
 *        shell当前用户密码有效的时候生效，超时后会自动重新锁定shell
 *        设置为0时关闭自动锁定功能，时间单位为`SHELL_GET_TICK()`单位
 * @note 使用超时锁定必须保证`SHELL_GET_TICK()`有效
 */
#ifndef SHELL_LOCK_TIMEOUT
#define SHELL_LOCK_TIMEOUT 0
#endif

#endif
