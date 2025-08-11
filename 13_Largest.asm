.model small
.stack 100h
.data
    a db 1
    b db 5
    c db 8
.code
main:
    mov ax, @data
    mov ds, ax

    mov al, a
    cmp al, b
    jge next
    mov al, b

next:
    cmp al, c
    jge print
    mov al, c

print:
    add al, '0'
    mov dl, al
    mov ah, 02h
    int 21h

    mov ah, 4ch
    int 21h
end main