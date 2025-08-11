.model small
.stack 100h
.data
    str db 'CAT$', 0
.code
main:
    mov ax, @data
    mov ds, ax

    mov dl, str
    mov ah, 02h
    int 21h

    mov ah, 4ch
    int 21h
end main