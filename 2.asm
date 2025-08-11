.model small
.stack 100h

.data
    msg1 db 'Enter first 3-digit number: $'
    msg2 db 13,10,'Enter second 3-digit number: $'
    msg3 db 13,10,'Sum: $'
    num1 dw ?
    num2 dw ?

.code
main proc
    mov ax, @data
    mov ds, ax

    lea dx, msg1
    mov ah, 9
    int 21h
    call readnum
    mov num1, ax

    lea dx, msg2
    mov ah, 9
    int 21h
    call readnum
    mov num2, ax

    lea dx, msg3
    mov ah, 9
    int 21h

    mov ax, num1
    add ax, num2
    call printnum

    mov ah, 4ch
    int 21h
main endp

readnum proc
    xor ax, ax        
    mov cx, 3

read_digit:
    mov ah, 1         
    int 21h

    cmp al, 13        
    je done_input
    sub al, '0'       
    cmp al, 9
    jae done_input

    mov bl, 10
    mul bl
    add ax, al

    loop read_digit

done_input:
    ret
readnum endp

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