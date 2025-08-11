.model small
.stack 100h
.data
    num db 5
.code
main:
    mov ax, @data
    mov ds, ax

    mov al, num
    test al, 1
    jz even

    mov dl, 'O'
    jmp print
even:
    mov dl, 'E'

print:
    mov ah, 02h
    int 21h

    mov ah, 4ch
    int 21h
end main