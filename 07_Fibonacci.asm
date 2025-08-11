.model small
.stack 100h
.data
    a dw 0
    b dw 1
    c dw ?
    count dw 10
.code
main:
    mov ax, @data
    mov ds, ax

    mov cx, count
fib_loop:
    mov dx, a
    call print_num

    mov ax, b
    add ax, a
    mov c, ax
    mov a, b
    mov b, c

    loop fib_loop

    mov ah, 4ch
    int 21h

print_num:
    add dl, '0'
    mov ah, 02h
    int 21h
    mov dl, ' '
    int 21h
    ret
end main