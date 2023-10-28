org 0x7c00

start:
    mov ax, cs
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7c00

    ; 读取磁盘扇区
    mov ah, 0x02
    mov al, 0x01
    mov ch, 0x00
    mov cl, 0x02
    mov dh, 0x00
    mov dl, 0x80
    int 0x13

    ; 跳转到操作系统
    jmp 0x0000:0x7e00

    ; 填充剩余的512字节
    times 510-($-$$) db 0
    dw 0xaa55