.model small
.stack 100h
.code
main:
    mov ah, 02h
    mov dl, 219
    int 21h

    mov ah, 4ch
    int 21h
end main