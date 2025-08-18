/* NimblicOS 3.0 .NEP文件链接器脚本 */

ENTRY(nep_main)

SECTIONS {
    /* .NEP文件从0x200000地址开始加载 */
    . = 0x200000;

    /* 文本段 - 代码 */
    .text : {
        *(.text)
    }

    /* 只读数据段 */
    .rodata : {
        *(.rodata)
    }

    /* 数据段 */
    .data : {
        *(.data)
    }

    /* 未初始化数据段 */
    .bss : {
        *(.bss)
    }

    /* 确保.NEP文件大小适中 */
    /DISCARD/ : {
        *(.note*)
        *(.comment)
    }
}