.model small
.stack 100h
.data
    msg db 10, 13, 'You entered: $'
.code
main:
    mov ax, @data
    mov ds, ax

    mov ah, 01h
    int 21h
    mov bl, al

    cmp al, 'Y'
    je display

    cmp al, 'y'
    je display

    jmp done

display:  
    lea dx, msg
    mov ah, 9
    int 21h
          
    mov ah, 2
    mov dl, bl
    int 21h

    jmp done

done:
    mov ah, 4Ch
    int 21h

main endp
end main