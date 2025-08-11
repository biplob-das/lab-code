.model small
.stack 100h

.data
    msg db 'Enter characters (blank to stop): $'

.code
main proc
    mov ax, @data
    mov ds, ax

    lea dx, msg
    mov ah, 9
    int 21h

read_loop:
    mov ah, 1
    int 21h         
    cmp al, ' '
    je done
    jmp read_loop

done:
    mov ah, 4ch
    int 21h

main endp
end main