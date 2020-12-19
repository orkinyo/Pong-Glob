include data.inc
include     \masm32\include\windows.inc
include     \masm32\include\kernel32.inc
include     \masm32\include\user32.inc
includelib  \masm32\lib\kernel32.lib
includelib  \masm32\lib\user32.lib
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib
.code
;here are all the basic funcs



;the procesure that makes a crowd sound when you win the game
crowdSound proc

invoke PlaySound, offset soundCrowd,NULL,SND_FILENAME
ret
crowdSound endp

;the procesdure that claps when the ball hits the wall
clapSound proc

invoke PlaySound, offset soundClap,NULL,SND_ASYNC
ret
clapSound endp

	;moves the racket if the keys are pressed
	;and handles when the racket touches the wall
	moveRack proc adrRack:dword
	start:
	cmp racket.pos.y,0
	jle onlydown

	cmp racket.pos.y,400
	jge onlyup

	mov ebx,adrRack
	invoke GetAsyncKeyState,[ebx]
	cmp eax,0
	jne moveup

	
	invoke GetAsyncKeyState,[ebx+4]
	cmp eax,0
	jne movedown

	

	
	ret

	moveup:
	add racket.pos.y,-3
	ret

	movedown:
	add racket.pos.y,3
	ret

	onlyup:
	add racket.pos.y,-3
	jmp start

	onlydown:
	add racket.pos.y,3
	jmp start

	moveRack endp


	;moves the racket if the keys are pressed
	;and handles when the racket touches the wall
	 moveRack2 proc adrRack:dword
	start:
	cmp racket2.pos.y,0
	je onlydown

	cmp racket2.pos.y,400
	je onlyup

	mov ebx,adrRack
	invoke GetAsyncKeyState,[ebx]
	cmp eax,0
	jne moveup

	
	invoke GetAsyncKeyState,[ebx+4]
	cmp eax,0
	jne movedown

	

	
	ret

	moveup:
	add racket2.pos.y,-2
	ret

	movedown:
	add racket2.pos.y,2
	ret

	onlyup:
	add racket2.pos.y,-2
	jmp start

	onlydown:
	add racket2.pos.y,2
	jmp start

	moveRack2 endp
	
	; 
	resetCounter proc


cmp counter,80
je reset
ret

reset:
mov counter,0


ret

resetCounter endp

resetCounter2 proc
cmp counter2,80
je reset
ret

reset:
mov counter2,0

ret

resetCounter2 endp

resetCounterSpeed proc
cmp counterDrc,80
je reset
ret

reset:
mov counter2,0
ret

resetCounterSpeed endp

resetCounterSpeed2 proc


cmp counterDrc2,80
je reset
ret

reset:
mov counter2,0
ret

resetCounterSpeed2 endp



	accalerateBall proc
	cmp posXBall,200
	je checkDrc1

	cmp posXBall,800
	je checkDrc2
ret

	checkDrc1:
	cmp drcXBall,2
	je incDrc1
	ret

	checkDrc2:
	cmp drcXBall,-2
	je incDrc2
	ret


	incDrc1:
	mov eax,counterDrc
	mov eax,randomSpeed[eax]

	mov drcXBall,eax
	ret 

	incDrc2:
	mov eax,counterDrc2
	mov eax,randomSpeed2[eax]
	mov drcXBall,eax 
	ret

	accalerateBall endp


;handles the ball movements:


; handles the ball when it touches the wall on the ySides
moveTheBallY proc
mov ebx,posYBall

cmp ebx,0
jle ChangeDown

cmp ebx,480
jge ChangeUp
ret

ChangeDown:
mov drcYBall,2
ret

ChangeUp:
mov drcYBall,-2
ret

moveTheBallY endp

;checks if the ball is on the same xvalue as the rackets
;and then if it is checks if the y values or also the same
; if they are changes the drc of the ball and moves it accordingly
moveTheBallX proc
invoke resetCounter

mov ebx,posXBall
mov ecx,posYBall

cmp ebx,30
jle chkRacket1Y

cmp ebx,950
jge chkRacket2Y
RET


chkRacket1Y:
mov edi,racket.pos.y
cmp ecx,edi
jge chkY1
ret

chkRacket2Y:
mov edi,racket2.pos.y
cmp ecx,edi
jge chkY2
ret


chkY1:
mov edi,racket.pos.y
add edi,100
cmp ecx,edi
jle changeDrc1
ret


chkY2:
mov edi,racket2.pos.y
add edi,100
cmp ecx,edi
jle changeDrc2
ret

;changes the drc of the ball when it touches a racket
changeDrc1:
mov eax,counter
mov eax,random[eax]
mov drcXBall,2
add posYBall,eax
add counter,4
ret

;changes the drc of the ball when it touches a racket and ads posy
changeDrc2:
mov eax,counter2
mov eax,random[eax]
mov drcXBall,-2
add posYBall,eax
add counter,4
ret

moveTheBallX endp

;if the ball touches the wall resets it to the middle 
; and updates the score
resetBall proc
mov ebx ,posXBall
cmp ebx,0
je reset1

cmp ebx,980
je reset2
ret

reset1:
invoke clapSound

mov posXBall,500
mov posYBall,250
mov drcXBall,2
add rack2Points,1
ret

reset2:
invoke clapSound

mov posXBall,500
mov posYBall,250
mov drcXBall,-2
add rackPoints,1

ret
resetBall endp

;handles increasing the x and y values of the ball with the drc
; of the ball
moveBall proc

mov ebx,drcXBall
add posXBall,ebx
mov ecx,drcYBall
add posYBall,ecx



ret
moveBall endp

;resets the points if they reach 5 points
resetPoints proc
cmp rackPoints,5
je reset

cmp rack2Points,5
je reset
ret

reset:
invoke crowdSound
mov rackPoints,0
mov rack2Points,0
mov boolGame,0


ret
resetPoints endp

