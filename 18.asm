.model small
.stack 100h
.data
    msg db 10, 13, 'Sorted letters: $'
.code
main:
    mov ax, @data
    mov ds, ax

    mov ah, 01h
    int 21h
    mov bl, al

    mov ah, 01h
    int 21h
    mov bh, al

    cmp bl, bh
    jbe print_bl_bh

print_bh_bl:
    lea dx, msg
    mov ah, 09h
    int 21h

    mov dl, bh
    mov ah, 02h
    int 21h

    mov dl, ' '
    int 21h

    mov dl, bl
    int 21h

    jmp done

print_bl_bh:
    lea dx, msg
    mov ah, 09h
    int 21h

    mov dl, bl
    mov ah, 02h
    int 21h

    mov dl, ' '
    int 21h

    mov dl, bh
    int 21h

done:
    mov ah, 4Ch
    int 21h

main endp
end main