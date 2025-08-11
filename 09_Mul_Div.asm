.model small
.stack 100h
.data
    num1 dw 25
    num2 dw 10
.code
main:
    mov ax, @data
    mov ds, ax

    mov ax, num1
    mul num2

    mov ax, num1
    div num2

    mov ah, 4ch
    int 21h
end main