.model small
.stack 100h
.code
main:
    mov cx, 80
print_loop:
    mov ah, 02h
    mov dl, '*'
    int 21h
    loop print_loop

    mov ah, 4ch
    int 21h
end main