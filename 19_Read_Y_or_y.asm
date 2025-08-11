.model small
.stack 100h
.code
main:
    mov ah, 01h
    int 21h
    cmp al, 'Y'
    je display
    cmp al, 'y'
    jne exit

display:
    mov dl, al
    mov ah, 02h
    int 21h

exit:
    mov ah, 4ch
    int 21h
end main