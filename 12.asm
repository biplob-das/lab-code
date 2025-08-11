.model small
.stack 100h

.data
    msg db 'IBM Characters:',13,10,'$'

.code
main proc
    mov ax, @data
    mov ds, ax

    lea dx, msg
    mov ah, 9
    int 21h

    mov cx, 32         
    mov bl, 0 

display_loop:
    mov ah, 2
    mov dl, bl
    int 21h            

    inc bl
    loop display_loop

    mov ah, 4ch
    int 21h
    
main endp
end main