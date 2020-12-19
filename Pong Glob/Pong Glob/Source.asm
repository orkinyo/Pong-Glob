include \masm32\include\masm32rt.inc
include main_code.inc
.code

main proc
	invoke load
	loopi:
	invoke update

	;check bool to see if game has already started
	cmp boolGame,0
	jg GAME
	; checks if s is pressed to start the game
	invoke GetAsyncKeyState,VK_S
	cmp eax,0
	jne GAME
	jmp OPSCREEN

	


	GAME:
	;update bool to stay in game
	inc boolGame
	invoke draw
	invoke movementManager
	jmp loopi

	OPSCREEN:
	;reset the pos of rackets to starting position
	mov racket.pos.y,200
	mov racket2.pos.y,200
	invoke drawOpScreen
	invoke drd_flip
	jmp loopi
ret
main endp

end main
