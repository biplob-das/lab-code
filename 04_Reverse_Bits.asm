.model small
.stack 100h
.data
    num db 0b10110000
.code
main:
    mov ax, @data
    mov ds, ax

    mov cl, 8
    mov al, num
    xor bl, bl

reverse_loop:
    ror al, 1
    rcl bl, 1
    dec cl
    jnz reverse_loop

    mov ah, 4ch
    int 21h
end main