.model small
.stack 100h
.data
    sum dw 0
    msg db 'Sum = $'
.code
main:
    mov ax, @data
    mov ds, ax

    mov cx, 4       ; count 4 numbers
    xor bx, bx      ; sum = 0
    mov ax, 0       ; counter

sum_loop:
    inc ax          ; ax = ax + 1
    add bx, ax      ; sum += ax
    loop sum_loop

    mov sum, bx     ; store sum

    ; print message
    lea dx, msg
    mov ah, 9
    int 21h

    mov ax, sum
    call printnum

    mov ah, 4Ch     ; exit
    int 21h

; printnum: print AX as decimal
printnum proc
    push ax
    push bx
    push cx
    push dx

    mov cx, 0
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
