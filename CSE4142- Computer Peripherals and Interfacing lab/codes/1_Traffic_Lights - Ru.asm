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


	MOV DX, 2070h

MAINLOOP:   
    MOV AL, 01h
	MOV CX, 4                   

LED:                      
	
    OUT DX, AL
	ROL Al, 1 
	
	cmp cx,4
	je D10
	
	cmp cx,3
	je D5
	
	cmp cx,2
	je D15
        
	cmp cx,1
	je D10L
	
	
D5: ;Yellow Light 5sec Delay
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h
    
    LOOP LED  


D10: ;Red Light 10 sec Delay
    mov bx,cx    
    mov CX,0098h
    mov DX,9680h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h
    
    LOOP LED    

   
D15: ;Green Light 15 sec Delay
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    
    
    mov bx,cx    
    mov CX,0098h
    mov DX,9680h
    mov ah,86h
    int 15h

    mov cx,bx
    MOV DX, 2070h
    
    LOOP LED   
    
D10L: ;Red Light 10 sec Delay
    mov bx,cx    
    mov CX,0098h
    mov DX,9680h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h
    
    JMP MAINLOOP    
        
 	

; return to operating system:
	RET
START   ENDP

CSEG    ENDS 

        END    START    