.model small
.stack 100h

.data
    msg db 'Sum is: $'

.code
main proc
    mov ax, @data
    mov ds, ax

    mov ax, 0

    mov bx, 1
    add ax, bx

    mov bx, 2
    add ax, bx    

    mov bx, 3
    add ax, bx     

    mov bx, 4
    add ax, bx

    lea dx, msg
    mov ah, 9
    int 21h

    call printnum

    mov ah, 4ch
    int 21h
main endp

printnum proc
    push ax
    push bx
    push cx
    push dx

    xor cx, cx
    mov bx, 10

print_loop:
    xor dx, dx
    div bx
    push dx
    inc cx

    test ax, ax
    jnz print_loop

print_digits:
    pop dx
    add dl, '0'
    mov ah, 2
    int 21h
    loop print_digits

    pop dx
    pop cx
    pop bx
    pop ax
    ret

printnum endp
end main