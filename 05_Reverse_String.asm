.model small
.stack 100h
.data
    str db 'HELLO$', 0
.code
main:
    mov ax, @data
    mov ds, ax

    lea si, str
    mov cx, 5
    add si, 4

print_reverse:
    mov dl, [si]
    mov ah, 02h
    int 21h
    dec si
    loop print_reverse

    mov ah, 4ch
    int 21h
end main