.model small
.stack 100h
.data
    num1 dw 523
    num2 dw 456
    msg db "Sum = $"

.code
main:
    mov ax, @data
    mov ds, ax

    ; Print message
    mov dx, offset msg
    mov ah, 09h
    int 21h

    ; Add numbers
    mov ax, num1
    sum ax, num2     ;when use sub operation then change here.

    ; Print result
    mov bx, 10
    mov cx, 0
next:
    xor dx, dx
    div bx
    push dx
    inc cx
    cmp ax, 0
    jne next
print:
    pop dx
    add dl, '0'
    mov ah, 02h
    int 21h
    loop print

    ; Exit
    mov ah, 4Ch
    int 21h
end main
