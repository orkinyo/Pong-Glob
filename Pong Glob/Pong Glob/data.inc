
.const

;all the images used for the project
;Img struct from drd
Resorses struct
	bgpath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Background.bmp",0
	bluepath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Blue.bmp",0
	racketpath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Racket.bmp",0
	zeroPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\0.bmp",0
	onePath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\1.bmp",0
	twoPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\2.bmp",0
	threePath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\3.bmp",0
	fourPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\4.bmp",0
	zeroCopyPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\0copy.bmp",0
	oneCopyPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\1copy.bmp",0
	twoCopyPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\2copy.bmp",0
	threeCopyPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\3copy.bmp",0
	fourCopyPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\4copy.bmp",0
	dotsPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\Numbers\dots.bmp",0
	boostPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\boost.bmp",0
	boostLeftPath byte "C:\Users\orkin\Desktop\Pong Glob\pics\boostLeft.bmp",0
	OpeningScreen byte "C:\Users\orkin\Desktop\Pong Glob\pics\Opening Screen.bmp",0
	bg Img<>
	blue Img<>
	racket1 Img<>
	racket2 Img<>
	zero Img<>
	one Img<>
	two Img<>
	three Img<>
	four Img<>
	zeroCopy Img<>
	oneCopy Img<>
	twoCopy Img<>
	threeCopy Img<>
	fourCopy Img<>
	dots Img<>
	boost Img<>
	boostLeft Img<>
	OpScreen Img<>
Resorses ends

; keys to use for movement of rackets
Keys struct
	up dword ?
	down dword ?
Keys ends

Key struct
s dword ?
Key ends

Rack struct
keys Keys<0,4>
pos POINT<8,12>
Rack ends
;racket struct
Racket struct
keys Keys<>
pos POINT<>
Racket ends


.data
boolGame dword 0


soundClap byte "C:\Users\orkin\Downloads\Clap.wav",0
soundCrowd byte "C:\Users\orkin\Downloads\crowd.wav",0


;used to move the ball and draw it again
posXBall DWORD 480
posYBall DWORD 230
drcXBall DWORD 2
drcYBall DWORD 2

;points of each racket
rackPoints dword 0
rack2Points dword 0
counter dword 0
counter2 dword 0


;the speed counter
counterDrc dword 0
counterDrc2 dword 0





res Resorses<>
;left racket
racket Racket<<VK_W,VK_S>,<0,200>>
;right racket
racket2 Racket<<VK_UP,VK_DOWN>,<970,200>>


; so that the game won't reapeat itself we change it's positiong every time it touches the wall.
random dword 20 dup (5,7,9,2,7,7,6,9,5,1,6,6,1,6,2,8,5,5,3,3)
random2 dword 20 dup (1,5,6,2,8,1,9,6,9,1,4,6,4,2,2,1,6,3,9,7)



;random speed - every time the ball passes through the arrows
randomSpeed dword 20 dup (4,2,4,2,2,4,2,4,2,4,2,2,2,4,4,6,6,4,2,2)
randomSpeed2 dword 20 dup (-4,-2,-4,-2,-2,-4,-2,-4,-2,-4,-2,-2,-2,-4,-4,-6,-6,-4,-2,-2)



