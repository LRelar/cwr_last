.name "t_bot_st_ld"
.comment "This bot just is for load instructions checks"

start:
	ld %65, r2
	ld %66, r3
	ld -100, r4
	st r3, :st_ind

st_ind:
	live %0
