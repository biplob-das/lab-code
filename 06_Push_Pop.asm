.model small
.stack 100h
.code
main:
    mov ax, 1234h
    push ax
    mov ax, 0
    pop ax

    mov ah, 4ch
    int 21h
end main