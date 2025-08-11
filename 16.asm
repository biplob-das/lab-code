.model small
.stack 100h

.code
main proc
    mov cx, 80

print_loop:
    mov dl, '*'
    mov ah, 2
    int 21h
    loop print_loop

    mov ah, 4ch
    int 21h
main endp
end main