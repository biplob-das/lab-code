.model small
.stack 100h
.code
main:
next:
    mov ah, 01h
    int 21h
    cmp al, ' '
    je endp
    mov dl, al
    mov ah, 02h
    int 21h
    jmp next

endp:
    mov ah, 4ch
    int 21h
end main