DSEG    SEGMENT 'DATA'
DSEG    ENDS
SSEG    SEGMENT STACK   'STACK'
        DW      100h    DUP(?)
SSEG    ENDS
CSEG    SEGMENT 'CODE'
START   PROC    FAR
; Store return address to OS:
    PUSH    DS
    MOV     AX, 0
    PUSH    AX

; set segment registers:
    MOV     AX, DSEG
    MOV     DS, AX
    MOV     ES, AX

	MOV DX, 2030h	; first Seven Segment Display

continue:
	MOV CX, 2

display: 

	;E
	MOV AL,01111001b
	out dx,al
	
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2030h
                 
                 
    ;F
    MOV AL,01110001b
	out dx,al
	
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2030h
    
    
    ;H
    MOV AL,01110110b
	out dx,al
	
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2030h
    
                 
                 
	LOOP display
	
	JMP continue

; return to operating system:
    RET
START   ENDP

CSEG    ENDS 

END    START    ; set entry point.

