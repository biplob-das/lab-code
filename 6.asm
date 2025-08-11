.model small
.stack 100h
.data
    msg1 db 'Enter first number: $'
    msg2 db 10, 13, 'Enter second number: $'
    msg3 db 10, 13, 'Using stack the reverse is: $'
.code
main proc
    mov ax, @data
    mov ds, ax

    mov ah, 9
    lea dx, msg1
    int 21h

    mov ah, 1
    int 21h
    push ax

    mov ah, 9
    lea dx, msg2
    int 21h

    mov ah, 1
    int 21h
    push ax

    mov ah, 9
    lea dx, msg3
    int 21h

    pop ax
    mov ah, 2
    mov dl, al
    int 21h

    pop ax
    mov ah, 2
    mov dl, al
    int 21h

exit:
    mov ah, 4ch
    int 21h

main endp
end main